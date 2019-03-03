#include "func.hpp"
#include "sys.hpp"
#include "mtm.hpp"


using namespace std;


/*=========================================================
//Работа с файлами при помощи потока ввода и вывода
=========================================================*/

//Открытие файла с размерами массива
szMs masSizeF(char *szNameFl)
{
	szMs szMass;
	ifstream fileSize(szNameFl);
	if (!fileSize.is_open())
	{
		cout << "Данный файл не может быть открыт!" << endl;
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

//Заполнение массива случайными числами из диапазона
void FillingMassRand(void)
{
	char NameFlSize[255];
	cout << "Введите имя файла содержащее размер массива: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	
	char NameFl[255];
	cout << "Введите имя файла массива: ";
	cin >> NameFl;
	cout << "Введите максимальное, а затем минимальное значение элементов: ";
	int rMax = 0, rMin = 0;
	cin >> rMax >> rMin;
	ofstream FMass(NameFl);
	if(!FMass.is_open())
	{
		cout << "Данный фаил невозможно открыть для записи!" << endl;
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
	cout << "Фаил создан." << endl;
	FMass.close();
}


//Ручное заполнение массива
void FillingMassManual(void)
{
	char NameFlSize[255];
	cout << "Введите имя файла содержащее размер массива: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	char NameFl[255];
	cout << "Введите имя файла массива: ";
	cin >> NameFl;
	ofstream FMass(NameFl);
	if(!FMass.is_open())
	{
		cout << "Данный фаил невозможно открыть для записи!" << endl;
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
	cout << endl << "Создание файла завершено." << endl;
	FMass.close();
}


//редактирование файла size
void editSizeF(char *szNameFl)
{
	ofstream FileSize(szNameFl);
	if(!FileSize.is_open())
	{
		cout << "Невозможно открыть данный файл!" << endl;
		system("pause");
		exit(-1);
	}
	else
	{
		cout << "Введите ширину массива: ";
		int h = 0, w = 0;
		cin >> h;
		FileSize << h << "\t";
		cout << "Введите высоту массива: ";
		cin >> w;
		FileSize << w;
		cout << "Файл удачно отредактирован.";
		FileSize.close();
	}
}


//печать массива
void printMass(char *szNameFl, char *massNameFl)
{
	szMs massSize = masSizeF(szNameFl);
	ifstream fileMass(massNameFl);
	if(!fileMass.is_open())
	{
		cout << "Данный файл не возможно открыть!" << endl;
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


