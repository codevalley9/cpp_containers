namespace s21 {

//  Возвращает ссылку на значение, сопоставленное с ключом,
//  выполняет вставку, если такой элемент еще не существует.
template <typename Key, typename T>
typename map<Key, T>::mapped_type &map<Key, T>::operator[](const Key &key) {
  if (!contains(key)) {
    insert(key, mapped_type());
  }
  return tree_type::find_node(key)->value_;
}

//  Возвращает ссылку на сопоставленное значение элемента с указанным ключом.
template <typename Key, typename T>
typename map<Key, T>::mapped_type &map<Key, T>::at(const Key &key) {
  if (!contains(key)) {
    throw std::out_of_range("map::at");
  }
  return tree_type::find_node(key)->value_;
}

//  Вставляет элемент в карту, если его ключ отсутствует
//  Возвращает итератор и результат операции
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type &element_to_insert) {
  return tree_type::insert_general(element_to_insert, false);
}

//  Пытается вставить элемент с заданным ключом и значением в карту.
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const key_type &key, const mapped_type &value) {
  return insert(std::make_pair(key, value));
}

//  Вставляет элемент или обновляет значение элемента в карте.
//  Пытается вставить элемент с заданным ключом и значением в карту.
//  Если элемент с таким ключом уже существует, его значение обновляется
//  заданным значением. Возвращается итератор на элемент и флаг, указывающий
//  на успешность операции.
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const key_type &key, const mapped_type &value) {
  std::pair<iterator, bool> node_info = tree_type::find(key);
  iterator result = node_info.first;
  if (node_info.second) {
    result.node_->value_ = value;
    result.node_->key_ = key;
  } else {
    result = insert(key, value).first;
  }
  return std::make_pair(result, true);
}

}  // namespace s21