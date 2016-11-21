#ifndef HTMLGENERATOR_H
#define HTMLGENERATOR_H
#include "doublylinkedlist.h"
#include "record.h"


void reportAllCourses(const DoublyLinkedList<Course>&);

void reportAllStudents(const DoublyLinkedList<Student>&);

void reportStudentsOfCourse(const Course&, const DoublyLinkedList<CourseSelection>&);

void reportCoursesOfStudent(const Student&, const DoublyLinkedList<CourseSelection>&);

#endif
