#include<iostream>
using namespace std;

int fibonacci(int n) {
    // base case
    if (n == 0) {
        return;
    } else if (n == 1) {
        return 1;
    } else {
        int ans = fibonacci(n-1) + fibonacci(n-2);
        return ans;
    }
}

int main() {
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int fibNum = fibonacci(n);
    return 0;
}