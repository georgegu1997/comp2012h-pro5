#include "registermanager.h"
#include <stdexcept>
using std::runtime_error;

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

int RegisterManager::deleteStudent(const string& id) {
  return students.deleteByKey(id);
}

int RegisterManager::deleteCourse(const string& code){
  return courses.deleteByKey(code);
}

int RegisterManager::deleteSelection(const string& id, const string& code) {
  SelectionTable::iterator itr;
  CourseSelection* cs = NULL;
  for(itr = selecitons.begin(); itr != selections.end(); itr++) {
    if(itr->getStudentID() == id && itr->getCourseCode() == code) {
      int i;
      cs = &(*itr);
      IndexByID id_index(cs, cs->getStudentID());
      IndexByCode id_index(cs, cs->getCourseCode());
      i = id_indexes.deleteByKey(id_index);
      if(i < 0) throw runtime_error("id index not exist!");
      i = code_indexes.deleteByKey(code_index);
      if(i < 0) throw runtime_error("code index not exits!");
      itr.deleteCurrent();
      return 0;
    }
  }
  return -1;
}

Student* RegisterManager::queryStudent(const string& id) {
  return students.searchAndAccessPointer(id);
}

Course* RegisterManager::queryCourse(const string& code) {
  return courses.searchAndAccessPointer(code);
}

CourseSelection* RegisterManager::querySelection(const string& id, const string& code) {
  SelectionTable::iterator itr;
  for(itr = selections.begin(); itr != selections.end(); itr ++) {
    if(itr->getStudentID() == id && itr->getCourseCode() == code) {
      return &(*itr);
    }
  }
  return NULL;
}

int RegisterManager::modifyStudent(Student* _data, const Student& _new) {
  if (_new.isValid()) {
    *(_data) = _new;
    return 0;
  }else {
    return -1;
  }
}

int RegisterManager::modifyCourse(Course* _data, const Course& _new) {
  if(_new.isValid()) {
    *(_data) = _new;
    return 0
  }else {
    return -1;
  }
}

int RegisterManager::modifySelection(CourseSelection* _data, const CourseSelection& _new) {
  if(_new.isValid()) {
    *(_data) = _new;
    return 0;
  }else {
    return -1;
  }
}

void RegisterManager::StudentsHTML() {
  reportAllStudents(students.returnAll());
}

void RegisterManager::CoursesHTML() {
  reportAllCourses(courses.returnAll());
}

void RegisterManager::StudentsOfCourseHTML(Course* cou) {

}

void RegisterManager::CoursesOfStudentHTML(Student* stu) {

}
