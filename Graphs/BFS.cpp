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

    void BFS(T src)
    {
        map<T, bool> visited;
        queue<T> q;
        q.push(src);
        while (!q.empty())
        {
            T vertex = q.front();
            q.pop();

            cout << vertex << "->";
            for (auto a : adjList[vertex])
            {
                // Here pointer 'a' refers to a list
                // adjList stands for adjacent List representation of the graph
                if (!visited[a.first])
                {
                    q.push(a.first);
                    visited[a.first] = true;
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

    g.BFS('0');
    return 0;
}