#include "records.h"
#include "doublylinkedlist.h"
#include "hashtable.h"
#include "constants.h"

int main() {
  Student stu1, stu2, stu3, stu4, stu5;
  int i;
  i = stu1.setStudentID("02000001");
  if (i < 0) cout<<"invalid input 1"<<endl;
  i = stu1.setStudentName("A");
  if (i < 0) cout<<"invalid input 2"<<endl;
  i = stu1.setYear(1);
  if (i < 0) cout<<"invalid input 3"<<endl;
  i = stu1.setGender(MALE);
  if (i < 0) cout<<"invalid input 4"<<endl;
  stu1.print();

  i = stu2.setStudentID("02000002");
  if (i < 0) cout<<"invalid input 5"<<endl;
  i = stu2.setStudentName("B");
  if (i < 0) cout<<"invalid input 6"<<endl;
  i = stu2.setYear(2);
  if (i < 0) cout<<"invalid input 7"<<endl;
  i = stu2.setGender(MALE);
  if (i < 0) cout<<"invalid input 8"<<endl;
  stu2.print();

  i = stu3.setStudentID("02000003");
  if (i < 0) cout<<"invalid input 9"<<endl;
  i = stu3.setStudentName("C");
  if (i < 0) cout<<"invalid input 10"<<endl;
  i = stu3.setYear(3);
  if (i < 0) cout<<"invalid input 11"<<endl;
  i = stu3.setGender(FEMALE);
  if (i < 0) cout<<"invalid input 12"<<endl;
  stu3.print();

  HashTable<Student> table(STUDENT_ID_M);
  cout<<"hashtable created"<<endl;
  i = table.insert(stu1);
  if(i<0) cout<<"insert fail 1"<<endl;
  cout<<"insertion 1 finished"<<endl;
  //table.printAll();
  i = table.insert(stu2);
  if(i<0) cout<<"insert fail 2"<<endl;
  cout<<"insertion 2 finished"<<endl;
  i = table.insert(stu3);
  if(i<0) cout<<"insert fail 3"<<endl;
  cout<<"insertion 3 finished"<<endl;

  //table.printAll();
}
