#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction) {
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

int main() {
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);

    return 0;
}