#ifndef REGISTERMANAGER_H
#define REGISTERMANAGER_H
#include "doublylinkedlist.h"
#include "hashtable.h"
#include "records.h"
#include "htmlgenerator.h"
#include "constants.h"
#include "utility.h"

class RegisterManager {
  typedef HashTable<Student> StudentTable;
  typedef HashTable<Course> CourseTable;
  typedef DoublyLinkedList<CourseSelection> SelectionTable;
  typedef HashTable<IndexByID> IDIndexTable;
  typedef HashTable<IndexByCode> CodeIndexTable;

private:
  StudentTable students;
  CourseTable courses;
  SelectionTable selections;
  IDIndexTable id_indexes;
  CodeIndexTable code_indexes;

public:
  RegisterManager();
  ~RegisterManager();

  int add(const Student& stu);
  int add(const Course& cou);
  int add(const CourseSelection& cs);

  Student* queryStudent(const string& id);
  Course* queryCourse(const stirng& code);
  CourseSelection* querySelectionByID(const string& id);
  CourseSelection* querySelectionByCode(const string& code);

  
};


#endif
