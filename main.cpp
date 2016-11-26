#include "registermanager.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
using std::system;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

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

  current_option = atoi(option_str);
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-5): ";
    current_option = atoi(option_str);
  }

  if(current_option == 1) {

  }else if(current_option == 2) {

  }else if(current_option == 3) {

  }else if(current_option == 4) {

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

  current_option = atoi(option_str);
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-5): ";
    current_option = atoi(option_str);
  }

  if(current_option == 1) {

  }else if(current_option == 2) {

  }else if(current_option == 3) {

  }else if(current_option == 4) {

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

  current_option = atoi(option_str);
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-5): ";
    current_option = atoi(option_str);
  }

  if(current_option == 1) {

  }else if(current_option == 2) {

  }else if(current_option == 3) {

  }else if(current_option == 4) {

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

  current_option = atoi(option_str);
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-5): ";
    current_option = atoi(option_str);
  }

  if(current_option == 1) {

  }else if(current_option == 2) {

  }else if(current_option == 3) {

  }else if(current_option == 4) {

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

  current_option = atoi(option_str);
  while(current_option > 5 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-3): ";
    current_option = atoi(option_str);
  }

  if(current_option == 1) {

  }else if(current_option == 2) {

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

  current_option = atoi(option_str);
  while(current_option > 6 || current_option < 1) {
    cout<<"Invalid input, re-enter again (1-6): ";
    current_option = atoi(option_str);
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
}

int main() {
  RegisterManager rm;
  while(true) {
    main_loop();
  }
}
