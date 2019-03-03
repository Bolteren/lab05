#include <iostream>
#include "matem.hpp"
#include "mtm.hpp"
#include "func.hpp"
#include "sys.hpp"

using namespace std;


void menu1(void);
void menu2(void);
void menu3(void);
void menu4(void);
void menu5(void);
void menu6(void);
void menuF(void);
void menuO(void);


//i - ������ j - �������� ������
//szMs mSizeOp(void);

int main(void) 
{
	setlocale(LC_ALL, "Russian");
	szMs mSize;
	while(true)
	{
		char mn1 = 0;
		cout << "�������� �������� �������� ��������������� �������: " << endl;
		cout << "1) ������� �������� �� ����� �����������.\n2) ������� �������� ������� �� �����.\n3) ��������� �������� ����� �����������." << endl;
		cout << "4) ���������� ������� ���������� �������.\n5) ���������� �� �������.\n6) ���������� ���������� �������." << endl;
		cout << "o) �����.\nf) ������� �� ���� �����. \ne) �����.";
		mn1 = getch();
		system("cls");
		switch (mn1)
		{
			case '1': menu1();
				break;
			case '2': menu2();
				break;
			case '3': menu3();
				break;
			case '4': menu4();
				break;
			case '5': menu5();
				break;
			case '6': menu6();
				break;
			case 'f': menuF();
				break;
			case 'o': menuO();
				break;
			case 'e': return 0;
		}
	}
	cout << endl;
	pause();
	return 0;
}

void menu1(void)//��������� ������� �������
{
	char szNameFile[255];
	cout << "������� ��� �����: ";
	cin >> szNameFile;
	szMs sizMas = masSizeF(szNameFile);
	cout << sizMas.height << " " << sizMas.width << endl;
	pauseCls();
}
void menu2(void)//��������� ������� �� �����
{
	char szNameFile[255], fileNameMass[255];
	cout << "������� ���� �������: ";
	cin >>szNameFile;
	cout << "������� �������� ����� � �������: ";
	cin >> fileNameMass;
	printMass(szNameFile, fileNameMass);
	pauseCls();
}
void menu3(void)//��������� ����������� �������.
{
	cout << "������� ��� ����� � �������� �������: ";
	char nameFile[255];
	cin >> nameFile;
	editSizeF(nameFile);
	pauseCls();
}
void menu4(void)//���������� ������� ���������� �������
{
	FillingMassRand();
	pauseCls();
}
void menu5(void)//���������� �� �������
{
	FillingMassManual();
	pauseCls();
}
void menu6(void)//�������� � ���������� � �������.
{
	testMass();
	pauseCls();
}
void menuF(void)//���������� �� ���� �����.
{
	fulScrean();
}

void menuO(void)//��������� ����� ���� � ������.
{
	cout << "�������� ������:\n";
	cout << " 0 = ������ 8 = �����" << endl;
 	cout << " 1 = ����� 9 = ������-�����" << endl;
 	cout << " 2 = ������� A = ������-�������" << endl;
 	cout << " 3 = ������� B = ������-�������" << endl;
 	cout << " 4 = ������� C = ������-�������" << endl;
 	cout << " 5 = ������� D = ������-�������" << endl;
 	cout << " 6 = ������ E = ������-������" << endl;
 	cout << " 7 = ����� F = ����-�����" << endl;
	cout << "������� �������� ����� ���� ";
	string colorFont, colorBackGraund;
	cin >> colorBackGraund;
	cout << "������� �������� ����� ������ ";
	cin >> colorFont;
	WindowColor(colorFont, colorBackGraund);
	cout << "��������� ���������. " << endl;
	pauseCls();
}
