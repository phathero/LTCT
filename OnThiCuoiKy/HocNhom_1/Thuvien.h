#define MAX 100

struct Date
{
    int ngay;
    int thang;
    int nam;
};

struct NhanVien
{
    int ms;
    char hoTen[MAX];
    Date date;
    char diaChi[MAX];
    double luong;
};

// Khai bao nguyen mau ham
int Doc_ThongTin_NhanVien(char filename[MAX], NhanVien nv[MAX], int &n);
void XuatDongKeNgang();
void XuatTieuDe();
void Xuat_1_NV(NhanVien nv);
void Xuat_DS_NV(NhanVien nv[MAX], int n);
int Tim_NV_MaSo(NhanVien nv[MAX], int n, int ms);
void LietKe_NV_Luong(NhanVien nv[MAX], int n, int X);
void LietKe_NV_NamSinh(NhanVien nv[MAX], int n, int u, int v);
int TinhTongLuong(NhanVien nv[MAX], int n);
void HoanVi(NhanVien &a, NhanVien &b);
void SapXep_TangDan_MaSo(NhanVien nv[MAX], int n);

// Dinh nghia ham chuc nang
int Doc_ThongTin_NhanVien(char filename[MAX], NhanVien nv[MAX], int &n)
{
    ifstream in(filename);
    if (!in)
        return 0;

    int ms;
    char hoTen[MAX];
    Date date;
    char diaChi[MAX];
    double luong;

    n = 0;

    in >> ms;
    nv[n].ms = ms;
    in >> hoTen;
    strcpy(nv[n].hoTen, hoTen);
    in >> date.ngay;
    nv[n].date.ngay = date.ngay;
    in >> date.thang;
    nv[n].date.thang = date.thang;
    in >> date.nam;
    nv[n].date.nam = date.nam;
    in >> diaChi;
    strcpy(nv[n].diaChi, diaChi);
    in >> luong;
    nv[n].luong = luong;

    while (!in.eof())
    {
        n++;
        in >> ms;
        nv[n].ms = ms;
        in >> hoTen;
        strcpy(nv[n].hoTen, hoTen);
        in >> date.ngay;
        nv[n].date.ngay = date.ngay;
        in >> date.thang;
        nv[n].date.thang = date.thang;
        in >> date.nam;
        nv[n].date.nam = date.nam;
        in >> diaChi;
        strcpy(nv[n].diaChi, diaChi);
        in >> luong;
        nv[n].luong = luong;
    }
    n++;
    in.close();
}

void XuatDongKeNgang()
{
    cout << '|';
    for (int i = 0; i < 86; i++)
        cout << '=';
    cout << '|' << endl;
}

void XuatTieuDe()
{
    XuatDongKeNgang();
    cout << setiosflags(ios::left);
    cout << '|';
    cout << setw(10) << "MS"
         << setw(25) << "Ho va ten"
         << setw(16) << "NTN sinh"
         << setw(20) << "Dia chi"
         << setw(15) << "Luong";
    cout << '|' << endl;
    XuatDongKeNgang();
}

void Xuat_1_NV(NhanVien nv)
{
    cout << setiosflags(ios::left);
    cout << '|'
         << setw(10) << nv.ms
         << setw(25) << nv.hoTen
         << setw(2) << nv.date.ngay << '/'
         << setw(2) << nv.date.thang << '/'
         << setw(10) << nv.date.nam
         << setw(20) << nv.diaChi
         << setiosflags(ios::fixed) << setprecision(2) << setw(15) << nv.luong;
    cout << '|' << endl;
}

void Xuat_DS_NV(NhanVien nv[MAX], int n)
{
    XuatTieuDe();
    for (int i = 0; i < n; i++)
        Xuat_1_NV(nv[i]);
    XuatDongKeNgang();
}

int Tim_NV_MaSo(NhanVien nv[MAX], int n, int ms)
{
    int kq = -1; // Khong tim thay nhan vien co ms

    for (int i = 0; i < n; i++)
        if (nv[i].ms == ms)
        {
            kq = i;
            break;
        }

    return kq;
}

void LietKe_NV_Luong(NhanVien nv[MAX], int n, int X)
{
    int i;
    int VT[MAX]; // Luu lai vi tri cua nhan vien co luong >= x
    int m;       // Chieu dai cua mang VT

    m = 0;
    for (i = 0; i < n; i++)
    {
        if (nv[i].luong >= X)
        {
            VT[m] = i;
            m++;
        }
    }

    if (m == 0)
        cout << "\nKhong co nhan vien nao co luong >= " << X;
    else
    {
        cout << "\nDANH SACH NHAN VIEN CO LUONG >= " << X << endl;
        XuatTieuDe();
        for (i = 0; i < m; i++)
            Xuat_1_NV(nv[VT[i]]);
        XuatDongKeNgang();
    }
}

void LietKe_NV_NamSinh(NhanVien nv[MAX], int n, int u, int v)
{
    int i;
    int VT[MAX];
    int m;

    m = 0;

    for (i = 0; i < n; i++)
    {
        if (u <= nv[i].date.nam && nv[n].date.nam <= v)
        {
            VT[m] = i;
            m++;
        }
    }

    if (m == 0)
        cout << "\nKhong co nhan vien nao sinh trong khoang [" << u << " .. " << v << "].";
        else
        {
            cout << "\nCo " << m << " nhan vien sinh trong khoang [" << u << " .. " << v << "]." << endl;
            XuatTieuDe();
            for (i = 0; i < m; i++)
                Xuat_1_NV(nv[VT[i]]);
            XuatDongKeNgang();
        }
}

int TinhTongLuong(NhanVien nv[MAX], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + nv[i].luong;
    }

    return sum;
}

void HoanVi(NhanVien &a, NhanVien &b)
{
    NhanVien t = a;
    a = b;
    b = t;
}

void SapXep_TangDan_MaSo(NhanVien nv[MAX], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (nv[i].ms > nv[j].ms)
                HoanVi(nv[i], nv[j]);
}
