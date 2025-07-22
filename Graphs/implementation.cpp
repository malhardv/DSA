#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

template <typename T>
class UGraph {       // Unweighted Graph
    public:
    unordered_map<T, list<T>> adjList;
    void addEdge(T u, T v, bool direction) {
        // direction -> 0 -> undirected
        // direction -> 1 -> directed
        if(direction == 1) {
            // u -> v from only u to v
            adjList[u].push_back(v);
        } else {
            // direction is 0
            // undirected    u -> v and v -> u
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        cout<<"Printing Adjacency List: "<<endl;
        printAdjList();
        cout<<endl;
    }
    
    void printAdjList() {
        for(auto i: adjList) {
            cout<< i.first << " -> { ";
            for(auto neighbour: i.second) {
                cout<<neighbour<<" ";
            }
            cout<<" }"<<endl;
        }
    }
};

template <typename T>
class WGraph {        // Weighted Graph
    public: 
    unordered_map<T, list<pair<T, T>>> adjList;
    
    void addEdge(T u, T v, bool direction, T weight) {
        
        // if directed edge
        if(direction == 1) {
            adjList[u].push_back({v, weight});
        } else {    // undirected edge
            // direction == 0
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }

        
        cout<<"Printing Adjacency List: "<<endl;
        printAdjList();
        cout<<endl;
    }
    
    void printAdjList() {
        for(auto i: adjList) {
            cout<< i.first << " -> { ";
            for(auto neighbour: i.second) {
                cout<<" { Node: "<<neighbour.first <<"  Weight: "<<neighbour.second<<" }";
            }
            cout<<" }"<<endl;
        }
    }
};

int main() {
    WGraph<int> g;                    // using template we can define the specific datatype during declaration
    g.addEdge(0, 1, 1, 20);
    g.addEdge(1, 2, 1, 30);
    g.addEdge(1, 3, 1, 50);
    g.addEdge(2, 3, 1, 40);

    return 0;
}