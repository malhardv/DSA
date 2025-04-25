#include<iostream>
#include <bits/stdc++.h> 
#include<vector>

int sort01(int arr[], int size) {
    int i = 0;
    int j = size-1;
    while(i < j) {
        if (arr[i] == 0) {
            i++;
        } else if (arr[j] == 1) {
            j--;
        } else if(arr[i] == 1 && arr[j] == 0) {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[6] = {0, 1, 1, 0, 1, 0};
    sort01(arr, 6);
}