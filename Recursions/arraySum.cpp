#include<iostream>
using namespace std;

int arraySum(int arr[], int size) {
    
    // base case
    if (size == 0) {
        return 0;
    }

    int sum = arr[0];
    sum += arraySum(arr + 1, size - 1);
    return sum;
}

int main() {
    int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int sum =  arraySum(arr, 11);
    cout<<"The sum of the array is: "<<sum;
    return 0;
} 