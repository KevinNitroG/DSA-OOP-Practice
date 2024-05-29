#pragma once
#include "VatPham.h"
#include <string>

using namespace std;

class Dan : public VatPham
{
  protected:
    string ma = "D";
    int soLanBan;
    int satThuong;

  public:
    int getSoLanBan() const;
    int getSatThuong() const;
    virtual int Ban() = 0;
};
