#include <iostream>
using namespace std;

int reverseArray(int arr[], int n) {
    int start = 0;
    int end = n-1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"\t";
    }

}

int main() {

    int arr[6] = {1, 2, 3, 4, 5, 6};
    int brr[5] = {5, 4, 3, 2, 1};
    reverseArray(arr, 6);
    reverseArray(brr, 5);

    printArray(arr, 6);
    printArray(brr, 5);
    return 0;
}