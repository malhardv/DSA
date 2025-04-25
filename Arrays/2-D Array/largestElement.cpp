#include<iostream>
using namespace std;

int largestSum(int arr[][3], int row, int col) {
    int maxi = INT16_MIN;
    int rowIndex = -1;

    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += arr[i][j];
        }
        if(sum > maxi) {
            maxi = sum;
            rowIndex = i;
        }
    }
    return rowIndex;
}

int main() {
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8 ,9};
    int largest = largestSum(arr, 3, 3);
    cout<<largest;
    return 0;
}