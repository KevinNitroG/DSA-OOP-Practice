#pragma once

#include "Dan.h"
#include <string>

class DanDoi : public Dan
{
  private:
    string amThanh = "BUM BUM";
    int soLanBan = 10;
    int satThuong = 2;

  public:
    int Ban() override;
};