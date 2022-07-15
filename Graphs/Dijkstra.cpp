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

    void dijkstra(T src)
    {
        map<T, int> dist;
        for (auto i : adjList)
        {
            dist[i.first] = INT_MAX;
        }
        set<pair<int, T>> s;
        s.insert(make_pair(0, src));
        dist[src] = 0;
        while (!s.empty())
        {
            auto p = *(s.begin());
            int nodeDist = p.first;
            T temp = p.second;
            s.erase(s.begin());

            for (auto neigh : adjList[temp])
            {
                if (nodeDist + neigh.second < dist[neigh.first])
                {

                    auto f = s.find(make_pair(dist[neigh.first], neigh.first));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }

                    dist[neigh.first] = nodeDist + neigh.second;
                    s.insert(make_pair(dist[neigh.first], neigh.first));
                }
            }
        }
        for (auto d : dist)
            cout << d.first << " and " << d.second << endl;
    }
};

int main()
{
    graph<char> g;
    // g.addEdge('0', '1', 4, 0);
    // g.addEdge('0', '7', 8, 0);
    // g.addEdge('1', '7', 11, 0);
    // g.addEdge('1', '2', 8, 0);
    // g.addEdge('7', '8', 7, 0);
    // g.addEdge('2', '8', 2, 0);
    // g.addEdge('8', '6', 6, 0);
    // g.addEdge('2', '5', 4, 0);
    // g.addEdge('6', '5', 2, 0);
    // g.addEdge('2', '3', 7, 0);
    // g.addEdge('3', '3', 14, 0);
    // g.addEdge('3', '4', 9, 0);
    // g.addEdge('5', '4', 10, 0);
    // g.addEdge('7', '6', 1, 0);
    g.addEdge('0', '1', 1, 1);
    g.addEdge('0', '2', 5, 1);
    g.addEdge('0', '3', 20, 1);
    g.addEdge('1', '3', 15, 1);
    g.addEdge('2', '3', 10, 1);

    g.dijkstra('0');
    return 0;
}