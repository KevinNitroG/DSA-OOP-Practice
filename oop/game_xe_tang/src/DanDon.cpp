#include "DanDon.h"
#include <iostream>

using namespace std;

int DanDon::Ban()
{
    if (this->soLanBan == 0)
        return 0;
    cout << this->amThanh << endl;
    this->soLanBan--;
    return this->satThuong;
}
