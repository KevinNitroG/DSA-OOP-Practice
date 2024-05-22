#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

string monHoc, monHocTienQuyet;
string monHocToCheck, monHocTienQuyetToCheck;
map<string, vector<string>> points;
set<string> visitedPoints;

bool dfs(const string &point, const int &tongMonHoc)
{
    if (point == monHocTienQuyetToCheck)
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
    for (auto &point : points[monHocToCheck])
        if (dfs(point, tongMonHoc))
            return true;
    return false;
}

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        cin >> monHoc >> monHocTienQuyet;
        points[monHoc].push_back(monHocTienQuyet);
    }
    cin >> monHocToCheck >> monHocTienQuyetToCheck;
    if (process())
        cout << "yeee";
    else
        cout << "NOOOO";
    return 0;
}
