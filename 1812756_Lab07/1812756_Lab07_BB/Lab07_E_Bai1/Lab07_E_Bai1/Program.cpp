#include <iostream>
#include <conio.h>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	int soMenu = 13, menu;
	String str;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, str);
	} while (menu > 0);
}





