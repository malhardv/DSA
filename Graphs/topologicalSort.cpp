#include<iostream>
#include<unordered_map>
#include<list>
#include<map>
#include<stack>
#include<queue>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {
        if(direction == 1) {
            adjList[u].push_back(v);
        } else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for(auto i : adjList) {
            cout<<i.first<<": ";
            for(auto j : i.second) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void topologicalSortDFS(int src, map<int, bool> &visited, stack<int> &s) {
        visited[src] = true;
        for(auto nbr: adjList[src]) {
            if(!visited[nbr]) {
                topologicalSortDFS(nbr, visited, s);
            }
        }

        s.push(src);
    }

    void topologicalSortBFS(int n) {
        queue<int> q;
        map<int, int> inDegree;

        for(auto i: adjList) {
            for(auto nbr: i.second) {
                inDegree[nbr]++;
            }
        }

        // for(auto i: inDegree) {
        //     cout<<i.first<<" : "<<i.second<<endl;
        // }

        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<" ";

            for(auto nbr: adjList[frontNode]) {
                inDegree[nbr]--;

                if(inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }

        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 1);
    // g.printAdjList();

    // topological sort
    // int n = 8;
    // map<int, bool> visited;
    // stack<int> s;
    // for(int node = 0; node < n; node++) {
    //     if(!visited[node]) {
    //         g.topologicalSortDFS(node, visited, s);
    //     }   
    // }
    // cout<<"Printing Topological Order: "<<endl;
    // while(!s.empty()) {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    g.topologicalSortBFS(8);
    return 0;
}