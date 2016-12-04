//For Register Project#5 of COMP 2012H @HKUST
//Auther: GU Qiao
//All rights reserved
//
//records.h
//The header file for the record classes used in the project.
//Student Course and CourseSelection

#ifndef RECORDS_H
#define RECORDS_H
#include <string>
#include <fstream>
#include "constants.h"
using std::string;

class Student {
private:
  string StudentID;
  string StudentName;
  int Year;
  int Gender;
public:
  //default constructor and destructor
  Student();
  ~Student();

  //copy constructor
  Student(const Student&);

  //assign constructor
  Student& operator=(const Student&);

  //getter functions
  string getStudentID() const;
  string getStudentName() const;
  int getYear() const;
  int getGender() const;

  //the setter functions(with formmat check);
  int setStudentID(const string&);
  int setStudentName(const string&);
  int setYear(int);
  int setGender(int);

  //The comparator used to sort the records in the linked list
  bool operator<(const Student&);
  bool operator>(const Student&);
  bool operator==(const Student&);
  bool operator==(const string& id);

  //return true if all the data of a instance is valid
  bool isValid() const;

  //the static functions to judge whether the input is valid or not
  static bool isValidID(const string&);
  static bool isValidName(const string&);
  static bool isValidYear(const int&);
  static bool isValidGender(const int&);

  //formatted output for console
  void print() const;
};

class Course {
private:
  string CourseCode;
  string CourseName;
  int Credit;
public:
  //default constructor and destructor
  Course();
  ~Course();

  //copy constructor
  Course(const Course&);

  //assign const
  Course& operator=(const Course&);

  //get functions
  int getCredit() const;
  string getCourseCode() const;
  string getCourseName() const;

  //setter functions.
  //return 0 if the input is valid, and return -1 if invalid
  int setCourseCode(const string&);
  int setCourseName(const string&);
  int setCredit(const int);

  //The compare operator
  //will compare based on the CourseCode
  bool operator<(const Course& cou);
  bool operator>(const Course& cou);
  bool operator==(const Course& cou);
  bool operator==(const string& code);

  //will return true if all the information in this instance is valid
  bool isValid() const;

  //static functions to test validity of an input
  static bool isValidCode(const string&);
  static bool isValidName(const string&);
  static bool isValidCredit(const int&);

  //will print the formmated output by cout
  void print() const;
};

class CourseSelection {
private:
  //will store the pointer of the Student and Course
  //The record of the Student and COurse should not be delete
  Student* stu;
  Course* cou;
  int ExamMark;
public:
  //default constructor and destructor
  CourseSelection();
  ~CourseSelection();

  //conversion constructor
  CourseSelection(Student* , Course* , int = UNASSIGNED);

  //assign constructor
  CourseSelection& operator=(CourseSelection&);

  //The getter functions
  string getStudentID() const;
  string getCourseCode() const;
  int getExamMark() const;
  Student* getStudent() const;
  Course* getCourse() const;

  //the setter functions
  int setCourse(Course&);
  int setCourse(Course*);
  int setStudent(Student&);
  int setStudent(Student*);
  int setExamMark(const int);

  //return true if all the information of a instance is valid
  bool isValid() const;

  //compare operators
  //will compare two instance firstly according to the StudentID and secondly the CourseCode
  bool operator<(const CourseSelection&);
  bool operator>(const CourseSelection&);
  bool operator==(const CourseSelection&);

  //test the validity of the exam mark
  static bool isValidExammark(const int&);

  //formmated output using cout.
  void print() const;
};

#endif
