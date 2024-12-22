#include "stack_and_queue.h"

#include <gtest.h>

TEST(mQueue, can_create_Queue)
{
    ASSERT_NO_THROW(mQueue<int> q);
}

TEST(mQueue, can_check_for_empty)
{
    mQueue<int> q;
    EXPECT_TRUE(q.isEmpty());
}

TEST(mQueue, can_check_for_full)
{
    mQueue<int> s;
    EXPECT_FALSE(s.isFull());
}

TEST(mQueue, can_get_size)
{
    mQueue<int> s;
    s.push(5);
    s.push(3);
    EXPECT_EQ(2, s.size());
}

TEST(mQueue, can_get_capacity)
{
    mQueue<int> s;
    EXPECT_EQ(2, s.getcapacity());
}

TEST(mQueue, can_push)
{
    mQueue<int> s;
    s.push(5);
    s.push(3);
    EXPECT_EQ(3, s.getBack());
}

TEST(mQueue, can_push_correct)
{
    mQueue<int> s;
    s.push(5);
    s.push(3);
    EXPECT_EQ(2, s.size());
}

TEST(mQueue, can_pop)
{
    mQueue<int> s;
    s.push(5);
    s.push(3);
    s.pop();
    EXPECT_EQ(3, s.getBack());
}

TEST(mQueue, can_pop_correct)
{
    mQueue<int> s;
    s.push(5);
    s.push(3);
    s.pop();
    EXPECT_EQ(1, s.size());
}

TEST(mQueue, throws_when_pop_empty_Queue)
{
    mQueue<int> s;
    ASSERT_ANY_THROW(s.pop());
}


TEST(mQueue, can_get_back_element)
{
    mQueue<int> s;
    s.push(10); s.push(8);
    EXPECT_EQ(8, s.getBack());
}

TEST(mQueue, can_get_front)
{
    mQueue<int> q;
    q.push(10);
    q.push(8);
    EXPECT_EQ(10, q.getFront());
}

TEST(Queue, can_fill_correctly)
{
    mQueue<int> q;
    q.push(8); q.push(10);
    q.pop();
    q.push(14);
    EXPECT_EQ(0, q.getBackIndex());
}