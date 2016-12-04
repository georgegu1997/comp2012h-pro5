//For Register Project#5 of COMP 2012H @HKUST
//Auther: GU Qiao
//All rights reserved
//
//htmlgenerator.h
//will take doubltlinkedlist as input and generate the html file

#ifndef HTMLGENERATOR_H
#define HTMLGENERATOR_H
#include "doublylinkedlist.h"
#include "records.h"

//report all courses in courses.html
void reportAllCourses(DoublyLinkedList<Course>);

//report all students in student.html
void reportAllStudents(DoublyLinkedList<Student>);

//report all the students having taken a course
//input list should be selected and ordered
void reportStudentsOfCourse(const Course&, DoublyLinkedList<CourseSelection>);

//report all the courses that a students has taken
//input list shoulf be selected and ordered
void reportCoursesOfStudent(const Student&, DoublyLinkedList<CourseSelection>);

#endif
