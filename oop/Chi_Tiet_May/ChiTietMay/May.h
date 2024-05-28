#pragma once
#include "ChiTietPhuc.h"

class May
{
private:
	vector<ChiTietDon*> dsChiTiet;
	int soChiTiet;

public:
	void Nhap();
	void Xuat() const;
	int TinhTongTien() const;
};
