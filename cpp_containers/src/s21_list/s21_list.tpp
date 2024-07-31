namespace s21 {

/* List Functions */

template <class T>
inline List<T>::List() : count_(0) {
  fake_ = new Node(value_type{});
  fake_->next_ = fake_;
  fake_->prev_ = fake_;
}

template <class T>
inline List<T>::List(size_t n) : List() {
  while (n > 0) {
    push_back(value_type{});
    --n;
  }
}

template <class T>
inline List<T>::List(std::initializer_list<value_type> const& items) : List() {
  for (const_reference n : items) {
    push_back(n);
  }
}

template <class T>
inline List<T>::List(const List& l) : List() {
  if (!l.empty())
    for (const_reference item : l) {
      push_back(item);
    }
}

template <class T>
inline List<T>::List(List&& l) : List() {
  if (!l.empty()) swap(l);
}

template <class T>
List<T>::~List() {
  clear();
  delete fake_;
}

template <class T>
inline List<T>& List<T>::operator=(List<T>&& l) noexcept {
  if (this != &l) {
    clear();
    swap(l);
  }
  return *this;
}

template <class T>
inline s21::List<T>& s21::List<T>::operator=(const List& l) noexcept {
  if (this != &l) {
    clear();
    if (!l.empty())
      // count_ = l.count_; //иначе зависает
      for (iterator it = l.begin(); it != l.end(); it++) {
        push_back(*it);
      }
  }
  return *this;
}

/* List Iterators */

template <class T>
typename s21::List<T>::iterator s21::List<T>::begin() noexcept {
  iterator it;
  it.current_ = head_ ? head_ : fake_;
  return it;
}

template <class T>
typename s21::List<T>::const_iterator s21::List<T>::begin() const noexcept {
  const_iterator it;
  it.current_ = head_ ? head_ : fake_;
  return it;
}

template <class T>
typename s21::List<T>::iterator s21::List<T>::end() noexcept {
  return iterator(fake_);
}

template <class T>
typename s21::List<T>::const_iterator s21::List<T>::end() const noexcept {
  return const_iterator(fake_);
}

template <class T>
inline typename s21::List<T>::ListIterator&
s21::List<T>::ListIterator::operator++() {
  current_ = current_->next_;
  return *this;
}

template <class T>
inline typename s21::List<T>::ListIterator
s21::List<T>::ListIterator::operator++(int) {
  iterator it(*this);
  ++(*this);
  return it;
}

template <class T>
inline typename s21::List<T>::ListIterator&
s21::List<T>::ListIterator::operator--() {
  current_ = current_->prev_;
  return *this;
}

template <class T>
inline typename s21::List<T>::ListIterator
s21::List<T>::ListIterator::operator--(int) {
  iterator it(*this);
  --(*this);
  return it;
}

/* List Modifiers */

template <class T>
void List<T>::clear() {
  while (!empty()) {
    pop_front();
  };
}

template <class T>
inline typename s21::List<T>::iterator s21::List<T>::insert(
    iterator pos, const_reference value) {
  Node* newNode = new Node(value);
  newNode->prev_ = pos.current_->prev_;
  newNode->prev_->next_ = newNode;
  newNode->next_ = pos.current_;
  newNode->next_->prev_ = newNode;
  if (pos.current_ == fake_) {
    tail_ = newNode;
    head_ = newNode;
  }
  head_ = fake_->next_;
  tail_ = fake_->prev_;
  ++count_;
  return iterator(newNode);
}

template <class T>
template <typename... Args>
inline typename s21::List<T>::iterator s21::List<T>::insert_many(
    s21::List<T>::const_iterator pos, Args&&... args) {
  iterator it = pos;
  ((it = insert(it, std::forward<Args>(args))), ...);
  return it;
}

template <class T>
template <typename... Args>
inline void s21::List<T>::insert_many_back(Args&&... args) {
  ((push_back(std::forward<Args>(args))), ...);
}

template <class T>
template <typename... Args>
inline void s21::List<T>::insert_many_front(Args&&... args) {
  ((push_front(std::forward<Args>(args))), ...);
}

template <class T>
inline void s21::List<T>::erase(iterator pos) {
  if (pos.current_ != fake_) {
    Node* nodeToDelete = pos.current_;
    nodeToDelete->prev_->next_ = nodeToDelete->next_;
    nodeToDelete->next_->prev_ = nodeToDelete->prev_;
    delete nodeToDelete;
    --count_;
    head_ = fake_->next_;
    tail_ = fake_->prev_;
  }
}

template <class T>
void List<T>::push_back(const_reference value) {
  insert(end(), value);
}

template <class T>
void List<T>::pop_back() {
  erase(--end());
}

template <class T>
void List<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <class T>
void List<T>::pop_front() {
  erase(begin());
}

template <class T>
inline void List<T>::swap(List<T>& other) noexcept {
  if (this != &other) {
    Node* headToSwap = head_;
    Node* tailToSwap = tail_;
    Node* fakeToSwap = fake_;
    head_ = other.head_;
    other.head_ = headToSwap;
    tail_ = other.tail_;
    other.tail_ = tailToSwap;
    fake_ = other.fake_;
    other.fake_ = fakeToSwap;
    std::swap(count_, other.count_);
  }
}

template <class T>
inline void List<T>::unique() {
  if (empty() || size() < 2) return;
  iterator it = begin();
  while (it.current_->next_ != fake_) {
    iterator it_prev = it;
    ++it;
    if (*it_prev == *it) {
      erase(it);
    }
    head_ = fake_->next_;
    tail_ = fake_->prev_;
  }
}

template <class T>
inline void List<T>::merge(List& other) {
  if (this == &other || other.empty()) return;
  iterator it1 = begin();
  iterator it2 = other.begin();
  List<T> tmp;
  while (it1 != end() && it2 != other.end()) {
    if (*it2 < *it1) {
      tmp.push_back(*it2);
      ++it2;
    } else {
      tmp.push_back(*it1);
      ++it1;
    }
  }
  /* если лист 1 < 2, то дополняем элементами второго листа */
  while (it2 != other.end()) {
    tmp.push_back(*it2);
    ++it2;
  }
  /* если лист 1 > 2, то дополняем элементами первого листа */
  while (it1 != end()) {
    tmp.push_back(*it1);
    ++it1;
  }
  other.clear();
  swap(tmp);
}

template <class T>
inline void List<T>::splice(const_iterator pos, List& other) {
  for (const_reference value : other) {
    insert(pos, value);
  }
  other.clear();
}

template <class T>
inline void List<T>::reverse() {
  if (empty() || size() <= 1) {
    return;
  }
  iterator it = begin();
  while (it.current_ != fake_) {
    std::swap(it.current_->next_, it.current_->prev_);
    --it;
  }
  std::swap(fake_->next_, fake_->prev_);
  std::swap(head_, tail_);
}

template <class T>
inline void List<T>::sort() {
  if (empty() || size() <= 1) {
    return;
  }
  Node* start = head_;
  while (start != fake_) {
    Node* nextStart = start->next_;
    while (nextStart != fake_) {
      if (start->value_ > nextStart->value_) {
        std::swap(start->value_, nextStart->value_);
      }
      nextStart = nextStart->next_;
    }
    start = start->next_;
  }
}

}  // namespace s21
