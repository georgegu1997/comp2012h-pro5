#ifndef REGISTERMANAGER_H
#define REGISTERMANAGER_H
#include "doublylinkedlist.h"
#include "hashtable.h"
#include "records.h"
#include "htmlgenerator.h"
#include "constants.h"
#include "utility.h"

class RegisterManager {
  typedef HashTable<Student> StudentTable;
  typedef HashTable<Course> CourseTable;
  typedef DoublyLinkedList<CourseSelection> SelectionTable;
  typedef HashTable<IndexByID> IDIndexTable;
  typedef HashTable<IndexByCode> CodeIndexTable;

private:
  StudentTable students;
  CourseTable courses;
  SelectionTable selections;
  IDIndexTable id_indexes;
  CodeIndexTable code_indexes;

public:
  RegisterManager();
  ~RegisterManager();

  int add(const Student& stu);
  int add(const Course& cou);
  int add(const CourseSelection& cs);

  int drop(const string& id, const string& code);

  int deleteStudent(const string& id);
  int deleteCourse(const string& code);
  int deleteSelection(const string& id, const string& code);

  Student* queryStudent(const string& id);
  Course* queryCourse(const string& code);
  CourseSelection* querySelection(const string& id, const string& code);

  void StudentsHTML();
  void CoursesHTML();
  void StudentsOfCourseHTML(Course* cou);
  void CoursesOfStudentHTML(Student* stu);

  void readDataFile(char* file_name);
  void saveDataFile(char* file_name);
};


#endif
