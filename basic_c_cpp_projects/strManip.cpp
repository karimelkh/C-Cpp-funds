#include <iostream>
using namespace std;

bool isAlpha(char c) {
  int _c = (int) c;
  if( (_c < 65) || (_c > 122)) return false;
  else if((_c > 90) && (_c < 97)) return false;
  return true;
}

char* toLower(char* lowStr) {
  for(int i = 0; lowStr[i] != '\0'; i++ )
    if(isAlpha(lowStr[i]) && (int) lowStr[i] < 91) lowStr[i] += 97 - 65;
  return lowStr;
}

void capitalize(char* str) {
  int i = 0;
  char prevc = ' ';
  while(str[i] != '\0') {
    if(isAlpha(str[i]) && (int) str[i] > 89 && (int) str[i] < 123 && prevc == ' ')
      str[i] -= 32;
    prevc = str[i++];
  }
}

int main() {
  char str[] = "are u sure u want to do that?";
  cout << str << " => ";
  capitalize(str);
  cout << str << endl;
  return 0;
}
