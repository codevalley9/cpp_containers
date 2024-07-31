#ifndef CPP2_S21_CONTAINERS_1_STACK_H
#define CPP2_S21_CONTAINERS_1_STACK_H

#include <initializer_list>
#include <iostream>

#include "../s21_list/s21_list.h"

namespace s21 {
template <typename T, class Container = s21::List<T> >

// Последний пришёл - первый вышел
class Stack {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  Stack() = default;

  Stack(std::initializer_list<value_type> const& items) { stack_(items); }

  Stack(const Stack& other) { stack_ = other.stack_; }

  Stack(Stack&& other) { stack_ = std::move(other.stack_); }

  Stack& operator=(const Stack& other) {
    if (this != &other) {
      stack_ = other.stack_;
    }
    return *this;
  }

  Stack& operator=(Stack&& other) {
    if (this != other) {
      stack_ = std::move(other.stack_);
    }
    return *this;
  }

  ~Stack() = default;

  // получает доступ к верхнему элементу
  const_reference top() { return stack_.back(); }

  bool empty() { return stack_.empty(); }

  size_type size() { return stack_.size(); }

  // добавление элемента наверх
  void push(const_reference value) { stack_.push_back(value); }

  // удаление элемента наверху
  void pop() { stack_.pop_back(); }

  void swap(Stack& other) { stack_.swap(other.stack_); }

  template <typename... Args>
  void insert_many_front(Args&&... args) {
    (push(std::forward<Args>(args)), ...);
  }

 private:
  Container stack_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_STACK_H
