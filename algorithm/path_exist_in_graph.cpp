#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int dinh1, dinh2;
int dinhCheckA = 0, dinhCheckB = 0;
map<int, vector<int>> points;
set<int> visitedPoints;

bool dfs(const int &point, const int &tongMonHoc)
{
    if (point == dinhCheckB)
        return true;
    if (!(visitedPoints.find(point) == visitedPoints.end()))
        return false;
    visitedPoints.insert(point);
    for (auto &relatedPoint : points[point])
        if (dfs(relatedPoint, tongMonHoc))
            return true;
    return false;
}

bool process()
{
    int tongMonHoc = points.size();
    for (auto &point : points[dinhCheckA])
        if (dfs(point, tongMonHoc))
            return true;
    return false;
}

int main()
{
    int m, n;
    cin >> m >> m;
    while (m--)
    {
        cin >> dinh1 >> dinh2;
        points[dinh1].push_back(dinh2);
        points[dinh2].push_back(dinh1);
    }
    cin >> dinhCheckA >> dinhCheckB;
    if (process())
        cout << 1;
    else
        cout << 0;
    return 0;
}
