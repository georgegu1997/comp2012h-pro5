#include "doublylinkedlist.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  DoublyLinkedList<int> intdll;
  cout<<intdll.isEmpty()<<endl;
  intdll.addLast(1);
  intdll.addLast(2);
  intdll.addLast(3);
  intdll.addLast(4);
  intdll.addFirst(-1);
  intdll.addFirst(-2);
  intdll.removeLast();
  intdll.removeFirst();
  cout<<intdll.size()<<endl;
  cout<<intdll.isEmpty()<<endl;


  DoublyLinkedList<int>::iterator int_itr;
  cout<<"traversal the list"<<endl;
  for (int_itr=intdll.begin(); int_itr != intdll.end(); int_itr++) {
    if(*int_itr == 3){
      int_itr.deleteCurrent();
    }
    if(*int_itr == 1){
      int_itr.insert(0);
    }
  }
  cout<<intdll.size()<<endl;
  for (int_itr=intdll.begin(); int_itr != intdll.end(); int_itr++) {
    cout <<"element: "<< *int_itr <<endl;
  }
}
