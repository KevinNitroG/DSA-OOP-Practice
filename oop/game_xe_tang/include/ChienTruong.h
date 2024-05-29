#pragma once

#include "Boss.h"
#include "XeTang.h"
#include <vector>

class ChienTruong
{
  private:
    Boss boss;
    vector<XeTang> dsXeTang;

    XeTang *GetXeTangBanManhNhatHetDan();

  public:
    void Nhap();
    void Xuat() const;
    void InXeTangBanManhNhatMotLan() const;
    void GiaLap();
};