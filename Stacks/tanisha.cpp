#include<iostream>
using namespace std;


class Stack {
    public:
    int top;
    int size;
    int *arr;

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(top == size - 1) {
            cout<<"Stack Overflow";
            return;
        } else {
            top++;
            arr[top] = element;
        }
    }

    void pop() {
        if(top == -1) {
            cout<<"Stack Underflow";
            return;
        } else {
            top--;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }

    int peek() {
        if(top == -1) {
            return -1;
        } else {
            return arr[top];
        }
    }

    int getSize() {
        int count = 0;
        int a = top;

        while(a >= 0) {
            a--;
            count++;
        }

        return count;
    }

    void print() {
        for(int i = 0; i <= top; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};



int main() {

    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();

    s.pop();
    s.print();

    s.pop();
    s.print();

    if(s.isEmpty()) {
        cout<<"Stack is empty" <<endl; 
    } else {
        cout<<"NoT Empty"<<endl;
    }


    cout<<"Size of the stack: "<<s.getSize()<<endl;

    cout<<"Peek Element: "<<s.peek();
    return 0;
}