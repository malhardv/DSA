#include<iostream>
using namespace std;

int power2(int n) {
    if (n == 0) {
        return 1;
    }
    return 2 * power2(n-1);
}

int main() {
    int n;
    cout<<"Enter the power: ";
    cin>>n;

    int ans = power2(n);
    cout<<"2 to the power "<<n<<" is "<< ans;
    return 0;
}