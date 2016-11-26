// need to add "-std=c++11" or "-std=gnu++11" to the complie command when compiling

#include "records.h"
#include <regex>
#include <iostream>
using std::regex;
using std::regex_match;
using std::cout;
using std::endl;

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
    return 0;
  }
}

int Student::setGender(int gender) {
  if (gender != MALE && gender != FEMALE) {
    return -1;
  }else {
    Gender = gender;
  }
}

bool Student::operator<(const Student& stu) {
  return StudentID < stu.getStudentID();
}

bool Student::operator>(const Student& stu) {
  return StudentID > stu.getStudentID();
}

bool Student::operator==(const Student& stu) {
  return StudentID == stu.getStudentID();
}

bool Student::operator==(const string& id) {
  return StudentID == id;
}

bool Student::isValid() const {
  return isValidID(StudentID) && isValidName(StudentName) && isValidYear(Year) && isValidGender(Gender);
}

bool Student::isValidID(const string& id) {
  return id.size() == STUDENT_ID_LENGTH && regex_match(id, regex("[0-9]+"));
}

bool Student::isValidName(const string& name) {
  return name.size() <= STUDENT_NAME_MAX && name.size() >= STUDENT_NAME_MIN;
}

bool Student::isValidYear(const int& year) {
  return year <= YEAR_MAX && year >= YEAR_MIN;
}

bool Student::isValidGender(const int& gender) {
  return gender == MALE || gender == FEMALE;
}

void Student::print() {
  cout<<"Student ID: "<<StudentID<<endl;
  cout<<"Student Name: "<<StudentName<<endl;
  cout<<"Student Year: " <<Year<<endl;
  cout<<"Student Gender: ";
  if(Gender == MALE) {
    cout<<"Male"<<endl;
  }else {
    cout<<"Female"<<endl;
  }
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

bool Course::operator<(const Course& cou) {
  return CourseCode < cou.getCourseCode();
}

bool Course::operator>(const Course& cou) {
  return CourseCode > cou.getCourseCode();
}

bool Course::operator==(const Course& cou) {
  return CourseCode == cou.getCourseCode();
}

bool Course::operator==(const string& code) {
  return CourseCode == code;
}

bool Course::isValid() const {
  return isValidCode(CourseCode) && isValidName(CourseName) && isValidCredit(Credit);
}

bool Course::isValidCode(const stirng& code) {
  return code.length() <= COURSECODE_MAX && code.length() <= COURSECODE_MIN && regex_match(code, regex("[[:upper:]]{4}[[:d:]]+[[:upper:]]?"));
}

bool Course::isValidName(const string& name) {
  return name.length() <= COURSENAME_MAX && name.length() >= COURSENAME_MIN;
}

bool Course::isValidCredit(const string& credit) {
  return credit <= CREDIT_MAX && credit >= CREDIT_MIN;
}

void Course::print() {
  cout<<"Course Code: "<< CourseCode << endl;
  cout<<"Course Name: "<< CourseName << endl;
  cout<<"Course Credit: "<< Credit << endl;
}

CourseSelection::CourseSelection()
:stu(NULL), cou(NULL), ExamMark(UNASSIGNED) {}

CourseSelection::~CourseSelection() {}

CourseSelection::CourseSelection(Student* s, Course* c, int m)
:stu(s), cou(c), ExamMark(m) {}

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

int CourseSelection::setCourse(Course& c) {
  cou = &c;
  return 0;
}

int CourseSelection::setCourse(Course* c) {
  cou = c;
  return 0;
}

int CourseSelection::setStudent(Student& s) {
  stu = &s;
  return 0;
}

int CourseSelection::setStudent(Student* s) {
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

bool CourseSelection::isValid() const {
  if (stu == NULL || cou == NULL) return false;
  return isValidExammark(ExamMark) && stu->isValid() && cou->isValid();
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

bool CourseSelection::isValidExammark(const int& mark) {
  return mark <= EXAMMARK_MAX && mark >= EXAMMARK_MIN;
}

void CourseSelection::print() {
  cout<<"Student ID: " <<getStudentID()<<endl;
  cout<<"CourseCode: " <<getCourseCode() <<endl;
  cout<<"Exam Mark: " <<ExamMark <<endl;
}
