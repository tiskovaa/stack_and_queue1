#include "stack_and_queue.h"

#include <gtest.h>

TEST(mStack, can_create_stack)
{
    ASSERT_NO_THROW(mStack<int> s);
}

TEST(mStack, can_check_for_empty)
{
    mStack<int> s;
    EXPECT_TRUE(s.isEmpty());
}

TEST(mStack, can_check_for_full)
{
    mStack<int> s;
    EXPECT_FALSE(s.isFull());
}

TEST(mStack, can_get_size)
{
    mStack<int> s;
    s.push(5);
    s.push(3);
    EXPECT_EQ(2, s.size());
}

TEST(mStack, can_get_capacity)
{
    mStack<int> s;
    EXPECT_EQ(2, s.getcapacity());
}

TEST(mStack, can_push)
{
    mStack<int> s;
    s.push(5);
    s.push(3);
    EXPECT_EQ(3, s.top());
}

TEST(mStack, can_push_correct)
{
    mStack<int> s;
    s.push(5);
    s.push(3);
    EXPECT_EQ(2, s.size());
}

TEST(mStack, can_pop)
{
    mStack<int> s;
    s.push(5);
    s.push(3);
    s.pop();
    EXPECT_EQ(5, s.top());
}

TEST(mStack, can_pop_correct)
{
    mStack<int> s;
    s.push(5);
    s.push(3);
    s.pop();
    EXPECT_EQ(1, s.size());
}

TEST(mStack, throws_when_pop_empty_stack)
{
    mStack<int> s;
    ASSERT_ANY_THROW(s.pop());
}

TEST(mStack, throws_when_take_top_elem_empty_stack)
{
    mStack<int> s;
    ASSERT_ANY_THROW(s.top());
}

TEST(mStack, can_get_top_element)
{
    mStack<int> s;
    s.push(10); s.push(8);
    EXPECT_EQ(8, s.top());
}