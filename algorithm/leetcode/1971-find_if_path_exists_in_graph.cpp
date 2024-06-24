// https://leetcode.com/problems/find-if-path-exists-in-graph/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if (edges.size() == 0 || edges.size() == 1)
            return true;
        vector<bool> visited(n, false);
        visited[source] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (auto const &pair : edges)
            {
                if (visited[pair[0]] != visited[pair[1]])
                    flag = visited[pair[0]] = visited[pair[1]] = true;
                if (visited[destination])
                    return true;
            }
        }
        return false;
    }
};
