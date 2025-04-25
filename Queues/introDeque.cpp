#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> d(5);

    d.push_front(10);
    d.push_back(20);
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    d.push_front(4);
    d.push_front(5);

    cout<<"Front: "<<d.front()<<endl;
    cout<<"Back: "<<d.back()<<endl;


    return 0;
}