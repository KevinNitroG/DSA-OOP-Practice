#include <iostream>
using namespace std;

class Time {
private:
	long seconds = 0;
public:
	friend istream& operator>> (istream& is, Time& rhs);
	friend ostream& operator<< (ostream& os, const Time& rhs);
	Time& operator++();
	Time operator++(int);
	Time operator+ (const Time& rhs);
};
istream& operator>> (istream& is, Time& rhs) {
	long gio = 0, phut = 0, giay = 0;
	cout << "Nhap gio: ";
	is >> gio;
	cout << "Nhap phut: ";
	is >> phut;
	cout << "Nhap giay: ";
	is >> giay;
	rhs.seconds = gio * 3600 + phut * 60 + giay;
	return is;
}
ostream& operator<< (ostream& os, const Time& rhs) {
	os << rhs.seconds / 3600 << ":";
	os << (rhs.seconds % 3600) / 60 << ":";
	os << rhs.seconds % 60;
	return os;
}
Time& Time::operator++() {
	++seconds;
	return *this;
}
Time Time::operator++(int) {
	Time ret = *this;
	++seconds;
	return ret;
}
Time Time::operator+ (const Time& rhs) {
	Time ret;
	ret.seconds = (this->seconds + rhs.seconds) % (3600 * 24);
	return ret;
}
