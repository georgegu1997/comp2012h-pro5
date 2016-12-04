//For Register Project#5 of COMP 2012H @HKUST
//Auther: GU Qiao
//All rights reserved
//
//registermanager.h
//Ther header file for the RegisterManager
//This class will store the instance of the HashTables and the DoublyLinkedLists
//Also provide interfaces to read write or delete the information

#ifndef REGISTERMANAGER_H
#define REGISTERMANAGER_H
#include "doublylinkedlist.h"
#include "hashtable.h"
#include "records.h"
#include "htmlgenerator.h"
#include "constants.h"
#include "utility.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

class RegisterManager {
  //Defien the type for convenience
  typedef HashTable<Student> StudentTable;
  typedef HashTable<Course> CourseTable;
  typedef DoublyLinkedList<CourseSelection> SelectionTable;
  typedef HashTable<IndexByID> IDIndexTable;
  typedef HashTable<IndexByCode> CodeIndexTable;

private:
  //Table for three kinds of records
  StudentTable students;
  CourseTable courses;
  SelectionTable selections;

  //Table for the indexes
  IDIndexTable id_indexes;
  CodeIndexTable code_indexes;

public:
  //Default constructor and destructor
  RegisterManager();
  ~RegisterManager();

  //add new records to the database
  int add(const Student& stu);
  int add(const Course& cou);
  int add(const CourseSelection& cs);

  //handling a student drops a course
  int drop(const string& id, const string& code);

  //handling deletion request
  //note that the student or course cannot be deletes if there is a registration record relating to them
  int deleteStudent(const string& id);
  int deleteCourse(const string& code);
  int deleteSelection(const string& id, const string& code);

  //query a Student or a Course
  //will return the point to the data  with all rights to read, write, revised.
  //will return NULL if the record not exist.
  Student* queryStudent(const string& id);
  Course* queryCourse(const string& code);
  CourseSelection* querySelection(const string& id, const string& code);

  //The interface to generate the HTMLfiles
  void StudentsHTML();
  void CoursesHTML();
  void StudentsOfCourseHTML(Course* cou);
  void CoursesOfStudentHTML(Student* stu);

  //The interface to save or load the dat file
  //The input is fstream.
  //The is_open() issue was handled by the UI part.
  int loadDataFile(ifstream& fout);
  int saveDataFile(ofstream& fin);
};


#endif
