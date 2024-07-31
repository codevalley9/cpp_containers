#ifndef CPP2_S21_CONTAINERS_SRC_S21_BTREE_S21_BTREE_H
#define CPP2_S21_CONTAINERS_SRC_S21_BTREE_S21_BTREE_H

#include <iostream>
#include <limits>

namespace s21 {

template <typename Key, typename T>
class BTree {
 private:
  struct BTreeNode;
  struct BTreeIterator;
  struct BTreeIteratorConst;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = key_type &;
  using const_reference = const key_type &;
  using iterator = BTreeIterator;
  using const_iterator = BTreeIteratorConst;
  using size_type = size_t;

  // Конструкторы и деструкторы
  BTree();
  BTree(const BTree &other) { copy_tree(other); };
  BTree(BTree &&other) noexcept { move_tree(std::move(other)); };
  BTree operator=(BTree &other) { copy_tree(other); };
  BTree operator=(BTree &&other) noexcept { move_tree(std::move(other)); };
  ~BTree() noexcept { Destroy(head_); };

  // Основные методы работы с деревом (вставка, поиск, удаление и т.д.)
  iterator insert(value_type val, bool multiset);
  std::pair<iterator, bool> insert_general(const value_type &value,
                                           bool multiset);
  std::pair<iterator, bool> find(key_type key);
  BTreeNode *find_node(key_type key);
  void erase(iterator iter);
  void copy_tree(const BTree &other);
  void move_tree(BTree &&other);

  // Вспомогательные методы (очистка, проверка, объединение и т.д.)
  void clear() noexcept;
  size_type size() const noexcept { return size_; }
  bool empty() const noexcept { return size_ == 0; }
  size_type max_size() const noexcept;
  void merge(BTree &other, bool multiset);
  void MergeUnique(BTree &other);
  void swap(BTree &other) noexcept;

  // Методы работы с итераторами
  iterator begin() noexcept { return iterator(find_min(head_)); }
  const_iterator begin() const noexcept {
    return const_iterator(find_min(head_));
  }
  iterator end() noexcept { return iterator(find_max(head_)); }
  const_iterator end() const noexcept {
    return const_iterator(find_max(head_));
  }
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(bool multiset,
                                                     Args &&...args);

 private:
  // Внутренние методы для работы с узлами и деревом
  void CopyTreeFromOther(const BTree &other);
  BTreeNode *Copy_node(BTreeNode *node);
  void Destroy(BTreeNode *node);
  BTreeNode *find_min(BTreeNode *node);
  BTreeNode *find_max(BTreeNode *node);

  struct BTreeNode {
    BTreeNode() noexcept = default;
    BTreeNode(key_type new_key, mapped_type new_value) {
      key_ = new_key;
      value_ = new_value;
    };
    BTreeNode *parent_ = nullptr;
    BTreeNode *left_ = nullptr;
    BTreeNode *right_ = nullptr;
    key_type key_{};
    mapped_type value_{};
  };
  struct BTreeIterator {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = BTree::value_type;
    using pointer = value_type *;

    BTreeIterator() = delete;

    explicit BTreeIterator(BTreeNode *node) : node_(node) {}

    value_type operator*() const noexcept {
      return {node_->key_, node_->value_};
    }

    iterator &operator++() {
      if (node_) {
        if (node_->right_) {
          node_ = node_->right_;
          while (node_->left_) node_ = node_->left_;
        } else {
          BTreeNode *ex = node_;
          if (node_->parent_) node_ = node_->parent_;
          while (node_ && node_->right_ == ex) {
            ex = node_;
            node_ = node_->parent_;
          }
        }
      }
      return *this;
    }

    iterator operator++(int) noexcept {
      iterator tmp{node_};
      ++(*this);
      return tmp;
    }

    iterator &operator--() {
      if (node_) {
        if (node_->left_) {
          node_ = node_->left_;
          while (node_->right_) node_ = node_->right_;
        } else {
          BTreeNode *ex = node_;
          node_ = node_->parent_;
          while (node_ && node_->left_ == ex) {
            ex = node_;
            node_ = node_->parent_;
          }
        }
      }
      return *this;
    }

    iterator operator--(int) noexcept {
      iterator tmp{node_};
      --(*this);
      return tmp;
    }

    bool operator==(const iterator &other) const noexcept {
      return node_ == other.node_;
    }

    bool operator!=(const iterator &other) const noexcept {
      return node_ != other.node_;
    }

    BTreeNode *node_;
  };
  struct BTreeIteratorConst {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = BTree::value_type;
    using pointer = const value_type *;

    BTreeIteratorConst() = delete;

    explicit BTreeIteratorConst(const BTreeNode *node) : node_(node) {}

    BTreeIteratorConst(const iterator &it) : node_(it.node_) {}

    value_type operator*() const noexcept {
      return {node_->key_, node_->value_};
    }

    const_iterator &operator++() noexcept {
      node_ = node_->NextNode();
      return *this;
    }

    const_iterator operator++(int) noexcept {
      const_iterator tmp{node_};
      ++(*this);
      return tmp;
    }

    const_iterator &operator--() noexcept {
      node_ = node_->PrevNode();
      return *this;
    }

    const_iterator operator--(int) noexcept {
      const_iterator tmp{node_};
      --(*this);
      return tmp;
    }

    friend bool operator==(const const_iterator &it1,
                           const const_iterator &it2) noexcept {
      return it1.node_ == it2.node_;
    }

    friend bool operator!=(const const_iterator &it1,
                           const const_iterator &it2) noexcept {
      return it1.node_ != it2.node_;
    }

    const BTreeNode *node_;
  };

  BTreeNode *head_{};
  size_type size_{};
};
}  // namespace s21

#include "s21_btree.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_S21_BTREE_S21_BTREE_H