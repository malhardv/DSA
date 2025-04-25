#include<iostream>

using namespace std;

bool search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return 1;     // 1 = true
        }
    return 0;
}
}


int main() {
    int arr[10] = {5, 7, -2, 100, 56, 23, 22, -17, -6, 96};
    int key;

    cout<<"Enter the key";
    cin>>key;

    bool found = search(arr, 10, key);
    if (found) {
        cout<<key<<" is present in the array!"<<endl;
    } else {
        cout<<key<<" is not present in the array!";
    }
    return 0;
}