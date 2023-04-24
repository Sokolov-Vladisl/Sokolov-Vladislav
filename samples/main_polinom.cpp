#include "../include/Functions.h"



int main()
{

	setlocale(LC_ALL, "Russian");


	try
	{
		cout << "Введите количество мономов в полиноме:  ";
		int n = amount_of_monoms();

		polinom A = create_polinom(n);
		polinom B;

		cout << endl << endl << endl << endl;
		system("pause");
		cout << endl;


		bool flg = true;

		while (flg)
		{



			show_polinom(A);

			cout << endl << endl << "       [Меню]" << endl;
			cout << " (1) Сложение полиномов" << endl;
			cout << " (2) Разность полиномов" << endl;
			cout << " (3) Умножение полиномов" << endl;
			cout << " (4) Умножение на число" << endl;
			cout << " (5) Посчитать полином" << endl;
			cout << endl;
			cout << " (0) Завершить программу" << endl;
			cout << endl;
			cout << " Выбор: ";

			int choice = -1;
			cin >> choice;

			if (choice == 0) flg = 0;

			if (choice == 1)
			{
				system("cls");
				cout << endl;
				cout << "Введите количество мономов во втором полиноме:  ";
				int n2 = amount_of_monoms();

				B = create_polinom(n2);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;

				show_polinom(A);
				cout << endl;
				show_polinom(B);

				cout << endl << endl << "Результат сложения двух полиномов:" << endl;

				A = A + B;

				show_polinom(A);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;

				B.clear();

			}

			if (choice == 2)
			{
				system("cls");
				cout << endl;
				cout << "Введите количество мономов во втором полиноме:  ";
				int n2 = amount_of_monoms();

				B = create_polinom(n2);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;

				show_polinom(A);
				cout << endl;
				show_polinom(B);

				cout << endl << endl << "Результат разности двух полиномов:" << endl;

				A = A - B;

				show_polinom(A);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;

				B.clear();
			}

			if (choice == 3)
			{
				system("cls");
				cout << endl;
				cout << "Введите количество мономов во втором полиноме:  ";
				int n2 = amount_of_monoms();

				B = create_polinom(n2);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;

				show_polinom(A);
				cout << endl;
				show_polinom(B);

				cout << endl << endl << "Результат умножения двух полиномов:" << endl;

				A = A * B;

				show_polinom(A);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;


				B.clear();
			}

			if (choice == 4)
			{
				double number = 0;
				cout << endl << endl << "Введите число на которое умножается полином: ";
				cin >> number;
				cout << endl << endl << "Результат умножения числа на полином :" << endl;

				A = A * number;

				show_polinom(A);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;
			}

			if (choice == 5)
			{
				calculate(A);
			}

			

		}

		A.clear();

		delete[] A.head;
		delete[] B.head;


	}
	catch (const exception error)
	{
		cout << endl << endl << "  <!> ОШИБКА <!>" << endl << " > " << error.what() << endl;
	}





}