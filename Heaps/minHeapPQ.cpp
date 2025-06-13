#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // insertion
    pq.push(100);
    pq.push(90);
    pq.push(80);
    pq.push(70);
    pq.push(60);

    cout<<"Minimum Element / Top of Heap: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Minimum Element / Top of Heap after Popping: "<<pq.top()<<endl;

    if(pq.empty()) {
        cout<<"Heap is Empty."<<endl;
    } else {
        cout<<"Heap is not Empty."<<endl;
    }

    cout<<"Size of Heap: "<<pq.size()<<endl;

    return 0;
}