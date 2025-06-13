#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout<<"Top Element of Heap: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top Element after Pop: "<<pq.top()<<endl;

    cout<<"Size of Max-Heap: "<<pq.size()<<endl;

    if(pq.empty()) {
        cout<<"Heap is Empty"<<endl;
    } else {
        cout<<"Heap is not Empty"<<endl;
    }

    return 0;
}