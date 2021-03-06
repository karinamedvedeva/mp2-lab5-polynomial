#include "gtest.h"
#include "../mp2-lab5-polynomial/Tlist.h"

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(TList <int> list);
}

TEST(List, empty_list_return_true)
{
	TList <int> list;
	EXPECT_EQ(1, list.Empty());
}

TEST(List, can_check_that_list_is_empty)
{
	TList <int> list;
	ASSERT_NO_THROW(list.Empty());
}

TEST(List, can_check_that_list_is_not_empty)
{
	TList <int> list;
	list.InsFirst(1);
	ASSERT_NO_THROW(!list.Empty());
}

/*TEST(List, can_put_out_of_not_empty_list)
{
	TList<int>list;
	list.InsCurr(2);
	//ASSERT_NO_THROW(list.GetCurr());
	EXPECT_EQ(2, list.GetCurr());
}*/

TEST(List, cant_put_out_of_empty_stack)
{
	TList<int>list;
	ASSERT_ANY_THROW(list.GetCurr());
}

TEST(List, can_put_element_in_the_beginning_of_the_list)
{
	TList<int> list;
	ASSERT_NO_THROW(list.InsFirst(11));
	list.InsFirst(7);
	list.InsFirst(11);
	EXPECT_EQ(list.GetCurr(), 7);
}

TEST(List, can_put_element_in_the_end_of_the_list)
{
	TList<int> list;
	ASSERT_NO_THROW(list.InsLast(11));
	list.InsFirst(9);
	list.InsLast(11);
	EXPECT_EQ(list.GetCurr(), 11);
}

TEST(List, can_put_element_in_the_current_position_of_the_list)
{
	TList<int> list;
	ASSERT_NO_THROW(list.InsCurr(11));
	list.InsCurr(5);
	list.InsCurr(15);
	EXPECT_EQ(list.GetCurr(), 5);
}

TEST(List, can_delete_the_first_element_of_the_list)
{
	TList<int> list;
	list.InsFirst(7);
	list.InsFirst(11);
	ASSERT_NO_THROW(list.DelFirst());
}

/*TEST(List, can_delete_current_element_of_the_list)
{
	TList<int> list;
	list.InsCurr(5);
	list.InsLast(15);
	ASSERT_NO_THROW(list.DelCurr());
	//EXPECT_EQ(list.GetCurr(), 15);
}*/