#include "May.h"

using namespace std;

int main()
{
    May may;
    may.Nhap();
    may.Xuat();
    cout << "Tong tien cua may: " << may.TinhTongTien() << endl;

    return 0;
}
