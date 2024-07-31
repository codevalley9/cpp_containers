#include "s21_tests.h"

TEST(StackTest, StackTop) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(34);
  s21_stack.push(12);
  std_stack.push(34);
  std_stack.push(12);

  ASSERT_EQ(true, s21_stack.top() == std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  ASSERT_EQ(true, s21_stack.top() == std_stack.top());
}

TEST(StackTest, StackPushPop) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(34);
  s21_stack.push(12);
  std_stack.push(34);
  std_stack.push(12);

  ASSERT_EQ(true, s21_stack.top() == std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  ASSERT_EQ(true, s21_stack.top() == std_stack.top());
}

TEST(StackTest, StackEmpty) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;

  ASSERT_EQ(true, s21_stack.empty() == std_stack.empty());
}

TEST(StackTest, StackSize) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(34);
  s21_stack.push(12);
  std_stack.push(34);
  std_stack.push(12);

  ASSERT_EQ(true, s21_stack.size() == std_stack.size());
}

TEST(StackTest, StackSwap) {
  s21::Stack<int> s21_stack;
  s21::Stack<int> s21_stack2;
  std::stack<int> std_stack;
  std::stack<int> std_stack2;

  s21_stack.push(1);
  s21_stack.push(2);
  s21_stack2.push(3);
  s21_stack2.push(4);
  s21_stack.swap(s21_stack2);

  std_stack.push(1);
  std_stack.push(2);
  std_stack2.push(3);
  std_stack2.push(4);
  std_stack.swap(std_stack2);

  ASSERT_EQ(true, std_stack.top() == s21_stack.top());
  ASSERT_EQ(true, std_stack.top() == s21_stack.top());

  ASSERT_EQ(true, std_stack2.top() == s21_stack2.top());
  ASSERT_EQ(true, std_stack2.top() == s21_stack2.top());
}

TEST(StackTest, InsertManyElements) {
  s21::Stack<int> s;
  s.push(123);
  s.insert_many_front(1, 2, 3);

  std::stack<int> st;
  st.push(123);
  int a[] = {1, 2, 3};
  for (const auto& el : a) {
    st.push(el);
  }
  while (!st.empty()) {
    ASSERT_EQ(true, s.top() == st.top());
    s.pop();
    st.pop();
  }
}
