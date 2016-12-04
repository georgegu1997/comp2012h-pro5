#include "registermanager.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <fstream>
using std::system;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;

RegisterManager rm;

string StudentIDInput() {
  cout<<"Enter the student ID: ";
  string str;
  getline(cin,str);
  while(!Student::isValidID(str)) {
    cout<<"Invalid input, re-enter again [student ID]: ";
    getline(cin,str);
  }
  return str;
}

string StudentNameInput() {
  string str;
  getline(cin,str);
  while(!Student::isValidName(str)) {
    cout<<"Invalid input, re-enter again [student name]: ";
    getline(cin,str);
  }
  return str;
}

int StudentYearInput() {
  int number;
  string str;
  getline(cin,str);
  number = atoi(str.c_str());
  while(!Student::isValidYear(number)){
    cout<<"Invalid input re-enter again [student year]: ";
    getline(cin,str);
    number = atoi(str.c_str());
  }
  return number;
}

int StudentGenderInput() {
  string str;
  int gender;
  getline(cin,str);
  while(str!="M" && str!="m" && str!="F" && str!="f"){
    cout<<"Invalid inputm re-enter again [student gender]: ";
    getline(cin, str);
  }
  if(str=="M" || str=="m") {
    return MALE;
  }else {
    return FEMALE;
  }
}

string CourseCodeInput() {
  cout<<"Enter the course code: ";
  string str;
  getline(cin, str);
  while(!Course::isValidCode(str)) {
    cout<<"Invalid input, re-enter again [course code]: ";
    getline(cin, str);
  }
  return str;
}

string CourseNameInput() {
  string str;
  getline(cin, str);
  while(!Course::isValidName(str)) {
    cout<<"Invalid Input, re-enter again [course name]: ";
    getline(cin, str);
  }
  return str;
}

int CourseCreditsInput() {
  string str;
  int number;
  getline(cin, str);
  number = atoi(str.c_str());
  while(!Course::isValidCredit(number)) {
    cout<<"Invalid input, re-enter again [course credit]: ";
    getline(cin, str);
    number = atoi(str.c_str());
  }
  return number;
}

int ExamMarkInput() {
  string str;
  int number;
  getline(cin, str);
  number = atoi(str.c_str());
  while(!CourseSelection::isValidExammark(number)) {
    cout<<"Invalid input, re-enter again [exam mark]: ";
    getline(cin, str);
    number = atoi(str.c_str());
  }
  return number;
}

void endOfLoop() {
  string str;
  cout<<"Hit ENTER to continue..."<<endl;
  getline(cin, str);
  return;
}

void StudentManagement() {
  int current_option;
  string option_str;
  system("clear");

  cout<<"HKUST Course Registration System (Student Menu)"<<endl;
  cout<<"------------------------------------------------"<<endl<<endl;
  cout<<"1. Insert Student Record"<<endl;
  cout<<"2. Modify Student Record"<<endl;
  cout<<"3. Delete Student Record"<<endl;
  cout<<"4. Query Student Record"<<endl;
  cout<<"5. Go back to main menu"<<endl<<endl;
  cout<<"Enter your choice (1-5): ";

  getline(cin, option_str);
  current_option = atoi(option_str.c_str());
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-5): ";
    getline(cin, option_str);
    current_option = atoi(option_str.c_str());
  }

  if(current_option == 1) {
    Student stu;

    stu.setStudentID(StudentIDInput());

    cout<<"Enter the student name: ";
    stu.setStudentName(StudentNameInput());

    cout<<"Enter the student year [1-3]: ";
    stu.setYear(StudentYearInput());

    cout<<"Enter the student gender [M,F]: ";
    stu.setGender(StudentGenderInput());

    if(stu.isValid() && rm.add(stu) == 0){
      cout<<"Creation of student record successful"<<endl<<endl;
    }else {
      cout<<"Creation of student record fail"<<endl<<endl;
    }

    endOfLoop();

  }else if(current_option == 2) {
    string str;
    Student* stuPtr = rm.queryStudent(StudentIDInput());

    if(stuPtr == NULL) {
      cout<<"Student not exist"<<endl<<endl;

    }else{
      cout<<"Enter the student name ["<<stuPtr->getStudentName()<<"]: ";
      stuPtr->setStudentName(StudentNameInput());

      int number;
      cout<<"Enter the student year["<<stuPtr->getYear()<<"]: ";
      stuPtr->setYear(StudentYearInput());

      string gender;
      if(stuPtr->getGender() == MALE) {gender="M";}
      else {gender="F";}
      cout<<"Enter the student gender ["<<gender<<"]: ";
      stuPtr->setGender(StudentGenderInput());

      cout<<"Modification of student record successful"<<endl<<endl;
    }

    endOfLoop();

  }else if(current_option == 3) {
    int result;
    result = rm.deleteStudent(StudentIDInput());
    if(result == 0) {
      cout<<"Deletion of student record successful"<<endl<<endl;
    }else if(result < 0) {
      cout<<"Student not exist"<<endl<<endl;
    }

    endOfLoop();

  }else if(current_option == 4) {
    Student* stuPtr;
    stuPtr = rm.queryStudent(StudentIDInput());
    if(stuPtr == NULL) {
      cout<<"Student not exist"<<endl<<endl;
    }else {
      cout<<endl;
      stuPtr->print();
      cout<<endl;
    }

    endOfLoop();

  }else if(current_option == 5) {
    return;
  }
}

void CourseManagement() {
  int current_option;
  string option_str;
  system("clear");

  cout<<"HKUST Course Registration System (Course Menu)"<<endl;
  cout<<"------------------------------------------------"<<endl<<endl;
  cout<<"1. Insert Course Record"<<endl;
  cout<<"2. Modify Course Record"<<endl;
  cout<<"3. Delete Course Record"<<endl;
  cout<<"4. Query Course Record"<<endl;
  cout<<"5. Go back to main menu"<<endl<<endl;
  cout<<"Enter your choice (1-5): ";

  getline(cin, option_str);
  current_option = atoi(option_str.c_str());
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-5): ";
    getline(cin, option_str);
    current_option = atoi(option_str.c_str());
  }

  if(current_option == 1) {
    Course cou;

    cou.setCourseCode(CourseCodeInput());

    cout<<"Enter the course name: ";
    cou.setCourseName(CourseNameInput());

    cout<<"Enter the course credits [0-5]: ";
    cou.setCredit(CourseCreditsInput());

    if(cou.isValid() && rm.add(cou) == 0) {
      cout<<"Creation of course record successful"<<endl<<endl;
    }else {
      cout<<"Creation of course record fail"<<endl<<endl;
    }

    endOfLoop();

  }else if(current_option == 2) {
    Course* couPtr;
    couPtr = rm.queryCourse(CourseCodeInput());

    if(couPtr == NULL) {
      cout<<"Course not exist"<<endl<<endl;
    }else {
      cout<<"Enter the course name["<<couPtr->getCourseName()<<"]: ";
      couPtr->setCourseName(CourseNameInput());

      cout<<"Enter the course credit["<<couPtr->getCredit()<<"]: ";
      couPtr->setCredit(CourseCreditsInput());

      cout<<"Modification of course record successful"<<endl<<endl;
    }

    endOfLoop();
  }else if(current_option == 3) {
    int result;
    result = rm.deleteCourse(CourseCodeInput());
    if(result == 0) {
      cout<<"Deletion of course record successful"<<endl<<endl;
    }else if(result < 0) {
      cout<<"Course not exist"<<endl<<endl;
    }

    endOfLoop();

  }else if(current_option == 4) {
    Course* couPtr;
    couPtr = rm.queryCourse(CourseCodeInput());
    if(couPtr == NULL) {
      cout<<"Course not exist"<<endl<<endl;
    }else {
      cout<<endl;
      couPtr->print();
      cout<<endl;
    }

    endOfLoop();
  }else if(current_option == 5) {
    return;
  }
}

void CourseRegistration() {
  int current_option;
  string option_str;
  system("clear");

  cout<<"HKUST Course Registration System (Registration Menu)"<<endl;
  cout<<"------------------------------------------------"<<endl<<endl;
  cout<<"1. Add Course"<<endl;
  cout<<"2. Drop Course"<<endl;
  cout<<"3. Modify Exam Mark"<<endl;
  cout<<"4. Query Registration"<<endl;
  cout<<"5. Go back to main menu"<<endl<<endl;
  cout<<"Enter your choice (1-5): ";

  getline(cin, option_str);
  current_option = atoi(option_str.c_str());
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-5): ";
    getline(cin, option_str);
    current_option = atoi(option_str.c_str());
  }

  if(current_option == 1) {

    Student* stu = rm.queryStudent(StudentIDInput());
    if(stu == NULL) {
      cout<<"Student not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    Course* cou = rm.queryCourse(CourseCodeInput());
    if(cou == NULL) {
      cout<<"Course not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    CourseSelection cs(stu, cou, UNASSIGNED);
    int result = rm.add(cs);

    if(result < 0) {
      cout<<"The student already registered the course"<<endl<<endl;
    }else {
      cout<<"Add course successful"<<endl<<endl;
    }

    endOfLoop();

  }else if(current_option == 2) {
    Student* stu = rm.queryStudent(StudentIDInput());
    if(stu == NULL) {
      cout<<"Student not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    Course* cou = rm.queryCourse(CourseCodeInput());
    if(cou == NULL) {
      cout<<"Course not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    int result = rm.deleteSelection(stu->getStudentID(), cou->getCourseCode());
    if(result == 0) {
      cout<<"Drop course successful"<<endl<<endl;
    }else {
      cout<<"The registration record not exist"<<endl<<endl;
    }

    endOfLoop();
    return;

  }else if(current_option == 3) {

    Student* stu = rm.queryStudent(StudentIDInput());
    if(stu == NULL) {
      cout<<"Student not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    Course* cou = rm.queryCourse(CourseCodeInput());
    if(cou == NULL) {
      cout<<"Course not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    CourseSelection* cs = rm.querySelection(stu->getStudentID(), cou->getCourseCode());
    if(cs == NULL) {
      cout<<"Registration record not exist"<<endl<<endl;
    }else {
      char mark_str[16];
      sprintf(mark_str, "%d", cs->getExamMark());
      cout<<"Enter the exam mark ["<< ((cs->getExamMark()==UNASSIGNED)? "UNASSIGNED": mark_str) <<"]: ";
      cs->setExamMark(ExamMarkInput());
      cout<<"Modification of the exam mark successful"<<endl<<endl;
    }

    endOfLoop();
    return;
  }else if(current_option == 4) {

    Student* stu = rm.queryStudent(StudentIDInput());
    if(stu == NULL) {
      cout<<"Student not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    Course* cou = rm.queryCourse(CourseCodeInput());
    if(cou == NULL) {
      cout<<"Course not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    CourseSelection* cs = rm.querySelection(stu->getStudentID(), cou->getCourseCode());
    if(cs == NULL) {
      cout<<"Registration record not exist"<<endl<<endl;
    }else {
      cout<<endl;
      cs->print();
      cout<<endl;
    }

    endOfLoop();
    return;
  }else if(current_option == 5) {
    return;
  }
}

void ReportManagement() {
  int current_option;
  string option_str;
  system("clear");

  cout<<"HKUST Course Registration System (Report Generation Menu)"<<endl;
  cout<<"------------------------------------------------"<<endl<<endl;
  cout<<"1. List all student information"<<endl;
  cout<<"2. List all course information"<<endl;
  cout<<"3. List all Courses of a student"<<endl;
  cout<<"4. List all students of a course"<<endl;
  cout<<"5. Go back to main menu"<<endl<<endl;
  cout<<"Enter your choice (1-5): ";

  getline(cin, option_str);
  current_option = atoi(option_str.c_str());
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-5): ";
    getline(cin, option_str);
    current_option = atoi(option_str.c_str());
  }

  if(current_option == 1) {
    rm.StudentsHTML();
    cout<<"Output successful"<<endl<<endl;
    endOfLoop();
    return;

  }else if(current_option == 2) {
    rm.CoursesHTML();
    cout<<"Output successful"<<endl<<endl;
    endOfLoop();
    return;

  }else if(current_option == 3) {
    Student* stu = rm.queryStudent(StudentIDInput());
    if(stu == NULL) {
      cout<<"Student not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    rm.CoursesOfStudentHTML(stu);

    cout<<"Output successful"<<endl<<endl;
    endOfLoop();
    return;

  }else if(current_option == 4) {
    Course* cou = rm.queryCourse(CourseCodeInput());
    if(cou == NULL) {
      cout<<"Course not exist"<<endl<<endl;
      endOfLoop();
      return;
    }

    rm.StudentsOfCourseHTML(cou);

    cout<<"Output successful"<<endl<<endl;
    endOfLoop();
    return;

  }else if(current_option == 5) {
    return;
  }
}

void FileManagement() {
  int current_option;
  string option_str;
  system("clear");

  cout<<"HKUST Course Registration System (File Menu)"<<endl;
  cout<<"------------------------------------------------"<<endl<<endl;
  cout<<"1. Save Database"<<endl;
  cout<<"2. Load Database"<<endl;
  cout<<"3. Go back to main menu"<<endl<<endl;
  cout<<"Enter your choice (1-3): ";

  getline(cin, option_str);
  current_option = atoi(option_str.c_str());
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-3): ";
    getline(cin, option_str);
    current_option = atoi(option_str.c_str());
  }

  if(current_option == 1) {
    cout<<"Enter the file name: ";
    string file_name;
    getline(cin, file_name);

    ofstream fout(file_name.c_str());
    if(!fout.is_open()) {
      cout<<"Cannot open the file"<<endl<<endl;
      endOfLoop();
      return;
    }

    rm.saveDataFile(fout);
    cout<<"Save data successful"<<endl<<endl;
    endOfLoop();
    return;
  }else if(current_option == 2) {
    cout<<"Enter the file name: ";
    string file_name;
    getline(cin, file_name);

    ifstream fin(file_name.c_str());
    if(!fin.is_open()) {
      cout<<"Cannot open the file"<<endl<<endl;
      endOfLoop();
      return;
    }

    rm.loadDataFile(fin);
  }else if(current_option == 3) {
    return;
  }
}

void main_loop() {
  int current_option;
  string option_str;
  system("clear");

  cout<<"HKUST Course Registration System"<<endl;
  cout<<"--------------------------------"<<endl<<endl;
  cout<<"1. Student Management"<<endl;
  cout<<"2. Course Management"<<endl;
  cout<<"3. Course Registration"<<endl;
  cout<<"4. Report Management"<<endl;
  cout<<"5. File Management"<<endl;
  cout<<"6. Exit" <<endl<<endl;
  cout<<"Enter your choice (1-6): ";

  getline(cin, option_str);
  current_option = atoi(option_str.c_str());
  while(current_option > 6 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-6): ";
    getline(cin, option_str);
    current_option = atoi(option_str.c_str());
  }

  if(current_option == 1) {
    StudentManagement();
  }else if(current_option == 2) {
    CourseManagement();
  }else if(current_option == 3) {
    CourseRegistration();
  }else if(current_option == 4) {
    ReportManagement();
  }else if(current_option == 5) {
    FileManagement();
  }else if(current_option == 6) {
    exit(0);
  }
  return;
}

int main() {

  while(true) {
    main_loop();
  }
}
