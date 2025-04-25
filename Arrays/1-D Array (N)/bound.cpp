#include <iostream>

using namespace std;

int firstOccur(int arr[], int n, int key) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans;

    while(s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        } else if(key < arr[mid]) {      // go left
            e = mid - 1;
        } else if (key > arr[mid]) {     // go right
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}
 
int lastOccur(int arr[], int n, int key) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans;

    while(s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        } else if(key < arr[mid]) {      // go left
            e = mid - 1;
        } else if (key > arr[mid]) {     // go right
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }

}



int main() {
    int even[5] = {3, 2, 3, 3, 5};
    int first = firstOccur(even, 5, 3);
    int last = lastOccur(even, 5, 3);

    cout<<"the first occurence of 3 is "<<first;
    cout<<"the last occurence of 3 is "<<last;
}