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
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template <typename T>
class HashTable {
  //typedef int (*HashFunction) (const string&);
  friend class iterator;

private:
  int m, _size;
  vector< DoublyLinkedList<T> > arr;

  typename DoublyLinkedList<T>::iterator searchAndAccessIterator(const string&);
  typename DoublyLinkedList<T>::iterator searchAndAccessIterator(const T&);
  //HashFunction Hash;
  T sample;
public:
  HashTable();
  ~HashTable();
  HashTable(int);

  int insert(const T&);

  int deleteByKey(const string&);
  int deleteByKey(const T&);

  T* searchAndAccessPointer(const string&);
  T* searchAndAccessPointer(const T&);
  void clear();
  bool isEmpty() const;
  int size() const;

  DoublyLinkedList<T> returnAll();
  DoublyLinkedList<T> returnByKey(const string&);
  void printAll();
};

template <typename T>
HashTable<T>::HashTable()
: m(1), _size(0) {}

template <typename T>
HashTable<T>::~HashTable() {}

template <typename T>
HashTable<T>::HashTable(int bucketsnumber)
:m(bucketsnumber), _size(0) {
  arr.resize(m);
  //cout<<"resizing"<<endl;
  //cout<<arr.size()<<endl;
}

template <typename T>
int HashTable<T>::insert(const T& item) {
  //cout<<"here 1"<<endl;
  int index = Hash(item);
  //cout<<"here:"<<index<<endl;
  //cout<<arr.size()<<endl;
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
int HashTable<T>::deleteByKey(const T& item) {
  typename DoublyLinkedList<T>::iterator itr;
  itr = searchAndAccessIterator(item);
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
    return NULL;
  }else {
    return &(*itr);
  }
}

template <typename T>
T* HashTable<T>::searchAndAccessPointer(const T& item) {
  typename DoublyLinkedList<T>::iterator itr;
  itr = searchAndAccessIterator(item);
  if(itr.isDummy()) {
    return NULL;
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
typename DoublyLinkedList<T>::iterator HashTable<T>::searchAndAccessIterator(const T& item) {
  int index = Hash(item);
  DoublyLinkedList<T>* list = &(arr[index]);
  typename DoublyLinkedList<T>::iterator itr;
  for(itr = list->begin(); ; itr++) {
    if(itr == list->end()) {
      return itr;
    }else if(*itr == item) {
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
DoublyLinkedList<T> HashTable<T>::returnAll() {
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
DoublyLinkedList<T> HashTable<T>::returnByKey(const string& key) {
  DoublyLinkedList<T> result;
  int hash_number = Hash(sample, key);
  DoublyLinkedList<T>* list = &(arr[hash_number]);
  typename DoublyLinkedList<T>::iterator itr;

  for(itr = list->begin(); itr != list->end(); itr++) {
    if(*itr == key) {
      list->insertInOrder(*itr);
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
      print(*itr);
    }
    cout<<endl;
  }
}

#endif
