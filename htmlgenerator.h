#ifndef HTMLGENERATOR_H
#define HTMLGENERATOR_H
#include "doublylinkedlist.h"
#include "records.h"


void reportAllCourses(DoublyLinkedList<Course>);

void reportAllStudents(DoublyLinkedList<Student>);

void reportStudentsOfCourse(const Course&, DoublyLinkedList<CourseSelection>);

void reportCoursesOfStudent(const Student&, DoublyLinkedList<CourseSelection>);

#endif
