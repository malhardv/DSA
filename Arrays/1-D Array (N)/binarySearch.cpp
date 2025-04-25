#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2; //if start and end both are max value of int, then they wont add up when using mid = start + end / 2

    while(start <= end) {
        if(arr[mid] == key) {
            return mid;
        }

        if(arr[mid] < key) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
        mid = (start+end)/2;
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<"\t";
    }
}


int main() {
    int even[6] = {3, 5, 7, 14, 22, 29};
    int odd[5] = {4, 5, 12, 34, 55};

    int index = binarySearch(odd, 5, 11);
    if(index == -1) {
        cout<<"Key not found.";
    } else {
        cout<<"Key found at index "<<index;
    }
    return 0;
}