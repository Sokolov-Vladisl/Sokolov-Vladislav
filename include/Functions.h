#pragma once

#include "polinom.h"





int amount_of_monoms()
{
	int nm;
	cin >> nm;
	if (nm < 0) throw exception("������������� ����� ������� � ��������");
	else if (nm == 0)
	{
		while (true)
		{
			system("cls");
			cout << endl << endl << " ��� ������� ��� 0" << endl << endl << " �� ������� � ���� ������?";
			cout << endl << " (1) �� \n (2) ��� \n\n\n > ";
			int choice = 0;
			cin >> choice;
			if (choice == 1) return 0;
			else if (choice == 2)
			{
				cout << endl << endl << "���������� ������� � ��������: ";
				return amount_of_monoms();
			}

		}
		
	}
	return nm;
}


int cr_degree()
{
	int tmp;
	cin >> tmp;
	if (tmp < 0 || tmp>99) throw exception("��������� ������: ������� ��� ���������  0 - 99");
	return tmp;
}

void show_monom(double tmp_dbl,int tmp_xyz)
{
	if (tmp_dbl == 0) cout << "0";
	else
	{
		if (tmp_xyz == 0) cout << tmp_dbl;  // 0

		else if (((tmp_xyz - tmp_xyz % 10000) / 10000) && ((tmp_xyz % 10000 - tmp_xyz % 100) / 100) && (tmp_xyz % 100)) //  x  y  z
		{
			cout << tmp_dbl << "*x^" << (tmp_xyz - tmp_xyz % 10000) / 10000 << "y^" << (tmp_xyz % 10000 - tmp_xyz % 100) / 100 << "z^" << tmp_xyz % 100;
		}

		else if (((tmp_xyz - tmp_xyz % 10000) / 10000) && ((tmp_xyz % 10000 - tmp_xyz % 100) / 100) && !(tmp_xyz % 100))//  x  y
		{
			cout << tmp_dbl << "*x^" << (tmp_xyz - tmp_xyz % 10000) / 10000 << "y^" << (tmp_xyz % 10000 - tmp_xyz % 100) / 100;
		}

		else if (((tmp_xyz - tmp_xyz % 10000) / 10000) && !((tmp_xyz % 10000 - tmp_xyz % 100) / 100) && (tmp_xyz % 100))//  x  z
		{
			cout << tmp_dbl << "*x^" << (tmp_xyz - tmp_xyz % 10000) / 10000 << "z^" << tmp_xyz % 100;
		}

		else if (!((tmp_xyz - tmp_xyz % 10000) / 10000) && ((tmp_xyz % 10000 - tmp_xyz % 100) / 100) && (tmp_xyz % 100))//  y  z
		{
			cout << tmp_dbl  << "y^" << (tmp_xyz % 10000 - tmp_xyz % 100) / 100 << "z^" << tmp_xyz % 100;
		}

		else if (((tmp_xyz - tmp_xyz % 10000) / 10000) && !((tmp_xyz % 10000 - tmp_xyz % 100) / 100) && !(tmp_xyz % 100))//  x
		{
			cout << tmp_dbl << "*x^" << (tmp_xyz - tmp_xyz % 10000) / 10000;
		}

		else if (!((tmp_xyz - tmp_xyz % 10000) / 10000) && ((tmp_xyz % 10000 - tmp_xyz % 100) / 100) && !(tmp_xyz % 100))//  y
		{
			cout << tmp_dbl << "y^" << (tmp_xyz % 10000 - tmp_xyz % 100) / 100;
		}

		else if (!((tmp_xyz - tmp_xyz % 10000) / 10000) && !((tmp_xyz % 10000 - tmp_xyz % 100) / 100) && (tmp_xyz % 100))// z
		{
			cout << tmp_dbl << "z^" << tmp_xyz % 100;
		}

	}
}


polinom create_polinom(int Nmon)
{

	system("cls");

	polinom P;
	double p_dbl=0.0;
	int xyz = -1;

	int tmp_degree = 0;

	for (int i = 0; i < Nmon; i++)
	{
		cout << endl <<"������ "<< i + 1 << "-� ����� �� " << Nmon <<"  ("<< i + 1<<"/"<< Nmon <<")"<< endl ;

		cout << "\n ������� ����������� :  ";
		cin >> p_dbl;

		cout << "\n ������� ������� ���������� � ������ (�� 0 �� 99) :";
		cout << "\nx^";
		xyz = cr_degree() *10000;

		cout << "\ny^";
		xyz += cr_degree() *100;

		cout << "\nz^";
		xyz += cr_degree();

		cout << endl <<i+1<< "-� �����:   " ;
		show_monom(p_dbl, xyz);
		cout << endl << endl;

		P.push(p_dbl, xyz);
	}

	return P;
}

void show_polinom(polinom P)
{
	system("cls");
	cout << "������� :    ";
	for (monom* it = P.head; it != nullptr; it = it->next)
	{
		show_monom(it->data, it->xyz);
		if (it->next != nullptr) cout << " + ";
	}
	cout << endl << endl;
}


void calculate(polinom P)
{

	double dbl1, dbl2, dbl3;

	double resultat = 0;

	system("cls");
	cout << endl << "������� �������� ����������:" << endl;
	cout << " x: "; cin >> dbl1; cout << endl;
	cout << " y: "; cin >> dbl2; cout << endl;
	cout << " z: "; cin >> dbl3; cout << endl;


	for (auto it = P.head; it != nullptr; it = it->next)
	{
		resultat += it->data * pow(dbl1, ((it->xyz) - (it->xyz) % 10000)/10000) * pow(dbl2, ((it->xyz) % 10000 - (it->xyz) % 100) / 100)*pow(dbl3, (it->xyz) % 100);
	}


	cout << endl << endl << "������� �����:  " << resultat << endl << endl;

	system("pause");
}



