#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int back;
    int size;
    int *arr;

    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        back = -1;
    }

    void push(int element)
    {
        if (back == size - 1)
        {
            // queue is full
            cout << "Queue Overflow"<<endl;
            return;
        }
        else if (front == -1 && back == -1)
        {
            // queue is empty
            // pushing first element;
            back++;
            arr[back] = element;
            front++;
        }
        else
        {
            back++;
            arr[back] = element;
        }
    }

    void pop()
    {
        if (front == -1 && back == -1)
        {
            cout << "Queue Empty"<<endl;
            return;
        }
        else if (front == back)
        {
            arr[front] = -1;
            front = -1;
            back = -1;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty() {
        if(front == -1 && back == -1) {
            return true;
        } else {
            return false;
        }
    }

    int getSize() {
        return back - front + 1;
    }

    int getFront() {
        if(front == -1) {
            return -1;
        } else {
            return arr[front];
        }
    }

    int getBack() {
        if(back == -1) {
            return -1;
        } else {
            return arr[back];
        }
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main() {
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.print();  // Expected Output: 10 20 30
    q.pop();
    q.print();  // Expected Output: 20 30
    return 0;
}