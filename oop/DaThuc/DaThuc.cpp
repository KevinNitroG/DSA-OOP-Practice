#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class DaThuc
{
  private:
    vector<int> dsHeSo;
    int bac;

  public:
    DaThuc() = default;
    DaThuc(const int &);
    DaThuc(const DaThuc &);
    friend istream &operator>>(istream &, DaThuc &);
    friend ostream &operator<<(ostream &, DaThuc const &);
    DaThuc operator-() const;
    DaThuc operator+(DaThuc const &);
    DaThuc operator-(DaThuc const &);
    int Tinh(const int &) const;
};

int main()
{
    DaThuc a, b;
    cout << "Nhap da thuc a:" << endl;
    cin >> a;
    cout << "Nhap da thuc b:" << endl;
    cin >> b;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "Nhap x: ";
    int x;
    cin >> x;
    cout << "a(" << x << ") = " << a.Tinh(x) << endl;
    cout << "b(" << x << ") = " << b.Tinh(x) << endl;
    return 0;
}

DaThuc::DaThuc(const DaThuc &other)
{
    this->dsHeSo = other.dsHeSo;
    this->bac = other.bac;
}
DaThuc::DaThuc(const int &_bac)
{
    this->dsHeSo = vector<int>(_bac, 0);
    this->bac = _bac;
}

istream &operator>>(istream &is, DaThuc &daThuc)
{
    cout << "Nhap bac: ";
    is >> daThuc.bac;
    daThuc.dsHeSo.resize(daThuc.bac);
    for (int i = daThuc.bac; i >= 0; i--)
    {
        cout << "Nhap he so bac " << i << ": ";
        is >> daThuc.dsHeSo[i];
    }
    return is;
}
ostream &operator<<(ostream &os, DaThuc const &daThuc)
{
    bool heSoDau = true;
    for (int i = daThuc.bac; i >= 0; i--)
    {
        int heSo = daThuc.dsHeSo[i];
        if (heSo == 0)
            continue;
        if (!heSoDau)
            os << " ";
        switch (heSo)
        {
        case 1:
            if (!heSoDau)
                os << "+ ";
            break;
        case -1:
            os << "-";
            break;
        default:
            if (heSo > 1)
                os << "+ " << heSo;
            else
                os << "- " << -heSo;
        }
        switch (i)
        {
        case 0:
            break;
        case 1:
            os << "x";
            break;
        default:
            os << "x^" << i;
        }
        heSoDau = false;
    }
    return os;
}

DaThuc DaThuc::operator-() const
{
    DaThuc res(this->bac);
    for (int i = this->bac; i >= 0; i--)
        res.dsHeSo[i] = -this->dsHeSo[i];
    return res;
}

DaThuc DaThuc::operator+(DaThuc const &other)
{
    DaThuc res = this->bac >= other.bac ? DaThuc(this->bac) : DaThuc(other.bac);
    for (int i = res.bac; i >= 0; i--)
    {
        int soBiTru = i > this->bac ? 0 : this->dsHeSo[i];
        int soTru = i > other.bac ? 0 : other.dsHeSo[i];
        res.dsHeSo[i] = soBiTru - soTru;
    }
    return res;
}

DaThuc DaThuc::operator-(DaThuc const &other)
{
    return *this + (-other);
}
int DaThuc::Tinh(const int &x) const
{
    int res;
    for (int i = this->bac; i >= 0; i--)
        res += this->dsHeSo[i] * pow(x, this->bac);
    return res;
}
