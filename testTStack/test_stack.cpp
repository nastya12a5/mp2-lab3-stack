#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "../mp2-lab3-stack/TStack.h"
#include "../mp2-lab3-stack/TCalculator.h"
#include "gtest.h"



TEST(TStack, can_create_stack_with_positive_size)
{
    ASSERT_NO_THROW(Tstack<int> st(3));
}
TEST(TStack, cant_create_stack_with_negative_size)
{
    ASSERT_ANY_THROW(Tstack<int> st(-12));
}

TEST(TStack, can_get_length)
{
    Tstack<int> st(3);


    EXPECT_EQ(-1, st.GetCurrInd());
}


TEST(TStack, new_stack_is_empty)
{
    Tstack<int> st(3);

    int sost = st.Empty();

    EXPECT_EQ(1, sost);
}

TEST(TStack, can_push)
{
    Tstack<int> st(5);
    int a1 = 4;
    int a2 = 2;
    int a3 = 3;
    int a4 = 5;
    int a5 = 6;
    ASSERT_NO_THROW(st.Push(a1));
    ASSERT_NO_THROW(st.Push(a2));
    ASSERT_NO_THROW(st.Push(a3));
    ASSERT_NO_THROW(st.Push(a4));
    ASSERT_NO_THROW(st.Push(a5));
}
TEST(TStack, cat_pop)
{
    Tstack<int> st(5);
    int a1 = 4;
    int a2 = 2;
    int a3 = 3;
    int a4 = 5;
    int a5 = 6;
    ASSERT_NO_THROW(st.Push(a1));
    ASSERT_NO_THROW(st.Push(a2));
    ASSERT_NO_THROW(st.Push(a3));
    ASSERT_NO_THROW(st.Push(a4));
    ASSERT_NO_THROW(st.Push(a5));
    int c1, c2, c3, c4, c5;
    ASSERT_NO_THROW(c1 = st.Pop());
    ASSERT_NO_THROW(c2 = st.Pop());
    ASSERT_NO_THROW(c3 = st.Pop());
    ASSERT_NO_THROW(c4 = st.Pop());
    ASSERT_NO_THROW(c5 = st.Pop());
}
TEST(TStack, can_push_and_pop)
{
    Tstack<int> st(5);
    int a1 = 4;
    int a2 = 2;
    int a3 = 3;
    int a4 = 5;
    int a5 = 6;
    ASSERT_NO_THROW(st.Push(a1));
    ASSERT_NO_THROW(st.Push(a2));
    ASSERT_NO_THROW(st.Push(a3));
    ASSERT_NO_THROW(st.Push(a4));
    ASSERT_NO_THROW(st.Push(a5));
    int c1, c2, c3,c4,c5;
    ASSERT_NO_THROW(c1 = st.Pop());
    ASSERT_NO_THROW(c2 = st.Pop());
    ASSERT_NO_THROW(c3 = st.Pop());
    ASSERT_NO_THROW(c4 = st.Pop());
    ASSERT_NO_THROW(c5 = st.Pop());
    EXPECT_EQ(a1, c5);
    EXPECT_EQ(a2, c4);
    EXPECT_EQ(a3, c3);
    EXPECT_EQ(a4, c2);
    EXPECT_EQ(a5, c1);

}
TEST(TStack, cant_pop_on_empty_stack)
{
    Tstack<int> st(3);
    ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, cant_push_on_overflow_stack)
{
    Tstack<int> st(3);
    st.Push(1);
    st.Push(1);
    st.Push(1);
    ASSERT_ANY_THROW(st.Push(1));
}

TEST(TStack, cant_use_First_el_on_empty_stack)
{
    Tstack<int> st(3);

    ASSERT_ANY_THROW(st.First_el());
}

TEST(TStack, return_true_for_using_Full_on_full_stack)
{
    Tstack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    EXPECT_EQ(st.Full(), true);
}
TEST(TStack, return_false_for_using_Full_on_not_full_stack)
{
    Tstack<int> st(3);
    st.Push(1);
    st.Push(2);
    EXPECT_EQ(st.Full(), false);
}
TEST(TStack, return_true_for_using_Empty_on_empty_stack)
{
    Tstack<int> st(3);
    EXPECT_EQ(st.Empty(), true);
}
TEST(TStack, return_false_for_using_Empty_on_not_empty_stack)
{
    Tstack<int> st(3);
    st.Push(1);
    st.Push(1);
    EXPECT_EQ(false, st.Empty());
}
