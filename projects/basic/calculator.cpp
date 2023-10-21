#include <iostream>
#include <iomanip>

void displayResult(float a, float b, char op, float r, int m = 2) {
  std::cout << "Result: " << a << " " << op << " " << b << " = ";
  std::cout << std::fixed << std::setprecision(m) << r << std::endl;
}

float calc(float a, float b, char o) {
  switch(o) {
    case '+':
      return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if(b != 0)
            return a / b;
        else
            std::cout << "Can't devide over 0.\n";
            return 1;
        break;
    default:
        std::cout << "Invalid opertaion.\n";
        return 1;
  }
}

int main() {

	float firstOperand = 0;
	float secondOperand = 0;
	char operation = '\0';
    float result = 0;

	std::cout << "Enter the first operand: ";
	std::cin >> firstOperand;
	std::cout << "Enter the second operand: ";
	std::cin >> secondOperand;
	std::cout << "Enter the operation (+, -, * or /): ";
	std::cin >> operation;

    result = calc(firstOperand, secondOperand, operation);
    displayResult(firstOperand, secondOperand, operation, result);

	return 0;
}

/*
Some additional features to add to the calculator program:
  1. **Memory Functions:** Add memory storage functions such as "M+" (add to memory), "M-" (subtract from memory), "MR" (recall from memory), and "MC" (clear memory).
  2. **Scientific Calculator Functions:** Include advanced mathematical functions like trigonometric functions (sin, cos, tan), logarithms (log), exponentials (exp), and square root (sqrt).
  3. **History:** Implement a history feature that keeps track of past calculations and allows the user to review or reuse them.
  4. **Unit Conversion:** Add unit conversion capabilities, such as converting between different units of measurement (e.g., inches to centimeters, pounds to kilograms).
  5. **Custom Functions:** Allow users to define and save their custom functions for repeated use.
  6. **Expression Parsing:** Extend your calculator to handle more complex expressions, such as "(2 + 3) * 4" or "sin(30)".
*/
