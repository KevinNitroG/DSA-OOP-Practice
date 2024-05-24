#include <iostream>
#include <string>
#define Nu 0
#define Nam 1

using namespace std;

class cHonNhan
{
  private:
    string ten;
    int namSinh;
    bool gioiTinh;

  public:
    cHonNhan(const string &_ten = "", const int &_tuoi = 0, const bool &_gioiTinh = 0)
        : ten(_ten), namSinh(_tuoi), gioiTinh(_gioiTinh)
    {
    }
    friend istream &operator>>(istream &is, cHonNhan &rhs)
    {
        is.ignore();
        getline(is, rhs.ten);
        is >> rhs.namSinh;
        is >> rhs.gioiTinh;
        return is;
    }
    friend ostream &operator<<(ostream &os, const cHonNhan &rhs)
    {
        os << rhs.ten << endl;
        os << rhs.namSinh << endl;
        os << rhs.gioiTinh << endl;
        return os;
    }
    int GetNamSinh() const
    {
        return this->namSinh;
    }
};

int main()
{
    cHonNhan A;
    cHonNhan B("Nguyen A", 2000);
    cHonNhan C("Tran B", 2000, Nu);
    cin >> A;
    cout << A;
    int NamHienTai;
    cout << "Nhap nam hien tai: ";
    cin >> NamHienTai;
    if (NamHienTai - B.GetNamSinh() >= 18)
        cout << "Du dieu kien ket hon";
    else
        cout << "Khong du dieu kien ket hon";
    return 0;
}
