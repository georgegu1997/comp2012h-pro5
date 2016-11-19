//For Register Project#5 of COMP 2012H @HKUST
//Auther: GU Qiao
//All rights reserved
//
//hashtable.h
//hash table written in template;
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "doublelinkedlist.h"
#include "utility.h"

template <typename T>
class HashTable {
private:
  int m;
  DoublyLinkedList<T>[] arr;
  T sample;
  DoublyLinkedList<T>::iterator searchAndAccessIterator(const string&);
public:
  HashTable();
  ~HashTable();
  HashTable(int);

  int insert(T&);
  int deleteByKey(const string&);
  T* searchAndAccessPointer(const string&);
};

template <typename T>
HashTable<T>::HashTable() {}

template <typename T>
HashTable<T>::~HashTable() {}

template <typename T>
HashTable<T>::HashTable(int m) {
  this->m = m;
  arr = DoublyLinkedList<T>[m];
}

template <typename T>
int HashTable<T>::insert(T& item) {
  int index = Hash(item);
  return arr[index].insertInOrder(item);
}

template <typename T>
int HashTable<T>::deleteByKey(const string& str) {
  DoublyLinkedList<T>::iterator itr;
  itr = searchAndAccessIterator(str);
  if (itr.isDummy()) {
    return -1;
  }else{
    itr.deleteCurrent();
    return 0;
  }
}

template <typename T>
T* HashTable<T>::searchAndAccessPointer(const string& str) {
  DoublyLinkedList<T>::iterator itr;
  irt = searchAndAccessIterator(const string& str);
  if(itr.isDummy()) {
    return -1;
  }else {
    return &(*itr);
  }
}

template <typename T>
DoublyLinkedList<T>::iterator HashTable<T>::searchAndAccessIterator(const string& str) {
  int index = Hash(sample, str);
  DoublyLinkedList<T>* list = &(arr[index]);
  DoublyLinkedList<T>::iterator itr;
  for(itr = list->begin(); ; itr++) {
    if(itr == list->end()) {
      return itr;
    }else if(*itr == str) {
      return itr;
    }
  }
}

#endif
