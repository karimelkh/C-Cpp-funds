#include <iostream>
#include <cstdlib>
#include <random> // srand, rand
#include <time.h> // time

#define MAX_GUESS 10
#define EXIT_CHOICE 3

using namespace std;

void clearConsole() {
  system("clear");
  // system("cls");
}

void wait() {
  cout << "Press Enter to continue..."; // Display a message to prompt user
  cin.ignore(); // Wait for the user to press Enter
  cin.get(); // Continue after Enter is pressed
}

struct gameStats {
  int rounds, losses, wins;
  gameStats() {
    rounds = 0;
    losses = 0;
    wins = 0;
  }
  void displayStats() {
    clearConsole();
    cout << "===== Game Stats =====" << endl;
    cout << "- Played rounds: " << rounds << endl;
    cout << "- Wins: " << wins << endl;
    cout << "- Losses: " << losses << endl;
    cout << "======================" << endl;
    wait();
  }

};

void getChoice(int& choice) {
  clearConsole();
  cout << "===== Number Guessing Game Menu =====" << endl;
  cout << "1. Play" << endl;
  cout << "2. Display stats" << endl;
  cout << EXIT_CHOICE << ". Exit" << endl;
  cout << "=====================================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
}

void displayDiffLvls() {
  cout << "Difficulty Levels:" << endl;
  cout << "1. Easy (1-10)" << endl;
  cout << "2. Medium (1-50)" << endl;
  cout << "3. Hard (1-100)" << endl;
}

void playGame(gameStats& s) {

  s.rounds++ ;
  
  int diff_lvl, diff_val = 0;
  int number, response = 0, guesses = 0;

  displayDiffLvls();

  do {
    cout << "Enter your choice: ";
    cin >> diff_lvl;

    switch (diff_lvl) {
      case 1:
        diff_val = 10;
        break;
      case 2:
        diff_val = 50;
        break;
      case 3:
        diff_val = 100;
        break;
      default:
        cout << "Invalid choice, Try again!" << endl;
        diff_val = 0;
        break;
    }

  } while (diff_val == 0);

  clearConsole();

  number = rand() % diff_val + 1;

  do {

    cout << "Guess the number (1-" << diff_val <<"): ";
    cin >> response;
    
    guesses++ ;

    if(response > number)
      cout << "That was too hight!\n";
    else if (response < number)
      cout << "\rThat was too low!\n";
    else {
      s.wins++ ; //
      cout << "\rThat was correct!\n";
      cout << "The number was: " << number << "\nYou took " << guesses << "/10 guesses." << endl;
      break;
    }

    if(guesses == MAX_GUESS) {
      s.losses++ ; //
      cout << "Sorry, you've run out of guesses (10/10). The number was: " << number << "." << endl;
      break;
    }

  } while (1);

  wait();

  s.displayStats();

}

int main() {
  gameStats s;

  srand(time(NULL));

  int choice;

  do {

    getChoice(choice);
    
    switch (choice){
      case 1:
        clearConsole();
        playGame(s);
        break;
      case 2:
        s.displayStats();
        break;
      case EXIT_CHOICE:
        cout << "Bye!" << endl;
        exit(0);
      default:
        cout << "Invalid choice, try again!\n";
        choice = 0;
        break;
    }

  } while (choice != EXIT_CHOICE);

  return 0;
}
