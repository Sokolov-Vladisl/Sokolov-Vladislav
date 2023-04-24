#include "../include/Functions.h"



int main()
{

	setlocale(LC_ALL, "Russian");


	try
	{
		cout << "������� ���������� ������� � ��������:  ";
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

			cout << endl << endl << "       [����]" << endl;
			cout << " (1) �������� ���������" << endl;
			cout << " (2) �������� ���������" << endl;
			cout << " (3) ��������� ���������" << endl;
			cout << " (4) ��������� �� �����" << endl;
			cout << " (5) ��������� �������" << endl;
			cout << endl;
			cout << " (0) ��������� ���������" << endl;
			cout << endl;
			cout << " �����: ";

			int choice = -1;
			cin >> choice;

			if (choice == 0) flg = 0;

			if (choice == 1)
			{
				system("cls");
				cout << endl;
				cout << "������� ���������� ������� �� ������ ��������:  ";
				int n2 = amount_of_monoms();

				B = create_polinom(n2);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;

				show_polinom(A);
				cout << endl;
				show_polinom(B);

				cout << endl << endl << "��������� �������� ���� ���������:" << endl;

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
				cout << "������� ���������� ������� �� ������ ��������:  ";
				int n2 = amount_of_monoms();

				B = create_polinom(n2);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;

				show_polinom(A);
				cout << endl;
				show_polinom(B);

				cout << endl << endl << "��������� �������� ���� ���������:" << endl;

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
				cout << "������� ���������� ������� �� ������ ��������:  ";
				int n2 = amount_of_monoms();

				B = create_polinom(n2);

				cout << endl << endl << endl << endl;
				system("pause");
				cout << endl;

				show_polinom(A);
				cout << endl;
				show_polinom(B);

				cout << endl << endl << "��������� ��������� ���� ���������:" << endl;

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
				cout << endl << endl << "������� ����� �� ������� ���������� �������: ";
				cin >> number;
				cout << endl << endl << "��������� ��������� ����� �� ������� :" << endl;

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
		cout << endl << endl << "  <!> ������ <!>" << endl << " > " << error.what() << endl;
	}





}