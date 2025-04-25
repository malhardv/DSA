#include<iostream>
#include<queue>
using namespace std;


int main() {

    // creation
    queue<int> q;

    // insertion
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);

    // top element
    cout<< "Front Element: "<< q.front() <<endl;
    cout<< "Last Element: "<< q.back() <<endl;
    
    // size
    cout<<"Size of Queue: "<<q.size()<<endl;
    
    // check empty
    if(q.empty()) {
        cout<<"Queue is EMPTY"<<endl;
    } else {
        cout<<"Queue is NOT EMPTY"<<endl;
    }
    
    // remove element
    q.pop();
    cout<< "Front Element: "<< q.front() <<endl;
    cout<< "Last Element: "<< q.back() <<endl;

    return 0;

}