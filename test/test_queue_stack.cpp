#include "stack_and_queue.h"

#include <gtest.h>

TEST(Queue2Stacks, can_create_Queue)
{
    ASSERT_NO_THROW(Queue2Stacks<int> q);
}

TEST(Queue2Stacks, can_check_for_empty)
{
    Queue2Stacks<int> q;
    EXPECT_TRUE(q.isEmpty());
}

TEST(Queue2Stacks, can_check_for_full)
{
    Queue2Stacks<int> s;
    EXPECT_FALSE(s.isFull());
}

TEST(Queue2Stacks, can_get_size)
{
    Queue2Stacks<int> s;
    s.push(5);
    s.push(3);
    EXPECT_EQ(2, s.size());
}

TEST(Queue2Stacks, can_get_capacity)
{
    Queue2Stacks<int> s;
    EXPECT_EQ(4, s.getcapacity());
}

TEST(Queue2Stacks, can_push)
{
    Queue2Stacks<int> s;
    s.push(5);
    s.push(3);
    EXPECT_EQ(5, s.front());
}

TEST(Queue2Stacks, can_push_correct)
{
    Queue2Stacks<int> s;
    s.push(5);
    s.push(3);
    EXPECT_EQ(2, s.size());
}

TEST(mQueue2Stacks, can_pop)
{
    Queue2Stacks<int> s;
    s.push(5);
    s.push(3);
    s.pop();
    EXPECT_EQ(3, s.front());
}

TEST(Queue2Stacks, can_pop_correct)
{
    Queue2Stacks<int> s;
    s.push(5);
    s.push(3);
    s.pop();
    EXPECT_EQ(1, s.size());
}

TEST(Queue2Stacks, can_get_front)
{
    Queue2Stacks<int> qs;
    qs.push(10); qs.push(8);
    EXPECT_EQ(10, qs.front());
}

TEST(Queue2Stacks, can_get_back)
{
    Queue2Stacks<int> qs;
    qs.push(10); qs.push(8);
    EXPECT_EQ(8, qs.back());
}
