#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
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
    unordered_map<T, list<pair<T, int>>> adjList;
    
    void addEdge(T u, T v, bool direction, int weight) {
        
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

    void bfsTraversal(T src, unordered_map<T, bool> &visited) {                // does not work for disconnected graph

        // queue
        queue<T> q;

        // initial state
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            T front = q.front();
            cout<<front<<" ";
            q.pop();

            for(auto i: adjList[front]) {    //  i will be a pair 
                if(!visited[i.first]) {
                    q.push(i.first);
                    visited[i.first] = true;
                }
            }
        }

    }

    void dfsTraversal(T src, unordered_map<T, bool> &visited) {

        visited[src] = true;
        cout<<src<<" ";

        for(auto nbr: adjList[src]) {
            T nbrData = nbr.first;
            if(!visited[nbrData]) {
                dfsTraversal(nbrData, visited);
            }
        }
    }
};

int main() {
    WGraph<char> g;                    // using template we can define the specific datatype during declaration
    // g.addEdge(0, 1, 1, 20);
    // g.addEdge(1, 2, 1, 30);
    // g.addEdge(1, 3, 1, 50);
    // g.addEdge(2, 3, 1, 40);
    g.addEdge('a', 'b', 1, 20);
    g.addEdge('b', 'c', 1, 30);
    g.addEdge('b', 'd', 1, 50);
    g.addEdge('c', 'd', 1, 40);
    g.addEdge('e', 'f', 1, 40);
    g.addEdge('g', 'h', 1, 40);


    // cout<<"BFS Traversal: ";
    unordered_map<char, bool> visited;
    // // g.bfsTraversal('a');               // wont work for disconnected graph
    // for(char i = 'a'; i <= 'f'; i++) {    // will work for disconnected graph also
    //     if(!visited[i]) {
    //         g.bfsTraversal(i, visited);
    //     }
    // }

    cout<<"DFS Traversal: ";
    for(int i = 'a'; i <= 'h'; i++) {
        if(!visited[i]) {
            g.dfsTraversal(i, visited);
        }
    }

    return 0;
}