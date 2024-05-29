#include "XeTang.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

VatPham *XeTang::getRandomVatPham()
{
    srand(time(NULL));
    switch (rand() % 3)
    {
    case 0:
        return new SinhMenh();
    case 1:
        return new DanDon();
    case 2:
        return new DanDoi();
    }
    return NULL;
}

bool XeTang::daChet() const
{
    return this->sinhMenh <= 0;
}

void XeTang::Nhap()
{
    cout << "Nhap so hieu xe tang: ";
    cin.ignore();
    getline(cin, this->soHieu);
    cout << "Nhap ten: ";
    getline(cin, this->ten);
    this->vatPham = this->getRandomVatPham();
}

void XeTang::Xuat() const
{
    cout << "So hieu xe tang: " << this->soHieu << endl;
    cout << "Ten xe tang: " << this->ten << endl;
    cout << "Ma vat pham xe tang: " << this->vatPham->getMa() << endl;
}

int XeTang::banThu() const
{
    if (this->vatPham->getMa() == "D")
        // cout << ((Dan *)(this->vatPham))->getSatThuong();
        return ((Dan *)(this->vatPham))->getSatThuong();
    return -1;
}

int XeTang::banHetThu() const
{
    if (this->vatPham->getMa() != "D")
        return -1;
    int tongSatThuong = 0;
    for (int i = 0; i < ((Dan *)(this->vatPham))->getSoLanBan(); i++)
        tongSatThuong += ((Dan *)(this->vatPham))->getSatThuong();
    return tongSatThuong;
}

int XeTang::hanhDong()
{
    if (this->daChet())
        return 0;
    if (this->vatPham->getMa() == "D")
        return ((Dan *)(this->vatPham))->Ban();
    this->sinhMenh += ((SinhMenh *)(this->vatPham))->getSinhLuong();
    return 1;
}

void XeTang::biSatThuong(int satThuong)
{
    if (this->daChet())
        return;
    sinhMenh -= satThuong;
}
