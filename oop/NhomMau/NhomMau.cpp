/*

5
Cha
1
Me
7
Con
2
Ban1
7
Ban2
5
1
2
3
4

*/
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

enum NHOM_MAU
{
    A,
    B,
    AB,
    O
};

const map<pair<NHOM_MAU, NHOM_MAU>, set<NHOM_MAU>> MAU_CON = {
    {{A, A}, {A, O}}, {{A, B}, {A, B, AB, O}}, {{B, A}, {A, B, AB, O}}, {{A, AB}, {A, B, AB}}, {{AB, A}, {A, B, AB}},
    {{A, O}, {A, O}}, {{O, A}, {A, O}},        {{B, B}, {B, O}},        {{B, AB}, {A, B, AB}}, {{AB, B}, {A, B, AB}},
    {{B, O}, {B, O}}, {{O, B}, {B, O}},        {{AB, AB}, {A, B}},      {{O, O}, {O}},
};

enum NHOM_MAU_CHO_NHAN
{
    Om,
    Op,
    Am,
    Ap,
    Bm,
    Bp,
    ABm,
    ABp
};

const set<pair<NHOM_MAU_CHO_NHAN, NHOM_MAU_CHO_NHAN>> CHO_NHAN = {
    {Om, Om},   {Om, Op},  {Op, Op},  {Om, Am},  {Am, Am},  {Om, Ap},  {Op, Ap},  {Am, Ap},   {Ap, Ap},
    {Om, Bm},   {Bm, Bm},  {Om, Bp},  {Op, Bp},  {Bm, Bp},  {Bp, Bp},  {Om, ABm}, {Am, ABm},  {Bm, ABm},
    {ABm, ABm}, {Om, ABp}, {Op, ABp}, {Am, ABp}, {Ap, ABp}, {Bm, ABp}, {Bp, ABp}, {ABm, ABp}, {ABp, ABp},
};

class Nguoi
{
    friend class DanhSach;

  private:
    string ten;
    NHOM_MAU nhomMau;
    NHOM_MAU_CHO_NHAN nhomMauChoNhan;

  public:
    void Nhap();
    void Xuat() const;
};

class DanhSach
{
  private:
    vector<Nguoi> dsNguoi;

  public:
    void Nhap();
    void InDanhSach() const;
    void KiemTraChaMeCon() const;
    void KiemTraTruyenMau() const;
};

int main()
{
    DanhSach ds;
    ds.Nhap();
    ds.KiemTraChaMeCon();
    ds.KiemTraTruyenMau();
    return 0;
}

void Nguoi::Nhap()
{
    int sel;
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, this->ten);
    cout << "[1]: Om" << endl;
    cout << "[2]: Op" << endl;
    cout << "[3]: Am" << endl;
    cout << "[4]: Ap" << endl;
    cout << "[5]: Bm" << endl;
    cout << "[6]: Bp" << endl;
    cout << "[7]: ABm" << endl;
    cout << "[8]: ABp" << endl;
    cout << "Nhap nhom mau: ";
    cin >> sel;
    switch (sel)
    {
    case 1: {
        this->nhomMau = O;
        this->nhomMauChoNhan = Om;
        break;
    }
    case 2: {
        this->nhomMau = O;
        this->nhomMauChoNhan = Op;
        break;
    }
    case 3: {
        this->nhomMau = A;
        this->nhomMauChoNhan = Am;
        break;
    }
    case 4: {
        this->nhomMau = A;
        this->nhomMauChoNhan = Ap;
        break;
    }
    case 5: {
        this->nhomMau = B;
        this->nhomMauChoNhan = Bm;
        break;
    }
    case 6: {
        this->nhomMau = B;
        this->nhomMauChoNhan = Bp;
        break;
    }
    case 7: {
        this->nhomMau = AB;
        this->nhomMauChoNhan = ABm;
        break;
    }
    case 8: {
        this->nhomMau = AB;
        this->nhomMauChoNhan = ABp;
        break;
    }
    default: {
        cout << "Nhap sai!" << endl;
        break;
    }
    }
}

void Nguoi::Xuat() const
{
    cout << "\tTen: " << this->ten << endl;
    cout << "\tNhom mau: " << this->nhomMauChoNhan << endl;
}

void DanhSach::Nhap()
{
    int n;
    cout << "Nhap so nguoi: ";
    cin >> n;
    this->dsNguoi.resize(n);
    for (int i = 0; i < n; i++)
        this->dsNguoi[i].Nhap();
}

void DanhSach::InDanhSach() const
{
    for (int i = 0; i < this->dsNguoi.size(); i++)
    {
        cout << "[" << i + 1 << "]:" << endl;
        this->dsNguoi[i].Xuat();
    }
}

void DanhSach::KiemTraChaMeCon() const
{
    int sel;
    Nguoi cha, me, con;
    this->InDanhSach();
    cout << "Nhap cha: ";
    cin >> sel;
    cha = this->dsNguoi[sel - 1];
    cout << "Nhap me: ";
    cin >> sel;
    me = this->dsNguoi[sel - 1];
    cout << "Nhap con: ";
    cin >> sel;
    con = this->dsNguoi[sel - 1];
    auto res = MAU_CON.find({cha.nhomMau, me.nhomMau});
    if (res != MAU_CON.end())
        if (res->second.find(con.nhomMau) != res->second.end())
        {
            cout << "Cung huyet thong ^^ !" << endl;
            return;
        }
    cout << "Khong cung huyet thong .-. !!!" << endl;
}

void DanhSach::KiemTraTruyenMau() const
{
    int sel;
    Nguoi nguoiNhan;
    this->InDanhSach();
    cout << "Nhap nguoi can truyen mau: ";
    cin >> sel;
    nguoiNhan = this->dsNguoi[sel - 1];
    cout << "Danh sach nguoi cho mau:" << endl;
    for (auto &nguoiCho : this->dsNguoi)
        if (CHO_NHAN.find({nguoiCho.nhomMauChoNhan, nguoiNhan.nhomMauChoNhan}) != CHO_NHAN.end())
            nguoiCho.Xuat();
}
