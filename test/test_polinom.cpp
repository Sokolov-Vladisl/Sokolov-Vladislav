#include "../include/Functions.h"
#include "../gtest/gtest.h"


TEST(MONOM, can_be_created)
{
	monom* mon = new monom(12, 100);

	EXPECT_EQ(mon->data, 12);
	EXPECT_EQ(mon->xyz, 100);
}

TEST(POLINOM, can_be_created)
{
	EXPECT_NO_THROW(polinom A ;);
}

TEST(POLINOM, can_be_expansed)
{
	polinom A ;
	EXPECT_NO_THROW(A.push(1, 1););
	EXPECT_NO_THROW(A.push(2, 1););
	EXPECT_NO_THROW(A.push(3, 1););
	EXPECT_NO_THROW(A.push(4, 1););
	EXPECT_NO_THROW(A.push(5, 1););

}



TEST(POLINOM, merge)
{
	polinom A;
	A.push(1, 1);
	A.push(2, 1);
	A.push(3, 1);
	A.push(4, 1);
	A.push(5, 1);

	EXPECT_EQ(A.head->data, 15);
	EXPECT_EQ(A.head->xyz, 1);
}

TEST(POLINOM, operator_plus)
{
	polinom A;
	A.push(1, 1);
	A.push(2, 1);

	polinom B;
	B.push(3, 1);
	B.push(4, 1);
	B.push(5, 1);

	A = A + B;

	EXPECT_EQ(A.head->data, 15);
	EXPECT_EQ(A.head->xyz, 1);
}
TEST(POLINOM, operator_minus)
{
	polinom A;
	A.push(1, 1);
	A.push(2, 1);

	polinom B;
	B.push(3, 1);
	B.push(4, 1);
	B.push(5, 1);

	A = A - B;

	EXPECT_EQ(A.head->data, -9);
	EXPECT_EQ(A.head->xyz, 1);
}


TEST(POLINOM, operator_to)
{
	polinom A;
	A.push(1, 1);
	A.push(2, 1);

	polinom B;
	B.push(3, 1);
	B.push(4, 1);
	B.push(5, 1);

	A = A * B;

	EXPECT_EQ(A.head->data, 36);
	EXPECT_EQ(A.head->xyz, 2);
}

TEST(POLINOM, operator_to_but_its_number)
{
	polinom A;
	A.push(1, 1);
	A.push(2, 1);

	A = A * 7;

	EXPECT_EQ(A.head->data, 21);
	EXPECT_EQ(A.head->xyz, 1);
}

