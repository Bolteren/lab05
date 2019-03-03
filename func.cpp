#include "func.hpp"
#include "sys.hpp"
#include "mtm.hpp"


using namespace std;


/*=========================================================
//������ � ������� ��� ������ ������ ����� � ������
=========================================================*/

//�������� ����� � ��������� �������
szMs masSizeF(char *szNameFl)
{
	szMs szMass;
	ifstream fileSize(szNameFl);
	if (!fileSize.is_open())
	{
		cout << "������ ���� �� ����� ���� ������!" << endl;
		system("pause");
		exit(-1);
	}
	else
	{
		fileSize >> szMass.height >> szMass.width;
		fileSize.close();
		return szMass;
	}
}

//���������� ������� ���������� ������� �� ���������
void FillingMassRand(void)
{
	char NameFlSize[255];
	cout << "������� ��� ����� ���������� ������ �������: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	
	char NameFl[255];
	cout << "������� ��� ����� �������: ";
	cin >> NameFl;
	cout << "������� ������������, � ����� ����������� �������� ���������: ";
	int rMax = 0, rMin = 0;
	cin >> rMax >> rMin;
	ofstream FMass(NameFl);
	if(!FMass.is_open())
	{
		cout << "������ ���� ���������� ������� ��� ������!" << endl;
		system("pause");
		exit(-1);
	}
	for(int counter = 0; counter < MassSize.height; counter ++)
	{
		for(int cntr = 0; cntr < MassSize.width; cntr++)
		{
			FMass << (rMin) + rand() % ((rMax + 1) - rMin)  << "\t";
		}
		FMass << endl;
	}
	cout << "���� ������." << endl;
	FMass.close();
}


//������ ���������� �������
void FillingMassManual(void)
{
	char NameFlSize[255];
	cout << "������� ��� ����� ���������� ������ �������: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	char NameFl[255];
	cout << "������� ��� ����� �������: ";
	cin >> NameFl;
	ofstream FMass(NameFl);
	if(!FMass.is_open())
	{
		cout << "������ ���� ���������� ������� ��� ������!" << endl;
		system("pause");
		exit(-1);
	}
	for(int counter = 0; counter < MassSize.height; counter ++)
	{
		for(int cntr = 0; cntr < MassSize.width; cntr++)
		{
			double temp;
			temp = funcshen(counter, cntr);
			cout << temp << " ";
			FMass << temp << "\t";
		}
		cout << endl;
		FMass << endl;
	}
	cout << endl << "�������� ����� ���������." << endl;
	FMass.close();
}


//�������������� ����� size
void editSizeF(char *szNameFl)
{
	ofstream FileSize(szNameFl);
	if(!FileSize.is_open())
	{
		cout << "���������� ������� ������ ����!" << endl;
		system("pause");
		exit(-1);
	}
	else
	{
		cout << "������� ������ �������: ";
		int h = 0, w = 0;
		cin >> h;
		FileSize << h << "\t";
		cout << "������� ������ �������: ";
		cin >> w;
		FileSize << w;
		cout << "���� ������ ��������������.";
		FileSize.close();
	}
}


//������ �������
void printMass(char *szNameFl, char *massNameFl)
{
	szMs massSize = masSizeF(szNameFl);
	ifstream fileMass(massNameFl);
	if(!fileMass.is_open())
	{
		cout << "������ ���� �� �������� �������!" << endl;
		system("pause");
		exit(-1);
	}
	else
	{
		for(int counter = 0; counter < massSize.height; counter++)
		{
			for(int num = 0; num < massSize.width; num++)
			{
				double a;
				fileMass >> a;
				cout << a << "\t";
			}
			cout << endl;
		}
		fileMass.close();
	}
}


