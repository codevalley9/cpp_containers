#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

namespace s21 {  //чтобы избежать конфликтов имен с другими библиотеками или
                 //частями программы

template <class T, class Allocator = std::allocator<T>>
class vector {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  using iterator = T*;
  using const_iterator = const T*;

  vector() : elements_(nullptr), size_(0), capacity_(0) {}

  vector(size_type n)
      : elements_(
            new T[n]{})  //указатель на дин выд массив эл-в типа т в кол-ве [n]
        ,
        size_(n)  //размер вектора
        ,
        capacity_(n)  //емкость  вектора
  {}

  // Конструктор копирования
  vector(const vector& other)
      : elements_(new T[other.size_]{}),
        size_(other.size_),
        capacity_(other.size_) {
    // for (size_type i = 0; i < size_; ++i) {
    //     elements_[i] = other.elements_[i];
    // }
    std::copy(other.begin(), other.end(), begin());
  }

  vector(std::initializer_list<value_type> const& items)
      : elements_(new T[items.size()]{}),
        size_(items.size()),
        capacity_(items.size()) {
    std::copy(items.begin(), items.end(), begin());
  }

  //Конструктор перемещения обычно выполняется в те случаи, когда перемещаемый
  //объект будет в скором времени уничтожен.//
  vector(vector&& other) noexcept { swap(other); }

  vector& operator=(vector&& other) {
    if (this != &other) {
      swap(other);
    }
    return *this;
  }

  vector& operator=(const vector& other) {
    if (this != &other) {
      realloc_array(other.size_);
      std::copy(other.begin(), other.end(), begin());
      size_ = other.size_;
      capacity_ = other.size_;
    }
    return *this;
  }

  ~vector() { delete[] elements_; }

  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("Oh, no! You out of range, bro");
    }
    return operator[](pos);
  }

  reference operator[](size_type pos) { return *(elements_ + pos); }

  const_reference front() { return operator[](0); }

  const_reference back() { return operator[](size_ - 1); }

  T* data() { return elements_; }

  size_type size() const noexcept { return size_; }

  const_iterator begin() const { return elements_; }
  const_iterator end() const { return elements_ + size_; }
  iterator begin() { return elements_; }
  iterator end() { return elements_ + size_; }

  bool empty() const noexcept { return (size_ == 0); }

  size_type max_size() {
    std::allocator<T> max;
    return static_cast<size_type>(max.max_size());
  }

  void reserve(size_type size) {
    if (capacity_ < size) {
      realloc_array(size);
    }
  }

  size_type capacity() { return capacity_; }

  void shrink_to_fit() {
    if (capacity_ > size_) {
      realloc_array(size_);
    }
  }

  void clear() {
    for (size_type i = 0; i < size_; ++i) {
      elements_[i] = {};
    }
    size_ = 0;
  }

  void push_back(const_reference value) {
    capacity_ensure(size_);
    elements_[size_] = value;
    ++size_;
  }

  void pop_back() {
    elements_[size_ - 1] = {};
    --size_;
  }

  void swap(vector& other) {
    std::swap(elements_, other.elements_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }

  iterator insert(iterator pos, const_reference value) {
    std::ptrdiff_t sizeofmove = pos - elements_;
    if (capacity_ <= size_ + 1) {
      realloc_array(size_ * 2);
    }
    pos = elements_ + sizeofmove;
    std::move(pos, elements_ + size_, pos + 1);
    *pos = value;
    size_++;
    return pos;
  }

  template <typename const_iterator, typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args) {
    size_t dist = std::distance(begin(), pos);
    size_t num_args = sizeof...(Args);
    if (capacity_ <= (size_ + num_args)) {
      realloc_array((size_ + num_args) * 2);
    }
    const_iterator pos_move = begin() + dist;
    std::move_backward(pos_move, end(), end() + num_args);
    value_type new_el[] = {args...};
    for (size_t i = 0; i < num_args; ++i) {
      *pos_move = new_el[i];
      pos_move++;
    }
    size_ += num_args;
    return begin() + dist;
  }

  // template <typename const_iterator, typename... Args>
  template <typename... Args>
  void insert_many_back(Args&&... args) {
    for (const auto& arg : {std::forward<Args>(args)...}) {
      push_back(arg);
    }
  }

  void erase(iterator pos) {
    iterator last_elem = end() - 1;
    while (pos < last_elem) {
      value_type value = *(pos + 1);
      *pos = value;
      pos++;
    }
    elements_[size_ - 1] = {};
    size_--;
  }

 private:
  void realloc_array(size_type size) {
    value_type* new_elements = new T[size]{};
    std::copy(begin(), end(), new_elements);
    capacity_ = size;
    delete[] elements_;
    elements_ = new_elements;
  }

  void capacity_ensure(size_type n_size) {
    if (capacity_ <= n_size) {
      realloc_array(capacity_ * 2);
    }
  }

  value_type* elements_{};
  size_type size_{};
  size_type capacity_{};
};
}  // namespace s21
