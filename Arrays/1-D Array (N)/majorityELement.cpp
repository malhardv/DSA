#include<iostream>
using namespace std;

int majorityElement(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > size/2) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int arr[10] = {5, 5, 3, 5, 4, 5, 5, 5, 4, 6};
    int answer = majorityElement(arr, 10);
    cout<<answer;
    return 0;
}