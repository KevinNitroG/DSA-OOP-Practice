// Not done :)) tired
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> merge(vector<queue<int>> list, const int &list_size)
{
    queue<int> res;
    while (true)
    {
        bool cont = false;
        for (auto q : list)
        {
            if (!q.empty())
            {
                cont = true;
                break;
            }
        }
        if (!cont)
            return res;
        int max_i = 0;
        for (int i = 1; i < list_size; i++)
            if (list[max_i].empty() || (list[i].front() < list[max_i].front()))
                max_i = i;
        res.push(list[max_i].front());
        list[max_i].pop();
    }
    return res;
}
int main()
{
    int m, n, input;
    vector<queue<int>> l;
    cin >> m >> n;
    l.resize(m);
    for (int i = 0; i < m; i++)
        for (int _ = 0; _ < n; _++)
        {
            cin >> input;
            l[i].push(input);
        }
    queue<int> res = merge(l, m);
    cout << "RES:" << endl;
    while (res.front())
    {
        cout << res.front() << " ";
        res.pop();
    }
    return 0;
}
