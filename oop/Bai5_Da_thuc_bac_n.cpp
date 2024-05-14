#include <iostream>
using namespace std;

class CDaThuc {
private:
	int n;
	float a[100];
public:
	CDaThuc operator+(const CDaThuc&);
	friend istream& operator>> (istream& is, CDaThuc& rhs);
	friend ostream& operator<< (ostream& os, const CDaThuc& rhs);
};

istream& operator>> (istream& is, CDaThuc& rhs) {
	cout << "Nhap bac cua da thuc: ";
	is >> rhs.n;
	for (int i = rhs.n; i >= 0; i--) {
		cout << "Nhap he so cua don thuc bac " << i << ": ";
		is >> rhs.a[i];
	}
	return is;
}
ostream& operator<< (ostream& os, const CDaThuc& rhs) {
	cout << "Da thuc: " << endl;
	for (int i = rhs.n; i > 0; i--) {
		cout << rhs.a[i] << "x^" << i << " + ";
	}
	cout << rhs.a[0] << endl;
	return os;
}
CDaThuc CDaThuc::operator+(const CDaThuc& P) {
	CDaThuc temp;
	if (this->n > P.n)
		temp.n = this->n;
	else
		temp.n = P.n;
	for (int i = temp.n; i >= 0; i--) {
		temp.a[i] = 0;
	}
	for (int i = this->n; i >= 0; i--) {
		temp.a[i] += a[i];
	}
	for (int i = P.n; i >= 0; i--) {
		temp.a[i] += P.a[i];
	}
	return temp;
}
