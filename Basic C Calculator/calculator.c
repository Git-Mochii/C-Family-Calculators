#include <stdio.h>

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
                printf("Error: Division by zero\n");
                return x; // Return the unchanged value in case of division by zero
            }
        default:
            printf("Invalid operator: %c\n", op);
            return x; // Return the unchanged value for an invalid operator
    }
}

int main() {
    char op;
    double result = 0.0;
    int validInput = 1; // Use 1 for true, 0 for false
    int isFirstInput = 1; // Use 1 for true, 0 for false

    printf("Basic Calculator (C Version)\n");

    do {
        if (!isFirstInput) {
            printf("Enter an operator (+, -, *, /), or '=' to calculate: ");
            if (scanf(" %c", &op) != 1) {
                printf("Invalid input. Please try again.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue;
            }

            if (op == '=') {
                if (validInput) {
                    printf("Final result: %lf\n", result);
                } else {
                    printf("Invalid input detected. Calculation aborted.\n");
                }
                break;
            }

            if (op != '+' && op != '-' && op != '*' && op != '/') {
                printf("Invalid operator. Please try again.\n");
                validInput = 0; // Set to false
                continue;
            }
        } else {
            isFirstInput = 0; // Set to false
        }

        double num;
        printf("Enter a number: ");
        if (scanf("%lf", &num) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            validInput = 0; // Set to false
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            if (validInput) {
                result = num;
            }
        }
    } while (1);

    return 0;
}
