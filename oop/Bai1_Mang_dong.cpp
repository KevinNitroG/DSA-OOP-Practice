#include <iostream>
#include <string>
using namespace std;

class IntArr {
	friend istream& operator>> (istream& is, IntArr& rhs);
	friend ostream& operator<< (ostream& os, const IntArr& rhs);
private:
	int count;
	int* values;
public:
	IntArr();
	IntArr(int size);
	IntArr(int size, int init);
	IntArr(const IntArr& rhs);
	IntArr& operator= (const IntArr& rhs);
	IntArr concat(const IntArr& rhs);
	void push(int val);
	~IntArr();
};

IntArr::IntArr() {
	count = 0;
	values = NULL;
}
IntArr::IntArr(int size) {
	count = size;
	values = new int[count];
	for (int i = 0; i < size; ++i) {
		values[i] = 0;
	}
}
IntArr::IntArr(int size, int init) {
	count = size;
	values = new int[count];
	for (int i = 0; i < count; ++i) {
		values[i] = init;
	}
}
IntArr::IntArr(const IntArr& rhs) {
	count = rhs.count;
	values = new int[count];
	for (int i = 0; i < count; ++i) {
		values[i] = rhs.values[i];
	}
}
IntArr& IntArr::operator= (const IntArr& rhs) {
	delete[] this->values;
	count = rhs.count;
	values = new int[count];
	for (int i = 0; i < count; ++i) {
		values[i] = rhs.values[i];
	}
	return *this;
}
IntArr IntArr::concat(const IntArr& rhs) {
	IntArr ret(this->count + rhs.count);
	int iRet = 0;
	for (int i = 0; i < this->count; ++i) {
		ret.values[iRet] = this->values[i];
		++iRet;
	}
	for (int i = 0; i < rhs.count; ++i) {
		ret.values[iRet] = rhs.values[i];
		++iRet;
	}
	return ret;
}
void IntArr::push(int val) {
	IntArr temp(1, val);
	*this = this->concat(temp);
}
IntArr::~IntArr() {
	cout << "Destructor has been called" << endl;
	delete[] values;
}
istream& operator>> (istream& is, IntArr& rhs) {
	delete[] rhs.values;
	cout << "Nhap so luong: ";
	is >> rhs.count;
	rhs.values = new int[rhs.count];
	cout << "Nhap cac phan tu :\n";
	for (int i = 0; i < rhs.count; ++i) {
		is >> rhs.values[i];
	}
	return is;
}
ostream& operator<< (ostream& os, const IntArr& rhs) {
	for (int i = 0; i < rhs.count; ++i) {
		os << rhs.values[i] << " ";
	}
	return os;
}
