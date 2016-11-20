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

int Hash(const Student& stu){
  return StudentIDHash(stu.getStudentID());
}

int Hash(const Course& cou) {
  return CourseCodeHash(cou.getCourseCode());
}

int Hash(Student& stu, string& ID) {
  return StudentIDHash(ID);
}

int Hash(Course& cou, string& code) {
  return CourseCodeHash(code);
}

int Hash(int number) {
  return number % 10;
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
