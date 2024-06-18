#include <iostream>

using namespace std;

class CDate
{

  private:
    int day;
    int month;
    int year;

  public:
    static int monthsOfLeap[13];
    static int monthsOfNoLeap[13];
    // CDate(CDate &);
    void Input();
    void Output() const;
    bool isLeap() const;
    CDate &operator++();
    CDate operator++(int);
    CDate &operator--();
    CDate operator--(int);
    CDate operator+(const int &) const;
    CDate operator-(const int &) const;
};

int main()
{
    CDate cDate;
    cDate.Input();
    cDate.Output();

    (cDate++).Output();
    (++cDate).Output();
    (cDate--).Output();
    (--cDate).Output();

    int n;
    cin >> n;

    (cDate + n).Output();
    (cDate - n).Output();

    return 0;
}

int CDate::monthsOfLeap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int CDate::monthsOfNoLeap[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// CDate::CDate(CDate &rhs)
// {
//     this->day = rhs.day;
//     this->month = rhs.month;
//     this->year = rhs.year;
// }

void CDate::Input()
{
    cout << "Nhap ngay: ";
    cin >> this->day;
    cout << "Nhap thang: ";
    cin >> this->month;
    cout << "Nhap nam: ";
    cin >> this->year;
}

void CDate::Output() const
{
    cout << "Ngay: " << this->day << "/" << this->month << "/" << this->year << endl;
}

bool CDate::isLeap() const
{
    return !(this->year % 4) && (!(this->year % 100) || !this->year % 400);
}

CDate &CDate::operator++()
{
    *this = *this + 1;
    return *this;
}

CDate CDate::operator++(int)
{
    CDate temp = *this;
    ++*this;
    return temp;
}

CDate &CDate::operator--()
{
    *this = *this - 1;
    return *this;
}

CDate CDate::operator--(int)
{
    CDate temp = *this;
    --*this;
    return temp;
}

CDate CDate::operator+(const int &n) const
{
    CDate res = *this;
    res.day += n;
    while (res.day > (res.isLeap() ? monthsOfLeap[res.month] : monthsOfNoLeap[res.month]))
    {
        res.day -= res.isLeap() ? monthsOfLeap[res.month] : monthsOfNoLeap[res.month];
        if (++res.month == 13)
        {
            res.month = 1;
            ++res.year;
        }
    }
    return res;
}

CDate CDate::operator-(const int &n) const
{
    CDate res = *this;
    res.day -= n;
    while (res.day <= 0)
    {
        if (--res.month == 0)
        {
            res.month = 12;
            --res.year;
        }
        res.day += res.isLeap() ? monthsOfLeap[res.month] : monthsOfNoLeap[res.month];
    }
    return res;
}
