#include <string>
#include <regex>
#include <iostream>
using namespace std;

int main() {
  string s1, s2, s3, s4, s5;
  s1 = "12312312";
  s2 = "123asd";
  s3 = "asd123";
  s4 = "asdfgh";
  s5 = "COMP2012H";
  cout<<regex_match(s1, regex("[[:digit:]]+"))<<endl;
  cout<<regex_match(s2, regex("[0-9]+"))<<endl;
  cout<<regex_match(s3, regex("[0-9]+"))<<endl;
  cout<<regex_match(s4, regex("[0-9]+"))<<endl;
  cout<<regex_match(s5, regex("[[:upper:]]{4}[[:d:]]+[[:upper:]]?"))<<endl;
}
