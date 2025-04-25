#include<iostream>
#include<array>
#include<vector>
#include<queue>

using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(5);
    pq.push(4);
    pq.push(3);
    pq.push(2);
    pq.push(1);
    pq.push(0);

    pq.pop();
    int n = pq.size();
    for(int i = 0; i < n; i++) {
        cout<<pq.top()<<endl;
    }
}