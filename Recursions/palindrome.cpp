#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string str, int i, int j) {
    
    // base case
    if (i > j) {
        return true;
    }

    //processing
    if(str[i] == str[j]) {
        checkPalindrome(str, i+1, j-1);
    } else {
        return false;
    }
    return true;
}



int main() {
    string str = "abcdedcba";
    int i = 0;
    int j = str.length()-1;
    bool check = checkPalindrome(str, i, j);
    if(check) {
        cout<<"The string IS A PALINDROME!";
    } else {
        cout<<"The string IS NOT A PALINDROME";
    }
}