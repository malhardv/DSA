#include<iostream>
using namespace std;

int findUnique(int arr[], int size) {
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans = ans^(arr[i]);
    }
    return ans;
}


int main() {
    int arr[7] = {3, 1, 2, 2, 8 , 3, 1};
    int uniqueElement = findUnique(arr, 7);
    cout<<"The unique element is: "<<uniqueElement<<endl;
    return 0;
}