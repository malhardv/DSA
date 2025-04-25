// Linear Search Using Recursions

#include<iostream>
using namespace std;

bool isPresent(int arr[], int size, int target) {
    // base case 
    if(size == 0) {
        return 0;
    }
    if(arr[0] == target) {
        return 1;
    } else {
        isPresent(arr + 1, size - 1, target);
    }
    // return 0;
}

int main() {
    int arr[10] = {32, 45, 23, 56, 7, 34, 4, 12, 31, 49};
    if(isPresent(arr, 10, 57)) {
        cout<<"The element is present!";
    } else {
        cout<<"The element is not present.";
    }
    return 0;
}