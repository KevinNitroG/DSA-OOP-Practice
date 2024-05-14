#include <iostream>
#include <string>

using namespace std;
class Date {
	friend istream& operator>> (istream& is, Date& rhs);
	friend ostream& operator<< (ostream& os, const Date& rhs);
private:
	int ngay;
	int thang;
	int nam;
public:
	Date();
	Date(int nam, int thang);
	Date(int nam, int thang, int ngay);
	int IsNhuan();
	bool operator< (const Date& rhs);
	Date operator++(int);
};

Date::Date() {
	nam = 1;
	thang = 1;
	ngay = 1;
}
Date::Date(int nam, int thang) {
	this->nam = nam;
	this->thang = thang;
	ngay = 1;
}
Date::Date(int nam, int thang, int ngay) {
	this->nam = nam;
	this->thang = thang;
	this->ngay = ngay;
}
int Date::IsNhuan() {
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		return 1;
	return 0;
}
istream& operator>> (istream& is, Date& rhs) {
	cout << "Nhap ngay: ";
	is >> rhs.ngay;
	cout << "Nhap thang: ";
	is >> rhs.thang;
	cout << "Nhap nam: ";
	is >> rhs.nam;
	return is;
}
ostream& operator<< (ostream& os, const Date& rhs) {
	os << rhs.ngay << "/";
	os << rhs.thang << "/";
	os << rhs.nam;
	return os;
}
bool Date::operator< (const Date& rhs) {
	if (nam < rhs.nam)
		return true;
	if (thang < rhs.thang)
		return true;
	if (ngay < rhs.ngay)
		return true;
	return false;
}
Date Date::operator++(int) {
	Date ret = *this;
	int ngayTrongThang[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsNhuan()) {
		ngayTrongThang[2] = 29;
	}
	++ngay;
	if (ngay > ngayTrongThang[thang]) {
		++thang;
		if (thang > 12) {
			++nam;
			thang = 1;
		}
		ngay = 1;
	}
	return ret;
}
