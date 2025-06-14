#include<iostream>
#include<queue>
using namespace std;


// method 1
int kthSmallestElementM1(int arr[], int size, int k) {
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

// method 2
int kthSmallestElementM2(int arr[], int size, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {
        int element = arr[i];
        pq.push(element);
    }

    for(int i = k; i < size; i++) {
        int element = arr[i];
        if(element < pq.top()) {
            pq.push(element);
            pq.pop();
        }
    }

    return pq.top();
}

int main() {
    int arr[] = {3, 7, 4, 5, 8, 6, 9};
    int size = 7;
    int k = 4;
    int kthSmallestM1 = kthSmallestElementM1(arr, size, k);
    int kthSmallestM2 = kthSmallestElementM2(arr, size, k);
    cout<<"Kth Smallest Element in Array (Method 1): "<<kthSmallestM1<<endl;
    cout<<"Kth Smallest Element in Array (Method 2): "<<kthSmallestM2;

    return 0;
}