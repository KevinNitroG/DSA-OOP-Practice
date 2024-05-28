#include "ChiTietDon.h"

string ChiTietDon::GetMaSo() const { return this->maSo; }
void ChiTietDon::Nhap()
{
	cout << "Nhap ma so: ";
	cin.ignore();
	cin >> this->maSo;
	cout << "Nhap gia tien: ";
	cin >> this->giaTien;
}
void ChiTietDon::Xuat() const
{
	cout << "Ma so: " << this->maSo << endl;
	cout << "Gia Tien: " << this->giaTien << endl;
}

int ChiTietDon::TinhGiaTien() const { return this->giaTien; }
