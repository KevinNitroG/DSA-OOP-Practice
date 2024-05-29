#pragma once
#include <string>

using namespace std;

class VatPham
{
  protected:
    string ma;
    string ten;

  public:
    VatPham();
    string getMa() const;
};