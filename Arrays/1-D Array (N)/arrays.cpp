#include<iostream>

using namespace std;

void printArray(int arr1[], int n) {
    for (int i = 0; i < n; i++) {
        cout<<arr1[i]<<"\t";
    }
}

int main() {

    //declare array
    int num[15];
    cout<<num[0]<<endl<<endl;

    //initialise array
    int n = 5;
    int arr[5] = {5, 7, 11};
    printArray(arr, n);
    cout<<endl;

    int arrSize = sizeof(arr) / sizeof(int);
    cout<<arrSize<<endl;

    return 0;
}