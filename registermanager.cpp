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

CourseSelection* querySelection(const string& id, const string& code) {
  SelectionTable::iterator itr;
  for(itr = selections.begin(); itr != selections.end(); itr ++) {
    if(itr->getStudentID() == id && itr->getCourseCode() == code) {
      return &(*itr);
    }
  }
  return NULL;
}

int modifyStudent(Student* _data, const Student& _new) {
  if (_new.isValid()) {
    *(_data) = _new;
    return 0;
  }else {
    return -1;
  }
}

int modifyCourse(Course* _data, const Course& _new) {
  if(_new.isValid()) {
    *(_data) = _new;
    return 0
  }else {
    return -1;
  }
}

int modifySelection(CourseSelection* _data, const CourseSelection& _new) {
  if(_new.isValid()) {
    *(_data) = _new;
    return 0;
  }else {
    return -1;
  }
}

void StudentsHTML() {
  reportAllStudents(students.returnAll());
}

void CoursesHTML() {
  reportAllCourses(courses.returnAll());
}

void StudentsOfCourseHTML(Course* cou) {

}

void CoursesOfStudentHTML(Student* stu) {

}
