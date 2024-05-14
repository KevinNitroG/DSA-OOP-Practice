#include <iostream>
#include <string>
using namespace std;

class NguoiSoHuu
{
  private:
    string tenNguoi;
    int namSinh;
    string cmnd;
    string diaChi;

  public:
    void Nhap()
    {
        cout << "Nhap ten nguoi so huu: ";
        cin >> tenNguoi;
        cin.ignore();
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap cmnd: ";
        cin >> cmnd;
        cin.ignore();
        cout << "Nhap dia chi nguoi so huu: ";
        cin >> diaChi;
        cin.ignore();
    }
    void Xuat()
    {
        cout << tenNguoi << endl << namSinh << endl << cmnd << endl << diaChi << endl;
    }
};

class Ngay
{
  private:
    int ngay;
    int thang;
    int nam;

  public:
    void Nhap()
    {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }
    void Xuat()
    {
        cout << ngay << "/" << thang << "/" << nam << endl;
    }
    int getNam()
    {
        return nam;
    }
};

class DatDai
{
  protected:
    string soGiay;
    NguoiSoHuu nguoi;
    int soThua;
    int dienTich;
    Ngay ngayCap;
    string diaChiDat;
    int soTo;
    int giaThue;

  public:
    virtual void Nhap()
    {
        cout << "Nhap so giay: ";
        cin >> soGiay;
        cin.ignore();
        cout << "Nhap nguoi so huu:\n";
        nguoi.Nhap();
        cout << "Nhap so thua dat: ";
        cin >> soThua;
        cout << "Nhap dien tich dat: ";
        cin >> dienTich;
        cout << "Nhap ngay cap: ";
        ngayCap.Nhap();
        cout << "Nhap dia chi dat: ";
        cin >> diaChiDat;
        cin.ignore();
        cout << "Nhap so to ban do: ";
        cin >> soTo;
        cout << "Nhap don gia thue: ";
        cin >> giaThue;
    }
    virtual void Xuat()
    {
        cout << soGiay << endl;
        nguoi.Xuat();
        cout << soThua << endl << dienTich << endl;
        ngayCap.Xuat();
        cout << diaChiDat << endl << soTo << endl << giaThue << endl;
    }
    virtual bool KiemTraNongNghiep()
    {
        return false;
    }
    int TinhThue()
    {
        return dienTich * giaThue;
    }
};

class DatNongNghiep : public DatDai
{
  protected:
    Ngay thoiHan;

  public:
    void Nhap()
    {
        DatDai::Nhap();
        cout << "Nhap thoi han su dung: ";
        thoiHan.Nhap();
    }
    void Xuat()
    {
        DatDai::Xuat();
        thoiHan.Xuat();
    }
    bool KiemTraThoiHan()
    {
        if (thoiHan.getNam() < 2023)
            return true;
        return false;
    }
    bool KiemTraNongNghiep()
    {
        return true;
    }
};

class DatO : public DatDai
{
};

class DanhSachDat
{
  protected:
    DatDai *arr[50];
    int size;

  public:
    void Nhap()
    {
        cout << "Nhap so luong dat: ";
        cin >> size;
        for (int i = 0; i < size; ++i)
        {
            cout << "Nhap kieu dat: 1 = Nong nghiep, 2 = Dat o: ";
            int type;
            cin >> type;
            if (type == 1)
            {
                arr[i] = new DatNongNghiep();
            }
            if (type == 2)
            {
                arr[i] = new DatO();
            }
            arr[i]->Nhap();
        }
    }
    DatDai *TimThueNhieuNhat()
    {
        int maxIndex = 0;
        for (int i = 1; i < size; ++i)
        {
            if (arr[i]->TinhThue() > arr[maxIndex]->TinhThue())
            {
                maxIndex = i;
            }
        }
        return arr[maxIndex];
    }
    void XuatDatNongNghiepHetHan()
    {
        for (int i = 0; i < size; ++i)
        {
            if (arr[i]->KiemTraNongNghiep())
            {
                if (((DatNongNghiep *)arr[i])->KiemTraThoiHan())
                {
                    arr[i]->Xuat();
                }
            }
        }
    }
};

int main()
{
    DanhSachDat item;
    item.Nhap();
    DatDai *kq = item.TimThueNhieuNhat();
    kq->Xuat();
    item.XuatDatNongNghiepHetHan();
    return 0;
}
