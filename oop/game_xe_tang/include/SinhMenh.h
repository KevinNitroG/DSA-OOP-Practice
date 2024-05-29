#pragma once
#include "VatPham.h"
#include <string>

using namespace std;
class SinhMenh : public VatPham
{
  private:
    int sinhLuong = 2;
    string ma = "SL";
    string ten = "Sinh Luong";

  public:
    int getSinhLuong();
};