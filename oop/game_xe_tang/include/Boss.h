#pragma once
#include <string>

using namespace std;

class Boss
{
  private:
    string ten = "BOSS";
    int sinhMenh = 20;
    int satThuong = 5;

  public:
    bool daChet() const;
    int hanhDong() const;
    void biSatThuong(int);
};