#include <iostream>
using namespace std;

class DaThucBacHai {
private:
	float a;
	float b;
	float c;
public:
	float TinhGiaTri(DaThucBacHai dt, float x0);
	DaThucBacHai operator+(const DaThucBacHai&);
};
float DaThucBacHai::TinhGiaTri(DaThucBacHai dt, float x0) {
	return a * pow(x0, 2) + b * x0 + c;
}
DaThucBacHai DaThucBacHai::operator+(const DaThucBacHai& dt) {
	DaThucBacHai tong;
	tong.a = this->a + dt.a;
	tong.b = this->b + dt.b;
	tong.c = this->c + dt.c;
	return tong;
}
