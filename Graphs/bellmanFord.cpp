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

    void bellmanFord(int n, T src) {
        // Distance map instead of vector<T>
        unordered_map<T, int> dist;
        for(auto const& pair: adjList) {
            dist[pair.first] = INT_MAX;
            for(auto const& nbr : pair.second) {
                dist[nbr.first] = INT_MAX;
            }
        }
        dist[src] = 0;

        // N - 1 TIMES RELXATION STEP
        for(int i = 1; i < n; i++) {
            for(auto a : adjList) {
                for(auto b : a.second) {
                    T u = a.first;
                    T v = b.first;
                    int weight = b.second;

                    if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // minimum distance map will be ready here
        // now we check for negative cycles
        bool isPresent = false;
        for(auto a : adjList) {
            for(auto b : a.second) {
                T u = a.first;
                T v = b.first;
                int weight = b.second;

                if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    isPresent = true;
                    break;
                }
            }
        }

        if(isPresent) {
            cout<<"Negative Cycle is Present."<<endl;
        } else {
            cout<<"Printing Distance Map: "<<endl;
            for(auto i : dist) {
                cout<<"{ "<<i.first<< "  : "<<i.second<<" }"<<endl;
            }
        }

    }
};

int main() {
    Graph<char> g;
    g.addEdge('A', 'B', -1, 1);
    g.addEdge('B', 'C', 2, 1);
    g.addEdge('C', 'D', -3, 1);
    g.addEdge('D', 'E', 5, 1);
    g.addEdge('A', 'E', 4, 1);
    g.addEdge('B', 'E', 3, 1);
    g.addEdge('B', 'D', 2, 1);
    g.addEdge('D', 'B', 1, 1);
    g.printAdjList();
    g.bellmanFord(5, 'A');

    return 0;
}
