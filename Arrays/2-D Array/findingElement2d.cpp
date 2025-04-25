#include<iostream>
using namespace std;

bool isPresent(int arr[][3], int target, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if(arr[i][j] == target) {
                return 1;
            }
        }
    }
    return 0;
}

void printSum(int arr[][3], int rows, int columns) {
    cout<<"Printing the Row-Wise Sum ---> "<<endl;
    for(int i = 0; i < rows; i++){
        int sum = 0;
        for(int j = 0; j < columns; j++) {
            sum += arr[i][j];
        }
        cout<<sum;
        cout<<endl;
    }
}

int main() {
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target;
    cout<<"Enter the element to find: ";
    cin>>target;

    if(isPresent(arr, target, 3, 3)) {
        cout<<"Element Found!"<<endl;
    } else {
        cout<<"Element Not Found.";
    }

    printSum(arr, 3, 3);
    return 0;
}