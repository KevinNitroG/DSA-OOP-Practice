#include "May.h"

void May::Nhap()
{
	cout << "Nhap so luong chi tiet cua may: ";
	cin >> this->soChiTiet;
	this->dsChiTiet.resize(this->soChiTiet);
	for (int i = 0; i < this->soChiTiet; i++)
	{
		cout << "Nhap chi tiet thu " << i + 1 << " cua may:" << endl;
		this->dsChiTiet[i] = ChiTietPhuc::ChonKieuChiTiet();
		this->dsChiTiet[i]->Nhap();
	}
}

void May::Xuat() const
{
	cout << "---" << endl;
	for (const auto& chiTiet : this->dsChiTiet)
		chiTiet->Xuat();
}

int May::TinhTongTien() const
{
	int tongTien = 0;
	for (const auto& chiTiet : this->dsChiTiet)
		tongTien += chiTiet->TinhGiaTien();
	return tongTien;
}
