#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
   
    //creation
    unordered_map<string, int> mapping;

    //insertion
    // ways to create pair
    pair<string, int> p = make_pair("Malhar", 21);
    pair<string, int> q("Navyaa", 10);
    pair<string, int> r;
    q.first = "John";
    q.second = 22;

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    // size of map
    cout<<"Size of Map: "<<mapping.size();
    return 0;
}