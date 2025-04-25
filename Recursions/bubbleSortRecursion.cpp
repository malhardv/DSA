#include<iostream>
#include<vector>
using namespace std;

// Bubble sort using recursion

void bubbleSort(int arr[], int size) {

    //base case
    if(size == 0 || size == 1) {
        return;
    }

    // processing
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    // recursive call
    bubbleSort(arr, size-1);
}

int main() {
    int arr[5] = {34, 12, 95, 100, 34};
    int n = 5;
    cout<<"Original array";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"\t";
    }
    bubbleSort(arr, n);
    cout<<"Sorted array :";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"\t";
    }
}