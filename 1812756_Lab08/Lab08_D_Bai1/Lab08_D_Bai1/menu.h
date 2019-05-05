
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, NhanVien a[MAX], int &n);

void XuatMenu()
{
	cout << "\n============== He thong chuc nang =============\n";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Nhap danh sach nhan vien";
	cout << "\n2. Xem danh sach nhan vien";
	cout << "\n3. Them mot nhan vien vao cuoi danh sach";
	cout << "\n4. Xoa mot nhan vien theo ma nhan vien";
	cout << "\n5. Sua thong tin nhan vien theo ma nhan vien";
	cout << "\n6. Tim nhan vien theo ma so";
	cout << "\n7. Tim nhan vien theo ten";
	cout << "\n8. Sap danh sach nhan vien tang dan theo ma nhan vien";
	cout << "\n9. Sap danh sach nhan vien tang dan theo ten-ho-luong";
	cout << "\n10. Tinh tong luong thang";
	cout << "\n11. Liet ke cac nhan vien co luong >= x (nhap tu ban phim)";
	cout << "\n12. Liet ke cac nhan vien co nam sinh trong khoang [u,v]";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\n\nNhap 1 so trong khoang [0.." << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, NhanVien a[MAX], int &n)
{
	switch (menu)
	{
		case 0:
			cout << "\n0. Thoat chuong trinh";
			break;
		case 1:
			cout << "\n1. Nhap danh sach nhan vien";
			break;
		case 2:
			cout << "\n2. Xem danh sach nhan vien";
			break;
		case 3:
			cout << "\n3. Them mot nhan vien vao cuoi danh sach";
			break;
		case 4:
			cout << "\n4. Xoa mot nhan vien theo ma nhan vien";
			break;
		case 5:
			cout << "\n5. Sua thong tin nhan vien theo ma nhan vien";
			break;
		case 6:
			cout << "\n6. Tim nhan vien theo ma so";
			break;
		case 7:
			cout << "\n7. Tim nhan vien theo ten";
			break; 
		case 8:
			cout << "\n8. Sap danh sach nhan vien tang dan theo ma nhan vien";
			break;
		case 9:
			cout << "\n9. Sap danh sach nhan vien tang dan theo ten-ho-luong";
			break;
		case 10:
			cout << "\n10. Tinh tong luong thang";
			break;
		case 11:
			cout << "\n11. Liet ke cac nhan vien co luong >= x (nhap tu ban phim)";
			break;
		case 12:
			cout << "\n12. Liet ke cac nhan vien co nam sinh trong khoang [u,v]";
			break;
	}
	_getch();
}


