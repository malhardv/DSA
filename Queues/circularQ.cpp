#include<iostream>
using namespace std;

class Cqueue {
    public: 
    int *arr;
    int size;
    int front;
    int rear;

    Cqueue(int size) {
        arr = new int[size];
        this -> size = size;
        front = -1;
        rear = -1;
    }

    void push(int element) {

        // overflow cond
        // empty queue
        // circular nature
        // normal flow

        if((front == 0 && rear == size - 1) || (rear == front - 1)) {
            cout<<"Queue Overflow"<<endl;;
        } else if(front == -1 && rear == -1) {
            front++;
            rear++;
            arr[front] = element;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = element;
        } else {
            rear++;
            arr[rear] = element;
        }
    }

    void pop() {

        // underflow
        // single element
        // circular nature
        // normal flow

        if(front == -1 && rear == -1) {
            cout<<"Stack Underflow"<<endl;
        } else if (front == rear) {
            arr[front] = -1;
            front++;
        } else if(front == size - 1) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        } else {
            arr[front] = -1;
            front++;
        }
    }

    void print() {
        cout<<"Front: "<<front<<"  "<<"Rear: "<<rear<<endl;
        cout<<"Printing Queue:   ";
        for(int i = 0; i < size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {

    Cqueue cq(5);
    cq.print();
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);

    cq.print();
    cq.pop();
    cq.push(6);
    cq.print();

    cq.push(10);
    return 0;
}