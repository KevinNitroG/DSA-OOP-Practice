#include "ChienTruong.h"
#include <iostream>
using namespace std;

void ChienTruong::Nhap()
{
    int n;
    cout << "Nhap so xe tang: ";
    cin >> n;
    while (n--)
    {
        XeTang xeTang;
        xeTang.Nhap();
        this->dsXeTang.push_back(xeTang);
    }
}

void ChienTruong::Xuat() const
{
    for (auto xeTang : this->dsXeTang)
        xeTang.Xuat();
}

void ChienTruong::InXeTangBanManhNhatMotLan() const
{
    XeTang xeTangMax = this->dsXeTang[0];
    for (auto xeTang : this->dsXeTang)
        if (xeTang.banThu() > xeTangMax.banThu())
            xeTangMax = xeTang;
    if (xeTangMax.banThu() == -1)
        cout << "Khong co xe tang nao co the ban!!!" << endl;
    else
        xeTangMax.Xuat();
}

XeTang *ChienTruong::GetXeTangBanManhNhatHetDan()
{
    XeTang &xeTangMax = this->dsXeTang[0];
    for (auto xeTang : this->dsXeTang)
        if (xeTang.banHetThu() > xeTangMax.banHetThu())
            xeTangMax = xeTang;
    if (xeTangMax.banHetThu() == -1)
        return NULL;
    else
        return &(xeTangMax);
}

void ChienTruong::GiaLap()
{
    XeTang *xeTang = this->GetXeTangBanManhNhatHetDan();
    if (xeTang == NULL)
    {
        cout << "Khong co xe tang nao co dan!!!" << endl;
        return;
    }
    while (!xeTang->daChet() || !this->boss.daChet())
    {
        this->boss.biSatThuong(xeTang->hanhDong());
        xeTang->biSatThuong(this->boss.hanhDong());
    }
    if (!xeTang->daChet())
        cout << "Xe tang win" << endl;
    else
        cout << "Boss win" << endl;
}
