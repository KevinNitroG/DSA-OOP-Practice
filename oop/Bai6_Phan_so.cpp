#include <iostream>
using namespace std;

class PhanSo
{
  private:
    int ts, ms;

  public:
    PhanSo();
    PhanSo(int a);
    PhanSo operator+(const PhanSo &);
    bool operator==(PhanSo &);
    friend istream &operator>>(istream &is, PhanSo &x);
    friend ostream &operator<<(ostream &os, const PhanSo &x);
};
PhanSo::PhanSo()
{
    ts = 0;
    ms = 1;
}
PhanSo::PhanSo(int a)
{
    ts = a;
    ms = 1;
}
PhanSo PhanSo::operator+(const PhanSo &y)
{
    PhanSo temp;
    temp.ts = this->ts * y.ms + y.ts * this->ms;
    temp.ms = this->ms * y.ms;
    return temp;
}
bool PhanSo::operator==(PhanSo &y)
{
    float s1 = this->ts / this->ms;
    float s2 = y.ts / y.ms;
    if (s1 == s2)
        return true;
    return false;
}
istream &operator>>(istream &is, PhanSo &x)
{
    cout << "Nhap tu so: ";
    is >> x.ts;
    cout << "Nhap mau so: ";
    is >> x.ms;
    return is;
}
ostream &operator<<(ostream &os, const PhanSo &x)
{
    os << "Tu so: ";
    os << x.ts;
    os << "Mau so: ";
    os << x.ms;
    return os;
}
