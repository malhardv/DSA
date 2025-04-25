// #include <bits/stdc++.h> 
// #include<string>
// #include<iostream>
// using namespace std;

// char toLowerCase(char a) {
//     if (a >= 'a' && a <= 'z') {
//         return a;
//     } else {
//         char temp = a - 'A' + 'a';
//         return temp;
//     }
// }

// bool isValidCharacter(char ch) {
//     return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
// }

// int lengthOfString(string arr) {
//     int i = 0;
//     int count = 0;
//     while (arr[i] != '\0') {
//         count++;
//         i++;
//     }
//     return count;
// }

// bool checkPalindrome(string s)
// {
//     int i = 0;
//     int e = lengthOfString(s)-1;
//     while(i<e) {
//         if(isValidCharacter(s[i]) && isValidCharacter(s[e])){
//             if (toLowerCase(s[i]) != toLowerCase(s[e])){
//                 return 0;
//             } else {
//                 i++;
//                 e--;
//             }
//         }
//     }
//     return 1;
// }

// int main() {
//     string s = "5?36@6?35";
//     bool result = checkPalindrome(s);

//     if(result) {
//         cout<<"palindrome";
//     } else {
//         cout<<"not palindrome";
//     }
// }

#include <iostream>
#include <string>
using namespace std;

char toLowerCase(char a) {
    if (a >= 'A' && a <= 'Z') {
        return a + 32;  // Convert to lowercase
    }
    return a;  // Return unchanged if already lowercase or not an alphabet
}

bool isValidCharacter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

bool checkPalindrome(const string& s) {
    int i = 0;
    int e = s.length() - 1; // Use length() to get the size of the string

    while (i < e) {
        // Move the left pointer until we find a valid character
        while (i < e && !isValidCharacter(s[i])) {
            i++;
        }
        // Move the right pointer until we find a valid character
        while (i < e && !isValidCharacter(s[e])) {
            e--;
        }

        // If both pointers have not crossed, compare the characters
        if (i < e) {
            if (toLowerCase(s[i]) != toLowerCase(s[e])) {
                return false; // Not a palindrome
            }
            i++;
            e--;
        }
    }
    return true; // The string is a palindrome
}

int main() {
    string s = "5?36@6?35"; // Example input
    bool result = checkPalindrome(s);

    if (result) {
        cout << "palindrome" << endl;
    } else {
        cout << "not palindrome" << endl;
    }

    return 0;
}
