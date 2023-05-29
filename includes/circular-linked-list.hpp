#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <iostream>

#include "node.hpp"

enum class Order { kASC, kDESC };

template <typename T>
class CircularLinkedList {
public:
  CircularLinkedList() = default;
  CircularLinkedList(const CircularLinkedList<T>& source);
  CircularLinkedList<T>& operator=(const CircularLinkedList<T>& source);
  ~CircularLinkedList();

  void InsertInOrder(const T& data);
  void Reverse();

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os,
                                  const CircularLinkedList<U>& cll);

private:
  void InsertAsc(const T& data);
  void InsertDsc(const T& data);

  Node<T>* head_ = nullptr;
  Node<T>* tail_ = nullptr;
  Order node_order_ = Order::kASC;
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& source): head_(nullptr), tail_(nullptr), node_order_(source.node_order_) {
  if(source.head_ == nullptr) {
    return;
  }
  head_ = new Node<T>(source.head_->data);
  Node<T>* currentsource = source.head_->next;
  Node<T>* current = head_;
  while (currentsource != source.head_) {
    current->next = new Node<T>(currentsource->data);
    current = current->next;
    currentsource = currentsource->next;
  }
  current->next = head_;
  tail_ = current; 
}

template <typename T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList<T>& source) {
  if(&source == this) {
    return *this;
  }
  while (head_ != tail_) {
    Node<T> *hold = head_->next;
    delete head_;
    head_ = hold;
  }
  delete head_;
  head_ = nullptr;
  tail_ = nullptr;
  if(source.head_ == nullptr) {
    return *this;
  }
  head_ = new Node<T>(source.head_->data);
  Node<T>* currentsource = source.head_->next;
  Node<T>* current = head_;
  while (currentsource != source.head_) {
    current->next = new Node<T>(currentsource->data);
    current = current->next;
    currentsource = currentsource->next;
  }
  current->next = head_;
  tail_ = current; 
  node_order_ = source.node_order_;
  return *this;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
  while (head_ != tail_) {
    Node<T> *hold = head_->next;
    delete head_;
    head_ = hold;
  }
  delete head_;
  head_ = nullptr;
  tail_ = nullptr;
}

template <typename T>
void CircularLinkedList<T>::InsertAsc(const T& data) {
  if (data <= head_->data) {
    Node<T> *hold = new Node<T>(data,head_);
    tail_->next = hold;
    head_ = hold; 
  } else if (data > tail_->data) {
    Node<T> *hold = new Node<T>(data,head_);
    tail_->next = hold;
    tail_ = hold;
  } else {
    Node<T> *current = head_;
    while (data > current->next->data) {
      current = current->next;
    }
    Node<T> *hold = new Node<T>(data, current->next);
    current->next = hold;
  }
}

template <typename T>
void CircularLinkedList<T>::InsertDsc(const T& data) {
  if (data >= head_->data) {
    Node<T> *hold = new Node<T>(data,head_);
    tail_->next = hold;
    head_ = hold; 
  } else if (data < tail_->data) {
    Node<T> *hold = new Node<T>(data,head_);
    tail_->next = hold;
    tail_ = hold;
  } else {
    Node<T> *current = head_;
    while (data < current->next->data) {
      current = current->next;
    }
    Node<T> *hold = new Node<T>(data,current->next);
    current->next = hold;
  }
}

template <typename T>
void CircularLinkedList<T>::InsertInOrder(const T& data) {
  if (head_ == nullptr) {
    head_ = new Node<T>(data);
    tail_ = head_; 
    tail_->next = head_;
  } else {
    if (node_order_ == Order::kASC) {
      InsertAsc(data);
    } else {
      InsertDsc(data);
    }
  }
}

template <typename T>
void CircularLinkedList<T>::Reverse() { 
  if (head_ == nullptr || head_ == tail_) {
    if (node_order_ == Order::kASC) {
      node_order_ = Order::kDESC;
    } else {
      node_order_ = Order::kASC;
    }
    return;
  }
  if (head_->next == tail_) {
    Node<T>* hold = tail_;
    tail_ = head_;
    head_ = hold;
    if (node_order_ == Order::kASC) {
      node_order_ = Order::kDESC;
    } else {
      node_order_ = Order::kASC;
    }
    return;
  }
  Node<T>* current = head_;
  Node<T>* prev = tail_;
  while(tail_->next == head_) {
    Node<T>* hold = current; 
    current = current->next;
    hold->next = prev; 
    prev = hold;
  }
  Node<T>* hold = tail_;
  tail_ = head_;
  head_ = hold;
  if (node_order_ == Order::kASC) {
    node_order_ = Order::kDESC;
  } else {
    node_order_ = Order::kASC;
  }
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const CircularLinkedList<T>& cll) {
  Node<T>* iter = cll.head_;
  // empty list condition
  if (iter == nullptr) {
    os << "Empty list";
    return os;
  }
  // non-empty list condition
  do {
    os << iter->data << '\t';
    iter = iter->next;
  } while (iter != cll.head_);

  return os;
}

#endif