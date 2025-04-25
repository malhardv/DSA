// boxes and piles waala question
#include <bits/stdc++.h>
using namespace std;

int minOperationsToAchieveD(vector<int> &boxes, int d) {
    // Implement your logic here
    int n = boxes.size();
    sort(boxes.begin(), boxes.end());
    int count = 0;

    int left = 0;
    int right = n-1;

    while((boxes[left] - boxes[right]) > d) {
        boxes[right]--;
        boxes[left]++;
        count++;

        if(boxes[left] > boxes[left+1]) left++;
        if(boxes[right] < boxes[right-1]) right++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> boxes(n);
    
    for (int i = 0; i < n; i++) cin >> boxes[i];

    int d;
    cin >> d; 

    cout << minOperationsToAchieveD(boxes, d) << endl;
    return 0;
}
