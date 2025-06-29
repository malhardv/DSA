#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Info {
    public:
        int data;
        int rowIndex;
        int colIndex;

        Info(int data, int row, int col) {
            this -> data = data;
            this -> rowIndex =  row;
            this -> colIndex = col;
        }
};

class compare {
    public:
    bool operator()(Info* a, Info* b) {
        return a -> data > b -> data;
    }
};

void mergeKSortedArrays(vector<vector<int>> in, int n, int k, vector<int> &answer) {
    // create min heap
    priority_queue<Info*, vector<Info*>, compare> pq;

    // 1. process first elements of all k arrays
    for(int i = 0; i < k; i++) {
        int element = in[i][0];
        Info* temp = new Info(element, i, 0);
        pq.push(temp);
    }

    while(!pq.empty()) {
        Info* temp = pq.top();
        pq.pop();

        int topData = temp -> data;
        int topRow = temp -> rowIndex;
        int topCol = temp -> colIndex;

        // store the answer in answer array
            answer.push_back(topData);

        if(topCol + 1 < n) {
            Info* newInfo = new Info(in[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(newInfo);
        }
    }

}

int main() {
    vector<vector<int>> input = {{1, 4, 8, 10},
                                 {2, 3, 6, 9},
                                 {5, 7, 11, 12}};

    int k = input.size();
    int n = input[0].size();
    vector<int> answer;

    mergeKSortedArrays(input, n, k, answer);

    cout<<"Merged Sorted Array: ";
    for(int i = 0; i < answer.size(); i++) {
        cout<<answer[i]<<" ";
    }
    
}