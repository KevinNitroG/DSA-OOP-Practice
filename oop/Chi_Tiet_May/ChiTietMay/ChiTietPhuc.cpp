#include "ChiTietPhuc.h"

ChiTietDon* ChiTietPhuc::ChonKieuChiTiet()
{
	int n;
	cout << "Chon kieu chi tiet: ";
	cin >> n;
	switch (n)
	{
		case 1:
			return new ChiTietDon;
		case 2:
			return new ChiTietPhuc;
	}
	return NULL;
}

void ChiTietPhuc::Nhap()
{
	this->ChiTietDon::Nhap();
	cout << "Nhap so luong chi tiet con:";
	cin >> this->soCon;
	this->dsCon.resize(this->soCon);
	for (int i = 0; i < this->soCon; i++)
	{
		cout << "Nhap chi tiet thu " << i + 1 << " cua may:" << endl;
		this->dsCon[i] = ChiTietPhuc::ChonKieuChiTiet();
		this->dsCon[i]->Nhap();
	}
}

void ChiTietPhuc::Xuat() const
{
	ChiTietDon::Xuat();
	for (const auto* chiTiet : this->dsCon)
		chiTiet->Xuat();
}

int ChiTietPhuc::TinhGiaTien() const
{
	int tongTien = this->giaTien;
	for (const auto* chiTiet : this->dsCon)
		tongTien += chiTiet->TinhGiaTien();
	return tongTien;
}
