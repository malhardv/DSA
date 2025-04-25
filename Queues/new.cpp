#include<iostream>
#include<string>
using namespace std;


int main() {
    int n = 5;
    for(int i = 0; i < n; i++) {
        string res = "";

        res.append(n-i, ' ');
        res.append(i+1, '*');

        cout<<res<<endl;
    }
    return 0;
}