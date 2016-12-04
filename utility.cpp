#include "utility.h"

int StudentIDHash(const string& ID) {
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

int CourseCodeHash(const string& code) {
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

int IndexIDHash(const IndexByID& index) {
  return StudentIDHash(index.StudentID);
}

int IndexCodeHash(const IndexByCode& index) {
  return CourseCodeHash(index.CourseCode);
}

void print(const Course& cou) {
  cou.print();
}

void print(const Student& stu) {
  stu.print();
}

void print(const CourseSelection& cs) {
  cs.print();
}

void print(int number) {
  cout<<number<<" ";
}

void print(IndexByID& index) {
  print(index.getSelection());
}

void print(IndexByCode& index) {
  print(index.getSelection());
}

string getKey(const Student& stu) {
  return stu.getStudentID();
}

string getKey(const IndexByID& index) {
  return index.StudentID;
}

string getKey(const Course& cou) {
  return cou.getCourseCode();
}

string getKey(const IndexByCode& index) {
  return index.CourseCode;
}

int Hash(const Student& stu) {
  return StudentIDHash(stu.getStudentID());
}

int Hash(const Course& cou) {
  return CourseCodeHash(cou.getCourseCode());
}

int Hash(const Student& sample, const string& id) {
  return StudentIDHash(id);
}

int Hash(const Course& sample, const string& code) {
  return CourseCodeHash(code);
}

int Hash(const IndexByID& index) {
  return StudentIDHash(index.StudentID);
}

int Hash(const IndexByCode& index) {
  return CourseCodeHash(index.CourseCode);
}

int Hash(const IndexByID& sample, const string& id) {
  return StudentIDHash(id);
}

int Hash(const IndexByCode& sample, const string& code) {
  return CourseCodeHash(code);
}
