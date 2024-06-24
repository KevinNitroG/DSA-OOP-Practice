#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {
        vector<vector<int>> graph(n);
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node == end)
                return true;

            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return false;
    }
};
