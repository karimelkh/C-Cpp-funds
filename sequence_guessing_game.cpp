#include <iostream>

int main() {
  int points = 0;
  int answers[3];
  int rightanswers[3] = {32, 21, 24};
  int seq[3][5] = {
    {2, 4, 8, 16, 32},
    {1, 8, 11, 18, 21},
    {3, 5, 10, 12, 24}
  };
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      std::cout << seq[i][j] << "\t";
    }
    std::cout << "\t?" << std::endl << std::endl;
  }
  std::cout << "Guess the last number of each row:" << std::endl;
  for(int i = 0; i < 3 ; i++) {
    std::cout << "Row " << i + 1 << " : ";
    std::cin >> answers[i];
  }
  for(int i = 0; i < 3; i++) {
    if(answers[i] == rightanswers[i]) {
      std::cout << "Row " << i + 1 << " is Correct." << std::endl;
      points++ ;
    }
    else
      std::cout << "Row " << i + 1 << " is Incorrect." << std::endl;
  }
  std::cout << "You got " << points << "/3." << std::endl;

  return 0;
}
