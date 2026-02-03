// Viết một chương trình lưu danh sách sinh viên 
//cho phép thêm/xóa/sửa và sort sinh viên theo điểm từ cao đến thấp
#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<fstream>
using namespace std;

struct SinhVien
{
	char maSV[20];
	string tenSV;
	float diemTB;
};

void nhap1SV(SinhVien &sv);
void nhapDSSV(SinhVien *dssv, int n);
void xuat1SV(SinhVien sv);
void xuatDSSV(SinhVien *dssv, int n);
void themSV(SinhVien *dssv, int &n);
void xoaSV(SinhVien *dssv, int &n, int vt);
void suaSV(SinhVien &sv);
void hoanDoi(SinhVien &a, SinhVien &b);
void sortDiemThapDenCao(SinhVien *dssv, int n);
void luuDSSV(SinhVien *dssv, int n);

void nhap1SV(SinhVien &sv)
{
	cout << "=============================================";
	cout << endl;
	cin.ignore();
	cout << "+ Nhap ma cua sinh vien: ";
	cin.getline(sv.maSV, 20); //dung cho bien char
	cout << "\n+ Nhap ten cua sinh vien: ";
	getline(cin, sv.tenSV); //dung cho bien string
	cout << "\n+ Nhap diem trung binh cua sinh vien: ";
	cin >> sv.diemTB;
	cout << "=============================================";
	cout << endl;
	cout << endl;
	cout << endl;
}

void nhapDSSV(SinhVien *dssv, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin sinh vien thu " << i + 1 << "!" << endl;
		nhap1SV(*(dssv + i));
	}
}

void xuat1SV(SinhVien sv)
{
	cout << "\nMa cua sinh vien la: " << sv.maSV;
	cout << "\nTen cua sinh vien la: " << sv.tenSV;
	cout << "\nDiem trung binh cua sinh vien la: " << sv.diemTB;

}

void xuatDSSV(SinhVien *dssv, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nTHONG TIN SINH VIEN THU " << i + 1 << "!";
		cout << endl;
		cout << "===================================================";
		xuat1SV(*(dssv + i));
		cout << endl;
		cout << "===================================================";
		if (*dssv == NULL)
		{
			cout << "\nDanh sach rong";
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

void themSV(SinhVien *dssv, int &n)
{
	cout << "\nNhap thong tin sinh vien can them: " << endl;
	nhap1SV(*(dssv + n));
	n++;
	cout << "Them sinh vien thanh cong!";

}

void xoaSV(SinhVien *dssv, int &n, int viTri)
{
	for (int i = viTri - 1; i < n; i++)
	{
		*(dssv + i) = *(dssv + i + 1);
	}
	n--;
}

void suaSV(SinhVien &sv)
{
	int luachon;
	while (true)
	{
		cout << "=============================================================" << endl;
		cout << "|                                                           |" << endl;
		cout << "|             BAN MUON SUA THONG TIN GI?                    |" << endl;
		cout << "| 1.Sua ma cua sinh vien.                                   |" << endl;
		cout << "| 2.Sua ten cua sinh vien.                                  |" << endl;
		cout << "| 3.Sua diem trung binh cua sinh vien.                      |" << endl;
		cout << "| 4.Sua toan bo thong tin sinh vien.                        |" << endl;
		cout << "| 5.Hoan tat chinh sua thong tin! Thoat.                    |" << endl;
		cout << "|                                                           |" << endl;
		cout << "=============================================================" << endl;
		cout << "\nNhap lua chon cua ban: ";
		cin >> luachon;
		if (luachon != 1 && luachon != 2 && luachon != 3 && luachon != 4 && luachon != 5)
		{
			cout << "\nLua chon da sai! Xin moi nhap lai lua chon.";
		}
		else if (luachon == 1)
		{
			cin.ignore();
			cout << "\nNhap ma moi cho sinh vien: ";
			cin.getline(sv.maSV, 20);
		}
		else if (luachon == 2)
		{
			cin.ignore();
			cout << "\nNhap ten moi cho sinh vien: ";
			getline(cin, sv.tenSV);
		}
		else if (luachon == 3)
		{
			cout << "\nNhap diem trung binh moi cho sinh vien: ";
			cin >> sv.diemTB;
		}
		else if (luachon == 4)
		{
			cout << "\nSua lai toan bo thong tin sinh vien: ";
			cout << endl;
			nhap1SV(sv);
		}
		else if (luachon == 5)
		{
			cout << "\nHoan tat viec chinh sua!";
			cout << endl;
			break;
		}
	}
}

void hoanDoi(SinhVien &a, SinhVien &b)
{
	SinhVien temp = a;
	a = b;
	b = temp;
}

void sortDiemThapDenCao(SinhVien *dssv, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((dssv + i)->diemTB < (dssv + j)->diemTB)
			{
				hoanDoi(*(dssv + i), *(dssv + j));
			}
		}
	}
}

void luuDSSV(SinhVien *dssv, int n)
{
	ofstream file("Danh Sach Sinh Vien Da Luu.txt");
	if (file.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			file << "\nTHONG TIN SINH VIEN THU " << i + 1 << "!" << endl;
			file << "======================================" << endl;
			file << "Ma cua sinh vien la: " << dssv[i].maSV << endl;
			file << "Ten cua sinh vien la: " << dssv[i].tenSV << endl;
			file << "Diem trung binh cua sinh vien la: " << dssv[i].diemTB << endl;
			file << "======================================";
			file << endl;
			file << endl;
			file << endl;
		}
		file.close();
		cout << endl;
		cout << "Da luu danh sach sinh vien thanh cong vao file!" << endl;
	}
	else
	{
		cout << "Khong the mo file de luu danh sach sinh vien!" << endl;
	}
}

int main()
{
	SinhVien ds[100];
	int n;
	int chon;
	int viTri;
	bool in = false;
	while (true)
	{
		system("cls");
		cout << "=============================================================" << endl;
		cout << "|                                                           |" << endl;
		cout << "|            QUAN LY THONG TIN SINH VIEN!                   |" << endl;
		cout << "|                      ~~~0~~~                              |" << endl;
		cout << "| 1.Nhap danh sach sinh vien.                               |" << endl;
		cout << "| 2.Xuat danh sach sinh vien.                               |" << endl;
		cout << "| 3.Them 1 sinh vien.                                       |" << endl;
		cout << "| 4.Xoa 1 sinh vien.                                        |" << endl;
		cout << "| 5.Sua 1 sinh vien (tuy chon).                             |" << endl;
		cout << "| 6.Sap xep sinh vien co diem trung binh tu cao den thap.   |" << endl;
		cout << "| 7.Luu danh sach sinh vien.                                |" << endl;
		cout << "| 8.Thoat.                                                  |" << endl;
		cout << "|                      ~~~0~~~                              |" << endl;
		cout << "|                                                           |" << endl;
		cout << "=============================================================" << endl;
		cout << "\nNhap lua chon cua ban: ";
		cin >> chon;
		if (chon != 1 && chon != 2 && chon != 3 && chon != 4 && chon != 5 && chon != 6 && chon != 7 && chon != 8)
		{
			cout << "\nLua chon da sai! Xin moi ban nhap lai lua chon.";
			cout << endl;
		}
		else if (chon == 1)
		{
			cout << "\nNhap so luong sinh vien: ";
			cin >> n;
			nhapDSSV(ds, n);
			in = true;
		}
		else if (chon == 2)
		{
			if (in)
			{
				xuatDSSV(ds, n);
			}
			else
			{
				cout << "\nBan chua nhap sinh vien!";
			}
		}
		else if (chon == 3)
		{
			if (in)
			{
				themSV(ds, n);
			}
			else
			{
				cout << "\nChua nhap sinh vien";
			}
		}
		else if (chon == 4)
		{
			if (in)
			{
				cout << "\nNhap vi tri sinh vien can xoa: ";
				cin >> viTri;
				if (viTri >= 1 && viTri <= n)
				{
					xoaSV(ds, n, viTri);
					cout << "\nBan da xoa thanh cong!";
				}
				else
				{
					cout << "\nVi tri sinh vien can xoa khong hop le!";
				}
			}
			else
			{
				cout << "Ban chua nhap sinh vien!";
			}
		}
		else if (chon == 5)
		{
			if (in)
			{
				cout << "\nNhap vi tri sinh vien can sua: ";
				cin >> viTri;
				if (viTri >= 1 && viTri <= n)
				{
					suaSV(*(ds + viTri - 1));
				}
				else
				{
					cout << "\nVi tri sinh vien can sua khong hop le!";
				}
			}
			else
			{
				cout << "\nBan chua nhap sinh vien!";
			}
		}
		else if (chon == 6)
		{
			if (in)
			{
				sortDiemThapDenCao(ds, n);
				cout << "\nSap xep sinh vien co diem trung binh tu cao den thap thanh cong!";
			}
			else
			{
				cout << "Ban chua nhap sinh vien!";
			}
		}
		else if (chon == 7)
		{
			if (in)
			{
				luuDSSV(ds, n);
			}
			else
			{
				cout << "\nBan chua nhap sinh vien!";
			}
		}
		else if (chon == 8)
		{
			cout << "\nXin cam on da su dung chuong trinh!";
			cout << endl;
			break;
		}
		_getch();
	}
}
