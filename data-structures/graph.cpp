/*

4 5
2 1
1 2
3 2
4 3
4 2

*/
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<bool> VISITED_DFS(100, false);
vector<bool> VISITED_BFS(100, false);

class Graph
{
  public:
    int m; // Vertexes, also max value of vertex is m
    int n; // Edges
    vector<vector<int>> graph;
    void Input();
    void PrintDFS(const int &) const;
    void PrintBFS(const int &) const;
    bool PathExist(const int &, const int &) const;
};

int main()
{
    Graph graph;
    graph.Input();

    graph.PrintBFS(0);
    graph.PrintDFS(0);

    return 0;
}

void Graph::Input()
{
    cin >> this->m >> this->n;
    int x, y;
    this->graph.resize(this->n);
    for (int i = 0; i < this->n; i++)
    {
        cin >> x >> y;
        this->graph[x].push_back(y);
    }
    for (auto &edgeList : this->graph)
        edgeList.shrink_to_fit();
}

void Graph::PrintDFS(const int &v) const
{
    cout << v << " ";
    VISITED_DFS[v] = true;
    for (auto &subV : this->graph[v])
        if (!VISITED_DFS[v])
            PrintDFS(subV);
}

void Graph::PrintBFS(const int &v) const
{
    queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        int currentV = q.front();
        cout << currentV << " ";
        q.pop();

        for (auto &subV : this->graph[currentV])
            if (!VISITED_BFS[v])
            {
                q.push(subV);
                VISITED_BFS[currentV] = true;
            }
    }
}

bool Graph::PathExist(const int &a, const int &b) const
{
    return true;
}
