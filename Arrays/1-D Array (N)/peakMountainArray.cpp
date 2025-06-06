#include <iostream>
#include <vector>
using namespace std;

int findMountainPeak(int arr[], int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while (s<e) {
        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}


int main() {
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    int peak = findMountainPeak(arr, 7);
    cout<< "The peak of the mountain array is "<<peak;
    return 0;
}
