//For Register Project#5 of COMP 2012H @HKUST
//Auther: GU Qiao
//All rights reserved
//
//registermanager.cpp
//The implementation of the RegisterManager class

#include "registermanager.h"
#include "constants.h"
#include <stdexcept>
#include <cstring>
#include <cstdlib>

using std::runtime_error;
using std::cerr;

RegisterManager::RegisterManager() {
  students = StudentTable(STUDENT_ID_M);
  courses = CourseTable(COURSECODE_M);
  selections = SelectionTable();
  id_indexes = IDIndexTable(STUDENT_ID_M);
  code_indexes = CodeIndexTable(COURSECODE_M);
}

RegisterManager::~RegisterManager() {}

int RegisterManager::add(const Student& stu) {
  return students.insert(stu);
}

int RegisterManager::add(const Course& cou) {
  return courses.insert(cou);
}

int RegisterManager::add(const CourseSelection& cs) {
  DoublyLinkedList<CourseSelection>::iterator itr;

  CourseSelection* address;
  address = selections.insertAndReturnAddress(cs);

  //cout<<address<<endl;
  //cout<<"selection inserted"<<endl;
  if(address == NULL) {return -1;}

  IndexByID id_index(address, cs.getStudentID());
  IndexByCode code_index(address, cs.getCourseCode());
  //cout<<"index created"<<endl;
  id_indexes.insert(id_index);
  code_indexes.insert(code_index);

  return 0;
}

int RegisterManager::deleteStudent(const string& id) {
  if(!id_indexes.returnByKey(id).isEmpty()) return -2;
  return students.deleteByKey(id);
}

int RegisterManager::deleteCourse(const string& code){
  if(!code_indexes.returnByKey(code).isEmpty()) return -2;
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

int RegisterManager::loadDataFile(ifstream& fin) {
  StudentTable new_students(STUDENT_ID_M);
  CourseTable new_courses(COURSECODE_M);
  SelectionTable new_selections;
  IDIndexTable new_id_indexes(STUDENT_ID_M);
  CodeIndexTable new_code_indexes(COURSECODE_M);

  char buffer[256];
  fin.clear();

  fin.getline(buffer, 256);
  if(strcmp(buffer, "__student") != 0) {
    return -17;
  }

  fin.getline(buffer, 256);
  while (strcmp(buffer, "__course") != 0) {
    Student stu;
    if(stu.setStudentID(string(buffer)) < 0) return -1;
    fin.getline(buffer, 256);
    if(stu.setStudentName(string(buffer)) < 0) return -2;
    fin.getline(buffer, 256);
    if(stu.setYear(atoi(buffer)) < 0) return -3;
    fin.getline(buffer, 256);
    if(stu.setGender(atoi(buffer)) < 0) return -4;

    if(new_students.insert(stu) < 0) return -5;

    fin.getline(buffer, 256);
    //if(fin.fail()) cout<<"fail bit"<<endl; return -6;
  }

  fin.getline(buffer, 256);
  while(strcmp(buffer, "__selection") != 0) {
    Course cou;
    if(cou.setCourseCode(string(buffer)) < 0) return -7;
    fin.getline(buffer, 256);
    if(cou.setCourseName(string(buffer)) < 0) return -8;
    fin.getline(buffer, 256);
    if(cou.setCredit(atoi(buffer)) < 0) return -9;

    if(new_courses.insert(cou) < 0) return -10;

    fin.getline(buffer, 256);
    if(fin.fail()) return -11;
  }

  fin.getline(buffer, 256);
  while(!fin.eof()) {
    Student* s;
    Course* c;

    string id(buffer);
    if(!Student::isValidID(id) || (s = new_students.searchAndAccessPointer(id)) == NULL) return -12;

    fin.getline(buffer, 256);
    string code(buffer);
    if(!Course::isValidCode(code) || (c = new_courses.searchAndAccessPointer(code)) == NULL) return -13;

    fin.getline(buffer, 256);
    int mark = atoi(buffer);
    if(!CourseSelection::isValidExammark(mark) && mark != UNASSIGNED) return -14;

    CourseSelection cs(s, c, mark);

    CourseSelection* address;
    address = new_selections.insertAndReturnAddress(cs);
    if(address == NULL) return -15;

    IndexByID id_index(address, cs.getStudentID());
    IndexByCode code_index(address, cs.getCourseCode());
    new_id_indexes.insert(id_index);
    new_code_indexes.insert(code_index);


    fin.getline(buffer, 256);
    //if(fin.fail()) return -16;
  }

  students = new_students;
  courses = new_courses;
  selections.clear();
  id_indexes.clear();
  code_indexes.clear();

  SelectionTable::iterator itr;
  for(itr = new_selections.begin(); itr !=new_selections.end(); itr++) {
    Student* s2 = queryStudent(itr->getStudentID());
    Course* c2 = queryCourse(itr->getCourseCode());
    CourseSelection cs(s2, c2, itr->getExamMark());
    CourseSelection* add;
    add = selections.insertAndReturnAddress(cs);

    IndexByID id_i(add, cs.getStudentID());
    IndexByCode code_i(add, cs.getCourseCode());
    id_indexes.insert(id_i);
    code_indexes.insert(code_i);
  }
  
  fin.close();

  return 0;
}

int RegisterManager::saveDataFile(ofstream& fout) {
  DoublyLinkedList<Student> student_list;
  DoublyLinkedList<Course> course_list;
  DoublyLinkedList<Student>::iterator student_itr;
  DoublyLinkedList<Course>::iterator course_itr;
  DoublyLinkedList<CourseSelection>::iterator selection_itr;

  student_list = students.returnAll();
  course_list = courses.returnAll();

  fout<<"__student"<<endl;
  for(student_itr = student_list.begin(); student_itr != student_list.end(); student_itr++) {
    fout<<student_itr->getStudentID()<<endl;
    fout<<student_itr->getStudentName()<<endl;
    fout<<student_itr->getYear()<<endl;
    fout<<student_itr->getGender()<<endl;
  }
  fout<<"__course"<<endl;
  for(course_itr = course_list.begin(); course_itr != course_list.end(); course_itr++) {
    fout<<course_itr->getCourseCode()<<endl;
    fout<<course_itr->getCourseName()<<endl;
    fout<<course_itr->getCredit()<<endl;
  }
  fout<<"__selection"<<endl;
  for(selection_itr = selections.begin(); selection_itr != selections.end(); selection_itr++) {
    fout<<selection_itr->getStudentID()<<endl;
    fout<<selection_itr->getCourseCode()<<endl;
    fout<<selection_itr->getExamMark()<<endl;
  }

  fout.close();
  return 0;

}
