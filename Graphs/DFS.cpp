#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int dist, bool biDir = 1)
    {
        adjList[u].push_back(make_pair(v, dist));

        if (biDir)
            adjList[v].push_back(make_pair(u, dist));
    }

    void printAdj()
    {
        for (auto n : adjList)
        {
            cout << n.first << " ";
            for (auto a : n.second)
            {
                cout << "->"
                     << " (" << a.first << ", " << a.second << ") ";
            }
            cout << endl;
        }
    }

    // DFS algorithm

    void dfs_helper(T src, map<T, bool> &visited)
    {
        visited[src] = true;
        cout << src << " -> ";
        for (auto a : adjList[src])
        {
            if (!visited[a.first])
            {
                dfs_helper(a.first, visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T, bool> visited;
        dfs_helper(src, visited);
    }

    void dfs_iter(T src)
    {
        map<T, bool> visited;
        stack<T> s;
        s.push(src);
        while (!s.empty())
        {
            T vertex = s.top();
            s.pop();

            cout << vertex << "->";
            for (auto a : adjList[vertex])
            {
                if (!visited[vertex])
                {
                    s.push(a.first);
                    visited[vertex] = true;
                }
            }
        }
    }
};

int main()
{
    graph<char> g;
    g.addEdge('0', '1', 4, 0);
    g.addEdge('0', '7', 8, 0);
    g.addEdge('1', '7', 11, 0);
    g.addEdge('1', '2', 8, 0);
    g.addEdge('7', '8', 7, 0);
    g.addEdge('2', '8', 2, 0);
    g.addEdge('8', '6', 6, 0);
    g.addEdge('2', '5', 4, 0);
    g.addEdge('6', '5', 2, 0);
    g.addEdge('2', '3', 7, 0);
    g.addEdge('3', '3', 14, 0);
    g.addEdge('3', '4', 9, 0);
    g.addEdge('5', '4', 10, 0);
    g.addEdge('7', '6', 1, 0);
    cout << "Depth First Search Traversal: " << endl;
    g.dfs_iter('0');
    return 0;
}