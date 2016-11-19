// need to add "-std=c++11" or "-std=gnu++11" to the complie command when compiling

#include "records.h"
#include <regex>
using std::regex;
using std::regex_match;

Student::Student() {};

Student::~Student() {};

Student::Student(const Student& stu) {
  setStudentID(stu.getStudentID());
  setStudentName(stu.getStudentName());
  setYear(stu.getYear());
  setGender(stu.getYear());
}

Student& Student::operator=(const Student& stu) {
  setStudentID(stu.getStudentID());
  setStudentName(stu.getStudentName());
  setYear(stu.getYear());
  setGender(stu.getYear());
  return (*this);
}

string Student::getStudentID() const{
  return StudentID;
}

string Student::getStudentName() const{
  return StudentName;
}

int Student::getYear() const {
  return Year;
}

int Student::getGender() const {
  return Gender;
}

int Student::setStudentID(const string& id) {
  if(id.size() != STUDENT_ID_LENGTH) {
    return -1;
  }else if(!regex_match(id, regex("[0-9]+"))) {
    return -2;
  }else {
    StudentID = id;
    return 0;
  }
}

int Student::setStudentName(const string& name) {
  if(name.size() < STUDENT_NAME_MIN || name.size() > STUDENT_NAME_MAX) {
    return -1;
  }else{
    StudentName = name;
    return 0;
  }
}

int Student::setYear(int year) {
  if (year < 1 || year > 3) {
    return -1;
  }else {
    Year = year;
  }
}

int Student::setGender(int gender) {
  if (gender != MALE && gender != FAMALE) {
    return -1;
  }else {
    Gender = gender;
  }
}

bool Student::operator<(const Student& stu) {
  return strcmp(this->getStudentID(), stu.getStudentID()) < 0;
}

bool Student::operator>(const Student& stu) {
  return strcmp(StudentID, stu.getStudentID()) > 0;
}

bool Student::operator==(const Student& stu) {
  return strcmp(StudentID, stu.getStudentID()) == 0;
}

bool Student::operator==(const string& id) {
  return StudentID == id;
}

Course::Course() {};

Course::~Course() {};

Course::Course(const Course& c) {
  setCourseCode(c.getCourseCode());
  setCourseName(c.getCourseName());
}

Course& Course::operator=(const Course& c) {
  setCourseCode(c.getCourseCode());
  setCourseName(c.getCourseName());
  return (*this);
}

string Course::getCourseCode() const {
  return CourseCode;
}

string Course::getCourseName() const {
  return CourseName;
}

int Course::getCredit() const {
  return Credit;
}

int Course::setCourseCode(const string& code) {
  if (code.length() < COURSECODE_MIN || code.length() > COURSECODE_MAX) {
    return -1;
  }else if(!regex_match(code, regex("[[:upper:]]{4}[[:d:]]+[[:upper:]]?"))) {
    return -2;
  }else {
    CourseCode = code;
    return 0;
  }
}

int Course::setCourseName(const string& name) {
  if(name .size() < COURSENAME_MIN || name.size() > COURSENAME_MAX) {
    return -1;
  }else {
    CourseName = name;
    return 0;
  }
}

int Course::setCredit(const int c) {
  if(c < CREDIT_MIN || c > CREDIT_MAX) {
    return -1;
  }else {
    Credit = c;
    return 0;
  }
}

bool Course::operator<(const Course* cou) {
  return strcmp(this->getCourseCode(), cou.getCourseCode()) < 0;
}

bool Course::operator>(const Course* cou) {
  return strcmp(CourseCode, cou.getCourseCode()) > 0;
}

bool Course::operator==(const Course* cou) {
  return strcmp(CourseCode, cou.getCourseCode()) == 0;
}

bool Course::operator==(const string& code) {
  return CourseCode == code;
}

CourseSelection::CourseSelection()
:stu(0), cou(0), EsamMark(UNASSIGNED) {}

CourseSelection::~CourseSelection() {}

CourseSelection::CourseSelection(Student* s, Course* c, int m)
:stu(s), cou(c), EsamMark(m) {}

CourseSelection& CourseSelection::operator=(CourseSelection& cs) {
  setCourse(cs.getCourse());
  setStudent(cs.getStudent());
  setExamMark(cs.getExamMark());
}

string CourseSelection::getStudentID() const {
  return stu->getStudentID();
}

string CourseSelection::getCourseCode() const {
  return cou->getCourseCode();
}

int CourseSelection::getExamMark() const {
  return ExamMark;
}

Student* CourseSelection::getStudent() const {
  return stu;
}

Course* CourseSelection::getCourse() const {
  return cou;
}

int CourseSelection::setCourse(const Course& c) {
  cou = *c;
  return 0;
}

int CourseSelection::setCourse(const Course* c) {
  cou = c;
  return 0;
}

int CourseSelection::setStudent(const Student& s) {
  stu = *s;
  return 0;
}

int CourseSelection::setStudent(const Student* s) {
  stu = s;
  return 0;
}

int CourseSelection::setExamMark(const int e) {
  if(e < EXAMMARK_MIN || e > EXAMMARK_MAX) {
    return -1;
  }else {
    ExamMark = e;
    return 0;
  }
}

bool CourseSelection::operator<(const CourseSelection& cs) {
  if(*stu == *(cs.getStudent())) {
    return *cou < *(cs.getCourse());
  }else {
    return *stu < *(cs.getStudent());
  }
}

bool CourseSelection::operator>(const CourseSelection& cs) {
  if(*stu == *(cs.getStudent())) {
    return *cou > *(cs.getCourse());
  }else {
    return *stu > *(cs.getStudent());
  }
}

bool CourseSelection::operator==(const CourseSelection& cs) {
  return *cou == *(cs.getCourse()) && *stu < *(cs.getStudent());
}
