#include<iostream>
#include<stack>
using namespace std;

class Stack {
    public:
        int *arr;
        int size;
        int top;

        Stack(int size) {
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element) {
            if((size - top) >  1) {
                top++;
                arr[top] = element;
            } else {
                cout<< "Stack Overflow";
            }
        }

        void pop() {
            if(top >= 0) {
                top--;
            } else {
                cout<<"Stack Underflow";
            }
        }

        int peak() {
            if(top >= 0) {
                return arr[top];
            } else {
                cout<<"Stack is Empty";
                return -1;
            }
        }

        bool isempty() {
            if(top == -1) {
                return true;
            } else {
                return false;
            }
        }
};


int main() {
    stack<int> s;

    // Push Operation
    s.push(2);
    s.push(3);

    // Pop Operation
    s.pop();    

    // Peek Operation
    cout<<"Top Element of the Stack: "<<s.top()<<endl;

    // isempty operation
    if(s.empty()) {
        cout<<"The Stack is Empty."<<endl;
    } else {
        cout<<"The Stack is Not Empty"<<endl;
    }

    // size of the stack
    cout<<"Size of Stack: "<<s.size();

    return 0;
}