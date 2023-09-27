#include <iostream>
using namespace std;

bool isAlpha(char c) {
  int _c = (int) c;
  if( (_c < 65) || (_c > 122)) return false;
  else if((_c > 90) && (_c < 97)) return false;
  return true;
}

const char* toLower(char* lowStr) {
  for(int i = 0; lowStr[i] != '\0'; i++ )
    if(isAlpha(lowStr[i]) && (int) lowStr[i] < 91) lowStr[i] += 97 - 65;
  return lowStr;
}

int main() {
  char str[] = "HELLO";
  cout << str << " => " << toLower(str) << endl;
  return 0;
}
