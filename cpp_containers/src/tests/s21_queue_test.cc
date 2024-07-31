#include "s21_tests.h"

TEST(QueueTest, FrontAndBack) {
  s21::Queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(34);
  s21_queue.push(12);
  std_queue.push(34);
  std_queue.push(12);

  ASSERT_EQ(true, s21_queue.front() == std_queue.front());
  ASSERT_EQ(true, s21_queue.back() == std_queue.back());
}

TEST(QueueTest, QueuePushPop) {
  s21::Queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(34);
  s21_queue.push(12);
  std_queue.push(34);
  std_queue.push(12);

  s21_queue.pop();
  std_queue.pop();

  ASSERT_EQ(true, s21_queue.front() == std_queue.front());
  ASSERT_EQ(true, s21_queue.back() == std_queue.back());
}

TEST(QueueTest, QueueEmpty) {
  s21::Queue<int> s21_queue;
  std::queue<int> std_queue;

  ASSERT_EQ(true, s21_queue.empty() == std_queue.empty());
}

TEST(QueueTest, QueueSize) {
  s21::Queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(34);
  s21_queue.push(12);
  std_queue.push(34);
  std_queue.push(12);

  ASSERT_EQ(true, s21_queue.size() == std_queue.size());
}

TEST(QueueTest, QueueSwap) {
  s21::Queue<int> s21_queue;
  s21::Queue<int> s21_queue2;
  std::queue<int> std_queue;
  std::queue<int> std_queue2;

  s21_queue.push(1);
  s21_queue.push(2);
  s21_queue2.push(3);
  s21_queue2.push(4);
  s21_queue.swap(s21_queue2);

  std_queue.push(1);
  std_queue.push(2);
  std_queue2.push(3);
  std_queue2.push(4);
  std_queue.swap(std_queue2);

  ASSERT_EQ(true, std_queue.front() == s21_queue.front());
  ASSERT_EQ(true, std_queue.back() == s21_queue.back());
  ASSERT_EQ(true, std_queue2.front() == s21_queue2.front());
  ASSERT_EQ(true, std_queue2.back() == s21_queue2.back());
}

TEST(QueueTest, InsertManyElements) {
  s21::Queue<int> q;
  q.push(123);
  q.insert_many_back(1, 2, 3);

  std::queue<int> qe;
  qe.push(123);
  int a[] = {1, 2, 3};
  for (const auto& el : a) {
    qe.push(el);
  }
  while (!qe.empty()) {
    ASSERT_EQ(true, q.front() == qe.front());
    q.pop();
    qe.pop();
  }
}
