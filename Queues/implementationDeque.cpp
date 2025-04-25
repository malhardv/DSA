#include<iostream>
using namespace std;

class deque {
    int *arr;
    int size;
    int front;
    int back;

    deque(int size) {
        arr = new int[size];
        this -> size = size;
        front = -1;
        back = -1;
    }

    void push_front(int element) {
        if (front == 0) {
            cout<<"Queue Overflow"<<endl;
        } else if (front == -1 && back  == -1) {
            front++;
            back++;
            arr[back] = element;
        } else {
            front--;
            arr[front] = element;
        }
        
    }

    void push_back(int element) {
        if((front == 0 && back == size - 1) || (back == front - 1)) {
            cout<<"Queue Overflow"<<endl;;
        } else if(front == -1 && back == -1) {
            front++;
            back++;
            arr[front] = element;
        } else if (back == size - 1 && front != 0) {
            back = 0;
            arr[back] = element;
        } else {
            back++;
            arr[back] = element;
        }
    }

    void pop_front() {
        if(front == -1) {
            cout<<"Queue Empty"<<endl;
        } else if ()
    }

    void pop_back() {

    }
};

