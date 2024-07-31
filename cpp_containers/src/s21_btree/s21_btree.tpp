namespace s21 {

template <typename Key, typename T>
BTree<Key, T>::BTree() : head_(nullptr), size_(0U) {}

//  Перемещающий конструктор
template <typename Key, typename T>
void BTree<Key, T>::move_tree(BTree &&other) {
  if (this != &other) {  // Проверка на самоприсваивание
    Destroy(head_);
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
    other.head_ = nullptr;
  }
}

//  Оператор присваивания копирует содержимое другого дерева
template <typename Key, typename T>
void BTree<Key, T>::copy_tree(const BTree &other) {
  if (this != &other) {  // Проверка на самоприсваивание
    clear();
    if (other.size() > 0) {
      CopyTreeFromOther(other);
    }
  }
}

//  Копирует структуру и содержимое дерева из другого дерева.
template <typename Key, typename T>
void BTree<Key, T>::CopyTreeFromOther(const BTree &other) {
  if (head_ != other.head_) {
    clear();
    if (other.head_ != nullptr) {
      BTreeNode *node = Copy_node(other.head_);
      while (node->parent_ != nullptr) node = node->parent_;
      head_ = node;
    }
    size_ = other.size_;
  }
};

template <typename Key, typename T>
typename BTree<Key, T>::BTreeNode *BTree<Key, T>::Copy_node(BTreeNode *node) {
  BTreeNode *new_node = nullptr;
  if (node) {
    new_node = new BTreeNode(node->key_, node->value_);
    new_node->left_ = Copy_node(node->left_);
    new_node->right_ = Copy_node(node->right_);
    new_node->parent_ = node->parent_;
    new_node->value_ = node->value_;
  }
  return new_node;
};

//  Очистка дерева
template <typename Key, typename T>
void BTree<Key, T>::clear() noexcept {
  if (head_) {
    Destroy(head_);  // Удаление всех узлов, начиная с корневого узла
    size_ = 0;  // Установка размера дерева равным нулю
  }
}

//  Рекурсивно удаляет узлы дерева, начиная с заданного узла.
template <typename Key, typename T>
void BTree<Key, T>::Destroy(BTreeNode *node) {
  if (node) {
    Destroy(node->right_);
    Destroy(node->left_);
    delete node;
    head_ = nullptr;
  }
}

//  Возвращает максимально возможный размер дерева.
template <typename Key, typename T>
typename BTree<Key, T>::size_type BTree<Key, T>::max_size() const noexcept {
  return ((std::numeric_limits<size_type>::max() / 2) - sizeof(BTree) -
          sizeof(BTreeNode)) /
         sizeof(BTreeNode);
}

//  Вставляет элемент с заданным ключом в дерево.
template <typename Key, typename T>
typename BTree<Key, T>::iterator BTree<Key, T>::insert(value_type val,
                                                       bool multiset) {
  BTreeNode *new_node = new BTreeNode(val.first, val.second);
  new_node->right_ = nullptr;
  BTreeNode *parent = nullptr;
  BTreeNode *current_node = head_;
  if (!head_) {
    head_ = new_node;
    head_->left_ = nullptr;
    head_->right_ = nullptr;
  } else {
    while (current_node) {
      parent = current_node;
      if (val.first < current_node->key_)
        current_node = current_node->left_;
      else
        current_node = current_node->right_;
    }
    new_node->parent_ = parent;
    if (val.first < parent->key_)
      parent->left_ = new_node;
    else if (val.first > parent->key_)
      parent->right_ = new_node;
    else if (val.first == parent->key_ && multiset)
      parent->right_ = new_node;
  }
  ++size_;
  return iterator(new_node);
};

template <typename Key, typename T>
std::pair<typename BTree<Key, T>::iterator, bool> BTree<Key, T>::insert_general(
    const value_type &value, bool multiset) {
  std::pair<iterator, bool> node_info = find(value.first);
  iterator it = node_info.first;
  bool inserted = false;
  if (multiset) {
    inserted = true;
    insert(value, multiset);
  } else {
    if (!node_info.second) {
      inserted = true;
      it = insert(value, multiset);
    }
  }
  return std::make_pair(it, inserted);
};

//  Находит элемент в дереве по заданному ключу.
template <typename Key, typename T>
std::pair<typename BTree<Key, T>::iterator, bool> BTree<Key, T>::find(
    key_type key) {
  BTreeNode *current_node = head_;
  std::pair result =
      std::make_pair(iterator(nullptr), false);  //  Если не найден
  while (current_node) {
    if (current_node->key_ == key) {
      result = std::make_pair(iterator(current_node), true);  //  Если найден
      break;
    }
    if (key < current_node->key_)
      current_node = current_node->left_;
    else
      current_node = current_node->right_;
  }
  return result;
}

template <typename Key, typename T>
typename BTree<Key, T>::BTreeNode *BTree<Key, T>::find_node(key_type key) {
  BTreeNode *current_node = head_;
  if (current_node) {
    while (current_node) {
      if (current_node->key_ == key) {
        break;
      }
      if (key < current_node->key_)
        current_node = current_node->left_;
      else
        current_node = current_node->right_;
    }
  } else {
    current_node = nullptr;
  }
  return current_node;
};

template <typename Key, typename T>
void BTree<Key, T>::swap(BTree &other) noexcept {
  std::swap(head_, other.head_);
  std::swap(size_, other.size_);
};

template <typename Key, typename T>
void BTree<Key, T>::erase(iterator iter) {
  if (iter.node_) {
    BTreeNode *y = nullptr, *x = nullptr;
    bool no_childs = 0;
    if (iter.node_->left_ == nullptr || iter.node_->right_ == nullptr) {
      y = iter.node_;
    } else {
      y = iter.node_->left_;
      while (y->right_) y = y->right_;
    }
    if (y->left_)
      x = y->left_;
    else if (y->right_)
      x = y->right_;
    else {
      x = new BTreeNode();
      y->right_ = x;
      no_childs = 1;
    }
    x->parent_ = y->parent_;
    if (!y->parent_)
      head_ = x;
    else if (y == y->parent_->left_)
      y->parent_->left_ = x;
    else
      y->parent_->right_ = x;

    if (y != iter.node_) {
      iter.node_->key_ = y->key_;
      iter.node_->value_ = y->value_;
    }
    if (no_childs) {
      y->right_ = nullptr;
      if (head_ == x)
        head_ = nullptr;
      else if (y->parent_->left_ == x)
        y->parent_->left_ = nullptr;
      else if (y->parent_->right_ == x)
        y->parent_->right_ = nullptr;
      delete x;
    }
    iter.node_ = y;
    delete iter.node_;
    --size_;
  }
};

template <typename Key, typename T>
typename BTree<Key, T>::BTreeNode *BTree<Key, T>::find_min(BTreeNode *node) {
  BTreeNode *result = node;
  if (!node) {
    result = nullptr;
  } else {
    while (node->left_ != nullptr) {
      node = node->left_;
      result = node;
    }
  }
  return result;
};

template <typename Key, typename T>
typename BTree<Key, T>::BTreeNode *BTree<Key, T>::find_max(BTreeNode *node) {
  BTreeNode *tmp = node;
  while (node != nullptr) {
    node = node->right_;
    tmp = node;
  }
  return tmp;
};

template <typename Key, typename T>
void BTree<Key, T>::merge(BTree &other, bool multiset) {
  if (this != &other) {
    iterator it = other.begin();
    while ((it != other.end())) {
      bool erased = false;
      if (multiset) {
        insert({it.node_->key_, it.node_->value_}, 1);
      } else {
        if (!(find(it.node_->key_)).second) {
          insert({(it.node_->key_), (it.node_->value_)}, 0);
          iterator to_erase = it;
          iterator buffer = ++it;
          other.erase(to_erase);
          it = buffer;
          erased = true;
          if (!other.head_) break;
        }
      }
      if (!erased) ++it;
    }
  }
};

template <typename Key, typename T>
template <class... Args>
std::vector<std::pair<typename BTree<Key, T>::iterator, bool>>
BTree<Key, T>::insert_many(bool multiset, Args &&...args) {
  std::vector<std::pair<iterator, bool>> result{};
  for (auto &arg : {args...})
    result.push_back(BTree::insert_general({arg, arg}, multiset));
  return result;
};

}  // namespace s21