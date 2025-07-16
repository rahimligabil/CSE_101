#include <stdio.h>
#include <stdlib.h>

float add() {
    float num1, num2;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    return num1 + num2;
}

float subtract() {
    float num1, num2;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    return num1 - num2;
}

float multiply() {
    float num1, num2;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    return num1 * num2;
}

void divide() {
    float num1, num2;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    if (num2 == 0) {
        printf("Error: Division by zero is undefined.\n");
    } else {
        printf("Result = %.4f\n", num1 / num2);
    }
}

void power() {
    float base, exponent;
    float result = 1;
    printf("Enter the base: ");
    scanf("%f", &base);
    printf("Enter the exponent: ");
    scanf("%f", &exponent);

    if (base == 0 && exponent == 0) {
        printf("Error: 0^0 is undefined.\n");
        return;
    }

    if (exponent < 0) {
        for (int i = -1; i >= exponent; i--) {
            result *= (1 / base);
        }
    } else if (exponent > 0) {
        for (int i = 1; i <= exponent; i++) {
            result *= base;
        }
    }

    printf("Result = %.4f\n", result);
}

void average() {
    float num, total = 0;
    int count = 0;
    float avg;

    printf("Enter numbers (type any character to finish):\n");
    while (1) {
        printf("Enter number: ");
        if (scanf("%f", &num) == 0) {
            break;
        }
        total += num;
        count++;
    }

    if (count == 0) {
        printf("No valid numbers entered.\n");
        return;
    }

    avg = total / count;
    printf("Average of %d numbers = %.4f\n", count, avg);
}

void find_max() {
    float num, max;
    int count = 0;
    printf("Enter numbers (type any character to finish):\n");
    while (1) {
        printf("Enter number: ");
        if (scanf("%f", &num) == 0) {
            break;
        }
        if (count == 0 || num > max) {
            max = num;
        }
        count++;
    }

    if (count == 0) {
        printf("No valid numbers entered.\n");
        return;
    }

    printf("Maximum number entered: %.4f\n", max);
}

void display_menu() {
    printf("\n%% WELCOME TO GTU CALCULATOR MACHINE %%\n");
    printf("%% STUDENT NAME: GABIL RAHIMLI       %%\n");
    printf("%% MENU %%\n");
    printf("1) Add two numbers\n");
    printf("2) Subtract two numbers\n");
    printf("3) Multiply two numbers\n");
    printf("4) Divide two numbers\n");
    printf("5) Calculate power of a number\n");
    printf("6) Calculate average of numbers\n");
    printf("7) Find the maximum of numbers\n");
    printf("0) Exit\n");
    printf("Please select an option: ");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Result = %.6f\n", add());
                break;
            case 2:
                printf("Result = %.6f\n", subtract());
                break;
            case 3:
                printf("Result = %.6f\n", multiply());
                break;
            case 4:
                divide();
                break;
            case 5:
                power();
                break;
            case 6:
                average();
                break;
            case 7:
                find_max();
                break;
            case 0:
                printf("Program exited.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
