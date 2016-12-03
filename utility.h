#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "constants.h"
#include "records.h"
using namespace std;

//The hash function for student ID
//Assume the input obeys the rules, No check.
int StudentIDHash(string ID) {
  int i;
  int sum = 0;
  stringstream ss;
  for (i = 0; i < STUDENT_ID_LENGTH; i++){
    //convert the data in string into number using stringstream
    ss << ID[i];
    int number;
    ss >> number;
    ss.clear();

    //use the modulo's property to sinplify the computation and avoid overflow
    int product = number % STUDENT_ID_M;
    int j;
    for (j = 0; j < i; j++) {
      product = (product * STUDENT_ID_B) % STUDENT_ID_M;
    }
    sum += product;
  }
  return sum % STUDENT_ID_M;
}

//return the corresponding values of different characrer in the course code
//The input should be upper letter A - Z or number 0 - 9.
int getCodeNumber(char a) {
  int number = (int) a;
  if (number >= 48 && number <= 57) {
    return (number - 48);
  }else if(number >= 65 && number <= 90) {
    return (number - 65 + 1 + 10);
  }else {
    throw runtime_error("wrong input in the course code!");
  }
}

//the hash function for course code
//Assume the input obey rhe rules. No check
int CourseCodeHash(string code) {
  int length = code.length();
  int i;
  int sum = 0;
  for (i = 0; i < length; i++) {
    int product = getCodeNumber(code[i]);
    int j;
    for(j = 0; j < i; j++) {
      product = (product * COURSECODE_B) % COURSECODE_M;
    }
    sum += product;
  }
  return sum % COURSECODE_M;
}

int StudentHash(const Student& stu) {
  return StudentIDHash(stu.getStudentID());
}

int CourseHash(const Course& cou) {
  return CourseCodeHash(cou.getCourseCode());
}

struct IndexByID {
  string StudentID;
  CourseSelection* selection;

  IndexByID(CourseSelection* cs = NULL, stirng id = "00000000")
  :selection(cs), StudentID(id) {
    if(selection != NULL && StudentID == "00000000") {
      StudentID = selection->getStudentID();
    }
  }

  bool operator>(const IndexByID& index) {
    return StudentID > index.StudentID;
  }

  bool operator==(const IndexByID& index) {
    return StudentID == index.StudentID;
  }

  bool operator==(CourseSelection* cs) {
    return selection == cs;
  }

  bool operator==(const CourseSelection& cs) {
    return &selection == cs;
  }

  bool operator<(const IndexByID& index) {
    return StudentID < index.StudentID;
  }

  CourseSelection& operator*() {
    return *(selection);
  }
};

int IndexIDHash(const IndexByID& index) {
  return StudentIDHash(index.StudentID);
}

struct IndexByCode {
  string CourseCode;
  CourseSelection* selection;

  IndexByCode(CourseSelection* cs = NULL, string code = "COMP1000")
  :selection(cs), CourseCode(code) {
    if(selection != NULL && CourseCode == "COMP1000") {
      CourseCode = selection->getCourseCode();
    }
  }

  bool operator>(const IndexByCode& index) {
    return CourseCode > index.CourseCode;
  }

  bool operator==(const IndexByCode& index) {
    return CourseCode == index.CourseCode;
  }

  bool operator==(CourseSelection* cs) {
    return selection == cs;
  }

  bool operator==(const CourseSelection& cs) {
    return &selection = cs;
  }

  bool operator<(const IndexByCode& index) {
    return CourseCode < index.CourseCode;
  }

  CourseSelection& operator*() {
    return *(selection);
  }
};

int IndexCodeHash(const IndexByCode& index) {
  return CourseCodeHash(index.CourseCode);
}

void print(Course& cou) {
  cou.print();
}

void print(Student& stu) {
  stu.print();
}

void print(CourseSelection& cs) {
  cs.print();
}

void print(int number) {
  cout<<number<<" ";
}
#endif
