#pragma once
#include "ChiTietDon.h"
#include <vector>

class ChiTietPhuc : public ChiTietDon
{
private:
	int soCon;
	vector<ChiTietDon*> dsCon;

public:
	static ChiTietDon* ChonKieuChiTiet();
	void Nhap() override;
	void Xuat() const override;
	int TinhGiaTien() const override;
};
