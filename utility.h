#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iostream>
#include <sstream>
#include "constants.h"
using namespace std;

//The hash function for student ID
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

//the hash function for course code
int CourseCodeHash(string code) {

}

#endif
