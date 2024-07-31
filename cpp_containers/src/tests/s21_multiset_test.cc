#include "s21_tests.h"

template <typename Key>
bool EqualMultisets(s21::multiset<Key> &first, std::multiset<Key> &second) {
  if (first.size() != second.size()) {
    return false;
  }
  auto it1 = first.begin();
  auto it2 = second.begin();
  for (; it1 != first.end() && it2 != second.end(); ++it1, ++it2) {
    if ((*it1).first != (*it2)) {
      return false;
    }
  }
  return true;
}

TEST(Multiset, CompareMultisets) {
  std::multiset<int> std_ms = {0, 1, 2};
  s21::multiset<int> s21_ms = {0, 1, 2};
  bool result = EqualMultisets<int>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, DefaultInt) {
  std::multiset<int> std_ms;
  s21::multiset<int> s21_ms;
  ASSERT_EQ(s21_ms.size(), std_ms.size());
}

TEST(Multiset, ValueCtorInt) {
  std::multiset<int> std_ms = {0, 1, 2};
  s21::multiset<int> s21_ms = {0, 1, 2};
  bool result = EqualMultisets<int>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, ValueCtorString) {
  std::multiset<std::string> std_ms = {"zero", "one"};
  s21::multiset<std::string> s21_ms = {"zero", "one"};
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, CopyCtor) {
  std::multiset<std::string> std_ms = {"zero", "one"};
  s21::multiset<std::string> s21_ms = {"zero", "one"};

  std::multiset<std::string> std_s_copy(std_ms);
  s21::multiset<std::string> s21_s_copy(s21_ms);

  bool result = EqualMultisets<std::string>(s21_s_copy, std_s_copy);
  ASSERT_EQ(result, true);
}

TEST(Multiset, CopyCtor_2) {
  std::multiset<int> std_ms = {1, 100, 1000};
  s21::multiset<int> s21_ms = {1, 100, 1000};

  std::multiset<int> std_s_copy(std_ms);
  s21::multiset<int> s21_s_copy(s21_ms);

  bool result = EqualMultisets<int>(s21_s_copy, std_s_copy);
  ASSERT_EQ(result, true);
}

TEST(Multiset, CopyOper) {
  std::multiset<std::string> std_ms = {"zero", "one"};
  s21::multiset<std::string> s21_ms = {"zero", "one"};

  std::multiset<std::string> std_s_copy = std_ms;
  s21::multiset<std::string> s21_s_copy = s21_ms;

  bool result = EqualMultisets<std::string>(s21_s_copy, std_s_copy);
  ASSERT_EQ(result, true);
}

TEST(Multiset, MoveCtor) {
  std::multiset<std::string> std_ms = {"zero", "one"};
  s21::multiset<std::string> s21_ms = {"zero", "one"};

  std::multiset<std::string> std_s_copy(std::move(std_ms));
  s21::multiset<std::string> s21_s_copy(std::move(s21_ms));

  bool result = EqualMultisets<std::string>(s21_s_copy, std_s_copy);
  ASSERT_EQ(result, true);
}

TEST(Multiset, MoveOper) {
  std::multiset<std::string> std_ms = {"zero", "one"};
  s21::multiset<std::string> s21_ms = {"zero", "one"};

  std::multiset<std::string> std_s_copy = std::move(std_ms);
  s21::multiset<std::string> s21_s_copy = std::move(s21_ms);
  bool result = EqualMultisets<std::string>(s21_s_copy, std_s_copy);
  ASSERT_EQ(result, true);
}

TEST(Multiset, Begin) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};
  auto it_std = std_ms.begin();
  auto it_s21 = s21_ms.begin();
  ASSERT_EQ((*it_std), (*it_s21).first);
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, Empty) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};
  bool s21_res = std_ms.empty();
  bool std_res = s21_ms.empty();
  ASSERT_EQ(s21_res, std_res);
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, Empty_2) {
  std::multiset<std::string> std_ms = {"zero"};
  s21::multiset<std::string> s21_ms = {"zero"};
  bool s21_res = std_ms.empty();
  bool std_res = s21_ms.empty();
  ASSERT_EQ(s21_res, std_res);
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, Empty_3) {
  std::multiset<std::string> std_ms;
  s21::multiset<std::string> s21_ms;
  ASSERT_EQ(std_ms.empty(), s21_ms.empty());
}

TEST(Multiset, Size) {
  std::multiset<std::string> std_ms;
  s21::multiset<std::string> s21_ms;
  ASSERT_EQ(std_ms.size(), s21_ms.size());
}

TEST(Multiset, Size_2) {
  std::multiset<std::string> std_ms = {"zero"};
  s21::multiset<std::string> s21_ms = {"zero"};
  ASSERT_EQ(std_ms.size(), s21_ms.size());
}

TEST(Multiset, Size_3) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};
  size_t s21_res = std_ms.size();
  size_t std_res = s21_ms.size();
  ASSERT_EQ(s21_res, std_res);
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, Clear) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};
  std_ms.clear();
  s21_ms.clear();
  ASSERT_EQ(std_ms.size(), s21_ms.size());
  ASSERT_EQ(std_ms.empty(), s21_ms.empty());
}

TEST(Multiset, Insert_1) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};
  std_ms.insert("three");
  s21_ms.insert("three");
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, Insert_2) {
  std::multiset<std::string> std_ms = {"zero", "one", "zero"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "zero"};
  std_ms.insert("three");
  s21_ms.insert("three");
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, Erase) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};
  std_ms.erase(std_ms.begin());
  s21_ms.erase(s21_ms.begin());
  ASSERT_EQ(std_ms.size(), s21_ms.size());
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, Erase_2) {
  std::multiset<std::string> std_ms = {"zero"};
  s21::multiset<std::string> s21_ms = {"zero"};
  std_ms.erase(std_ms.begin());
  s21_ms.erase(s21_ms.begin());
  ASSERT_EQ(std_ms.size(), s21_ms.size());
  ASSERT_EQ(std_ms.empty(), s21_ms.empty());
}

TEST(Multiset, Erase_3) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};
  std_ms.erase(++(std_ms.begin()));
  s21_ms.erase(++(s21_ms.begin()));
  ASSERT_EQ(std_ms.size(), s21_ms.size());
  ASSERT_EQ(std_ms.empty(), s21_ms.empty());
}

TEST(Multiset, Swap) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};

  std::multiset<std::string> std_s_swap = {"null", "first", "second"};
  s21::multiset<std::string> s21_s_swap = {"null", "first", "second"};

  std_ms.swap(std_s_swap);
  s21_ms.swap(s21_s_swap);

  ASSERT_EQ(std_ms.size(), s21_ms.size());
  bool result = EqualMultisets<std::string>(s21_s_swap, std_s_swap);
  ASSERT_EQ(result, true);
  bool result2 = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result2, true);
}

TEST(Multiset, Merge) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};

  std::multiset<std::string> std_s_merge = {"null", "first", "second"};
  s21::multiset<std::string> s21_s_merge = {"null", "first", "second"};

  std_ms.merge(std_s_merge);
  s21_ms.merge(s21_s_merge);

  ASSERT_EQ(std_ms.size(), s21_ms.size());
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, Find) {
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};
  auto it = s21_ms.find("zero");
  ASSERT_EQ("zero", (*it).first);
}

TEST(Multiset, Contains) {
  s21::multiset<std::string> s21_ms = {"zero", "one", "two"};
  ASSERT_EQ(s21_ms.contains("zero"), true);
  ASSERT_EQ(s21_ms.contains("five"), false);
}

TEST(Multiset, Contains_2) {
  s21::multiset<std::string> s21_ms;
  ASSERT_EQ(s21_ms.contains("zero"), false);
}

TEST(Multiset, InsertMany) {
  std::multiset<std::string> std_ms = {"zero", "one", "two"};
  s21::multiset<std::string> s21_ms;
  s21_ms.insert_many("zero", "one", "two");
  ASSERT_EQ(std_ms.size(), s21_ms.size());
  bool result = EqualMultisets<std::string>(s21_ms, std_ms);
  ASSERT_EQ(result, true);
}

TEST(Multiset, TestLowerBound) {
  s21::multiset<int> my = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  auto lb1 = my.lower_bound(2);
  EXPECT_EQ((*lb1).first, 2);
  auto lb2 = my.lower_bound(5);
  EXPECT_EQ(lb2, my.end());
  auto lb3 = my.lower_bound(0);
  EXPECT_EQ(lb3, my.begin());
}

TEST(Multiset, TestUpperBound) {
  s21::multiset<int> my = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  auto lb1 = my.upper_bound(1);
  EXPECT_EQ((*lb1).first, 2);
  auto lb2 = my.upper_bound(5);
  EXPECT_EQ(lb2, my.end());
  auto lb3 = my.upper_bound(0);
  EXPECT_EQ(lb3, my.begin());
}

TEST(Multiset, TestEqualRange) {
  s21::multiset<int> myMultiset = {1, 2, 2, 3, 4, 4, 5};
  auto range1 = myMultiset.equal_range(2);
  EXPECT_EQ(range1.first, myMultiset.lower_bound(2));
  auto ub1 = myMultiset.upper_bound(2);
  EXPECT_EQ(range1.second, ub1);

  auto range2 = myMultiset.equal_range(4);
  EXPECT_EQ(range2.first, myMultiset.lower_bound(4));
  auto ub2 = myMultiset.upper_bound(4);
  EXPECT_EQ(range2.second, ub2);
}