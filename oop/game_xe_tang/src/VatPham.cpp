#include "VatPham.h"
#include <iostream>

using namespace std;

VatPham::VatPham()
{
    // cout << "Nhap ma vat pham: ";
    // cin.ignore();
    // getline(cin, this->ma);
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, this->ten);
}

string VatPham::getMa() const
{
    return this->ma;
}
