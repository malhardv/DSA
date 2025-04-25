#include<iostream>
using namespace std;

void swapAlternate(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if(i+1 < n) {
            swap(arr[i], arr[i+1]);
            i++;
        }
    }
}

void printArray(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"\t";
    }

}

int main() {

    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Output -> {2, 1, 4, 3, 6, 5, 8, 7 , 10, 9} 
    swapAlternate(arr, 9);
    printArray(arr, 9);
    return 0;
}