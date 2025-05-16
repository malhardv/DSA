#include<iostream>
#include<queue>
using namespace std;

int kthSmallest(int arr[], int k, int n) {
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}

int main() {
    int arr[] = {3, 7, 4, 5, 6, 8, 9};
    int answer = kthSmallest(arr, 4, 7);
    cout<<"Kth Smallest Element in Array: "<<answer;
    return 0;
}