#include<iostream>
using namespace std;

int lengthOfString(char arr[]) {
    int i = 0;
    int count = 0;
    while (arr[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

int main() {
    char name[10];
    cout<<"Enter your name: "<<endl;
    cin>>name;
    cout<<"The length of your name is: "<<lengthOfString(name);
    return 0;
}