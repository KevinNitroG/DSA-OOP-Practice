#include<iostream>
#include<vector>
using namespace std;

class KyHieu {
protected:
	float truongDo;
public:
	virtual void Nhap() {
		int loai;
		cout << "Nhap vao loai hinh not(1-Tron, 2-Trang, 3-Den, 4-Moc don, 5-Moc kep, 6-Moc tam, 7-Moc tu): ";
		cin >> loai;
		switch (loai) {
		case 1: { truongDo = 4; break; }
		case 2: { truongDo = 2; break; }
		case 3: { truongDo = 1; break; }
		case 4: { truongDo = 0.5; break; }
		case 5: { truongDo = 0.25; break; }
		case 6: { truongDo = 0.125; break; }
		case 7: { truongDo = 0.0625; break; }
		}
	}
	virtual bool LaDauLangDen() {
		return false;
	}
	virtual int LayCaoDo() {
		return 0;
	}
};

class NotNhac : public KyHieu {
private:
	int caoDo;
public:
	void Nhap() {
		cout << "Nhap vao cao do(1-Do(C), 2-Re(D), 3-Mi(E), 4-Fa(F), 5-Sol(G), 6-La(A), 7-Si(B)): ";
		cin >> caoDo;
	}
	int LayCaoDo() {
		return caoDo;
	}

};

class DauLang :public KyHieu {
public:
	bool LaDauLangDen() {
		if (truongDo == 1)
			return true;
		return false;
	}
};

class BanNhac {
private:
	vector<KyHieu*> ds;
public:
	void Nhap() {
		cout << "Nhap vao so ky hieu cua ban nhac: ";
		int n;
		cin >> n;
		KyHieu* tmp;
		for (int i = 0; i < n; i++) {
			int loai;
			tmp = NULL;
			cout << "Nhap ky hieu thu " << i + 1 << " can them vao ban nhac(1 - NotNhac, 2 - DauLang) : ";
			cin >> loai;
			if (loai == 1) tmp = new NotNhac;
			else tmp = new DauLang;
			tmp->Nhap();
			ds.push_back(tmp);
		}
	}
	// cau b
	int DemDauLangDen() {
		int dem = 0;
		for (int i = 0; i < ds.size(); i++) {
			if (ds[i]->LaDauLangDen()) {
				dem++;
			}
		}
		return dem;
	}
	// cau c
	int TimCaoDoMAX() {
		int max = ds[0]->LayCaoDo();
		int index = 0;
		for (int i = 0; i < ds.size(); i++) {
			if (ds[i]->LayCaoDo() > max) {
				max = ds[i]->LayCaoDo();
				index = i;
			}
		}
		return index + 1;
	}
};

int main() {
	BanNhac b;
	b.Nhap();
	cout << "So dau lang den cua ban nhac la: " << b.DemDauLangDen();
	cout << "\nVi tri not nhac co cao do lon nhat la :" << b.TimCaoDoMAX();
}
