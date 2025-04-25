#include<iostream>
#include<string>
using namespace std;

void reverseString(string str, int s, int e){

    cout<<"String ---->      "<<str<<endl;

    // base case    
    if (s > e) {
        return;
    }
    swap(str[s], str[e]);
    reverseString(str, s+1, e-1);
}

int main() {
    string str = "malhar";
    int s = 0;
    int e = 5;
    reverseString(str, s, e);
    return 0;
}