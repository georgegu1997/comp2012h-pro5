#include "utility.h"
#include <iostream>
using namespace std;

int main() {
  cout<<StudentIDHash("00000001")<<endl;
  cout<<StudentIDHash("00000002")<<endl;
  cout<<StudentIDHash("00000003")<<endl;
  cout<<StudentIDHash("00000004")<<endl;

  cout<<CourseCodeHash("COMP2012H")<<endl;
  cout<<CourseCodeHash("COMP300Y")<<endl;
}
