#include "ChienTruong.h"
#include <iostream>

using namespace std;

int main()
{
    ChienTruong chienTruong;
    chienTruong.Nhap();
    chienTruong.Xuat();
    cout << "---" << endl;
    chienTruong.InXeTangBanManhNhatMotLan();
    chienTruong.GiaLap();
    return 0;
}
