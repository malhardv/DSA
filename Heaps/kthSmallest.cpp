#include<iostream>
#include<queue>
using namespace std;

int kthSmallestElement(int arr[], int size, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {
        int element = arr[i];
        pq.push(element);
    }

    for(int i = k; i < size; i++) {
        int element = arr[i];
        pq.push(element);
        if(pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}

int main() {
    int arr[] = {3, 7, 4, 5, 8, 6, 9};
    int size = 7;
    int k = 4;
    int kthSmallest = kthSmallestElement(arr, size, k);
    cout<<"Kth Smallest Element in Array: "<<kthSmallest;

    return 0;
}