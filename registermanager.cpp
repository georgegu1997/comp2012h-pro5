#include "registermanager.h"
#include <stdexcept>
using std::runtime_error;

RegisterManager::RegisterManager() {
  StudentTable students(STUDENT_ID_M, StudentIDHash);
  CourseTable courses(COURSECODE_M, CourseCodeHash);
  SelectionTable selections();
  IDIndexTable id_indexes(STUDENT_ID_M, StudentIDHash);
  CodeIndexTable code_indexes(COURSECODE_M, CourseCodeHash);
}

RegisterManager::~RegisterManager() {}

int RegisterManager::add(const Student& stu) {
  return students.insert(stu);
}

int RegisterManager::add(const Course& cou) {
  return courses.insert(cou);
}

int RegisterManager::add(const CourseSelection& cs) {
  CourseSelection* address;
  address = selections.insertAndReturnAddress(cs);
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
  for(itr = selections.begin(); itr != selections.end(); itr++) {
    if(itr->getStudentID() == id && itr->getCourseCode() == code) {
      int i;
      cs = &(*itr);
      IndexByID id_index(cs, cs->getStudentID());
      IndexByCode code_index(cs, cs->getCourseCode());
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

void RegisterManager::StudentsHTML() {
  reportAllStudents(students.returnAll());
}

void RegisterManager::CoursesHTML() {
  reportAllCourses(courses.returnAll());
}

void RegisterManager::StudentsOfCourseHTML(Course* cou) {
  DoublyLinkedList<IndexByCode> index_list;
  index_list = code_indexes.returnByKey(cou->getCourseCode());

  DoublyLinkedList<CourseSelection> selection_list;

  DoublyLinkedList<IndexByCode>::iterator itr;
  for(itr = index_list.begin(); itr != index_list.end(); itr++) {
    selection_list.insertInOrder(*(itr->selection));
  }

  reportStudentsOfCourse(*cou, selection_list);
}

void RegisterManager::CoursesOfStudentHTML(Student* stu) {
  DoublyLinkedList<IndexByID> index_list;
  index_list = id_indexes.returnByKey(stu->getStudentID());

  DoublyLinkedList<CourseSelection> selection_list;

  DoublyLinkedList<IndexByID>::iterator itr;
  for(itr = index_list.begin(); itr != index_list.end(); itr++) {
    selection_list.insertInOrder(*(itr->selection));
  }

  reportCoursesOfStudent(*stu, selection_list);
}
