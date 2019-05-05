#define MAX 100
#define NGANGDOI '='
#define NGANGDON '-'

typedef unsigned short int Byte;

struct NgayThangNam
{
	Byte ngaySinh;
	Byte thangSinh;
	unsigned int namSinh;
};

struct NhanVien
{
	char maNV[8];
	char hoLot[21];
	char ten[8];
	NgayThangNam ntns;
	char diaChi[21];
	double luong;
};

void Nhap_1NV(NhanVien &p);
void Nhap_DSNV(NhanVien a[MAX], int &n);
void XuatKeNgang();
void XuatTieuDe();
void Xuat_1NV(NhanVien p);
void Xuat_DSNV(NhanVien a[MAX], int n);
void ThemNhanVien_Cuoi(NhanVien a[MAX], int &n, NhanVien p);
void XoaNhanVien_MaNV(NhanVien a[MAX], int &n, char maNV[8]);
void SuaNhanVien_MaNV(NhanVien a[MAX], int &n, char maNV[8]);
int TimNhanVien_MaNV(NhanVien a[MAX], int n, char MaNV[8]);

void Nhap_1NV(NhanVien &p)
{
	cout << "\nMa nhan vien (dung 7 ky so): ";
	cin.ignore(MAX, '\n');
	gets_s(p.maNV, 8);

	cout << "\nHo va chu lot: ";
	gets_s(p.hoLot, 21);

	cout << "\nTen nhan vien: ";
	gets_s(p.ten, 7);

	cout << "\nNgay sinh: ";
	cin >> p.ntns.ngaySinh;

	cout << "\nThang sinh: ";
	cin >> p.ntns.thangSinh;

	cout << "\nNam sinh: ";
	cin >> p.ntns.namSinh;

	cout << "\nNhap dia chi: ";
	cin.ignore(MAX, '\n');
	gets_s(p.diaChi, 20);

	cout << "\nNhap luong: ";
	cin >> p.luong;
}

void Nhap_DSNV(NhanVien a[MAX], int &n)
{
	int i;
	cout << "\nNhap n = ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		system("cls");
		cout << "\nNhap thong tin cho nhan vien thu " << i + 1 << " : ";
		Nhap_1NV(a[i]);
	}
}

void XuatKeNgang()
{
	int i;
	cout << "\n";
	cout << setiosflags(ios::left) << "|";
	for (i = 1; i <= 76; i++)
		cout << NGANGDOI;
	cout << '|';
}

void XuatTieuDe()
{
	XuatKeNgang();
	cout << endl;
	cout << setiosflags(ios::left)
		<< '|'
		<< setw(8) << "Ma NV"
		<< '|'
		<< setw(16) << "Ho"
		<< setw(8) << "Ten"
		<< '|'
		<< setw(12) << "NTN sinh"
		<< '|'
		<< setw(16) << "Dia chi"
		<< '|'
		<< setw(12) << "Luong"
		<< '|';
	XuatKeNgang();
}

void Xuat_1NV(NhanVien p)
{
	cout << setiosflags(ios::left)
		<< '|'
		<< setw(8) << p.maNV
		<< '|'
		<< setw(16) << p.hoLot
		<< setw(8) << p.ten
		<< '|'
		<< setw(2) << p.ntns.ngaySinh
		<< '/'
		<< setw(2) << p.ntns.thangSinh
		<< '/'
		<< setw(6) << p.ntns.namSinh
		<< '|'
		<< setw(16) << p.diaChi
		<< '|'
		<< setw(12) << setiosflags(ios::fixed) << setprecision(2) << p.luong
		<< '|';
}

void Xuat_DSNV(NhanVien a[MAX], int n)
{
	int i;
	XuatTieuDe();
	for (i = 0; i < n; i++)
	{
		cout << endl;
		Xuat_1NV(a[i]);
	}
	XuatKeNgang();
}

void ThemNhanVien_Cuoi(NhanVien a[MAX], int &n, NhanVien p)
{
	a[n++] = p;
}

void XoaNhanVien_MaNV(NhanVien a[MAX], int &n, char maNV[8])
{
	int i, j;
	for (i = 0; i < n; i++)
		if (strcmp(a[i].maNV, maNV) == 0)
			break;
	if (i == n)
	{
		cout << "\nKhong co nhan vien nao trong danh sach co ma so " << maNV;
		return;
	}
	for (j = i + 1; j < n; j++)
		a[j - 1] = a[j];
	n--;
}

void SuaNhanVien_MaNV(NhanVien a[MAX], int &n, char maNV[8])
{
	int i;
	char tl;
	for (i = 0; i < n; i++)
		if (strcmp(a[i].maNV, maNV) == 0)
			break;
	if (i == n)
	{
		cout << "\nKhong co nhan vien nao trong danh sach co ma so " << maNV;
		return;
	}

	cout << "\nSua thong tin nhan vien co ma so: " << maNV;
	cout << "\nCo sua ma nhan vien khong? nhan k neu khong";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nMa nhan vien: ";
		cin.ignore(MAX, '\n');
		gets_s(a[i].maNV, 8);
	}

	cout << "\nCo sua ho va chu lot khong? nhan k neu khong";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nHo va chu lot: ";
		//cin.ignore(MAX, '\n');
		gets_s(a[i].hoLot, 21);
	}

	cout << "\nCo sua ten khong? nhan k neu khong";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nTen nhan vien: ";
		//cin.ignore(MAX, '\n');
		gets_s(a[i].ten, 8);
	}

	cout << "\nCo sua ngay sinh khong? nhan k neu khong";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nNgay sinh: ";
		//cin.ignore(MAX, '\n');
		cin >> a[i].ntns.ngaySinh;
	}

	cout << "\nCo sua thang sinh khong? nhan k neu khong";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nThang sinh: ";
		//cin.ignore(MAX, '\n');
		cin >> a[i].ntns.thangSinh;
	}

	cout << "\nCo sua nam sinh khong? nhan k neu khong";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nNam sinh: ";
		//cin.ignore(MAX, '\n');
		cin >> a[i].ntns.namSinh;
	}

	cout << "\nCo sua dia chi khong? nhan k neu khong";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nNhap dia chi: ";
		cin.ignore(MAX, '\n');
		gets_s(a[i].diaChi, 20);
	}

	cout << "\nCo sua luong khong? nhan k neu khong";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nNhap luong: ";
		//cin.ignore(MAX, '\n');
		cin >> a[i].luong;
	}
}

int TimNhanVien_MaNV(NhanVien a[MAX], int n, char MaNV[8])
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (strcmp(a[i].maNV, MaNV) == 0)
		{
			kq = i;
			break;
		}
	return kq;
}



















