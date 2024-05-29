#include "Boss.h"

bool Boss::daChet() const
{
    return this->sinhMenh <= 0;
}

int Boss::hanhDong() const
{
    if (this->daChet())
        return 0;
    return this->satThuong;
}

void Boss::biSatThuong(int satThuong)
{
    if (this->daChet())
        return;
    sinhMenh -= satThuong;
}
