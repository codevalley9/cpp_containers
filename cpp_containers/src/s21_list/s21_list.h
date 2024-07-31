#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_LIST_S21_LIST_H_

#include <iostream>

namespace s21 {

/* List Class */
template <class T>
class List {
 public:
  /* Inner Classes */
  class Node;
  class ListIterator;
  class ListIteratorConst;

  /* List Member type */
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = List<T>::ListIterator;
  using const_iterator = List<T>::ListIteratorConst;
  using size_type = size_t;

  /* List Functions */
  List();             // Default constructor
  List(size_type n);  // Parameterized constructor, creates the list of size n;
  List(std::initializer_list<value_type> const&
           items);      // initializer list constructor
  List(const List& l);  // Copy constructor;
  List(List&& l);       // Move constructor;
  ~List();              // Destructor
  List& operator=(
      List&& l) noexcept;  // assignment operator overload for moving object
  List& operator=(const List& l) noexcept;  // copy assignment operator
  // list &operator=(std::initializer_list<value_type> const &items); - удалить

  /* List Element access */
  const_reference front() { return fake_->next_->value_; };
  const_reference back() { return fake_->prev_->value_; };

  /* List Iterators */
  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;

  /* List Capacity */
  bool empty() const noexcept { return (count_ == 0) ? true : false; };
  size_type size() const noexcept { return count_; };
  size_type max_size() const noexcept { return PTRDIFF_MAX / sizeof(Node); };

  /* List Modifiers */
  void clear();
  iterator insert(iterator pos, const_reference value);
  template <class... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <class... Args>
  void insert_many_back(Args&&... args);
  template <class... Args>
  void insert_many_front(Args&&... args);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(List& other) noexcept;
  void merge(List& other);
  void splice(const_iterator pos, List& other);
  void reverse();
  void unique();
  void sort();

  class Node {
   public:
    value_type value_{};
    Node* prev_{};
    Node* next_{};

    Node(const_reference value)
        : value_(value), prev_(nullptr), next_(nullptr) {}
  };

  class ListIterator {
    friend class List;

   public:
    /* Сonstructors */
    ListIterator() {}  // Default Iterator constructor
    ListIterator(Node* node)
        : current_(node) {  // Parameterized Iterator constructor
    }

    /* Comparison operators */
    bool operator==(ListIterator other) noexcept {
      return current_ == other.current_;
    };
    bool operator!=(ListIterator other) noexcept {
      return current_ != other.current_;
    };

    /* Increment and decrement operators */
    ListIterator& operator++();
    ListIterator operator++(int);
    ListIterator& operator--();
    ListIterator operator--(int);

    /* Dereference operator */
    const_reference operator*() { return current_->value_; }

   private:
    Node* current_{};
  };

  class ListIteratorConst : public ListIterator {
   public:
    /* Constructors */
    ListIteratorConst(){};
    ListIteratorConst(ListIterator other) : ListIterator(other) {}
  };

 private:
  Node* head_{};
  Node* tail_{};
  Node* fake_{};
  size_type count_{};
};

}  // namespace s21

#include "s21_list.tpp"

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_LIST_S21_LIST_H_
