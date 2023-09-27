#include <iostream>
using namespace std;

bool isAlpha(char c) {
  int _c = (int) c;
  if( (_c < 65) || (_c > 122)) return false;
  else if((_c > 90) && (_c < 97)) return false;
  return true;
}

int main() {
  cout << isAlpha('a') << endl; // 1
  cout << isAlpha('?') << endl; // 0
  cout << isAlpha('1') << endl; // 0
  cout << isAlpha('A') << endl; // 1
  return 0;
}