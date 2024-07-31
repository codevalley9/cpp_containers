#ifndef CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_
#define CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_

#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace s21 {

template <typename T, size_t N>

class Array {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  // Конструктор по умолчанию
  Array() = default;
  //        Array() : data_(new T[N]) {}

  // Конструктор с использованием std::initializer_list
  Array(std::initializer_list<value_type> const& items) {
    if (items.size() != N) {
      throw std::invalid_argument(
          "Initializer list size does not match array size");
    }

    const T* it = items.begin();
    for (size_type i = 0; i < N; ++i) {
      data_[i] = *it;
      ++it;
    }
  }

  // Конструктор копирования
  Array(const Array& other) {
    for (size_type i = 0; i < N; ++i) {
      data_[i] = other.data_[i];
    }
    //            std::copy(other.data_, other.data_ + N, this->data_); ????
  }

  // Конструктор перемещения
  Array(Array&& other) {
    for (size_type i = 0; i < N; ++i) {
      data_[i] = std::move(other.data_[i]);
    }
  }

  // Оператор копирования
  Array& operator=(const Array& other) {
    if (this != &other) {
      delete[] data_;
      data_ = new T[N];
      std::copy(other.data_, other.data_ + N, data_);
    }
    return *this;
  }

  // Оператор перемещения
  Array& operator=(Array&& other) {
    for (size_type i = 0; i < N; ++i) {
      data_[i] = std::move(other.data_[i]);
    }
    return *this;
  }

  // Деструктор
  ~Array() = default;
  //        ~Array() {
  //            for (size_t i = 0; i < N; ++i) { }
  //        }

  reference operator[](size_type pos) { return data_[pos]; }

  reference at(size_type pos) {
    if (pos >= N)
      throw std::out_of_range(
          "array at : the entered number is larger than the size of the array");
    return data_[pos];
  }

  const_reference front() { return data_[0]; }
  const_reference back() { return data_[N - 1]; }

  iterator data() { return data_; }
  iterator begin() { return data_; }
  iterator end() { return data_ + N; }

  bool equal() { return N == 0; }
  size_type size() { return N; }
  size_type max_size() { return N; }

  void swap(Array& other) {
    for (size_type i = 0; i < N; ++i) {
      value_type tmp = data_[i];
      data_[i] = other.data_[i];
      other.data_[i] = tmp;
    }
  }

  void fill(const_reference value) {
    for (size_type i = 0; i < N; ++i) {
      data_[i] = value;
    }
  }

 private:
  T data_[N];
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_
