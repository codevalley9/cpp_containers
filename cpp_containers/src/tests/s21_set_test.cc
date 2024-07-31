#include "s21_tests.h"

TEST(SetTest, DefaultConstructor) {
  s21::set<int> s;
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(s.size(), 0);
}

TEST(SetTest, InitializerListConstructor) {
  s21::set<int> s{1, 2, 3, 4};
  auto it = s.find(1);
  EXPECT_FALSE(s.empty());
  EXPECT_EQ(s.size(), 4);
  EXPECT_EQ((*it).first, 1);
}

TEST(SetTest, CopyConstructor) {
  s21::set<int> original{1, 2, 3};
  s21::set<int> copy(original);
  EXPECT_EQ(copy.size(), 3);
  EXPECT_EQ((*copy.find(2)).first, 2);
}

TEST(SetTest, MoveConstructor) {
  s21::set<int> original{1, 2, 3};
  s21::set<int> moved(std::move(original));
  EXPECT_EQ(moved.size(), 3);
  EXPECT_TRUE(original.empty());
}

TEST(SetTest, Insert) {
  s21::set<int> s;
  auto [it, success] = s.insert(42);
  EXPECT_TRUE(success);
  EXPECT_EQ((*it).second, 42);
  EXPECT_EQ(s.size(), 1);

  auto [it2, success2] = s.insert(42);
  EXPECT_FALSE(success2);
  EXPECT_EQ(s.size(), 1);
}

TEST(SetTest, Erase) {
  s21::set<int> s{1, 2, 3};
  auto it = s.find(2);
  s.erase(it);
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s.find(2), s.end());
}

TEST(SetTest, Erase_1) {
  s21::set<int> set1 = {1, 2, 3};
  auto it = set1.find(2);
  set1.erase(it);
  EXPECT_EQ(set1.contains(2), 0);
}

TEST(SetTest, Merge) {
  s21::set<int> s1{1, 2, 3};
  s21::set<int> s2{3, 4, 5};
  s1.merge(s2);
  EXPECT_EQ(s1.size(), 5);
  EXPECT_EQ(s2.size(), 1);
  EXPECT_TRUE(s1.contains(4));
  EXPECT_TRUE(s2.contains(3));
}

TEST(SetTest, Swap) {
  s21::set<int> s1{1, 2, 3};
  s21::set<int> s2{4, 5, 6};
  s1.swap(s2);
  EXPECT_EQ(s1.size(), 3);
  EXPECT_EQ((*s1.find(4)).first, 4);
  EXPECT_EQ(s2.size(), 3);
  EXPECT_EQ((*s2.find(1)).first, 1);
}

TEST(SetTest, Clear) {
  s21::set<int> s{1, 2, 3};
  s.clear();
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(s.size(), 0);
}

TEST(SetTest, MergeEmptyTrees) {
  s21::set<int> s1;
  s21::set<int> s2;
  s1.merge(s2);
  EXPECT_TRUE(s1.empty());
  EXPECT_TRUE(s2.empty());
}

TEST(SetTest, MergeWithSelf) {
  s21::set<int> s1{1, 2, 3};
  s1.merge(s1);
  EXPECT_EQ(s1.size(), 3);
}

TEST(SetTest, ContainsMethod) {
  s21::set<int> s{1, 2, 3};
  EXPECT_TRUE(s.contains(2));
  EXPECT_FALSE(s.contains(4));
}

TEST(SetTest, MaxSizeMethod) {
  s21::set<int> s;
  EXPECT_GT(s.max_size(), 0);
}

TEST(SetTest, CopyAssignment) {
  s21::set<int> original{1, 2, 3};
  s21::set<int> copy;
  copy = original;
  EXPECT_EQ(copy.size(), 3);
  EXPECT_EQ((*copy.find(2)).first, 2);
}

TEST(SetTest, MoveAssignment) {
  s21::set<int> original{1, 2, 3};
  s21::set<int> moved;
  moved = std::move(original);
  EXPECT_EQ(moved.size(), 3);
  EXPECT_TRUE(original.empty());
}
TEST(SetTest, BeginEndIterators) {
  s21::set<int> s{1, 2, 3};
  auto it = s.begin();
  EXPECT_EQ(it.node_->value_, 1);
  ++it;
  EXPECT_EQ(it.node_->value_, 2);
  ++it;
  EXPECT_EQ(it.node_->value_, 3);
  ++it;
  EXPECT_EQ(it, s.end());
}

TEST(SetTest, MergeWithEmptySet) {
  s21::set<int> s1{1, 2, 3};
  s21::set<int> s2;
  s1.merge(s2);
  EXPECT_EQ(s1.size(), 3);
  EXPECT_TRUE(s2.empty());
}

TEST(SetTest, FindNonExistentElement) {
  s21::set<int> s{1, 2, 3};
  EXPECT_EQ(s.find(42), s.end());
}

TEST(Set, DefaultInt) {
  std::set<int> std_s;
  s21::set<int> s21_s;
  ASSERT_EQ(std_s.size(), s21_s.size());
}

TEST(Set, Empty) {
  std::set<std::string> std_s = {"zero", "one", "two"};
  s21::set<std::string> s21_s = {"zero", "one", "two"};
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Empty_2) {
  std::set<std::string> std_s = {"zero"};
  s21::set<std::string> s21_s = {"zero"};
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Empty_3) {
  std::set<std::string> std_s;
  s21::set<std::string> s21_s;
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Size) {
  std::set<std::string> std_s;
  s21::set<std::string> s21_s;
  size_t s21_res = std_s.size();
  size_t std_res = s21_s.size();
  ASSERT_EQ(s21_res, std_res);
}

TEST(Set, Clear) {
  std::set<std::string> std_s = {"zero", "one", "two"};
  s21::set<std::string> s21_s = {"zero", "one", "two"};
  std_s.clear();
  s21_s.clear();
  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase) {
  std::set<std::string> std_s = {"zero", "one", "two"};
  s21::set<std::string> s21_s = {"zero", "one", "two"};
  std_s.erase(std_s.begin());
  s21_s.erase(s21_s.begin());
  ASSERT_EQ(std_s.size(), s21_s.size());
}

TEST(Set, Erase_2) {
  std::set<std::string> std_s = {"zero"};
  s21::set<std::string> s21_s = {"zero"};
  std_s.erase(std_s.begin());
  s21_s.erase(s21_s.begin());
  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_3) {
  std::set<std::string> std_s = {"zero", "one", "two"};
  s21::set<std::string> s21_s = {"zero", "one", "two"};
  std_s.erase(++(std_s.begin()));
  s21_s.erase(++(s21_s.begin()));
  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_4) {
  std::set<int> std_s = {1, 5, 3, 4, 6, 7, 10, 11};
  s21::set<int> s21_s = {1, 5, 3, 4, 6, 7, 10, 11};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();
  ++it_std;
  ++it_s21;
  ++it_std;
  ++it_s21;
  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_5) {
  std::set<int> std_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  s21::set<int> s21_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();
  ++it_std;
  ++it_s21;

  ++it_std;
  ++it_s21;

  ++it_std;
  ++it_s21;

  ++it_std;
  ++it_s21;

  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_6) {
  std::set<int> std_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  s21::set<int> s21_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();
  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_7) {
  std::set<int> std_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  s21::set<int> s21_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();
  for (int i = 0; i < 2; i++) {
    ++it_s21;
    ++it_std;
  }

  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_8) {
  std::set<int> std_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  s21::set<int> s21_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();
  for (int i = 0; i < 7; i++) {
    ++it_s21;
    ++it_std;
  }

  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_9) {
  std::set<int> std_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  s21::set<int> s21_s = {20, 10, 25, 4,  16, 23, 30, 2,
                         5,  3,  11, 12, 14, 15, 17, 19};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();
  for (int i = 0; i < 5; i++) {
    ++it_s21;
    ++it_std;
  }

  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_10) {
  std::set<int> std_s = {0, 2, 56, 34, 11, 23, 1, 7, 5, 9, 10};
  s21::set<int> s21_s = {0, 2, 56, 34, 11, 23, 1, 7, 5, 9, 10};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();

  ++it_s21;
  ++it_std;

  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_11) {
  std::set<int> std_s = {1, 5, 13, 4, 0};
  s21::set<int> s21_s = {1, 5, 13, 4, 0};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();

  ++it_s21;
  ++it_std;

  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_12) {
  std::set<int> std_s = {40, 30, 50, 20, 35, 45, 60, 15, 25, 33, 43, 47, 65};
  s21::set<int> s21_s = {40, 30, 50, 20, 35, 45, 60, 15, 25, 33, 43, 47, 65};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  --it_s21;
  --it_std;

  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_13) {
  std::set<int> std_s = {40, 30, 50, 20, 35, 45, 60, 15, 25, 33, 43, 47, 65};
  s21::set<int> s21_s = {40, 30, 50, 20, 35, 45, 60, 15, 25, 33, 43, 47, 65};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  --it_s21;
  --it_std;

  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Erase_14) {
  std::set<int> std_s = {20, 10, 25, 4, 16, 23, 30, 2,
                         5,  14, 17, 3, 12, 15, 11, 19};
  s21::set<int> s21_s = {20, 10, 25, 4, 16, 23, 30, 2,
                         5,  14, 17, 3, 12, 15, 11, 19};
  auto it_std = std_s.begin();
  auto it_s21 = s21_s.begin();

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  ++it_s21;
  ++it_std;

  std_s.erase(it_std);
  s21_s.erase(it_s21);

  ASSERT_EQ(std_s.size(), s21_s.size());
  ASSERT_EQ(std_s.empty(), s21_s.empty());
}

TEST(Set, Find) {
  s21::set<std::string> s21_s = {"zero", "one", "two"};
  auto it = s21_s.find("zero");
  ASSERT_EQ("zero", (*it).first);
}

TEST(Set, Contains) {
  s21::set<std::string> s21_s = {"zero", "one", "two"};
  ASSERT_EQ(s21_s.contains("zero"), true);
  ASSERT_EQ(s21_s.contains("five"), false);
}

TEST(Set, Contains_2) {
  s21::set<std::string> s21_s;
  ASSERT_EQ(s21_s.contains("zero"), false);
}

TEST(Set, InsertMany) {
  std::set<std::string> std_s = {"zero", "one", "two"};
  s21::set<std::string> s21_s;
  s21_s.insert_many("zero", "one", "two");
  ASSERT_EQ(std_s.size(), s21_s.size());
}