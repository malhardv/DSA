// MAX HEAP USING PRIORITY QUEUE

#include<iostream>
#include<queue>
using namespace std;

int main() {

    // create max heap
    priority_queue<int> pq;

    // insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    // top element
    cout<<"Top Element of Heap: "<<pq.top()<<endl;

    // delete element (always top element is deleted)
    pq.pop();
    cout<<"Deleted root element."<<endl;
    cout<<"Top Element: "<<pq.top()<<endl;

    // size of max Heap
    cout<<"Size of Max Heap: "<<pq.size()<<endl;

    if(pq.empty()) {
        cout<<"Heap Empty"<<endl;
    } else {
        cout<<"Heap Not Empty"<<endl;
    }
    return 0;
}