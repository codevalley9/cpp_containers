#include "s21_tests.h"

TEST(MapTest, EmptyMap) {
  s21::map<int, std::string> m;
  EXPECT_TRUE(m.empty());
  EXPECT_EQ(m.size(), 0);
}
TEST(MapTest, InsertSingleElement) {
  s21::map<int, std::string> m;
  m.insert(std::make_pair(1, "one"));
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.size(), 1);
  EXPECT_EQ(m[1], "one");
}

TEST(MapTest, InsertAndRetrieveMultipleElements) {
  s21::map<int, std::string> m;
  m.insert(std::make_pair(1, "one"));
  m.insert(std::make_pair(2, "two"));
  EXPECT_EQ(m.size(), 2);
  EXPECT_EQ(m[1], "one");
  EXPECT_EQ(m[2], "two");
}

TEST(MapTest, CopyConstructor) {
  s21::map<int, std::string> m1;
  m1[1] = "one";
  s21::map<int, std::string> m2(m1);
  EXPECT_EQ(m1[1], m2[1]);
}

TEST(MapTest, AtNonExistentKey) {
  s21::map<int, std::string> m;
  EXPECT_THROW(m.at(1), std::out_of_range);
}

TEST(MapTest, InsertOrAssign) {
  s21::map<int, std::string> m;
  m.insert_or_assign(1, "one");
  EXPECT_EQ(m[1], "one");
  m.insert_or_assign(1, "new_one");
  EXPECT_EQ(m[1], "new_one");
}

TEST(MapTest, MoveConstructor) {
  s21::map<int, std::string> m1;
  m1[1] = "one";
  s21::map<int, std::string> m2(std::move(m1));
  EXPECT_EQ(m2[1], "one");
  EXPECT_TRUE(m1.empty());
}

TEST(MapTest, SwapMaps) {
  s21::map<int, std::string> m1;
  m1[1] = "one";
  s21::map<int, std::string> m2;
  m2[2] = "two";
  m1.swap(m2);
  EXPECT_EQ(m1[2], "two");
  EXPECT_EQ(m2[1], "one");
}

TEST(MapTest, EraseElement) {
  s21::map<int, std::string> m;
  m.insert(std::make_pair(1, "one"));
  auto it = m.begin();
  m.erase(it);
  EXPECT_TRUE(m.empty());
  EXPECT_EQ(m.size(), 0);
}

TEST(MapTest, EraseElement_1) {
  s21::map<int, std::string> m;
  m.insert(std::make_pair(1, "one"));
  m.insert(std::make_pair(2, "two"));
  auto it = m.begin();
  m.erase(it);
  EXPECT_EQ(m.size(), 1);
  EXPECT_EQ(m[2], "two");
}

TEST(MapTest, End_Begin) {
  s21::map<int, std::string> m;
  auto it = m.begin();
  EXPECT_EQ(it.node_, nullptr);
}

TEST(MapTest, MergeMaps) {
  s21::map<int, std::string> m1;
  m1[1] = "one";
  s21::map<int, std::string> m2;
  m2[2] = "two";
  m2[3] = "three";
  m1.merge(m2);
  EXPECT_EQ(m1[1], "one");
  EXPECT_EQ(m1[2], "two");
  EXPECT_EQ(m1[3], "three");
}

TEST(MapTest, MergeMaps_1) {
  s21::map<int, std::string> m1;
  m1[1] = "one";
  m1[3] = "same_3";
  m1[5] = "five";
  m1[7] = "same_7";
  s21::map<int, std::string> m2;
  m2[2] = "two";
  m2[3] = "three";
  m2[4] = "four";
  m2[6] = "six";
  m2[7] = "seven";
  m1.merge(m2);
  EXPECT_EQ(m1[1], "one");
  EXPECT_EQ(m1[2], "two");
  EXPECT_EQ(m1[3], "same_3");
  EXPECT_EQ(m1[4], "four");
  EXPECT_EQ(m1[5], "five");
  EXPECT_EQ(m1[6], "six");
  EXPECT_EQ(m1[7], "same_7");
  EXPECT_EQ(m2[3], "three");
  EXPECT_EQ(m2[7], "seven");
  EXPECT_EQ(m1.size(), 7);
  EXPECT_EQ(m2.size(), 2);
}

TEST(MapTest, IteratorTraversal) {
  s21::map<int, std::string> m;
  m.insert(std::make_pair(1, "one"));
  m.insert(std::make_pair(2, "two"));
  m.insert(std::make_pair(3, "three"));

  auto it = m.begin();
  EXPECT_EQ((*it).first, 1);
  EXPECT_EQ((*it).second, "one");
  ++it;
  EXPECT_EQ((*it).first, 2);
  EXPECT_EQ((*it).second, "two");
  ++it;
  EXPECT_EQ((*it).first, 3);
  EXPECT_EQ((*it).second, "three");
}

TEST(MapTest, AssignmentOperator) {
  s21::map<int, std::string> m1;
  m1[1] = "one";
  s21::map<int, std::string> m2;
  m2 = m1;
  EXPECT_EQ(m2[1], "one");
}

TEST(MapTest, InitializerListConstructor) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}};
  EXPECT_EQ(m[1], "one");
  EXPECT_EQ(m[2], "two");
  EXPECT_EQ(m.size(), 2);
}

TEST(MapTest, ContainsMethod) {
  s21::map<int, std::string> m;
  m[1] = "one";
  EXPECT_TRUE(m.contains(1));
  EXPECT_FALSE(m.contains(2));
}

TEST(MapTest, EmptyMapAfterClear) {
  s21::map<int, std::string> m;
  m.insert(std::make_pair(1, "one"));
  m.clear();
  EXPECT_TRUE(m.empty());
  EXPECT_EQ(m.size(), 0);
}

TEST(MapTest, InsertDuplicateKey) {
  s21::map<int, std::string> m;
  m.insert(std::make_pair(1, "one"));
  m.insert(std::make_pair(1, "duplicate"));
  EXPECT_EQ(m.size(), 1);
  EXPECT_EQ(m[1], "one");
}

TEST(MapTest, EraseSingleElement) {
  s21::map<int, std::string> m;
  m.insert(std::make_pair(1, "one"));
  m.erase(m.begin());
  EXPECT_TRUE(m.empty());
  EXPECT_EQ(m.size(), 0);
}

TEST(MapTest, MergeDuplicateKeys) {
  s21::map<int, std::string> m1{{1, "one"}, {2, "two"}};
  s21::map<int, std::string> m2{{2, "duplicate"}, {3, "three"}};
  m1.merge(m2);
  EXPECT_EQ(m1.size(), 3);
  EXPECT_EQ(m1[2], "two");
}

TEST(MapTest, InsertManyElements) {
  s21::map<int, std::string> m;
  std::vector<std::pair<int, std::string>> values = {
      {1, "one"}, {2, "two"}, {3, "three"}};
  m.insert_many(values[0], values[1], values[2]);
  EXPECT_EQ(m.size(), 3);
  EXPECT_EQ(m[1], "one");
  EXPECT_EQ(m[2], "two");
  EXPECT_EQ(m[3], "three");
}

TEST(MapTest, EqualityOperator) {
  s21::map<int, std::string> m1{{1, "one"}, {2, "two"}};
  s21::map<int, std::string> m2{{1, "one"}, {2, "two"}};
  s21::map<int, std::string> m3{{1, "one"}, {3, "three"}};
  EXPECT_TRUE(m1[1] == m2[1]);
  EXPECT_FALSE(m1[1] == m3[3]);
}

TEST(MapTest, InequalityOperator) {
  s21::map<int, std::string> m1{{1, "one"}, {2, "two"}};
  s21::map<int, std::string> m2{{1, "one"}, {2, "two"}};
  s21::map<int, std::string> m3{{1, "one"}, {3, "three"}};
  EXPECT_FALSE(m1[1] != m2[1]);
  EXPECT_TRUE(m1[2] != m3[3]);
}

TEST(MapTest, MergeWithoutModifyingOriginal) {
  s21::map<int, std::string> m1{{1, "one"}, {2, "two"}};
  s21::map<int, std::string> m2{{3, "three"}};
  s21::map<int, std::string> m1_copy = m1;
  m1.merge(m2);
  EXPECT_EQ(m1.size(), 3);
  EXPECT_EQ(m1_copy.size(), 2);
}

TEST(Map, DefaultInt) {
  std::map<int, int> std_m;
  s21::map<int, int> s21_m;
  ASSERT_EQ(std_m.size(), s21_m.size());
}

TEST(Map, DefaultNoKey) {
  std::map<int, int> std_m;
  std_m[0] = 100;
  s21::map<int, int> s21_m;
  s21_m[0] = 100;
  ASSERT_EQ(std_m[1], s21_m[1]);
  ASSERT_EQ(0, s21_m[1]);
}

TEST(Map, MoveCtor) {
  std::map<int, int> std_m = {{0, 5}};
  std::map<int, int> std_m_copy(std::move(std_m));
  s21::map<int, int> s21_m = {{0, 5}};
  s21::map<int, int> s21_m_copy(std::move(s21_m));
  ASSERT_EQ(std_m_copy[0], s21_m_copy[0]);
  ASSERT_EQ(std_m_copy.size(), s21_m_copy.size());
}

TEST(Map, MoveOper) {
  std::map<int, std::string> std_m = {{0, "zero"}};
  std::map<int, std::string> std_m_copy = std::move(std_m);
  s21::map<int, std::string> s21_m = {{0, "zero"}};
  s21::map<int, std::string> s21_m_copy = std::move(s21_m);
  ASSERT_EQ(std_m_copy[0], s21_m_copy[0]);
  ASSERT_EQ(std_m_copy.size(), s21_m_copy.size());
}

TEST(Map, Operators) {
  std::map<int, std::string> std_m = {{0, "zero"}, {1, "one"}, {2, "two"}};
  s21::map<int, std::string> s21_m = {{0, "zero"}, {1, "one"}, {2, "two"}};
  auto it_s21 = s21_m.begin();
  auto it_std = std_m.begin();
  ++it_std;
  ++it_s21;
  --it_std;
  --it_s21;
  ASSERT_EQ((*it_s21).first, (*it_std).first);
}

TEST(Map, Operators_2) {
  std::map<int, std::string> std_m = {{0, "zero"}, {1, "one"}, {2, "two"}};
  s21::map<int, std::string> s21_m = {{0, "zero"}, {1, "one"}, {2, "two"}};
  auto it_s21 = s21_m.begin();
  auto it_std = std_m.begin();
  ++it_std;
  ++it_s21;
  ++it_std;
  ++it_s21;
  --it_std;
  --it_s21;
  ASSERT_EQ((*it_s21).first, (*it_std).first);
}

TEST(Map, Operators_3) {
  std::map<int, std::string> std_m = {{0, "zero"},
                                      {1, "one"},
                                      {2, "two"},
                                      {-1, "minus_one"},
                                      {-3, "minus_three"}};
  s21::map<int, std::string> s21_m = {{0, "zero"},
                                      {1, "one"},
                                      {2, "two"},
                                      {-1, "minus_one"},
                                      {-3, "minus_three"}};
  auto it_s21 = s21_m.begin();
  auto it_std = std_m.begin();
  ++it_std;
  ++it_s21;
  ++it_std;
  ++it_s21;
  --it_std;
  --it_s21;
  ASSERT_EQ((*it_s21).first, (*it_std).first);
}

TEST(Map, Operators_4) {
  s21::map<int, std::string> s21_m;
  auto it_s21 = s21_m.begin();
  EXPECT_FALSE((it_s21.node_));
}

TEST(Map, InsertMany) {
  std::map<int, std::string> std_m = {{0, "zero"}, {1, "one"}, {2, "two"}};
  s21::map<int, std::string> s21_m;
  s21_m.insert_many(std::make_pair(0, "zero"), std::make_pair(1, "one"),
                    std::make_pair(2, "two"));

  ASSERT_EQ(std_m.size(), s21_m.size());
  ASSERT_EQ(s21_m[0], "zero");
}

TEST(Map, InsertMany_1) {
  s21::map<int, std::string> s21_m = {{3, "three"}};
  s21_m.insert_many(std::make_pair(0, "zero"), std::make_pair(1, "one"),
                    std::make_pair(2, "two"));

  ASSERT_EQ(s21_m.size(), 4);
  ASSERT_EQ(s21_m[0], "zero");
  ASSERT_EQ(s21_m[1], "one");
  ASSERT_EQ(s21_m[2], "two");
  ASSERT_EQ(s21_m[3], "three");
}