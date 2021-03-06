
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, String a, String b);

void XuatMenu()
{
	cout << "\n=================== BANG MENU==================\n";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. gets_s: Nhap chuoi";
	cout << "\n2. Xem chuoi";
	cout << "\n3. strlen_Tinh chieu dai cua chuoi";
	cout << "\n4. strcat_s_Noi chuoi sau vao sau chuoi truoc";
	cout << "\n5. strcpy_s_Chep chuoi sau vao chuoi truoc";
	cout << "\n6. _strcmpi_So sanh chuoi_Khong phan biet KT thuong, HOA";
	cout << "\n7. strcmp_So sanh chuoi_Phan biet KT thuong, HOA";
	cout << "\n8. Noi chuoi sau vao sau chuoi truoc";
	cout << "\n9. Chep chuoi sau qua chuoi truoc";
	cout << "\n10. So sanh chuoi_Khong phan biet KT thuong, HOA";
	cout << "\n11. So sanh chuoi_Phan biet KT thuong, HOA";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang[0.." << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, String a, String b)
{
	int kq;
	system("cls");

	switch (menu)
	{
		case 0:
			cout << "\n0. Thoat chuong trinh";
			break;

		case 1:
			cout << "\n1. gets_s: Nhap chuoi";
			gets_s_NhapChuoi(a, 'a');
			cout << "\nChuoi vua nhap: ";
			XuatChuoi(a);

			gets_s_NhapChuoi(b, 'b');
			cout << "\nChuoi vua nhap: ";
			XuatChuoi(b);

			cout << "\nNhan phim bat ky de tiep tuc.";

			break;

		case 2:
			cout << "\n2. Xem chuoi";
			cout << "\nChuoi a: ";
			XuatChuoi(a);
			cout << "\nChuoi b: ";
			XuatChuoi(b);
			
			cout << "\nNhan phim bat ky de tiep tuc.";

			break;

		case 3:
			cout << "\n3. strlen_Tinh chieu dai cua chuoi";
			cout << "\nChuoi a: ";
			XuatChuoi(a);
			cout << "\nChieu dai chuoi a: l = " << strlen_TinhChieuDaiCuaChuoi(a);
			cout << "\nChuoi b: ";
			XuatChuoi(b);
			cout << "\nChieu dai chuoi b: l = " << strlen_TinhChieuDaiCuaChuoi(b);
			cout << "\nNhan phim bat ky de tiep tuc";
			break;

		case 4:
			cout << "\n4. strcat_s_Noi chuoi sau vao sau chuoi truoc";
			cout << "\nChuoi truoc: a = ";
			XuatChuoi(a);
			cout << "\nChuoi sau: b = ";
			XuatChuoi(b);
			strcat_s_Noi_ChuoiSau_VaoSau_ChuoiTruoc(a, b);
			cout << "\nChuoi truoc sau khi noi: a = ";
			XuatChuoi(a);
			break;

		case 5:
			cout << "\n5. strcpy_s_Chep chuoi sau vao chuoi truoc";
			cout << "\nChuoi sau: b = ";
			XuatChuoi(b);

			strcpy_s_Chep_ChuoiSau_Qua_ChuoiTruoc(a, b);
			cout << "\nChuoi truoc a, do b chep qua: a = ";
			XuatChuoi(a);
			break;
		case 6:
			cout << "\n6. _strcmpi_So sanh chuoi_Khong phan biet KT thuong, HOA";
			cout << "\nChuoi a: ";
			XuatChuoi(a);
			cout << "\nChuoi b: ";
			XuatChuoi(b);

			kq = _strcmpi_SoSanhChuoi_KPB(a, b);
			if (kq > 0)
				cout << "\na > b";
			else
				if (kq < 0)
					cout << "\na < b";
				else
					cout << "\na == b";
			break;
		case 7:
			cout << "\n7. strcmp_So sanh chuoi_Phan biet KT thuong, HOA";
			cout << "\nChuoi a: ";
			XuatChuoi(a);
			cout << "\nChuoi b: ";
			XuatChuoi(b);

			kq = strcmp_SoSanhChuoi_PB(a, b);
			if (kq > 0)
				cout << "\na > b";
			else
				if (kq < 0)
					cout << "\na < b";
				else
					cout << "\na == b";
			break;
		case 8:
			cout << "\n8. Noi chuoi sau vao sau chuoi truoc";
			cout << "\nChuoi truoc: a = ";
			XuatChuoi(a);
			cout << "\nChuoi sau: b = ";
			XuatChuoi(b);
			Noi_ChuoiSau_VaoSau_ChuoiTruoc(a, b);
			cout << "\nChuoi truoc sau khi noi: a = ";
			XuatChuoi(a);

			break;

		case 9:
			cout << "\n9. Chep chuoi sau qua chuoi truoc";
			cout << "\nChuoi sau: b = ";
			XuatChuoi(b);

			Chep_ChuoiSau_Qua_ChuoiTruoc(a, b);
			cout << "\nChuoi truoc a, do b chep qua: a = ";
			XuatChuoi(a);
			break;

		case 10:
			cout << "\n10. So sanh chuoi_Khong phan biet KT thuong, HOA";
			cout << "\nChuoi a = ";
			XuatChuoi(a);
			cout << "\nChuoi b = ";
			XuatChuoi(b);

			kq = SoSanhChuoi_KPB(a, b);
			if (kq == 1)
				cout << "\na > b";
			else
				if (kq == -1)
					cout << "\na < b";
				else
					cout << "\na == b";
			break;

		case 11:
			cout << "\n11. So sanh chuoi_Phan biet KT thuong, HOA";
			cout << "\nChuoi a = ";
			XuatChuoi(a);
			cout << "\nChuoi b = ";
			XuatChuoi(b);

			kq = SoSanhChuoi_PB(a, b);
			if (kq == 1)
				cout << "\na > b";
			else
				if (kq == -1)
					cout << "\na < b";
				else
					cout << "\na == b";
			break;
	}

	_getch();
}


