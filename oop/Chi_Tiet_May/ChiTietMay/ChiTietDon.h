#pragma once
#include <iostream>
#include <string>

using namespace std;

class ChiTietDon {
protected:
  string maSo;
  int giaTien;

public:
  string GetMaSo() const;
  virtual void Nhap();
  virtual void Xuat() const;
  virtual int TinhGiaTien() const;
};
