#include<iostream>
#include<math.h>
using namespace std;

int findValue(int base, int exp) {
    int value;
    if (exp == 0) {
        return 1;
    }
    if (exp == 1) {
        return base;
    }

    int ans = findValue(base, exp/2);

    if (exp%2 == 0) {
        return ans*ans;
    } else {
        return base * ans * ans;
    }
}

int main() {
    int a, b;
    cout<<"Enter the base: ";
    cin>>a;
    cout<<"Enter the exponent: ";
    cin>>b;
    int value = findValue(a, b);
    cout<<"The value is: "<<value;
    return 0;
}