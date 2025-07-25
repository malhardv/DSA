#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

template <typename T>
class UGraph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        if (direction)
        {
            adjList[u] = v;
        }
        else
        {
            adjList[u] = v;
            adjList[v] = u;
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " : { ";
            for (auto nbr : i.second)
            {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    void shortestPathBFS(T src, T destination)
    {
        queue<T> q;
        unordered_map<T, T, > parent;
        unordered_map<T, bool> visited;

        // initialise karde source ko daalke
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        // all the parents have been assigned, jo node closest
        // hogi woh automatically destination ko sabse pehle touch karegi
        while (!q.empty())
        {
            T frontNode = q.top();
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
        }

        vector<T> shortestPath; // storing the path
        while (destination != -1)
        {
            shortestPath.push_back(destination);
            destination = parent[destination];
        }

        reverse(shortestPath.begin(), shortestPath.end());

        cout << "Shortest Path: ";
        for (auto i : shortestPath)
        {
            cout << i << " ";
        }
    }
};

template <typename T>
class WGraph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, bool direction, int weight)
    {
        if (direction)
        {
            adjList[u] = {v, weight};
        }
        else
        {
            adjList[u] = {v, weight};
            adjList[v] = {u, weight};
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " : { ";
            for (auto nbr : i.second)
            {
                cout << "(" << nbr.first << ", " << nbr.second << ")";
            }
            cout << " } " << endl;
        }
    }

    void topoOrderDFS(int src, stack<T> &topOrder, unordered_map<T, bool> &visited)
    {
        visited[src] = true;
        for (auto nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                topoOrder(nbr.first, topOrder, visited);
            }
        }
        topOrder.push(src);
    }

    void shortestPathDFS(stack<T> &topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);

        T src = topoOrder.top();
        topoOrder.pop()
            dist[src] = 0;

        // maintain the distance array for all the neighbours
        for (auto nbr : adjList[src])
        {
            T nbrNode = nbr.first;
            int nbrDist = nbr.second;

            if (nbrDist + dist[src] < dist[nbrNode])
            {
                dist[nbrNode] = nbrDist + dist[src];
            }
        }

        // now do it for all other other remaining nodes
        while (!topoOrder.empty())
        {
            T src = topoOrder.top();
            topoOrder.pop();

            for (auto nbr : adjList[src])
            {
                T nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if (nbrDist + dist[src] < dist[nbrNode])
                {
                    dist[nbrNode] = nbrDist + dist[src];
                }
            }
        }


        // distanc array is ready
        cout<<"Printing Shortest Distance Array: "<<;
        for(auto i : dist) {
            cout<<i<<" ";
        }
    }
};

int main()
{
    // UGraph g;
    // g.addEdge(0, 4, 0);
    // g.addEdge(4, 1, 0);
    // g.addEdge(1, 5, 0);
    // g.addEdge(0, 3, 0);
    // g.addEdge(3, 5, 0);
    // g.addEdge(6, 1, 0);
    // g.addEdge(1, 5, 0);
    // g.printAdjList();
    // g.shortestPathBFS(0, 5);

    WGraph<int> g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);
    int src = 0;
    int n = 5;
    stack<int> topOrder;
    unordered_map<int, bool> visited;
    g.topoOrderDFS(src, topOrder, visited);
    g.shortestPathDFS(topOrder, n);
    return 0;
}