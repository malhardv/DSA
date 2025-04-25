#include<iostream>
using namespace std;

void merge(int s, int e, int *arr) {
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy the left part in the first array
    int k = s;
    for(int i = 0; i < len1; i++) {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for(int i = 0; i < len2; i++) {
        second[i] = arr[k++];
    }

    int index1 = 0;
    int index2 = 0;
    k = s;
    
    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[k++] = first[index1++];
        } else {
            arr[k++] = second[index2++];
        }
    }

    while(index1 < len1) {
        arr[k++] = first[index1++];
    }

    while(index2 < len2) {
        arr[k++] = second[index2++];
    }
}

void mergeSort(int s, int e, int *arr) {
    // base case
    if(s >= e) {
        return;
    }
    int mid = s + (e-s)/2;
    // Left Part
    mergeSort(s, mid, arr);
    // Right Part
    mergeSort(mid + 1, e, arr);
    // Merge
    merge(s, e, arr);
}

int main() {
    int arr[5] = {29, 58, 100, 34, 3};
    int size = 5;
    int s = 0;
    int e = size - 1;

    cout<<"Original Array: ";
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    mergeSort(s, e, arr);

    cout<<"Sorted Array: ";
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}