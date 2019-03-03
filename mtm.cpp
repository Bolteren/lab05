#include "matem.hpp"
#include "func.hpp"
#include "sys.hpp"

using namespace std;

double funcshen(int i, int j)//���������� �� �������
{
	double tmp = 0.0;
	tmp = 3.7 - j;
	tmp = mdl(tmp);
	tmp = tmp - 2;
	tmp = tmp * (i - 4.3);
	tmp = tmp * pw(2, -i);
	return tmp;
}

int maxElem(int i, int j, double **mass)//����� ������������� ��������
{
	int maxstr = 0;
	int tmpMax = 0;
	for (int num = 0; num < j; num++)
	{
		tmpMax += mass[0][num];
	}
	
	for (int counter = 1; counter < i; counter++)
	{
		int tmp = 0;
		for(int num = 0; num < j; num++)
		{
			tmp += mass[counter][num];
		}
		if(tmpMax < tmp)
		{
			tmpMax = tmp;
			maxstr = counter;
		}
//		cout << "max " << tmpMax << " OK" << endl << "str " << maxstr << " OK" << endl;
	}
	return maxstr;
}

void testMass(void)//����� ������� ��������� ��� �� ����� � ������ ��� � ����
{
	char FlNmSiz[255];
	cout << "������� ��� ����� ���������� ������ �������: ";
	cin >> FlNmSiz;
	szMs MassSize = masSizeF(FlNmSiz);
	double **mass;
	mass = new double*[MassSize.height];
	for(int counter = 0; counter < MassSize.height; counter++)//�������� ������� ��������� ��������.
	{
		mass[counter] = new double[MassSize.width];
	}
	cout << "������� ��� ����� ����������� ������ �������: ";
	char NameFlMass[255];
	cin >> NameFlMass;
	ifstream fileMass(NameFlMass);
	if (!fileMass.is_open())
	{
		cout << "������ ���� �� ����� ���� ������!" << endl;
		system("pause");
		exit(-1);
	}
	else
	{
		for(int counter = 0; counter < MassSize.height; counter++)
		{
			for(int num = 0; num < MassSize.width; num++)
			{
				fileMass >> mass[counter][num];
			}
		}
		fileMass.close();
	}
	int numStr = maxElem(MassSize.height, MassSize.width, mass);
	double tmp1 = mass[numStr][0], temp = 0.0;
	cout << "�������������� ������ ��������� �� " << numStr + 1 << " ������ �������." << endl;
	cout << "������ ";
	for (int j = 0; j < MassSize.width; j++)
	{
		cout << mass[numStr][j] << " ";
	}
	cout << endl;

	for(int i = 0; i < MassSize.width - 1; i++)
	{
		for(int j = 0; j < MassSize.width - 1; j++)
		{
			double temp = 0;
			if(mass[numStr][j] < mass[numStr][j + 1])
			{
				temp = mass[numStr][j];
				mass[numStr][j] = mass[numStr][j + 1];
				mass[numStr][j + 1] = temp;
			}
		}
	}
	cout << "������ � : ";
	for(int counter = 0; counter < MassSize.width; counter ++)
	{
		cout << mass[numStr][counter] << " ";
	}
	char NameF1[255];
	cout << endl << "������� ��� ����� ��� ���������� ��������������� ������� �: ";
	cin >> NameF1;
	ofstream FileVector(NameF1);
	if(!FileVector.is_open())
	{
		cout << "���������� ������� ������ ����!" << endl;
		system("pause");
		exit(-1);
	}
	else
	{
		for(int counter = 0; counter < MassSize.width; counter++)
		{
			FileVector << mass[numStr][counter] << "\t";
		}
		cout << "������ ������ �������� � ���� " << NameF1 <<"." << endl;
		FileVector.close();
	}
	//=========================================================================
	for(int counter = 0; counter < MassSize.height; counter++)//������� ������.
	{
		delete[]mass[counter];
		mass[counter] = NULL;
	}
	delete[]mass;
	mass = NULL;
}
