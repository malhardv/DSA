// MIN HEAP USING PRIORITY QUEUE

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {

    // creation of min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // insertion
    pq.push(100);
    pq.push(90);
    pq.push(70);

    // top element - minimum element in the queue
    cout<<"Top Element in Min Heap: "<<pq.top()<<endl;

    // remove element - always root element is removed
    pq.pop();
    cout<<"Top element deleted."<<endl;
    cout<<"Top Element in Min Heap: "<<pq.top()<<endl;

    // size of heap
    cout<<"Size of Heap: "<<pq.size()<<endl;

    // empty or not
    if(pq.empty()){
        cout<<"Heap is Empty"<<endl;
    } else {
        cout<<"Heap is Not Empty"<<endl;
    }
    return 0;
}