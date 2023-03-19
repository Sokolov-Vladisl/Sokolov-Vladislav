#include "../include/polinom.h"



void polinom::push(double data, int xyz)
{
	int flg = 1, flg2 = 1;
	if (head == nullptr)
	{
		push_start(data, xyz);
		flg = 0;
		flg2 = 0;
	}
	else if (head->xyz > xyz)
	{
		push_start(data, xyz);
		flg = 0;
		flg2 = 0;
	}
	else for (auto it = head; it != nullptr && flg2; it = it->next)
	{
		if (it->xyz == xyz)
		{
			push_add(data, it);
			flg = 0;
			flg2 = 0;
		}
		else if (it->next != nullptr && it->next->xyz > xyz)
		{
			push_between(data, xyz, it, it->next);
			flg = 0;
			flg2 = 0;
		}
		else if (flg && it->next == nullptr)
		{
			push_end(data, xyz, it);
			flg = 0;
			flg2 = 0;
		}
	}

}
void polinom::push_start(double data, int xyz)
{
	monom* mon = new monom(data, xyz, head);
	head = mon;
}
void polinom::push_between(double data, int xyz, monom* last, monom* next)
{
	monom* mon = new monom(data, xyz);
	last->next = mon;
	mon->next = next;
}
void polinom::push_end(double data, int xyz, monom* last)
{
	monom* mon = new monom(data, xyz);
	last->next = mon;
	mon->next = nullptr;
}
void polinom::push_add(double data, monom* itis)
{
	itis->data += data;
}


//----------------[ Перегрузка операций ]----------------------



polinom polinom::operator+(const polinom& second)
{
	polinom p_tmp;
	/*
	for (auto it = this->head; it != nullptr; it = it->next)
	{
		p_tmp.push(this->head->data, this->head->xyz);
	}
	for (auto it2 = second.head; it2 != nullptr; it2 = it2->next)
	{
		p_tmp.push(second.head->data, second.head->xyz);
	}
	*/
	auto it1 = head, it2 = second.head;
	while (it1 != nullptr || it2 != nullptr)
	{
		if (it1 == nullptr)
		{
			p_tmp.push(it2->data, it2->xyz);
			it2 = it2->next;
		}
		else if (it2 == nullptr)
		{
			p_tmp.push(it1->data, it1->xyz);
			it1 = it1->next;
		}
		else if (it1->xyz == it2->xyz)
		{
			p_tmp.push(it1->data+it2->data, it1->xyz);
			it1 = it1->next;
			it2 = it2->next;
		}
		else if (it1->xyz > it2->xyz)
		{
			p_tmp.push(it2->data, it2->xyz);
			it2 = it2->next;
		}
		else if (it2->xyz > it1->xyz)
		{
			p_tmp.push(it1->data, it1->xyz);
			it1 = it1->next;
		}
	}
	return p_tmp;
}

polinom polinom::operator-( polinom second)
{
	polinom p_tmp = second *-1.0;
	p_tmp = *this + p_tmp;
	return p_tmp;
}

polinom polinom::operator*(const polinom& second)
{
	polinom p_tmp;
	for (auto it = this->head; it != nullptr; it = it->next)
	{
		for (auto it2 = second.head; it2 != nullptr; it2 = it2->next)
		{
			p_tmp.push((it->data) * (it2->data), (it->xyz) + (it2->xyz));
			if ( ((it->xyz) % 100 + (it2->xyz) % 100) >= 100)
				throw exception("При умножении полиномов степень z в каком-то мономе стала больше 99");

			if((((it->xyz) - (it->xyz) % 10000) + ((it2->xyz) - (it2->xyz) % 10000)) / 10000 >= 100)
				throw exception("При умножении полиномов степень x в каком-то мономе стала больше 99");

			if((((it->xyz) % 10000 - (it->xyz) % 100) + ((it2->xyz) % 10000 - (it2->xyz) % 100)) / 100 >= 100)
				throw exception("При умножении полиномов степень y в каком-то мономе стала больше 99");




		}
	}
	return p_tmp;
}

polinom polinom::operator*(const double& var)
{
	polinom tmp;
	for (auto it = this->head; it != nullptr; it = it->next)
	{
		tmp.push(it->data * var, it->xyz);
	}
	return tmp;
}
