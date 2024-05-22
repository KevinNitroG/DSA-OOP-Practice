#include <iostream>
#include <map>
#include <string>
using namespace std;

class Nguoi
{
  private:
    int maKhach;
    string ten;
    string SDT;

  public:
    void Nhap();
    void Xuat();
    int getMaKhach();
};

class Ngay
{
  private:
    int ngay;
    int thang;
    int nam;

  public:
    void Nhap();
    void Xuat();
};

class SanPham
{
  protected:
    string maSo;
    string tieuDe;
    long gia;

  public:
    virtual void Nhap();
    virtual void Xuat();
    long getGia();
};

class Tranh : public SanPham
{
  protected:
    int rong;
    int cao;
    string hoaSi;

  public:
    void Nhap();
    void Xuat();
};

class CD : public SanPham
{
  protected:
    string caSi;
    string donVi;

  public:
    void Nhap();
    void Xuat();
};

class HoaDon
{
  protected:
    string maDon;
    Nguoi khach;
    Ngay ngayCap;
    int n;
    SanPham *hd[100];
    long tongGia;

  public:
    void Nhap();
    void Xuat();
    long getTongGia();
    Nguoi getKhach();
};

class DanhSach
{
  protected:
    int size;
    HoaDon ds[100];

  public:
    void Nhap();
    void Xuat();
    long ThuNhap();
    void TimKiemMax();
};

void Ngay::Nhap()
{
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
}
void Ngay::Xuat()
{
    cout << ngay << "/" << thang << "/" << nam << endl;
}

void Nguoi::Nhap()
{
    cout << "Nhap ma khach hang: ";
    cin >> maKhach;
    cout << "Nhap ho ten: ";
    cin >> ten;
    cout << "Nhap so dien thoai: ";
    cin >> SDT;
}
void Nguoi::Xuat()
{
    cout << "Ma khach hang: " << maKhach << endl;
    cout << "Ho ten: " << ten << endl;
    cout << "So dien thoai: " << SDT << endl;
}
int Nguoi::getMaKhach()
{
    return maKhach;
}

void SanPham::Nhap()
{
    cout << "Nhap ma so: ";
    cin >> maSo;
    cout << "Nhap tieu de: ";
    cin >> tieuDe;
    cout << "Nhap gia ban: ";
    cin >> gia;
}
void SanPham::Xuat()
{
    cout << "Ma so: " << maSo << endl;
    cout << "Tieu de: " << tieuDe << endl;
    cout << "Gia ban: " << gia << endl;
}
long SanPham::getGia()
{
    return gia;
}

void Tranh::Nhap()
{
    SanPham::Nhap();
    cout << "Nhap kich thuoc: " << endl;
    cout << "Nhap chieu rong: ";
    cin >> rong;
    cout << "Nhap chieu cao: ";
    cin >> cao;
    cout << "Nhap ten hoa si: ";
    cin >> hoaSi;
}
void Tranh::Xuat()
{
    SanPham::Xuat();
    cout << "Chieu rong: " << rong << endl;
    cout << "Chieu cao: " << cao << endl;
    cout << "Ten hoa si: " << hoaSi << endl;
}

void CD::Nhap()
{
    SanPham::Nhap();
    cout << "Nhap ten ca si: ";
    cin >> caSi;
    cout << "Nhap don vi san xuat: ";
    cin >> donVi;
}
void CD::Xuat()
{
    SanPham::Xuat();
    cout << "Ten ca si: " << caSi << endl;
    cout << "Don vi san xuat: " << donVi << endl;
}

void HoaDon::Nhap()
{
    cout << "Nhap ma hoa don: ";
    cin >> maDon;
    cout << "Nhap thong tin khach hang: " << endl;
    khach.Nhap();
    cout << "Nhap ngay cap: " << endl;
    ngayCap.Nhap();
    cout << "Nhap so luong san pham: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap san pham thu " << i + 1 << endl;
        int loai;
        cout << "Nhap loai (0. Tranh anh, 1. CD): ";
        cin >> loai;
        if (loai == 0)
        {
            hd[i] = new Tranh();
        }
        else
        {
            hd[i] = new CD();
        }
        hd[i]->Nhap();
    }
}
void HoaDon::Xuat()
{
    cout << "Ma hoa don: " << maDon << endl;
    cout << "Ngay cap: ";
    ngayCap.Xuat();
    cout << "Thong tin khach hang: " << endl;
    cout << "Tong gia tien: " << getTongGia() << endl;
    khach.Xuat();
    for (int i = 0; i < n; i++)
    {
        cout << "San pham thu " << i + 1 << endl;
        hd[i]->Xuat();
    }
}
long HoaDon::getTongGia()
{
    tongGia = 0;
    for (int i = 0; i < n; i++)
    {
        tongGia += hd[i]->getGia();
    }
    return tongGia;
}
Nguoi HoaDon::getKhach()
{
    return khach;
}

void DanhSach::Nhap()
{
    cout << "Nhap so luong hoa don: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Nhap hoa don thu " << i + 1 << endl;
        ds[i].Nhap();
    }
}
void DanhSach::Xuat()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Hoa don thu " << i + 1 << endl;
        ds[i].Xuat();
    }
}
long DanhSach::ThuNhap()
{
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += ds[i].getTongGia();
    }
    return s;
}
void DanhSach::TimKiemMax()
{
    map<int, long> mp;
    for (int i = 0; i < size; ++i)
    {
        int id = ds[i].getKhach().getMaKhach();
        mp[id] += ds[i].getTongGia();
    }
    long max = 0;
    for (const auto &pair : mp)
    {
        if (pair.second > max)
        {
            max = pair.second;
        }
    }
    cout << "ID cac khach mua nhieu nhat: \n";
    for (const auto &pair : mp)
    {
        if (pair.second == max)
        {
            cout << pair.first << endl;
        }
    }
}

int main()
{
    DanhSach l;
    l.Nhap();
    l.Xuat();
    cout << "Tong thu nhap: " << l.ThuNhap() << endl;
    l.TimKiemMax();
}
