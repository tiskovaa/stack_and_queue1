#include "stack_and_queue.h"

#include <gtest.h>

TEST(mStack, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(mVector<int> v(5));
}

TEST(mStack, can_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(mVector<int> v(-5));
}

TEST(mVector, can_create_vector_from_arr)
{
    int* arr = new int[3] {8, 10, 12};
    mVector<int> v(arr, 5);
    int flag = 0;
    for (size_t i = 0; i < 3; i++)
        if (v[i] != arr[i])
            flag = 1;
    delete[] arr;
    EXPECT_EQ(0, flag);
}

TEST(mVector, can_create_copied_vector)
{
    mVector<int> v(10);
    ASSERT_NO_THROW(mVector<int> v1(v));
}

TEST(mVector, copied_vector_is_equal_to_source_one)
{
    mVector<int> v(10);
    v[0] = 1;
    mVector<int> vcpy(v);

    EXPECT_EQ(v, vcpy);
}

TEST(mVector, copied_vector_has_its_own_memory)
{
    mVector<int> v(10);
    mVector<int> vcpy(v);

    EXPECT_NE(&v, &vcpy);
}

TEST(mVector, can_get_size)
{
    mVector<int> v(4);
    EXPECT_EQ(4, v.size());
}

TEST(mVector, can_get_size_1)
{
    mVector<int> v;
    EXPECT_EQ(0, v.size());
}

TEST(mVector, can_get_capacity)
{
    mVector<int> v;
    EXPECT_EQ(2, v.getcapacity());
}

TEST(mVector, can_get_capacity_1)
{
    mVector<int> v(3);
    EXPECT_EQ(3 * 2 + 2, v.getcapacity());
}

TEST(mVector, can_set_and_get_element)
{
    mVector<int> v(3);
    v[0] = 5;
    EXPECT_EQ(5, v[0]);
}

TEST(mVector, can_assign_vector_to_itself)
{
    mVector<int> v(10);
    v[0] = 1;
    mVector<int> vcpy(v);
    v = v;
    EXPECT_EQ(v, vcpy);
}

TEST(mVector, can_assign_vectors_of_equal_size)
{
    mVector<int> v1(10);
    mVector<int> v2(10);
    v2[0] = 3;
    v1 = v2;
    EXPECT_EQ(v1, v2);
}

TEST(mVector, assign_operator_change_vector_size)
{
    mVector<int> v1(10);
    mVector<int> v2(5);
    v1 = v2;
    EXPECT_EQ(5, v1.size());
}

TEST(mVector, can_assign_vectors_of_different_size)
{
    mVector<int> v1(10);
    mVector<int> v2(5);
    v2[4] = 8;
    v1 = v2;
    EXPECT_EQ(v1, v2);
}

TEST(mVector, compare_equal_vectors_return_true)
{
    int* arr1 = new int[3] {1, 2, 3};
    mVector<int> v1(arr1, 3);
    delete[] arr1;
    int* arr2 = new int[3] {1, 2, 3};
    mVector<int> v2(arr2, 3);
    delete[] arr2;
    EXPECT_TRUE(v1 == v2);
}

TEST(mVector, compare_vector_with_itself_return_true)
{
    mVector<int> v(10);
    v[3] = 8;
    EXPECT_TRUE(v == v);
}

TEST(mVector, vectors_with_different_size_are_not_equal)
{
    mVector<int> v1(10);
    mVector<int> v2(5);
    EXPECT_FALSE(v1 == v2);
}

TEST(mVector, can_check_for_full)
{
    mVector<int> v;
    EXPECT_FALSE(v.isFull());
}

TEST(mVector, can_check_for_empty)
{
    mVector<int> v;
    EXPECT_TRUE(v.isEmpty());
}

TEST(mVector, can_push_back_elem)
{
    int* arr = new int[3] {1, 2, 3};
    mVector<int> v1(arr, 3);
    delete[] arr;
    int* arr_check = new int[4] {1, 2, 3, 4};
    mVector<int> v2(arr_check, 4);
    delete[] arr_check;
    v1.push_back(4);
    EXPECT_EQ(v1, v2);
}

TEST(mVector, can_push_front_elem)
{
    int* arr = new int[3] {8, 10, 12};
    mVector<int> v1(arr, 3);
    delete[] arr;
    int* arr_check = new int[4] {14, 8, 10, 12};
    mVector<int> v2(arr_check, 4);
    delete[] arr_check;
    v1.push_front(14);
    EXPECT_EQ(v1, v2);
}

TEST(mVector, can_pop_back_elem)
{
    int* arr = new int[5] {1, 2, 3, 4, 5};
    mVector<int> v1(arr, 5);
    delete[] arr;
    int* arr_check = new int[4] {1, 2, 3, 4};
    mVector<int> v2(arr_check, 4);
    delete[] arr_check;
    v1.pop_back();
    EXPECT_EQ(v1, v2);
}

TEST(mVector, throws_when_pop_back_elem_from_empty_vector)
{
    mVector<int> v;
    ASSERT_ANY_THROW(v.pop_back());
}

TEST(mVector, can_pop_front_elem)
{
    int* arr = new int[3] {8, 10, 12};
    mVector<int> v1(arr, 3);
    delete[] arr;
    int* arr_check = new int[2] {10, 12};
    mVector<int> v2(arr_check, 2);
    delete[] arr_check;
    v1.pop_front();
    EXPECT_EQ(v1, v2);
}

TEST(mVector, throws_when_pop_front_elem_from_empty_vector)
{
    mVector<int> v;
    ASSERT_ANY_THROW(v.pop_front());
}

TEST(mVector, can_insert_elem)
{
    int* arr = new int[3] {1, 2, 4};
    mVector<int> v1(arr, 3);
    delete[] arr;
    int* arr_check = new int[4] {1, 2, 3, 4};
    mVector<int> v2(arr_check, 4);
    delete[] arr_check;
    v1.insert(3, 2);
    EXPECT_EQ(v1, v2);
}

TEST(mVector, can_erase_elem)
{
    int* arr = new int[3] {1, 2, 3};
    mVector<int> v1(arr, 3);
    delete[] arr;
    int* arr_check = new int[2] {1, 3};
    mVector<int> v2(arr_check, 2);
    delete[] arr_check;
    v1.erase(1);
    EXPECT_EQ(v1, v2);
}

TEST(mVector, throws_when_erase_elem_from_empty_vector)
{
    mVector<int> v;
    ASSERT_ANY_THROW(v.erase(0));
}