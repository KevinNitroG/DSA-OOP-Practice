#include<iostream>
using namespace std;

class NhomMau {
protected:
	char Rh;
public:
	void Nhap();/*Các lớp con không có thuộc tính riêng nên hàm Nhap()
				 không cần là phương thức ảo*/
	virtual char getMau() = 0;/*Lấy nhóm máu của các lớp con(không xét Rh)
								để thực hiện các phương thức kiểm tra*/
	char getRh();//Tương tự như phương thức Nhap()
	virtual bool KiemTraChaMe(NhomMau*, NhomMau*) = 0;
	//Kiểm tra xem nhóm  máu cha mẹ có phù hợp với nhóm máu của conn
	virtual bool KiemTraTuongThich(NhomMau*) = 0;
	//Kiểm tra nhóm máu người cho có phù hợp
};

class DanhSach { // Lớp DanhSach dùng để quản lí các nhóm mau
protected:
	int n;                     // Số lượng loại máu
	NhomMau* ds[100];    //Mảng ds dùng để quản lí nhóm máu của từng người
public:
	void Nhap();               //Nhập danh sách nhóm máu của từng người
	bool KiemTraDiTruyen();    //Kiểm tra nhóm máu của cha, mẹ, con 
	void TimKiemNguoiCho(int); //Xuất ra chỉ số của những người cho phù hợp
};

class A : public NhomMau {
public:
	char getMau();
	bool KiemTraChaMe(NhomMau*, NhomMau*);
	bool KiemTraTuongThich(NhomMau*);
};

class B : public NhomMau {
public:
	char getMau();
	bool KiemTraChaMe(NhomMau*, NhomMau*);
	bool KiemTraTuongThich(NhomMau*);
};

class O : public NhomMau {
public:
	char getMau();
	bool KiemTraChaMe(NhomMau*, NhomMau*);
	bool KiemTraTuongThich(NhomMau*);
};

class AB : public NhomMau {
public:
	char getMau();
	bool KiemTraChaMe(NhomMau*, NhomMau*);
	bool KiemTraTuongThich(NhomMau*);
};

//Định nghĩa các phương thức cho câu 1
void NhomMau::Nhap() {
	cout << "Nhap Rh: ";
	cin >> Rh;
}
void DanhSach::Nhap() {
	cout << "Nhap so luong nguoi: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		char loai;
		cout << "Nhap loai mau (nhap C thay cho AB) thu [" << i << "]: ";
		cin >> loai;
		switch (loai) {
		case 'A':
			ds[i] = new A;
			break;
		case 'B':
			ds[i] = new B;
			break;
		case 'O':
			ds[i] = new O;
			break;
		case 'C':
			ds[i] = new AB;
		}
		ds[i]->Nhap();
	}
}

//Định nghĩa các phương thức cho câu 2
char A::getMau() {
	return 'A';
}
char B::getMau() {
	return 'B';
}
char O::getMau() {
	return 'O';
}
char AB::getMau() {
	return 'C';
}
char NhomMau::getRh() {
	return Rh;
}
bool A::KiemTraChaMe(NhomMau* cha, NhomMau* me) {
	char mauCha = cha->getMau();
	char mauMe = me->getMau();
	//Nếu cha hoặc mẹ có nhóm máu A hoặc AB thì con có thể có nhóm máu A
	if (mauCha == 'A' || mauCha == 'C' || mauMe == 'A' || mauMe == 'C') {
		return true;
	}
	return false;
}
bool B::KiemTraChaMe(NhomMau* cha, NhomMau* me) {
	char mauCha = cha->getMau();
	char mauMe = me->getMau();
	//Nếu cha hoặc mẹ có nhóm máu B hoặc AB thì con có thể có nhóm máu B
	if (mauCha == 'B' || mauCha == 'C' || mauMe == 'B' || mauMe == 'C') {
		return true;
	}
	return false;
}
bool O::KiemTraChaMe(NhomMau* cha, NhomMau* me) {
	char mauCha = cha->getMau();
	char mauMe = me->getMau();
	//Nếu cha và mẹ có nhóm máu AB thì con không thể có nhóm máu O
	if (mauCha == 'C' && mauMe == 'C') {
		return false;
	}
	return true;
}
bool AB::KiemTraChaMe(NhomMau* cha, NhomMau* me) {
	char mauCha = cha->getMau();
	char mauMe = me->getMau();
	/*Các trường hợp con không thể có nhóm máu AB:
	  - Cha và mẹ có nhóm máu giống nhau nhưng khác nhóm máu AB
	  - Cha hoặc mẹ có nhóm máu O*/
	if ((mauCha == mauMe && mauMe != 'C') || mauCha == 'O' || mauMe == 'O') {
		return false;
	}
	return true;
}
bool DanhSach::KiemTraDiTruyen() {
	int cha, me, con;
	cout << "Nhap lan luot chi so cua cha, me, con: ";
	cin >> cha >> me >> con;
	bool check = ds[con]->KiemTraChaMe(ds[cha], ds[me]);
	if (check == 1) {
		return true;
	}
	return false;
}

//Định nghĩa các phương thức cho câu 3
void DanhSach::TimKiemNguoiCho(int x) {
	for (int i = 0; i < n; i++) {
		if (i != x && ds[x]->KiemTraTuongThich(ds[i]) == 1) {
			cout << i << endl;
		}
	}
}
bool A::KiemTraTuongThich(NhomMau* nguoiCho) {
	//Người có nhóm máu A chỉ nhận được nhóm máu A và O(chưa xét Rh)
	if (nguoiCho->getMau() == 'A' || nguoiCho->getMau() == 'O') {
		//Người có nhóm máu Rh+ có thể nhận nhóm máu Rh+ hoặc Rh-  
		//Người có nhóm máu Rh- có thể cho người có nhóm máu Rh+ hoặc Rh- 
		if (this->getRh() == '+' || nguoiCho->getRh() == '-') {
			return true;
		}
	}
	return false;
}
bool B::KiemTraTuongThich(NhomMau* nguoiCho) {
	//Người có nhóm máu B chỉ nhận được nhóm máu B và O(chưa xét Rh)
	if (nguoiCho->getMau() == 'O' || nguoiCho->getMau() == 'B') {
		if (this->getRh() == '+' || nguoiCho->getRh() == '-') {
			return true;
		}
	}
	return false;
}
bool O::KiemTraTuongThich(NhomMau* nguoiCho) {
	//Người có nhóm máu O chỉ nhận được nhóm máu O(chưa xét Rh)
	if (nguoiCho->getMau() == 'O') {
		if (this->getRh() == '+' || nguoiCho->getRh() == '-') {
			return true;
		}
	}
	return false;
}
bool AB::KiemTraTuongThich(NhomMau* nguoiCho) {
	//Người có nhóm máu AB có thể nhận được tất cả nhóm máu (chưa xét Rh)
	if (this->getRh() == '+' || nguoiCho->getRh() == '-') {
		return true;
	}
	return false;
}

