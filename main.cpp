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


//i - строки j - элементы строки
//szMs mSizeOp(void);

int main(void) 
{
	setlocale(LC_ALL, "Russian");
	szMs mSize;
	while(true)
	{
		char mn1 = 0;
		cout << "Выберите действие нажатием соответствующей клавиши: " << endl;
		cout << "1) Вывести значение из файла размерности.\n2) Вывести значения массива на экран.\n3) Изменение значений файла размерности." << endl;
		cout << "4) Заполнение массива случайными числами.\n5) Заполнение по формуле.\n6) Произвести вычисление вектора." << endl;
		cout << "o) опции.\nf) открыть во весь экран. \ne) Выход.";
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

void menu1(void)//Выведение размера массива
{
	char szNameFile[255];
	cout << "Введите имя файла: ";
	cin >> szNameFile;
	szMs sizMas = masSizeF(szNameFile);
	cout << sizMas.height << " " << sizMas.width << endl;
	pauseCls();
}
void menu2(void)//Выведение массива на экран
{
	char szNameFile[255], fileNameMass[255];
	cout << "Введите файл размера: ";
	cin >>szNameFile;
	cout << "Введите название файла с данными: ";
	cin >> fileNameMass;
	printMass(szNameFile, fileNameMass);
	pauseCls();
}
void menu3(void)//Изменение размерности массива.
{
	cout << "Введите имя файла с размером массива: ";
	char nameFile[255];
	cin >> nameFile;
	editSizeF(nameFile);
	pauseCls();
}
void menu4(void)//Заполнение массива случайными числами
{
	FillingMassRand();
	pauseCls();
}
void menu5(void)//Заполнение по формуле
{
	FillingMassManual();
	pauseCls();
}
void menu6(void)//Проверка У образности и рассчет.
{
	testMass();
	pauseCls();
}
void menuF(void)//Развернуть во весь экран.
{
	fulScrean();
}

void menuO(void)//Изменение цвета фона и текста.
{
	cout << "Варианты цветов:\n";
	cout << " 0 = Черный 8 = Серый" << endl;
 	cout << " 1 = Синий 9 = Светло-синий" << endl;
 	cout << " 2 = Зеленый A = Светло-зеленый" << endl;
 	cout << " 3 = голубой B = Светло-голубой" << endl;
 	cout << " 4 = Красный C = Светло-красный" << endl;
 	cout << " 5 = Лиловый D = Светло-лиловый" << endl;
 	cout << " 6 = Желтый E = Светло-желтый" << endl;
 	cout << " 7 = белый F = Ярко-белый" << endl;
	cout << "Введите значение цвета фона ";
	string colorFont, colorBackGraund;
	cin >> colorBackGraund;
	cout << "Введите значение цвета текста ";
	cin >> colorFont;
	WindowColor(colorFont, colorBackGraund);
	cout << "Изменения применены. " << endl;
	pauseCls();
}
