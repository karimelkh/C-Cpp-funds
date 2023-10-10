#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

#define TIE "Tie!"
#define LOSE "You lose!"
#define WIN "You win!"

void log(string m) {
  cout << m << endl;
}

string getMove(const int choice) {
  if(choice == ROCK) return "rock";
  else if(choice == PAPER) return "paper";
  else if(choice == SCISSORS) return "scissors";
  return "";
}

string getComputerMove() {
  int number = rand() % 3 + 1;
  return getMove(number);
}

string getUserMove() {
  int choice;
  do {
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if(choice < 4 && choice > 0) break;
  } while (1);
  return getMove(choice);
}

string getResult(string user, string computer) {
  if(user == computer) return TIE;
  else if(user == "rock" && computer == "paper") return LOSE;
  else if(user == "rock" && computer == "scissors") return WIN;
  else if(user == "paper" && computer == "rock") return WIN;
  else if(user == "paper" && computer == "scissors") return LOSE;
  else if(user == "scissors" && computer == "rock") return LOSE;
  else if(user == "scissors" && computer == "paper") return WIN;
  return "";
}

void playRPS(int& t, int& l, int& w) {
  string user = getUserMove(), computer = getComputerMove();
  string result = getResult(user, computer);
  log("You: " + user + " - " + computer + " : Computer");
  log(result);
  if(result == TIE) t++ ;
  else if(result == LOSE) l++ ;
  else if(result == WIN) w++ ;
  cout << "Ties: " << t << ", Losses: " << l << ", Wins: " << w << "." << endl;
}

int main() {
  int c;
  int ties = 0, wins = 0, losses = 0;
  srand(time(NULL));
  do {
    playRPS(ties, wins, losses);
    log("1. Play\n0. Exit");
    cout << "Enter you choice: ";
    cin >> c;
  } while(c != 0);
  return 0;
}
