#include "gtest.h"
#include "../mp2-lab5-polynomial/TPolinom.h"

TEST(Monom, can_creat_monom)
{
	ASSERT_NO_THROW(TMonom m);
}

TEST(Monom, can_define_larger_monom)
{
	TMonom m1, m2;
	ASSERT_NO_THROW(m1 > m2);
}

TEST(Monom, can_define_smaller_monom)
{
	TMonom m1, m2;
	ASSERT_NO_THROW(m1 < m2);
}

TEST(Monom, compare_equal_monoms_return_true)
{
	TMonom m1(1, 1, 2, 3);
	TMonom m2(1, 1, 2, 3);
	EXPECT_EQ(1, m1 == m2);
}

TEST(Monom, compare_monom_with_itself_return_true)
{
	TMonom m;
	EXPECT_EQ(1, m == m);
}

TEST(Monom, monoms_with_different_coefficientÛ_are_not_equal)
{
	TMonom m1(1, 2, 3, 4);
	TMonom m2(3, 2, 3, 4);
	EXPECT_EQ(0, m1 == m2);
}

TEST(Monom, monoms_with_different_powers_are_not_equal)
{
	TMonom m1(1, 2, 3, 4), m2(1, 1, 3, 4);
	EXPECT_EQ(0, m1 == m2);
	TMonom m3(1, 2, 3, 4), m4(1, 2, 7, 4);
	EXPECT_EQ(0, m3 == m4);
	TMonom m5(1, 2, 3, 4), m6(1, 2, 3, 1);
	EXPECT_EQ(0, m5 == m6);
}

TEST(Monom, can_multiply_monom_by_a_number)
{
	TMonom m1;
	ASSERT_NO_THROW(m1 * 11);
}

TEST(Monom, can_multiply_monom_by_the_other_monom)
{
	TMonom m1, m2;
	ASSERT_NO_THROW(m1 * m2);
}

TEST(Monom, can_assign_monoms)
{
	TMonom m1(1, 2, 3, 4), m2;
	ASSERT_NO_THROW(m2 = m1);
}

TEST(Polinom, can_create_polynomial)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(Polinom, can_assign_polynomials)
{
	TPolinom p1,p2;
	ASSERT_NO_THROW(p2 = p1);
}

TEST(Polinom, can_insert_monom_in_the_empty_polynomial)
{
	TPolinom p;
	TMonom m;
	ASSERT_NO_THROW(p.InsMonom(m));
}

TEST(Polinom, can_insert_monom_in_not_empty_polynomial)
{
	TPolinom p;
	TMonom m1(1, 1, 2, 3), m2;
	p.InsMonom(m1);
	ASSERT_NO_THROW(p.InsMonom(m2));
}

TEST(Polinom, can_add_polynomials)
{
	TPolinom p1, p2;
	ASSERT_NO_THROW(p1 += p2);
}

TEST(Polinom, can_add_not_empty_polynomials)
{
	TPolinom p1, p2;
	TMonom m1, m2;
	p1.InsMonom(m1);
	p2.InsMonom(m2);
	ASSERT_NO_THROW(p1 += p2);
}

TEST(Polinom, can_multiply_by_monom)
{
	TPolinom p;
	TMonom m;
	ASSERT_NO_THROW(p *= m);
}

TEST(Polinom, monoms_with_opposite_coefficients_are_removed)
{
	TPolinom p1, p2;
	TMonom m1(1,7,7,3), m2(1, 3, 5, 7), m3(-1, 3, 5, 7);
	p1.InsMonom(m1);
	p1.InsMonom(m2);
	p2.InsMonom(m3);
	p1 += p2;
	EXPECT_EQ(p1.GetSize(), 2);
}
