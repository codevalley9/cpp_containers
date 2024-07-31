#include "s21_tests.h"

/* Сonstructors*/

TEST(ListTest, Default_Constructor) {
  /* int */
  s21::List<int> list_int;
  std::list<int> origin_list_int;

  ASSERT_EQ(list_int.size(), origin_list_int.size());
  ASSERT_EQ(origin_list_int.size(), 0U);
  ASSERT_EQ(list_int.size(), 0U);

  /* double */
  s21::List<double> list_double;
  std::list<double> origin_list_double;

  ASSERT_EQ(list_double.size(), origin_list_double.size());
  ASSERT_EQ(origin_list_double.size(), 0U);
  ASSERT_EQ(list_double.size(), 0U);

  /* string */
  s21::List<std::string> list_string;
  std::list<std::string> origin_list_string;

  ASSERT_EQ(list_string.size(), origin_list_string.size());
  ASSERT_EQ(origin_list_string.size(), 0U);
  ASSERT_EQ(list_string.size(), 0U);

  /* char */
  s21::List<char> list_char;
  std::list<char> origin_list_char;

  ASSERT_EQ(list_char.size(), origin_list_char.size());
  ASSERT_EQ(origin_list_char.size(), 0U);
  ASSERT_EQ(list_char.size(), 0U);
}

TEST(ListTest, Parameterized_Constructor) {
  size_t zero = 0U;
  size_t two = 2U;
  size_t five = 5U;
  size_t seven = 7U;
  size_t nine = 9U;

  /* int */
  s21::List<int> list_int(five);
  s21::List<int> list_int2(zero);
  std::list<int> origin_list_int1(five);
  std::list<int> origin_list_int2(nine);
  std::list<int> origin_list_int3(zero);

  ASSERT_EQ(list_int.size(), origin_list_int1.size());
  ASSERT_NE(list_int.size(), origin_list_int2.size());
  ASSERT_LE(list_int.size(), origin_list_int2.size());

  /* double */
  s21::List<double> list_double(seven);
  s21::List<double> list_double2(zero);
  std::list<double> origin_list_double1(seven);
  std::list<double> origin_list_double2(two);
  std::list<double> origin_list_double3(zero);

  ASSERT_EQ(list_double.size(), origin_list_double1.size());
  ASSERT_NE(list_double.size(), origin_list_double2.size());
  ASSERT_GT(list_double.size(), origin_list_double2.size());

  /* string */
  s21::List<std::string> list_string(nine);
  s21::List<std::string> list_string2(zero);
  std::list<std::string> origin_list_string1(nine);
  std::list<std::string> origin_list_string2(two);
  std::list<std::string> origin_list_string3(zero);

  ASSERT_EQ(list_string.size(), origin_list_string1.size());
  ASSERT_NE(list_string.size(), origin_list_string2.size());
  ASSERT_GT(list_string.size(), origin_list_string2.size());

  /* char */
  s21::List<char> list_char(seven);
  s21::List<char> list_char2(zero);
  std::list<char> origin_list_char1(seven);
  std::list<char> origin_list_char2(five);
  std::list<char> origin_list_char3(zero);

  ASSERT_EQ(list_char.size(), origin_list_char1.size());
  ASSERT_NE(list_char.size(), origin_list_char2.size());
  ASSERT_GT(list_char.size(), origin_list_char2.size());

  /* zero */
  ASSERT_EQ(list_int2.size(), origin_list_int3.size());
  ASSERT_EQ(list_double2.size(), origin_list_double3.size());
  ASSERT_EQ(list_string2.size(), origin_list_string3.size());
  ASSERT_EQ(list_char2.size(), origin_list_char3.size());
}

TEST(ListTest, Initializer_Constructor) {
  /* int */
  s21::List<int> list_int{6, 6, 435, 89};
  s21::List<int> list_int2{};
  std::list<int> origin_list_int1{6, 6, 435, 89};
  std::list<int> origin_list_int2{78, 345, 9};
  std::list<int> origin_list_int3{};

  ASSERT_EQ(list_int.size(), origin_list_int1.size());
  ASSERT_NE(list_int.size(), origin_list_int2.size());
  ASSERT_GT(list_int.size(), origin_list_int2.size());
  ASSERT_EQ(list_int.front(), origin_list_int1.front());
  ASSERT_EQ(list_int.back(), origin_list_int1.back());
  ASSERT_NE(list_int.front(), origin_list_int2.front());
  ASSERT_NE(list_int.back(), origin_list_int2.back());

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  for (it1 = list_int.begin(), it2 = origin_list_int1.begin();
       it1 != list_int.end() || it2 != origin_list_int1.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }

  for (it1 = list_int.begin(), it2 = origin_list_int2.begin();
       it1 != list_int.end() || it2 != origin_list_int2.end(); ++it1, ++it2) {
    ASSERT_NE(*it1, *it2);
  }
  /* double */
  s21::List<double> list_double{6.5, 63.6, 435.65, 89.3};
  s21::List<double> list_double2{};
  std::list<double> origin_list_double1{6.5, 63.6, 435.65, 89.3};
  std::list<double> origin_list_double2{0.5, 43.5, 8.3};
  std::list<double> origin_list_double3{};

  ASSERT_EQ(list_double.size(), origin_list_double1.size());
  ASSERT_NE(list_double.size(), origin_list_double2.size());
  ASSERT_GT(list_double.size(), origin_list_double2.size());
  ASSERT_EQ(list_double.front(), origin_list_double1.front());
  ASSERT_EQ(list_double.back(), origin_list_double1.back());
  ASSERT_NE(list_double.front(), origin_list_double2.front());
  ASSERT_NE(list_double.back(), origin_list_double2.back());

  s21::List<double>::iterator it3;
  std::list<double>::iterator it4;

  for (it3 = list_double.begin(), it4 = origin_list_double1.begin();
       it3 != list_double.end() || it4 != origin_list_double1.end();
       ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }

  for (it3 = list_double.begin(), it4 = origin_list_double2.begin();
       it3 != list_double.end() || it4 != origin_list_double2.end();
       ++it3, ++it4) {
    ASSERT_NE(*it3, *it4);
  }
  /* string */
  s21::List<std::string> list_string{"List", "Array", "Stack"};
  s21::List<std::string> list_string2{};
  std::list<std::string> origin_list_string1{"List", "Array", "Stack"};
  std::list<std::string> origin_list_string2{"Map", "Set"};
  std::list<std::string> origin_list_string3{};

  ASSERT_EQ(list_string.size(), origin_list_string1.size());
  ASSERT_NE(list_string.size(), origin_list_string2.size());
  ASSERT_GT(list_string.size(), origin_list_string2.size());
  ASSERT_EQ(list_string.front(), origin_list_string1.front());
  ASSERT_EQ(list_string.back(), origin_list_string1.back());
  ASSERT_NE(list_string.front(), origin_list_string2.front());
  ASSERT_NE(list_string.back(), origin_list_string2.back());

  /* char */
  s21::List<char> list_char{'A', 'B', 'C'};
  s21::List<char> list_char2{};
  std::list<char> origin_list_char1{'A', 'B', 'C'};
  std::list<char> origin_list_char2{'D', 'E', 'F', 'G'};
  std::list<char> origin_list_char3{};

  ASSERT_EQ(list_char.size(), origin_list_char1.size());
  ASSERT_NE(list_char.size(), origin_list_char2.size());
  ASSERT_LE(list_char.size(), origin_list_char2.size());
  ASSERT_EQ(list_char.front(), origin_list_char1.front());
  ASSERT_EQ(list_char.back(), origin_list_char1.back());
  ASSERT_NE(list_char.front(), origin_list_char2.front());
  ASSERT_NE(list_char.back(), origin_list_char2.back());

  /* zero */
  ASSERT_EQ(list_int2.size(), origin_list_int3.size());
  ASSERT_EQ(list_double2.size(), origin_list_double3.size());
  ASSERT_EQ(list_string2.size(), origin_list_string3.size());
  ASSERT_EQ(list_char2.size(), origin_list_char3.size());
}

TEST(ListTest, Copy_Constructor) {
  /* int */
  s21::List<int> list_int{6, 6, 435, 89};
  s21::List<int> list_int2{list_int};

  std::list<int> origin_list_int1{6, 6, 435, 89};
  std::list<int> origin_list_int2{origin_list_int1};
  std::list<int> origin_list_int3{1, 6, 7};

  ASSERT_EQ(list_int2.size(), origin_list_int2.size());
  ASSERT_NE(list_int2.size(), origin_list_int3.size());
  ASSERT_LE(list_int.size(), origin_list_int2.size());
  ASSERT_EQ(list_int2.front(), origin_list_int2.front());
  ASSERT_EQ(list_int2.back(), origin_list_int2.back());
  ASSERT_NE(list_int2.front(), origin_list_int3.front());
  ASSERT_NE(list_int2.back(), origin_list_int3.back());

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  for (it1 = list_int2.begin(), it2 = origin_list_int2.begin();
       it1 != list_int2.end() || it2 != origin_list_int2.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }

  /* double */
  s21::List<double> list_double{6.5, 63.6, 435.65, 89.3};
  s21::List<double> list_double2{list_double};

  std::list<double> origin_list_double1{6.5, 63.6, 435.65, 89.3};
  std::list<double> origin_list_double2{origin_list_double1};
  std::list<double> origin_list_double3{1.1, 77.8, 6.9};

  ASSERT_EQ(list_double2.size(), origin_list_double2.size());
  ASSERT_NE(list_double2.size(), origin_list_double3.size());
  ASSERT_GT(list_double2.size(), origin_list_double3.size());
  ASSERT_EQ(list_double2.front(), origin_list_double2.front());
  ASSERT_EQ(list_double2.back(), origin_list_double2.back());
  ASSERT_EQ(list_double2.front(), origin_list_double2.front());
  ASSERT_EQ(list_double2.back(), origin_list_double2.back());

  s21::List<double>::iterator it3;
  std::list<double>::iterator it4;

  for (it3 = list_double2.begin(), it4 = origin_list_double2.begin();
       it3 != list_double2.end() || it4 != origin_list_double2.end();
       ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }

  /* string */
  s21::List<std::string> list_string{"List", "Array", "Stack"};
  s21::List<std::string> list_string2{list_string};
  std::list<std::string> origin_list_string1{"List", "Array", "Stack"};
  std::list<std::string> origin_list_string2{origin_list_string1};
  std::list<std::string> origin_list_string3{"Map", "Set"};

  ASSERT_EQ(list_string2.size(), origin_list_string2.size());
  ASSERT_NE(list_string2.size(), origin_list_string3.size());
  ASSERT_GT(list_string2.size(), origin_list_string3.size());
  ASSERT_EQ(list_string2.front(), origin_list_string2.front());
  ASSERT_EQ(list_string2.back(), origin_list_string2.back());
  ASSERT_EQ(list_string2.front(), origin_list_string2.front());
  ASSERT_EQ(list_string2.back(), origin_list_string2.back());

  /* char */
  s21::List<char> list_char{'A', 'B', 'C'};
  s21::List<char> list_char2{list_char};
  std::list<char> origin_list_char1{'A', 'B', 'C'};
  std::list<char> origin_list_char2{origin_list_char1};
  std::list<char> origin_list_char3{'D', 'E', 'F', 'G'};

  ASSERT_EQ(list_char2.size(), origin_list_char2.size());
  ASSERT_NE(list_char2.size(), origin_list_char3.size());
  ASSERT_LE(list_char2.size(), origin_list_char3.size());
  ASSERT_EQ(list_char2.front(), origin_list_char2.front());
  ASSERT_EQ(list_char2.back(), origin_list_char2.back());
  ASSERT_EQ(list_char2.front(), origin_list_char2.front());
  ASSERT_EQ(list_char2.back(), origin_list_char2.back());
}

TEST(ListTest, Move_Constructor) {
  /* int */
  s21::List<int> list_int{6, 6, 435, 89};
  s21::List<int> list_int2(std::move(list_int));

  std::list<int> origin_list_int1{6, 6, 435, 89};
  std::list<int> origin_list_int2(std::move(origin_list_int1));
  std::list<int> origin_list_int3{1, 6, 7};

  ASSERT_EQ(list_int2.size(), origin_list_int2.size());
  ASSERT_NE(list_int2.size(), origin_list_int3.size());
  ASSERT_LE(list_int.size(), origin_list_int2.size());
  ASSERT_EQ(list_int2.front(), origin_list_int2.front());
  ASSERT_EQ(list_int2.back(), origin_list_int2.back());
  ASSERT_NE(list_int2.front(), origin_list_int3.front());
  ASSERT_NE(list_int2.back(), origin_list_int3.back());

  /* zero */
  ASSERT_EQ(list_int.size(), origin_list_int1.size());
  ASSERT_EQ(list_int.size(), 0U);
  ASSERT_EQ(0U, origin_list_int1.size());

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  for (it1 = list_int2.begin(), it2 = origin_list_int2.begin();
       it1 != list_int2.end() || it2 != origin_list_int2.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }

  /* double */
  s21::List<double> list_double{6.5, 63.6, 435.65, 89.3};
  s21::List<double> list_double2{std::move(list_double)};

  std::list<double> origin_list_double1{6.5, 63.6, 435.65, 89.3};
  std::list<double> origin_list_double2{std::move(origin_list_double1)};
  std::list<double> origin_list_double3{1.1, 77.8, 6.9};

  ASSERT_EQ(list_double2.size(), origin_list_double2.size());
  ASSERT_NE(list_double2.size(), origin_list_double3.size());
  ASSERT_GT(list_double2.size(), origin_list_double3.size());
  ASSERT_EQ(list_double2.front(), origin_list_double2.front());
  ASSERT_EQ(list_double2.back(), origin_list_double2.back());
  ASSERT_EQ(list_double2.front(), origin_list_double2.front());
  ASSERT_EQ(list_double2.back(), origin_list_double2.back());

  /* zero */
  ASSERT_EQ(list_double.size(), origin_list_double1.size());
  ASSERT_EQ(list_double.size(), 0U);
  ASSERT_EQ(0U, origin_list_double1.size());

  s21::List<double>::iterator it3;
  std::list<double>::iterator it4;

  for (it3 = list_double2.begin(), it4 = origin_list_double2.begin();
       it3 != list_double2.end() || it4 != origin_list_double2.end();
       ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }

  /* string */
  s21::List<std::string> list_string{"List", "Array", "Stack"};
  s21::List<std::string> list_string2{std::move(list_string)};
  std::list<std::string> origin_list_string1{"List", "Array", "Stack"};
  std::list<std::string> origin_list_string2{std::move(origin_list_string1)};
  std::list<std::string> origin_list_string3{"Map", "Set"};

  ASSERT_EQ(list_string2.size(), origin_list_string2.size());
  ASSERT_NE(list_string2.size(), origin_list_string3.size());
  ASSERT_GT(list_string2.size(), origin_list_string3.size());
  ASSERT_EQ(list_string2.front(), origin_list_string2.front());
  ASSERT_EQ(list_string2.back(), origin_list_string2.back());
  ASSERT_EQ(list_string2.front(), origin_list_string2.front());
  ASSERT_EQ(list_string2.back(), origin_list_string2.back());

  /* zero */
  ASSERT_EQ(list_string.size(), origin_list_string1.size());
  ASSERT_EQ(list_string.size(), 0U);
  ASSERT_EQ(0U, origin_list_string1.size());

  /* char */
  s21::List<char> list_char{'A', 'B', 'C'};
  s21::List<char> list_char2{std::move(list_char)};
  std::list<char> origin_list_char1{'A', 'B', 'C'};
  std::list<char> origin_list_char2{std::move(origin_list_char1)};
  std::list<char> origin_list_char3{'D', 'E', 'F', 'G'};

  ASSERT_EQ(list_char2.size(), origin_list_char2.size());
  ASSERT_NE(list_char2.size(), origin_list_char3.size());
  ASSERT_LE(list_char2.size(), origin_list_char3.size());
  ASSERT_EQ(list_char2.front(), origin_list_char2.front());
  ASSERT_EQ(list_char2.back(), origin_list_char2.back());
  ASSERT_EQ(list_char2.front(), origin_list_char2.front());
  ASSERT_EQ(list_char2.back(), origin_list_char2.back());

  /* zero */
  ASSERT_EQ(list_char.size(), origin_list_char1.size());
  ASSERT_EQ(list_char.size(), 0U);
  ASSERT_EQ(0U, origin_list_char1.size());
}

TEST(ListTest, Move_Assignment_Operator) {
  /* int */
  s21::List<int> list_int{6, 6, 435, 89};
  s21::List<int> list_int2{7, 5, 6};
  list_int2 = std::move(list_int);

  std::list<int> origin_list_int1{6, 6, 435, 89};
  std::list<int> origin_list_int2{1, 6, 7};
  origin_list_int2 = std::move(origin_list_int1);

  ASSERT_EQ(list_int2.size(), origin_list_int2.size());
  ASSERT_EQ(list_int2.front(), origin_list_int2.front());
  ASSERT_EQ(list_int2.back(), origin_list_int2.back());

  /* zero */
  ASSERT_EQ(list_int.size(), origin_list_int1.size());
  ASSERT_EQ(list_int.size(), 0U);
  ASSERT_EQ(0U, origin_list_int1.size());

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  for (it1 = list_int2.begin(), it2 = origin_list_int2.begin();
       it1 != list_int2.end() || it2 != origin_list_int2.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }

  /* double */
  s21::List<double> list_double{6.5, 63.6, 435.65, 89.3};
  s21::List<double> list_double2{1.1, 543.3, 1.6454, 2.3234, 43.345};
  list_double2 = std::move(list_double);

  std::list<double> origin_list_double1{6.5, 63.6, 435.65, 89.3};
  std::list<double> origin_list_double2{1.1, 77.8, 6.9};
  origin_list_double2 = std::move(origin_list_double1);

  ASSERT_EQ(list_double2.size(), origin_list_double2.size());
  ASSERT_EQ(list_double2.front(), origin_list_double2.front());
  ASSERT_EQ(list_double2.back(), origin_list_double2.back());

  /* zero */
  ASSERT_EQ(list_double.size(), origin_list_double1.size());
  ASSERT_EQ(list_double.size(), 0U);
  ASSERT_EQ(0U, origin_list_double1.size());

  s21::List<double>::iterator it3;
  std::list<double>::iterator it4;

  for (it3 = list_double2.begin(), it4 = origin_list_double2.begin();
       it3 != list_double2.end() || it4 != origin_list_double2.end();
       ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }

  /* string */
  s21::List<std::string> list_string{"List", "Array", "Stack"};
  s21::List<std::string> list_string2{"Map", "Set"};
  list_string2 = std::move(list_string);

  std::list<std::string> origin_list_string1{"List", "Array", "Stack"};
  std::list<std::string> origin_list_string2{"Map", "Set"};
  origin_list_string2 = std::move(origin_list_string1);

  ASSERT_EQ(list_string2.size(), origin_list_string2.size());
  ASSERT_EQ(list_string2.front(), origin_list_string2.front());
  ASSERT_EQ(list_string2.back(), origin_list_string2.back());

  /* zero */
  ASSERT_EQ(list_string.size(), origin_list_string1.size());
  ASSERT_EQ(list_string.size(), 0U);
  ASSERT_EQ(0U, origin_list_string1.size());

  /* char */
  s21::List<char> list_char{'A', 'B', 'C'};
  s21::List<char> list_char2{'D', 'E', 'F', 'G'};
  list_char2 = std::move(list_char);

  std::list<char> origin_list_char1{'A', 'B', 'C'};
  std::list<char> origin_list_char2{'D', 'E', 'F', 'G'};
  origin_list_char2 = std::move(origin_list_char1);

  ASSERT_EQ(list_char2.size(), origin_list_char2.size());
  ASSERT_EQ(list_char2.front(), origin_list_char2.front());
  ASSERT_EQ(list_char2.back(), origin_list_char2.back());

  /* zero */
  ASSERT_EQ(list_char.size(), origin_list_char1.size());
  ASSERT_EQ(list_char.size(), 0U);
  ASSERT_EQ(0U, origin_list_char1.size());
}

TEST(ListTest, Copy_Assignment_Operator) {
  /* int */
  const s21::List<int> list_int{6, 6, 435, 89};
  s21::List<int> list_int2{7, 5, 6};
  list_int2 = list_int;

  const std::list<int> origin_list_int1{6, 6, 435, 89};
  std::list<int> origin_list_int2{1, 6, 7};
  origin_list_int2 = origin_list_int1;

  ASSERT_EQ(list_int2.size(), origin_list_int2.size());
  ASSERT_EQ(list_int2.front(), origin_list_int2.front());
  ASSERT_EQ(list_int2.back(), origin_list_int2.back());

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  for (it1 = list_int2.begin(), it2 = origin_list_int2.begin();
       it1 != list_int2.end() || it2 != origin_list_int2.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }

  /* double */
  s21::List<double> list_double{6.5, 63.6, 435.65, 89.3};
  s21::List<double> list_double2{1.1, 543.3, 1.6454, 2.3234, 43.345};
  list_double2 = list_double;

  std::list<double> origin_list_double1{6.5, 63.6, 435.65, 89.3};
  std::list<double> origin_list_double2{1.1, 77.8, 6.9};
  origin_list_double2 = origin_list_double1;

  ASSERT_EQ(list_double2.size(), origin_list_double2.size());
  ASSERT_EQ(list_double2.front(), origin_list_double2.front());
  ASSERT_EQ(list_double2.back(), origin_list_double2.back());

  s21::List<double>::iterator it3;
  std::list<double>::iterator it4;

  for (it3 = list_double2.begin(), it4 = origin_list_double2.begin();
       it3 != list_double2.end() || it4 != origin_list_double2.end();
       ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }

  /* string */
  s21::List<std::string> list_string{"List", "Array", "Stack"};
  s21::List<std::string> list_string2{"Map", "Set"};
  list_string2 = list_string;

  std::list<std::string> origin_list_string1{"List", "Array", "Stack"};
  std::list<std::string> origin_list_string2{"Map", "Set"};
  origin_list_string2 = origin_list_string1;

  ASSERT_EQ(list_string2.size(), origin_list_string2.size());
  ASSERT_EQ(list_string2.front(), origin_list_string2.front());
  ASSERT_EQ(list_string2.back(), origin_list_string2.back());

  /* char */
  s21::List<char> list_char{'A', 'B', 'C'};
  s21::List<char> list_char2{'D', 'E', 'F', 'G'};
  list_char2 = std::move(list_char);

  std::list<char> origin_list_char1{'A', 'B', 'C'};
  std::list<char> origin_list_char2{'D', 'E', 'F', 'G'};
  origin_list_char2 = std::move(origin_list_char1);

  ASSERT_EQ(list_char2.size(), origin_list_char2.size());
  ASSERT_EQ(list_char2.front(), origin_list_char2.front());
  ASSERT_EQ(list_char2.back(), origin_list_char2.back());
}

/* List Iterators */

TEST(ListTest, List_Iterators) {
  /* int */
  s21::List<int> list_int{6, 6, 435, 89};
  const s21::List<int> list_int2{1, 7, 435, 6, 9};
  s21::List<int> list_int3{};

  std::list<int> origin_list_int{6, 6, 435, 89};
  const std::list<int> origin_list_int2{1, 7, 435, 6, 9};
  std::list<int> origin_list_int3{};

  ASSERT_EQ(*list_int.begin(), *origin_list_int.begin());
  ASSERT_EQ(*list_int2.begin(), *origin_list_int2.begin());
  ASSERT_EQ(*list_int3.begin(), *origin_list_int3.begin());
  /* UB - оригинальный end() для int выдает кол-во эл-ов листа (для пустого
  ok):
   */
  // ASSERT_EQ(*list_int.end(), *origin_list_int.end());
  // ASSERT_EQ(*list_int2.end(), *origin_list_int2.end());
  ASSERT_EQ(*list_int3.end(), *origin_list_int3.end());

  /* double */
  s21::List<double> list_double{6.5, 63.6, 435.65, 89.3};
  const s21::List<double> list_double2{1.1, 543.3, 1.6454, 2.3234, 43.345};
  s21::List<double> list_double3{};

  std::list<double> origin_list_double{6.5, 63.6, 435.65, 89.3};
  const std::list<double> origin_list_double2{1.1, 77.8, 6.9};
  std::list<double> origin_list_double3{};

  ASSERT_EQ(*list_double.begin(), *origin_list_double.begin());
  ASSERT_EQ(*list_double2.begin(), *origin_list_double2.begin());
  ASSERT_EQ(*list_double3.begin(), *origin_list_double3.begin());
  /* UB for end() */
  // ASSERT_EQ(*list_double.end(), *origin_list_double.end());
  // ASSERT_EQ(*list_double2.end(), *origin_list_double2.end());
  ASSERT_EQ(*list_double3.end(), *origin_list_double3.end());

  /* string */
  s21::List<std::string> list_string{"List", "Array", "Stack"};
  const s21::List<std::string> list_string2{"Map", "Set"};
  s21::List<std::string> list_string3{};

  std::list<std::string> origin_list_string1{"List", "Array", "Stack"};
  const std::list<std::string> origin_list_string2{"Map", "Set"};
  std::list<std::string> origin_list_string3{};

  ASSERT_EQ(*list_string.begin(), *origin_list_string1.begin());
  ASSERT_EQ(*list_string2.begin(), *origin_list_string2.begin());
  ASSERT_EQ(*list_string3.begin(), *origin_list_string3.begin());
  ASSERT_EQ(*list_string3.end(), *origin_list_string3.end());

  /* char */
  s21::List<char> list_char{'A', 'B', 'C'};
  std::list<char> origin_list_char1{'A', 'B', 'C'};

  ASSERT_EQ(*list_char.begin(), *origin_list_char1.begin());
  /* UB for end() */
  // ASSERT_EQ(*list_char.end(), *origin_list_char1.end());
}

/* List Capacity */

TEST(ListTest, List_Capacity) {
  /* int */
  s21::List<int> list_int{6, 6, 435, 89};
  s21::List<int> list_int2{};

  std::list<int> origin_list_int{6, 6, 435, 89};
  std::list<int> origin_list_int2{};

  ASSERT_TRUE(list_int2.empty());
  ASSERT_TRUE(origin_list_int2.empty());
  ASSERT_EQ(list_int2.empty(), origin_list_int2.empty());
  ASSERT_EQ(list_int2.size(), origin_list_int2.size());
  ASSERT_EQ(list_int.size(), origin_list_int.size());
  ASSERT_EQ(list_int2.max_size(), origin_list_int2.max_size());
  ASSERT_EQ(list_int.max_size(), origin_list_int.max_size());
}

/* List Modifiers */

TEST(ListTest, List_Modifiers_Clear) {
  /* int */
  s21::List<int> list_int{6, 6, 435, 89};
  std::list<int> origin_list_int{6, 6, 435, 89};
  list_int.clear();
  origin_list_int.clear();
  ASSERT_EQ(list_int.empty(), origin_list_int.empty());
}

TEST(ListTest, List_Modifiers_Insert) {
  /* int */
  s21::List<int> list_int{1, 2, 3, 4};
  s21::List<int> list_int2{5, 6, 7, 8};
  s21::List<int> list_int3{};

  std::list<int> origin_list_int{1, 2, 3, 4};
  std::list<int> origin_list_int2{5, 6, 7, 8};
  std::list<int> origin_list_int3{};

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  for (it1 = list_int2.begin(); it1 != list_int2.end(); ++it1) {
    list_int.insert(list_int.end(), *it1);
  }

  for (it2 = origin_list_int2.begin(); it2 != origin_list_int2.end(); ++it2) {
    origin_list_int.insert(origin_list_int.end(), *it2);
  }

  for (it1 = list_int.begin(), it2 = origin_list_int.begin();
       it1 != list_int.end() || it2 != origin_list_int.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it1);
  }

  s21::List<int>::iterator it3 = list_int3.begin();
  std::list<int>::iterator it4 = origin_list_int3.begin();

  list_int3.insert(it3, 8);
  origin_list_int3.insert(it4, 8);
  ASSERT_EQ(*list_int3.begin(), *origin_list_int3.begin());
  ASSERT_EQ(list_int3.size(), origin_list_int3.size());
}

TEST(ListTest, List_Modifiers_Insert_Many) {
  /* int */
  s21::List<int> list_int{5, 6, 7, 8};
  s21::List<int> list_int2{};

  s21::List<int>::iterator it1 = list_int.begin();
  s21::List<int>::iterator it2 = list_int2.begin();

  list_int.insert_many(it1, 4, 3, 2, 1);
  list_int2.insert_many(it2, 8, 7, 6, 5, 4, 3, 2, 1);

  ASSERT_EQ(list_int.size(), list_int.size());
  ASSERT_EQ(list_int.front(), list_int2.front());
  ASSERT_EQ(list_int.back(), list_int2.back());

  for (it1 = list_int.begin(), it2 = list_int2.begin();
       it1 != list_int.end() || it2 != list_int2.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ListTest, List_Modifiers_Insert_Many_Back) {
  /* int */
  s21::List<int> list_int{1, 2, 3};
  s21::List<int> list_int2{};

  s21::List<int>::iterator it1 = list_int.begin();
  s21::List<int>::iterator it2 = list_int2.begin();

  list_int.insert_many_back(4, 5);
  list_int2.insert_many_back(1, 2, 3, 4, 5);

  ASSERT_EQ(list_int.size(), list_int.size());
  ASSERT_EQ(list_int.front(), list_int2.front());
  ASSERT_EQ(list_int.back(), list_int2.back());

  for (it1 = list_int.begin(), it2 = list_int2.begin();
       it1 != list_int.end() || it2 != list_int2.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ListTest, List_Modifiers_Insert_Many_Front) {
  /* int */
  s21::List<int> list_int{5, 6, 7, 8};
  s21::List<int> list_int2{};

  s21::List<int>::iterator it1 = list_int.begin();
  s21::List<int>::iterator it2 = list_int2.begin();

  list_int.insert_many_front(4, 3, 2, 1);
  list_int2.insert_many_front(8, 7, 6, 5, 4, 3, 2, 1);

  ASSERT_EQ(list_int.size(), list_int.size());
  ASSERT_EQ(list_int.front(), list_int2.front());
  ASSERT_EQ(list_int.back(), list_int2.back());

  for (it1 = list_int.begin(), it2 = list_int2.begin();
       it1 != list_int.end() || it2 != list_int2.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ListTest, List_Modifiers_Erase) {
  /* int */
  s21::List<int> list_int{5, 6, 7, 8};

  s21::List<int>::iterator it = list_int.begin();

  list_int.erase(it);
  it = list_int.begin();
  ASSERT_EQ(*it, 6);
}

TEST(ListTest, List_Modifiers_Push_Back_Front) {
  /* int */
  s21::List<int> list_int{3, 4, 5, 6, 7};
  s21::List<int> list_int2{1, 2, 3, 4, 5, 6, 7, 8, 9};

  list_int.push_front(2);
  list_int.push_front(1);
  list_int.push_back(8);
  list_int.push_back(9);

  s21::List<int>::iterator it1 = list_int.begin();
  s21::List<int>::iterator it2 = list_int2.begin();

  for (it1 = list_int.begin(), it2 = list_int2.begin();
       it1 != list_int.end() || it2 != list_int2.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ListTest, List_Modifiers_Pop_Back_Front) {
  /* int */
  s21::List<int> list_int{3, 4, 5, 6, 7};
  s21::List<int> list_int2{1, 2, 3, 4, 5, 6, 7, 8, 9};

  list_int2.pop_front();
  list_int2.pop_front();
  list_int2.pop_back();
  list_int2.pop_back();

  s21::List<int>::iterator it1 = list_int.begin();
  s21::List<int>::iterator it2 = list_int2.begin();

  for (it1 = list_int.begin(), it2 = list_int2.begin();
       it1 != list_int.end() || it2 != list_int2.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ListTest, List_Modifiers_Swap) {
  /* int */
  s21::List<int> list_int{1, 2, 3, 4};
  s21::List<int> list_int2{5, 6, 7, 8, 9};
  s21::List<int> list_int3{1, 2, 3, 4};
  s21::List<int> list_int4{5, 6, 7, 8, 9};

  list_int.swap(list_int2);

  s21::List<int>::iterator it1 = list_int.begin();
  s21::List<int>::iterator it2 = list_int4.begin();
  s21::List<int>::iterator it3 = list_int2.begin();
  s21::List<int>::iterator it4 = list_int3.begin();

  for (it1 = list_int.begin(), it2 = list_int4.begin();
       it1 != list_int.end() || it2 != list_int4.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }

  for (it3 = list_int.begin(), it4 = list_int4.begin();
       it3 != list_int.end() || it4 != list_int4.end(); ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }
}

TEST(ListTest, List_Modifiers_Merge) {
  s21::List<int> list_int{6, 5, 4, 3, 2, 1, 0};
  s21::List<int> list_int2{-1, -2, -3, -7, -8, -9, 0};
  s21::List<int> list_int3{9, 0, 7};
  s21::List<int> list_int4{-1, 9, 0, -87};
  s21::List<int> list_int5(6);

  std::list<int> std_int{6, 5, 4, 3, 2, 1, 0};
  std::list<int> std_int2{-1, -2, -3, -7, -8, -9, 0};
  std::list<int> std_int3{9, 0, 7};
  std::list<int> std_int4{-1, 9, 0, -87};
  std::list<int> std_int5(6);

  list_int.merge(list_int2);
  std_int.merge(std_int2);

  s21::List<int>::iterator it3;
  std::list<int>::iterator it4;

  ASSERT_EQ(list_int2.size(), std_int2.size());
  ASSERT_EQ(list_int2.size(), 0U);
  ASSERT_EQ(std_int2.size(), 0U);

  for (it3 = list_int.begin(), it4 = std_int.begin(); it3 != list_int.end();
       ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }

  ASSERT_EQ(list_int.front(), std_int.front());
  ASSERT_EQ(list_int.back(), std_int.back());
  ASSERT_EQ(list_int.size(), std_int.size());

  list_int.merge(list_int3);
  std_int.merge(std_int3);

  s21::List<int>::iterator it5;
  std::list<int>::iterator it6;

  ASSERT_EQ(list_int3.size(), std_int3.size());
  ASSERT_EQ(list_int3.size(), 0U);
  ASSERT_EQ(std_int3.size(), 0U);

  for (it5 = list_int.begin(), it6 = std_int.begin(); it5 != list_int.end();
       ++it5, ++it6) {
    ASSERT_EQ(*it5, *it6);
  }

  list_int4.merge(list_int5);
  std_int4.merge(std_int5);

  s21::List<int>::iterator it7;
  std::list<int>::iterator it8;

  ASSERT_EQ(list_int5.size(), std_int5.size());
  ASSERT_EQ(list_int5.size(), 0U);
  ASSERT_EQ(std_int5.size(), 0U);

  for (it7 = list_int4.begin(), it8 = std_int4.begin(); it7 != list_int4.end();
       ++it7, ++it8) {
    ASSERT_EQ(*it7, *it8);
  }
}

TEST(ListTest, List_Modifiers_Splice) {
  /* int */
  s21::List<int> list_int{1, 2, 3, 4};
  s21::List<int> list_int2{5, 6, 7, 8, 9};
  s21::List<int> list_int3{1, 2, 3, 4, 5, 6, 7, 8, 9};

  s21::List<int>::iterator it1 = list_int2.begin();
  s21::List<int>::iterator it2 = list_int3.begin();

  list_int2.splice(it1, list_int);

  for (it1 = list_int2.begin(), it2 = list_int3.begin();
       it1 != list_int2.end() || it2 != list_int3.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ListTest, List_Modifiers_Reverse) {
  /* int */
  s21::List<int> list_int{1, 1, 2, 3, 3, 4};
  s21::List<int> list_int2{1, 1, 1};

  std::list<int> origin_list_int{1, 1, 2, 3, 3, 4};
  std::list<int> origin_list_int2{1, 1, 1};

  s21::List<int>::iterator it1 = list_int.begin();
  std::list<int>::iterator it2 = origin_list_int.begin();
  s21::List<int>::iterator it3 = list_int2.begin();
  std::list<int>::iterator it4 = origin_list_int2.begin();

  list_int.reverse();
  list_int2.reverse();
  origin_list_int.reverse();
  origin_list_int2.reverse();

  for (it1 = list_int.begin(), it2 = origin_list_int.begin();
       it1 != list_int.end() || it2 != origin_list_int.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }

  for (it3 = list_int2.begin(), it4 = origin_list_int2.begin();
       it3 != list_int2.end() || it4 != origin_list_int2.end(); ++it3, ++it4) {
    ASSERT_EQ(*it3, *it4);
  }

  s21::List<int> list_int3{};
  std::list<int> origin_list_int3{};
  list_int3.reverse();
  origin_list_int3.reverse();

  ASSERT_EQ(list_int3.front(), origin_list_int3.front());
  ASSERT_EQ(list_int3.back(), origin_list_int3.back());
  ASSERT_EQ(list_int3.size(), origin_list_int3.size());
}

TEST(ListTest, List_Modifiers_Unique) {
  /* int */
  s21::List<int> list_int;
  s21::List<int> list_int2{0, 1, 2, 3, 4, 5, 6, 7};
  s21::List<int> list_int3{9, 9, 9, 0, 0, 9, 9, 0, 1, 2, 3, 4};

  list_int.unique();
  list_int2.unique();
  list_int3.unique();

  std::list<int> origin_list_int;
  std::list<int> origin_list_int2{0, 1, 2, 3, 4, 5, 6, 7};
  std::list<int> origin_list_int3{9, 9, 9, 0, 0, 9, 9, 0, 1, 2, 3, 4};

  origin_list_int.unique();
  origin_list_int2.unique();
  origin_list_int3.unique();

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;

  ASSERT_EQ(list_int.size(), origin_list_int.size());
  ASSERT_EQ(list_int.front(), origin_list_int.front());
  ASSERT_EQ(list_int.back(), origin_list_int.back());
}

TEST(ListTest, List_Modifiers_Sort) {
  /* int */
  s21::List<int> list_int{5, 4, 3, 2, 1, 0, 1};
  std::list<int> origin_list_int{5, 4, 3, 2, 1, 0, 1};

  list_int.sort();
  origin_list_int.sort();

  ASSERT_EQ(list_int.front(), origin_list_int.front());
  ASSERT_EQ(list_int.back(), origin_list_int.back());
  ASSERT_EQ(list_int.size(), origin_list_int.size());

  s21::List<int>::iterator it1;
  std::list<int>::iterator it2;
  for (it1 = list_int.begin(), it2 = origin_list_int.begin();
       it1 != list_int.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }

  s21::List<int> list_int2{};
  std::list<int> origin_list_int2{};
  list_int2.sort();
  origin_list_int2.sort();

  ASSERT_EQ(list_int2.front(), origin_list_int2.front());
  ASSERT_EQ(list_int2.back(), origin_list_int2.back());
  ASSERT_EQ(list_int2.size(), origin_list_int2.size());
}