#include <iostream>
#include <string>
#include <limits>

double performCalculation(double x, double y, char op) {
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y != 0) {
                return x / y;
            } else {
                std::cout << "Error: Division by zero" << std::endl;
                return x; // Return the unchanged value in case of division by zero
            }
        default:
            std::cout << "Invalid operator: " << op << std::endl;
            return x; // Return the unchanged value for an invalid operator
    }
}

int main() {
    char op;
    double result = 0.0;
    bool validInput = true;
    bool isFirstInput = true;

    std::cout << "Basic Calculator (C++ Version)" << std::endl;

    do {
        if (!isFirstInput) {
            std::cout << "Enter an operator (+, -, *, /), or '=' to calculate: ";
            if (!(std::cin >> op)) {
                std::cout << "Invalid input. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (op == '=') {
                if (validInput) {
                    std::cout << "Final result: " << result << std::endl;
                } else {
                    std::cout << "Invalid input detected. Calculation aborted." << std::endl;
                }
                break;
            }

            if (op != '+' && op != '-' && op != '*' && op != '/') {
                std::cout << "Invalid operator. Please try again." << std::endl;
                validInput = false;
                continue;
            }
        } else {
            isFirstInput = false;
        }

        double num;
        std::cout << "Enter a number: ";
        if (!(std::cin >> num)) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            validInput = false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if (validInput) {
                result = num;
            }
        }
    } while (true);

    return 0;
}
