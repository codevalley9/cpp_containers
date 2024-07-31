#ifndef CPP2_S21_CONTAINERS_SRC_MULTISET_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_SRC_MULTISET_S21_MULTISET_H_

#include "../s21_btree/s21_btree.h"

namespace s21 {
template <typename Key>
class multiset : protected BTree<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using tree_type = BTree<key_type, value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename tree_type::iterator;
  using const_iterator = typename tree_type::const_iterator;
  using size_type = size_t;

  // Конструкторы, деструкторы и операторы присваивания
  multiset() : tree_type() {}
  multiset(std::initializer_list<value_type> const &items) {
    for (const_reference item : items) tree_type::insert({item, item}, true);
  };
  multiset(const multiset &otherMultiset) : tree_type(otherMultiset) {}
  multiset(multiset &&otherMultiset) noexcept
      : tree_type(std::move(otherMultiset)) {}
  ~multiset() noexcept {}

  multiset operator=(multiset &otherMultiset) {
    tree_type::copy_tree(otherMultiset);
    return *this;
  };
  multiset operator=(multiset &&otherMultiset) noexcept {
    tree_type::move_tree(std::move(otherMultiset));
    return *this;
  };

  // Доступ к элементам
  value_type &operator[](const key_type &key) {
    if (!contains(key)) insert(key, value_type());
    return tree_type::find_node(key)->value_;
  };

  //  Итераторы
  iterator begin() { return tree_type::begin(); }
  iterator end() { return tree_type::end(); }

  // Размеры
  size_type size() const noexcept { return tree_type::size(); }
  size_type max_size() const noexcept { return tree_type::max_size(); }
  bool empty() const noexcept { return tree_type::empty(); }

  // Модификаторы
  void clear() noexcept { tree_type::clear(); }
  std::pair<iterator, bool> insert(const value_type &value) {
    return tree_type::insert_general({value, value}, true);
  };
  void swap(multiset &other) noexcept { tree_type::swap(other); }

  // Операции над элементами
  iterator find(const Key &key) { return (tree_type::find(key)).first; }
  bool contains(const Key &key) { return (tree_type::find(key)).second; };
  void erase(iterator iter) { tree_type::erase(iter); }
  void merge(multiset &other) { tree_type::merge(other, true); }
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    return tree_type::insert_many(true, args...);
  }

  std::pair<iterator, iterator> equal_range(const Key &key) {
    return {lower_bound(key), upper_bound(key)};
  }

  iterator lower_bound(const Key &key) {
    iterator result = end();
    for (iterator it = begin(); it != end(); ++it)
      if ((*it).first >= key) {
        result = it;
        break;
      }
    return result;
  }

  iterator upper_bound(const Key &key) {
    iterator result = end();
    for (iterator it = begin(); it != end(); ++it)
      if ((*it).first > key) {
        result = it;
        break;
      }
    return result;
  }
};

}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_SRC_S21_MULTISET_S21_MULTISET_H