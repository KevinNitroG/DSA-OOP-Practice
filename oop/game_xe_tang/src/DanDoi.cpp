#include "DanDoi.h"
#include <iostream>

using namespace std;

int DanDoi::Ban()
{
    if (this->soLanBan == 0)
        return 0;
    cout << this->amThanh << endl;
    this->soLanBan--;
    return this->satThuong;
}
