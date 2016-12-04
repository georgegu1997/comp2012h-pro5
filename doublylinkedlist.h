//For Register Project#5 of COMP 2012H @HKUST
//Auther: GU Qiao
//All rights reserved
//
//doublylinkedlist.h
//This file is the container template implemented by doublly-linked list.
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;
using std::runtime_error;

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
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);

  //destructor
  ~DoublyLinkedList();

  //if the list is empty, return true. else,retun false
  bool isEmpty();

  //return the number of the data stored
  int size();

  //insert an element according the comparator <
  //return -1 if there already exists the data
  int insertInOrder(const T&);

  T* insertAndReturnAddress (const T&);

  //these method are of the same functions as the name suggested, copied from the project 3
  void addLast(T);
  void addFirst(T);
  T removeFirst();
  T removeLast();

  void clear();

  class iterator {
    friend class DoublyLinkedList<T>;
  public:
    //default constructor
    iterator();

    //copy constructor
    iterator(const iterator& itr);

    //the assign constructor
    iterator& operator=(const iterator& itr);

    iterator operator++();
    iterator operator++(int);
    T& operator*();
    bool operator==(const iterator& itr);
    bool operator!=(const iterator& itr);
    iterator operator+(int);
    iterator operator-(int);
    T* operator->();
    //insert a node at the current position, the ones after it will be pushed back.
    void insert(T);
    //delete the node at the current position, the ones after it will be pushed front.
    void deleteCurrent();
    //return true if the iterator is at haed position.
    bool isDummy();
  private:
    Node* node;
    DoublyLinkedList<T>* list;
  };

  //return the head->next node of the list as a iterator
  iterator begin();

  //return the head node of the list as a iterator
  iterator end();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
:head(new Node), _size(0) {
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
    //cout<<"deleting "<<current->prev<<endl;
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
void DoublyLinkedList<T>::clear() {
  while(!isEmpty()) {
    removeFirst();
  }
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() {
  return _size == 0;
}

template <typename T>
int DoublyLinkedList<T>::insertInOrder(const T& item) {
  if(isEmpty()) {
    addFirst(item);
    return 0;
  }else{
    iterator itr;
    for (itr = begin(); ; itr++) {
      if(itr == end()) {
        addLast(item);
        return 0;
      }else if(*(itr) == item) {
        return -1;
      }else if(*(itr) > item) {
        itr.insert(item);
        return 0;
      }
    }
  }
}

template <typename T>
T* DoublyLinkedList<T>::insertAndReturnAddress(const T& item) {
  iterator itr;
  for (itr = begin(); ; itr++) {
    if(itr == end()) {
      addLast(item);
      return &(itr.node->prev->data);
    }else if(*(itr) == item) {
      return NULL;
    }else if(*(itr) > item) {
      itr.insert(item);
      return &(itr.node->prev->data);
    }
  }
}

template <typename T>
int DoublyLinkedList<T>::size() {
  return _size;
}

template <typename T>
DoublyLinkedList<T>::iterator::iterator()
:node(0), list(0) {};

template <typename T>
DoublyLinkedList<T>::iterator::iterator(const iterator& itr) {
  this->node = itr.node;
  this->list = itr.list;
}

template <typename T>
void DoublyLinkedList<T>::iterator::insert(T item) {
  Node* new_node = new Node;
  new_node->data = item;
  new_node->next = this->node;
  new_node->prev = this->node->prev;
  this->node->prev = new_node;
  new_node->prev->next = new_node;
  (list->_size)++;
}

template <typename T>
void DoublyLinkedList<T>::iterator::deleteCurrent() {
  if(this->node == list->head) {
    throw runtime_error("Try to delete the dummy head node.");
  }
  Node* current_node = this->node;
  this->node->next->prev = this->node->prev;
  this->node->prev->next = this->node->next;
  delete current_node;
  current_node = 0;
  (list->_size)--;
}

template <typename T>
bool DoublyLinkedList<T>::iterator::isDummy() {
  return node == list->head;
}

template <typename T>
typename DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator=(const iterator& itr) {
  this->node = itr.node;
  this->list = itr.list;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::operator++() {
  this->node = this->node->next;
  return (*this);
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::operator++(int) {
  iterator itr;
  itr.node = this->node;
  this->node = this->node->next;
  return itr;
}

template <typename T>
T& DoublyLinkedList<T>::iterator::operator*() {
  return node->data;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::operator+(int num) {
  int i;
  iterator itr = *this;
  for (i = 0; i < num; i++) {
    itr.node = itr.node->next;
  }
  return itr;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::operator-(int num) {
  int i;
  iterator itr = *this;
  for (i = 0; i < num; i++) {
    itr.node = itr.node->prev;
  }
  return itr;
}

template <typename T>
bool DoublyLinkedList<T>::iterator::operator==(const iterator& itr) {
  return this->node == itr.node;
}

template <typename T>
bool DoublyLinkedList<T>::iterator::operator!=(const iterator& itr) {
  return this->node != itr.node;
}

template <typename T>
T* DoublyLinkedList<T>::iterator::operator->() {
  return &(node->data);
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
  iterator itr;
  itr.node = this->head->next;
  itr.list = this;
  return itr;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
  iterator itr;
  itr.node = this->head;
  itr.list = this;
  return itr;
}

#endif
