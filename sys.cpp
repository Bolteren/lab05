#include "sys.hpp"

using namespace std;

void pause(void)
{
	system("pause");
}

void CLS(void)
{
	system("cls");
}

void pauseCls(void)
{
	pause();
	CLS();
}

void fulScrean(void)
{
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

void WindowColor(string colorFont, string colorBackGraund)
{
	string a = "color ";
	string sizeColorOpt;
	sizeColorOpt = a + colorBackGraund + colorFont;
	char str[255];
	int num = 0;
	for(num; sizeColorOpt[num] != '\0'; num++)
	{
		str[num] = sizeColorOpt[num];
	}
	str[num++] = '\0';
//	cout << str;
	system(str);
}
