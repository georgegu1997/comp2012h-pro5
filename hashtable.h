//For Register Project#5 of COMP 2012H @HKUST
//Auther: GU Qiao
//All rights reserved
//
//hashtable.h
//hash table written in template;
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "doublylinkedlist.h"
#include "utility.h"
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HashTable {
private:
  int m, _size;
  DoublyLinkedList<T> arr[];
  T sample;
  typename DoublyLinkedList<T>::iterator searchAndAccessIterator(const string&);
public:
  HashTable();
  ~HashTable();
  HashTable(int);

  int insert(T&);
  int deleteByKey(const string&);
  T* searchAndAccessPointer(const string&);
  void clear();
  bool isEmpty() const;
  int size() const;

  DoublyLinkedList<T> returnAll() const;
  void printAll();
};

template <typename T>
HashTable<T>::HashTable() {}

template <typename T>
HashTable<T>::~HashTable() {
  int i;
  for (i = 0; i != m; i++) {
    arr[i].~DoublyLinkedList();
  }
}

template <typename T>
HashTable<T>::HashTable(int m) {
  this->m = m;
  DoublyLinkedList<T> arr[m];
}

template <typename T>
int HashTable<T>::insert(T& item) {
  int index = Hash(item);
  cout<<"index: "<<index<<endl;
  cout<<"number fo buckets: "<<m<<endl;
  int result = arr[index].insertInOrder(item);
  if(result = 0) {
    _size++;
  }
  return result;
}

template <typename T>
int HashTable<T>::deleteByKey(const string& str) {
  typename DoublyLinkedList<T>::iterator itr;
  itr = searchAndAccessIterator(str);
  if (itr.isDummy()) {
    return -1;
  }else{
    itr.deleteCurrent();
    _size--;
    return 0;
  }
}

template <typename T>
T* HashTable<T>::searchAndAccessPointer(const string& str) {
  typename DoublyLinkedList<T>::iterator itr;
  itr = searchAndAccessIterator(str);
  if(itr.isDummy()) {
    return -1;
  }else {
    return &(*itr);
  }
}

template <typename T>
typename DoublyLinkedList<T>::iterator HashTable<T>::searchAndAccessIterator(const string& str) {
  int index = Hash(sample, str);
  DoublyLinkedList<T>* list = &(arr[index]);
  typename DoublyLinkedList<T>::iterator itr;
  for(itr = list->begin(); ; itr++) {
    if(itr == list->end()) {
      return itr;
    }else if(*itr == str) {
      return itr;
    }
  }
}

template <typename T>
void HashTable<T>::clear() {
  int i;
  for(i = 0; i != m; i++) {
    arr[i].clear();
  }
  _size = 0;
}

template <typename T>
bool HashTable<T>::isEmpty() const {
  return _size == 0;
}

template <typename T>
int HashTable<T>::size() const {
  return _size;
}

template <typename T>
DoublyLinkedList<T> HashTable<T>::returnAll() const {
  DoublyLinkedList<T> result;
  int i;
  for( i = 0; i != m; i++) {
    DoublyLinkedList<T>* list = &(arr[i]);
    if(!(list->isEmpty())) {
      typename DoublyLinkedList<T>::iterator itr;
      for (itr = list->begin(); itr != list-> end(); itr++) {
        result.insertInOrder(*itr);
      }
    }
  }
  return result;
}

template <typename T>
void HashTable<T>::printAll() {
  int i;
  for( i = 0; i != m; i++) {
    cout<< "hash value = "<<i<<": "<<endl;
    DoublyLinkedList<T>* list = &(arr[i]);
    typename DoublyLinkedList<T>::iterator itr;
    for(itr = list->begin(); itr != list->end(); itr++) {
      (*itr).print();
    }
  }
}

#endif
