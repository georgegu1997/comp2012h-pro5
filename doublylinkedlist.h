//For Register Project#5 of COMP 2012H @HKUST
//Auther: GU Qiao
//All rights reserved
//
//doublylinkedlist.h
//This file is the container template implemented by doublly-linked list.
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList {
private:
  struct Node {
    T data;
    Node* next;
    Node* prev;
  };

  Node* head;

  int _size;
public:
  //Default constructor
  DoublyLinkedList();

  //copy constructor
  DoublyLinkedList(const DoublyLinkedList<T>&);

  //assignment constructor
  DoublyLinkedList<T> operator=(const DoublyLinkedList<T>&);

  //destructor
  ~DoublyLinkedList();

  //if the list is empty, return true. else,retun false
  bool isEmpty();

  //return the number of the data stored
  int size();

  //insert an element according to alphebet order
  void insert();

  //delete the input element if there exists
  void delete(const T&);

  void addLast(const T&);

  void addFirst(const T&);

  void removeFirst(const T&);

  void removeLast(const T&);

  class iterator {
    friend class DoublyLinkedList<T>;
  public:
    //default constructor
    iterator();
    iterator(const iterator& itr);

    //the assign constructor
    iterator operator=(const iterator& itr);

    void operator++();
    T operator*();
    bool operator==(const iterator& itr);
    bool operator==(const iterator& itr);
  private:
    Node* node;
  };

  //return the head->next node of the list as a iterator
  iterator begin();

  //return the head node of the list as a iterator
  iterator end();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
:_head(new NOde), _size(0) {
  head->next = head;
  head->prev = head;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dq)
:head(new Node), _size(0) {
  head->prev = head;
  head->next = head;

  int i;
  Node* dq_current;
  dq_current = dq.head;
  for (i = 0; i<dq._size; i++) {
    dq_current = dq_current->next;
    this->addLast(dq_current->data);
  }
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dq){
  this->~DoublyLinkedList();
  _size = 0;
  head = new Node;
  head->prev = head;
  head->next = head;
  int i;
  Node* dq_current;
  dq_current = dq.head;
  for (i = 0; i < dq._size; i++) {
    dq_current = dq_current->next;
    this->addLast(dq_current->data);
  }

  return *this;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  Node *current  = head->next;
  while (current!=head) {
    current = current->next;
    delete current->prev;
  }
  delete current;
}

template <typename T>
void DoublyLinkedList<T>::addFirst(T item) {
  Node *new_node = new Node;
  new_node->data = item;
  new_node->next = head->next;
  new_node->prev = head;
  head->next->prev = new_node;
  head->next = new_node;
  _size++;
}

template <typename T>
void DoublyLinkedList<T>::addLast(T item) {
  Node *new_node = new Node;
  new_node->data = item;
  new_node->prev = head->prev;
  new_node->next = head;
  head->prev->next = new_node;
  head->prev = new_node;
  _size++;
}

template <typename T>
T DoublyLinkedList<T>::removeFirst() {
  if(this->isEmpty()) {
    throw runtime_error("Try to remove item from a empty list.");
  }

  T first_data = head->next->data;
  Node *first = head->next;
  head->next = head->next->next;
  head->next->prev = head;
  delete first;
  _size--;
  return first_data;
}

template <typename T>
T DoublyLinkedList<T>::removeLast() {
  if(this->isEmpty()) {
    throw runtime_error("Try to remove item from a empty list.");
  }

  T last_data = head->prev->data;
  Node *last = head->prev;
  head->prev = head->prev->prev;
  head->prev->next = head;
  delete last;
  _size--;
  return last_data;
}

template <typename T>
DoublyLinkedList<T>::iterator::iterator() {};

template <typename T>
DoublyLinkedList<T>::iterator::iterator(const iterator& itr) {
  this->node = itr.node;
}

template <typename T>
DoublyLinkedList<T>::iterator::operator=(const iterator& itr) {
  this->node = itr.node;
}

template <typename T>
void DoublyLinkedList<T>::iterator::operator++() {
  node = node->next;
}

template <typename T>
T DoublyLinkedList<T>::iterator::operator*() {
  return node->data;
}

template <typename T>
bool DoublyLinkedList<T>::iterator::operator==(const iterator& itr) {
  return this->node == itr.node;
}

template <typename T>
bool DoublyLinkedList<T>::iterator::operator!=(const iterator& itr) {
  return !(*this == itr);
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
  iterator itr;
  itr.node = this->head->next;
}

#endif
