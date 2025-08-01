#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
#include<stack>
#include<map>
using namespace std;

template <typename T>
class Graph {
public:
    map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        if (direction) {
            adjList[u].push_back(v);
        } else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << " : { ";
            for (auto nbr : i.second) {
                cout << nbr << " ";
            }
            cout << "}" << endl;
        }
    }

    void dfs1(int src, stack<int> &s, unordered_map<int, bool> &visited) {
        visited[src] = true;

        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) {
                dfs1(nbr, s, visited);
            }
        }

        s.push(src);
    }

    void dfs2(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjNew) {
        visited[src] = true;

        for(auto nbr: adjNew[src]) {
            if(!visited[nbr]) {
                dfs2(nbr, visited, adjNew);
            }
        }

    }   

    int getStronglyConnectedComponents(int n) {

        // step 1 get the ordering  
        stack<T> s;
        unordered_map<T, bool> visited;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs1(i, s, visited);
            }
        }

        // step 2 reverse the edges
        unordered_map<T, list<T>> adjNew;
        for(auto a : adjList) {
            for(auto b : a.second) {
                int u = a.first;
                int v = b;

                adjNew[v].push_back(u);
            }
        }

        // step 3 traverse using ordering and count components
        int count = 0;
        unordered_map<T, bool> visited2;
        while(!s.empty()) {
            T node = s.top();
            s.pop();

            if(!visited2[node]) {
                dfs2(node, visited2, adjNew);
                count++;
            }
        }
        return count;
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);
    g.printAdjList();
    int noSCC = g.getStronglyConnectedComponents(8);
    cout<<"Number of Strongly Connected Components: "<<noSCC<<endl;
    return 0;
}