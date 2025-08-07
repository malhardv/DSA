#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> p_arr;
vector<int> seg_tree;

void build_seg_tree(int node, int start, int end) {
    if (start == end) {
        seg_tree[node] = p_arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    build_seg_tree(2 * node, start, mid);
    build_seg_tree(2 * node + 1, mid + 1, end);
    seg_tree[node] = min(seg_tree[2 * node], seg_tree[2 * node + 1]);
}

int query_seg_tree(int node, int start, int end, int l, int r) {
    if (r < start || end < l || l > r) {
        return INT_MAX;
    }
    if (l <= start && end <= r) {
        return seg_tree[node];
    }
    int mid = start + (end - start) / 2;
    int p1 = query_seg_tree(2 * node, start, mid, l, r);
    int p2 = query_seg_tree(2 * node + 1, mid + 1, end, l, r);
    return min(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        p_arr.assign(N, 0);
        int current_sum = 0;
        for (int i = 0; i < N; ++i) {
            int val;
            cin >> val;
            current_sum += val;
            p_arr[i] = current_sum;
        }

        seg_tree.assign(4 * N, 0);
        build_seg_tree(1, 0, N - 1);

        int Q;
        cin >> Q;
        vector<int> answers;
        for (int q = 0; q < Q; ++q) {
            int L, R;
            cin >> L >> R;
            L--;
            R--;

            int p_r = p_arr[R];
            int p_l_minus_1 = (L == 0) ? 0 : p_arr[L - 1];
            
            int min_p_in_range = query_seg_tree(1, 0, N - 1, L, R);

            int ones_count = ((R - L + 1) + (p_r - p_l_minus_1)) / 2;
            int final_balance = p_r - min_p_in_range;
            
            int len = 2 * (ones_count - final_balance);
            answers.push_back(len);
        }

        for (int i = 0; i < answers.size(); ++i) {
            cout << answers[i] << (i == answers.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}