#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<set>
#include<limits.h>
#include<algorithm>
using namespace std;

template <typename T>
class WGraph {
    public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int weight, bool direction) {
        if(direction) {
            adjList[u].push_back({v, weight});
        } else {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjList() {
        for(auto i : adjList) {
            cout<<i.first<<" : { ";
            for(auto nbr : i.second) {
                cout<<"( "<<nbr.first<<", "<<nbr.second<<" )";
            }
            cout<<" } "<<endl;
        }
    }

    void printPath(vector<T> &parent, T destination) {
        vector<T> path;
        T curr = destination;
        
        while(curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());
        cout<<"Path: ";
        for(auto i : path) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    void dijkstraAlgo(int n, T src, T destination) {
        vector<int> dist(n + 1, INT_MAX);
        vector<T> parent(n + 1, -1);
        set<pair<int, T>> st;

        // maintain initial state    0, src
        st.insert({0, src});
        dist[src] = 0;

        // distance array updation
        while(!st.empty()) {
            auto topElement = st.begin();      // gives reference to top pair
            pair<int, T> topPair = *topElement;     // pointer to reference
            int topDist = topPair.first;
            T topNode = topPair.second;
            st.erase(st.begin());

            for(auto nbr : adjList[topNode]) {
                T nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if(topDist + nbrDist < dist[nbrNode]) {    // main logic
                    // if same node is already present in the set
                    // then update the distance in the set first
                    // delete the previous entry of the node
                    // enter new updated distance entry
                    auto previousEntry = st.find({dist[nbrNode], nbrNode});
                    if(previousEntry != st.end()) {
                        st.erase(previousEntry);
                    }

                    // distance array updation
                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                    parent[nbrNode] = topNode;
                }
            }
        }

        cout<<"Shortest Distance from "<<src<<" to "<<destination<<": "<<dist[destination]<<endl;
        printPath(parent, destination);
    }
};

int main() {
    WGraph<int> g;
    g.addEdge(6, 5, 9, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 1, 14, 0);
    g.addEdge(5, 4, 6, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(3, 2, 10, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 4, 15, 0);

    int src;
    cout<<"Enter the Source Node: ";
    cin>> src;
    int dest;
    cout<<"Enter the Destination Node: ";
    cin>>dest;
    g.dijkstraAlgo(6, src, dest);
    return 0;
}