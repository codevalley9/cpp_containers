#include "s21_tests.h"

TEST(ArrayTest, EqualityOfArrays) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  std::array<int, 3> std_array = {1, 2, 3};
  s21_array[0] = 8;
  std_array[0] = 8;

  ASSERT_EQ(true, s21_array.at(0) == std_array.at(0));
  ASSERT_EQ(true, s21_array.at(1) == std_array.at(1));
  ASSERT_EQ(true, s21_array.at(2) == std_array.at(2));
}

TEST(ArrayTest, ArrayInequality) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  std::array<int, 3> std_array = {1, 2, 3};

  s21_array.at(2) = 1;
  std_array.at(2) = 6;

  ASSERT_EQ(true, s21_array.at(0) == std_array.at(0));
  ASSERT_EQ(true, s21_array.at(1) == std_array.at(1));
  ASSERT_EQ(false, s21_array.at(2) == std_array.at(2));
}

TEST(ArrayTest, ArraySwap) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  s21::Array<int, 3> s21_array1 = {3, 2, 1};
  s21_array.swap(s21_array1);

  std::array<int, 3> std_array = {1, 2, 3};
  std::array<int, 3> std_array1 = {3, 2, 1};
  std_array.swap(std_array1);

  ASSERT_EQ(true, s21_array.at(0) == std_array.at(0));
  ASSERT_EQ(true, s21_array.at(1) == std_array.at(1));
  ASSERT_EQ(true, s21_array.at(2) == std_array.at(2));

  ASSERT_EQ(true, s21_array1.at(0) == std_array1.at(0));
  ASSERT_EQ(true, s21_array1.at(1) == std_array1.at(1));
  ASSERT_EQ(true, s21_array1.at(2) == std_array1.at(2));
}

TEST(ArrayTest, ArrayFill) {
  s21::Array<int, 3> s21_array;
  s21_array.fill(12);

  std::array<int, 3> std_array;
  std_array.fill(12);

  ASSERT_EQ(true, s21_array.at(0) == std_array.at(0));
  ASSERT_EQ(true, s21_array.at(1) == std_array.at(1));
  ASSERT_EQ(true, s21_array.at(2) == std_array.at(2));
}

TEST(ArrayTest, ArraySizeAndMazSize) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  std::array<int, 3> std_array = {1, 2, 3};

  //    ASSERT_EQ(true, s21_array.size() == std_array.size());
  //    ASSERT_EQ(true, s21_array.max_size() == std_array.max_size());
  EXPECT_EQ(s21_array.size(), std_array.size());
  EXPECT_EQ(s21_array.max_size(), std_array.max_size());
}

TEST(ArrayTest, ArrayEqual) {
  s21::Array<int, 0> s21_array;

  ASSERT_EQ(true, s21_array.equal());
}

TEST(ArrayTest, ArrayFrontAndBack) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  std::array<int, 3> std_array = {1, 2, 3};

  ASSERT_EQ(true, s21_array.front() == std_array.front());
  ASSERT_EQ(true, s21_array.back() == std_array.back());
}