#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
#include<map>
using namespace std;

template <typename T>
class Graph {
public:
    map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int weight, bool direction) {
        if (direction) {
            adjList[u].push_back({v, weight});
        } else {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << " : { ";
            for (auto nbr : i.second) {
                cout << "( Node: " << nbr.first << ", Weight: " << nbr.second << " ) ";
            }
            cout << "}" << endl;
        }
    }

    void floydWarshal(int n) {
        // initial state
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i = 0; i < dist.size(); i++) {
            dist[i][i] = 0;
        }

        // update the dist array according to the already given weights
        for(auto a : adjList) {
            for(auto b : a.second) {
                T u = a.first;
                T v = b.first;
                int weight = b.second;
                dist[u][v] = weight;
            }
        }

        // main logic
        for(int helper = 0; helper < n; helper++) {
            for(int src = 0; src < n; src++) {
                for(int dest = 0; dest < n; dest++) {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }

        // distance vector is ready now
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, 3, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(0, 3, 5, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(2, 1, 1, 1);
    g.addEdge(3, 2, 2, 1);
    g.printAdjList();
    g.floydWarshal(4);

    return 0;
}