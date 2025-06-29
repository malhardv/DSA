#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
   
    //creation
    unordered_map<string, int> mapping;

    // Insertion
    // ways to create pair
    pair<string, int> p = make_pair("Malhar", 21);
    pair<string, int> q("Navyaa", 10);
    pair<string, int> r;
    q.first = "John";
    q.second = 22;

    // Insertion Using Pair
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    // Insertion Direct
    mapping["MDV"] = 21;

    // Size of map
    cout<<"Size of Map: "<<mapping.size()<<endl;

    // Access
    cout<<"Age of Malhar: "<<mapping.at("Malhar")<<endl;
    cout<<"Age of Malhar: "<<mapping["Malhar"]<<endl; // returns value if key is present else creates new key with value 0
    
    cout<<"Age of MDV: "<<mapping.at("MDV")<<endl;

    // Searching
    cout<<"Is Malhar in Map: "<<mapping.count("Malhar")<<endl;    // returns 1 if key is present else returns 0
    cout<<"Is MalharV in Map: "<<mapping.count("MalharV")<<endl;  

    if(mapping.find("Malhar") != mapping.end()) {
        cout<<"Key Found!"<<endl;
    } else {
        cout<<"Key Not Found.";
    }

    cout<<"Size of Map: "<<mapping.size()<<endl;
    cout<<mapping["NavyaaV"]<<endl;
    cout<<"Size of Map: "<<mapping.size()<<endl;
    
    return 0;
}