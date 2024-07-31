#ifndef CPP2_S21_CONTAINERS_SRC_S21_MAP_S21_MAP_H
#define CPP2_S21_CONTAINERS_SRC_S21_MAP_S21_MAP_H

#include "../s21_btree/s21_btree.h"

namespace s21 {
template <typename Key, typename T>
class map : protected BTree<Key, T> {
 public:
  // Map Member type
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using tree_type = BTree<key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename tree_type::iterator;
  using const_iterator = typename tree_type::const_iterator;
  using size_type = size_t;

  // Конструкторы, деструкторы и операторы присваивания
  map() : tree_type() {}
  map(std::initializer_list<value_type> const &items) {
    for (const_reference item : items)
      if (!contains(item.first)) tree_type::insert(item, false);
  };
  map(const map &otherMap) : tree_type(otherMap) {}
  map(map &&otherMap) noexcept : tree_type(std::move(otherMap)) {}
  ~map() noexcept {}

  map operator=(map &otherMap) {
    tree_type::copy_tree(otherMap);
    return *this;
  };
  map operator=(map &&otherMap) noexcept {
    tree_type::move_tree(std::move(otherMap));
    return *this;
  };

  // Доступ к элементам
  mapped_type &at(const key_type &key);
  const mapped_type &at(const key_type &key) const;
  mapped_type &operator[](const key_type &key);

  //  Итераторы
  iterator begin() { return tree_type::begin(); }
  iterator end() { return tree_type::end(); }
  const_iterator begin() const { return tree_type::begin(); }
  const_iterator end() const { return tree_type::end(); }

  // Размеры
  size_type size() const noexcept { return tree_type::size(); }
  size_type max_size() const noexcept { return tree_type::max_size(); }
  bool empty() const noexcept { return tree_type::empty(); }

  // Модификаторы
  void clear() noexcept { tree_type::clear(); }
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const key_type &key,
                                   const mapped_type &value);
  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const mapped_type &value);
  void swap(map &other) noexcept { tree_type::swap(other); }

  // Операции над элементами
  iterator find(key_type &key) { return (tree_type::find(key)).first; }
  bool contains(const Key &key) { return (tree_type::find(key)).second; };
  void erase(iterator iter) { tree_type::erase(iter); }
  void merge(map &other) { tree_type::merge(other, false); }
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result{};
    for (auto &arg : {args...})
      result.push_back(tree_type::insert_general(arg, false));
    return result;
  }
};

}  // namespace s21

#include "s21_map.tpp"

#endif  //  CPP2_S21_CONTAINERS_SRC_S21_MAP_S21_MAP_H