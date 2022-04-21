/*
Обчислити кількість кожної з оцінок «5», «4», «3» з фізики
Обчислити кількість студентів, які отримали і з фізики і з математики оцінки «4» або «5»
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Specialty { KN, INF, ME, PI, TD };

string specialtyStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та екноміка", " Фізика та інформатика", "Трудове навчання" };

struct Student {
	char prizv[64];
	unsigned kurs;
	Specialty specialty;
	unsigned gradePhys;
	int gradeMath;
	union {
		unsigned gradeProg;
		unsigned gradeMetod;
		unsigned gradePed;
	};
};



void Create(const char* fName)
{
	ofstream f(fName, ios::binary);
	Student student;
	char ch;
	int specialty;
	do {

		cout << "Прізвище: ";
		cin >> student.prizv;
		cout << "Курс: "; cin >> student.kurs;
		cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та екноміка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialty;
		student.specialty = (Specialty)specialty;
		cout << "Оцінка з фізики: "; cin >> student.gradePhys;
		cout << "Оцінка з математики: "; cin >> student.gradeMath;
		switch (student.specialty) {
		case KN:
			cout << "Оцінка з програмування: "; cin >> student.gradeProg;
			break;
		case INF:
			cout << "Оцінка з чисельних методоів: "; cin >> student.gradeMetod;
			break;
		default:
			cout << "Оцінка педагогіки: "; cin >> student.gradePed;
			break;
		}

		cout << endl;
		if (!f.write((char*)&student, sizeof(Student))) {
			cerr << "Error writing file." << endl;
		}
		cout << "Continue?(Y/N)"; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}


void Print(const char* fName)
{
	cout << endl << "\nfile \"" << fName << "\":\n";
	cout << "==================================================================================================="
		<< endl;
	cout << "| № |  Прізвище  | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
		<< endl;
	cout << "==================================================================================================="
		<< endl;

	ifstream f(fName, ios::binary);
	Student student;
	int i = 1;
	while (f.read((char*)&student, sizeof(Student))) {
		cout << "| " << right << i++ << "  ";
		cout << "| " << setw(11) << left << student.prizv
			<< "|   " << setw(4) << right << student.kurs << "  "
			<< "| " << setw(18) << left << specialtyStr[student.specialty]
			<< "| " << setw(6) << right << student.gradePhys << " "
			<< "| " << setw(6) << right << student.gradeMath << " ";
		switch (student.specialty) {
		case KN:
			cout << "| " << setw(8) << fixed << right << student.gradeProg
				<< " |" << setw(12) << "|" << setw(12) << "|" << endl;
			break;
		case INF:
			cout << "|" << setw(11)
				<< "| " << right << fixed << setw(9) << student.gradeMetod << " |" << setw(12) << "|" << endl;
			break;
		default:
			cout << "|" << setw(11)
				<< "|" << setw(12) << "| " << setw(10) << student.gradePed << " |" << endl;
			break;
		}

	}
	cout << "===================================================================================================" << endl;
	cout << endl;
}



int physStat5(const char* fName) {
	ifstream f(fName, ios::binary);
	Student student;
	int fiveCount = 0;
	if (!f)
	{
		cerr << "Error writing file '" << fName << "'" << endl;
		return 0;
	}

	while (f.read((char*)&student, sizeof(Student))) {
		
		if (student.gradePhys == 5) {
			fiveCount++;
		}

	}
	return fiveCount;
}

int physStat4(const char* fName) {
	ifstream f(fName, ios::binary);
	Student student;
	int  fourCount = 0;
	if (!f)
	{
		cerr << "Error writing file '" << fName << "'" << endl;
		return 0;
	}
	while (f.read((char*)&student, sizeof(Student))) {
		
		if (student.gradePhys == 4) {
			fourCount++;
		}
	}
	return fourCount;
}

int physStat3(const char* fName) {
	ifstream f(fName, ios::binary);
	Student student;
	int  threeCount = 0;
	if (!f)
	{
		cerr << "Error writing file '" << fName << "'" << endl;
		return 0;
	}

	while (f.read((char*)&student, sizeof(Student))) {

		if (student.gradePhys == 3) {
			threeCount++;
		}
	}
	return threeCount;
}

int goodMathPhys(const char* fName) {


	ifstream f(fName, ios::binary);
	Student student;
	int n = 0;

	if (!f)
	{
		cerr << "Error writing file '" << fName << "'" << endl;
		return 0;
	}
	
	while (f.read((char*)&student, sizeof(Student))) {
		if ((student.gradeMath == 4 || student.gradeMath == 5) && (student.gradePhys == 4 || student.gradePhys == 5))
			n++;

	}
	return n;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char f[6] = "f.dat";

	int menuItem;

	do
	{
		cout << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - ввести дані у файл" << endl;
		cout << " [2] - вивести дані на екран" << endl;
		cout << " [3] - кількість кожної з оцінок «5», «4», «3» з математики" << endl;
		cout << " [4] - вивести прізвища студентів, які отримали і з фізики і з математики оцінку «5» " << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			Create(f);
			break;
		case 2:
		
			Print(f);
			break;
		case 3:
			cout << "Кількість 5 за фізику: " << physStat5(f) << endl;
			cout << "Кількість 4 за фізику: " << physStat4(f) << endl;
			cout << "Кількість 3 за фізику: " << physStat3(f) << endl;
			break;
		case 4:
			cout << "Кількість учнів 4 або 5 з фізики та метематики " << goodMathPhys(f) << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число  - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	
	system("pause");
	cin.get();
	return 0;
}