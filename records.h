#ifndef RECORDS_H
#define RECORDS_H
#include <string>
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
};

class Course {
private:
  string CourseCode;
  string CourseName;
  int Credit;
public:
  Course();
  ~Course();

  Course(const Course&);

  Course& operator=(const Course&);

  int getCredit() const;
  string getCourseCode() const;
  string getCourseName() const;

  int setCourseCode(const string&);
  int setCourseName(const string&);
  int setCredit(const int);
};

class CourseSelection {
private:
  Student* stu;
  Course* cou;
  int ExamMark;
public:
  CourseSelection();
  ~CourseSelection();

  CourseSelection(Student* , Course* , int);
  CourseSelection& operator=(CourseSelection&);

  string getStudentID() const;
  string getCourseCode() const;
  int getExamMark() const;
  Student* getStudent() const;
  Course* getCourse() const;

  int setCourse(const Course&);
  int setCourse(const Course*);
  int setStudent(const Student&);
  int setStudent(const Student*);
  int setExamMark(const int);
};

#endif
