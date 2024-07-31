#ifndef CPP2_S21_CONTAINERS_1_S21_QUEUE_H
#define CPP2_S21_CONTAINERS_1_S21_QUEUE_H

#include <initializer_list>
#include <iostream>
#include <list>
// #include "../s21_list/s21_list.h"

// Первый зашёл - первый вышел
namespace s21 {
template <typename T, class Container = s21::List<T> >

class Queue {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  // Конструктор по умолчанию
  Queue() = default;

  // Конструктор с использованием std::initializer_list
  Queue(std::initializer_list<value_type> const& items) { queue_(items); }

  // Конструктор копирования
  Queue(const Queue& other) { queue_ = other.queue_; }

  // Конструктор перемещения
  Queue(Queue&& other) { queue_ = std::move(other.queue_); }

  // Оператор копирования
  Queue& operator=(const Queue& other) {
    if (this != &other) {
      queue_ = other.queue_;
    }
    return *this;
  }

  // Оператор перемещения
  Queue& operator=(Queue&& other) {
    if (this != other) {
      queue_ = std::move(other.queue_);
    }
    return *this;
  }

  // Деструктор
  ~Queue() = default;

  // Доступ к 1 элементу
  const_reference front() { return queue_.front(); }

  // Доступ к последнему элементу
  const_reference back() { return queue_.back(); }

  bool empty() { return queue_.empty(); }

  size_type size() { return queue_.size(); }

  // Добавляет элемент в конец
  void push(const_reference value) { queue_.push_back(value); }

  // Удаляет 1 элемент
  void pop() { queue_.pop_front(); }

  // Меняет местами содержимое
  void swap(Queue& other) { queue_.swap(other.queue_); }

  template <typename... Args>
  void insert_many_back(Args&&... args) {
    (push(std::forward<Args>(args)), ...);
  }

 private:
  Container queue_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_S21_QUEUE_H
