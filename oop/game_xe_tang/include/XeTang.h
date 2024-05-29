#pragma once

#include "DanDoi.h"
#include "DanDon.h"
#include "SinhMenh.h"
#include <string>

using namespace std;

class XeTang
{
  private:
    string soHieu;
    string ten;
    int sinhMenh = 10;
    VatPham *vatPham;

    static VatPham *getRandomVatPham();

  public:
    bool daChet() const;
    void Nhap();
    void Xuat() const;
    int banThu() const;
    int banHetThu() const;
    int hanhDong();
    void biSatThuong(int);
};