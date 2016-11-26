#include "registermanager.h"

RegisterManager::RegisterManager() {
  StudentTable students(STUDENT_ID_M, StudentHash);
  CourseTable courses(COURSECODE_M, CourseHash);
  SelectionTable selections();
  IDIndexTable id_indexes(STUDENT_ID_M, IndexIDHash);
  CodeIndexTable code_indexes(COURSECODE_M, IndexCodeHash);
}

RegisterManager::~RegisterManager() {}

int RegisterManager::add(const Student& stu) {
  return students.insert(stu);
}

int RegisterManager::add(const Course& cou) {
  return courses.insert(cou);
}

int RegisterManager::add(const CourseSelection& cs) {
  T* address;
  address = selections.insertInOrder(cs);
  if(address == NULL) {return -1;}
  IndexByID id_index(address, cs.getStudentID());
  IndexByCode code_index(address, cs.getCourseCode());
  id_indexes.insert(id_index);
  code_indexes.insert(code_index);
  return 0;
}

Student* queryStudent(const string& id) {
  return students.searchAndAccessPointer(id);
}

Course* queryCourse(const string& code) {
  return courses.searchAndAccessPointer(code);
}

CourseSelection* querySelectionByID(const string& id) {
  return id_indexes.searchAndAccessPointer(id)->selection;
}

CourseSelection* querySelectionByCode(const string& code) {
  return code_indexes.searchAndAccessPointer(code)->selection;
}
