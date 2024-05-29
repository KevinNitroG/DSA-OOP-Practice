#pragma once

#include "Dan.h"
#include <string>

class DanDon : public Dan
{
  private:
    string amThanh = "BUM";
    int soLanBan = 20;
    int satThuong = 1;

  public:
    int Ban() override;
};