#include <iostream>
#include <string>
#include <cstdlib> // Include cstdlib for system function
#include <limits>  // Include limits for std::numeric_limits

void executePowerShellCommand(const std::string &command) {
    std::string powerShellCommand = "powershell -Command \"" + command + "\"";
    system(powerShellCommand.c_str());
}

void calculator() {
    char operation;
    double num1, num2, result;

    std::cout << "Enter first number: ";
    if (!(std::cin >> num1)) {
        std::cerr << "Error reading input. Exiting..." << std::endl;
        return;
    }

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    if (!(std::cin >> num2)) {
        std::cerr << "Error reading input. Exiting..." << std::endl;
        return;
    }

    switch (operation) {
    case '+':
        result = num1 + num2;
        std::cout << "Result: " << result << std::endl;
        break;
    case '-':
        result = num1 - num2;
        std::cout << "Result: " << result << std::endl;
        break;
    case '*':
        result = num1 * num2;
        std::cout << "Result: " << result << std::endl;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
            std::cout << "Result: " << result << std::endl;
        } else {
            std::cerr << "Error: Division by zero." << std::endl;
            return;
        }
        break;
    default:
        std::cerr << "Invalid operation." << std::endl;
    }
}

int main() {

    printf("===| HypeEm Alpha 0.0.3 Build 240124 |===\n");

    while (true) {

        std::string command;
        printf("Enter a command: ");

        if (!(std::cin >> command)) {
            std::cerr << "Error reading input. Exiting..." << std::endl;
            return 1;
        }

        if (command == "help") {
            printf("HypeEm Alpha 0.0.3 Build 240124\n");
            printf("Copyright 2023-2024 TechDreams Innovations\n");
            printf("cal: Opens calculator\n");
            printf("cls: Clears the screen\n");
            printf("info: Displays detailed info about HypeEm\n");
            printf("exit: Exits HypeEm\n");
            printf("powershell: Run a PowerShell command\n");
        } else if (command == "cal") {
            calculator();
        } else if (command == "cls") {
            system("cls"); // for Windows
        } else if (command == "info") {
            printf("HypeEm Alpha 0.0.3 Build 240124 x86 (Win32/Spider32) \n");
            printf("(C) 2023-2024 TechDreams Innovations, All rights reserved\n");
            printf("For more info, visit https://www.github.com/TechDreams-Innovations/HypeEm \n");
        } else if (command == "powershell") {
            printf("Enter the PowerShell command: ");
            std::string powerShellCommand;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, powerShellCommand);
            executePowerShellCommand(powerShellCommand);
        }
        else if (command == "exit")
        {
            exit(0);
        } else {
            std::cerr << "\'" << command << "\'" << " is an invalid command." << std::endl;
        }

    }

    return 0;
}