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
int StudentIDHash(const string& ID);

//return the corresponding values of different characrer in the course code
//The input should be upper letter A - Z or number 0 - 9.
int getCodeNumber(char a);

//the hash function for course code
//Assume the input obey rhe rules. No check
int CourseCodeHash(const string& code);

int StudentHash(const Student& stu);

int CourseHash(const Course& cou);

struct IndexByID {
  string StudentID;
  CourseSelection* selection;

  IndexByID(CourseSelection* cs = NULL, string id = "00000000")
  :selection(cs), StudentID(id) {
    if(selection != NULL && StudentID == "00000000") {
      StudentID = selection->getStudentID();
    }
  }

  bool operator==(const IndexByID& index) {
    return selection == index.selection;
  }

  bool operator==(CourseSelection* cs) {
    return selection == cs;
  }

  bool operator==(const CourseSelection& cs) {
    return *selection == cs;
  }

  bool operator==(const string& id) {
    return StudentID == id;
  }

  bool operator<(const IndexByID& index) {
    return StudentID < index.StudentID;
  }

  bool operator>(const IndexByID& index) {
    return StudentID > index.StudentID;
  }

  CourseSelection& getSelection() {
    return *(selection);
  }
};

int IndexIDHash(const IndexByID& index);

struct IndexByCode {
  string CourseCode;
  CourseSelection* selection;

  IndexByCode(CourseSelection* cs = NULL, string code = "COMP1000")
  :selection(cs), CourseCode(code) {
    if(selection != NULL && CourseCode == "COMP1000") {
      CourseCode = selection->getCourseCode();
    }
  }

  bool operator==(const IndexByCode& index) {
    return selection == index.selection;
  }

  bool operator==(CourseSelection* cs) {
    return selection == cs;
  }

  bool operator==(const CourseSelection& cs) {
    return *selection == cs;
  }

  bool operator==(const string& code) {
    return CourseCode == code;
  }

  bool operator<(const IndexByCode& index) {
    return CourseCode < index.CourseCode;
  }

  bool operator>(const IndexByCode& index) {
    return CourseCode > index.CourseCode;
  }

  CourseSelection& getSelection() {
    return *(selection);
  }
};

int IndexCodeHash(const IndexByCode& index);

void print(const Course& cou);

void print(const Student& stu);

void print(const CourseSelection& cs);

void print(int number);

void print(IndexByID& index);

void print(IndexByCode& index);

string getKey(const Student& stu);

string getKey(const IndexByID& index);

string getKey(const Course& cou);

string getKey(const IndexByCode& index);

int Hash(const Student& stu);

int Hash(const Course& cou);

int Hash(const Student& sample, const string& id);

int Hash(const Course& sample, const string& code);

int Hash(const IndexByID& index);

int Hash(const IndexByCode& index);

int Hash(const IndexByID& sample, const string& id);

int Hash(const IndexByCode& sample, const string& code);

#endif
