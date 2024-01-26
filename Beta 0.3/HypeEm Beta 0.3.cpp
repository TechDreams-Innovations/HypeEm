#include <iostream>
#include <string>
#include <cstdlib> // Include cstdlib for system function
#include <limits> // Include limits for std::numeric_limits
#include <ctime>
#include <vector>

void executePowerShellCommand(const std::string &command) {
    std::string powerShellCommand = "powershell -Command \"" + command + "\"";
    system(powerShellCommand.c_str());
}

int countWords(const std::string &text) {
    int wordCount = 0;
    bool inWord = false;

    for (char c : text) {
        if (std::ispunct(c)) {
            inWord = true;
            --wordCount;
        }
        if (std::isalpha(c)) {
            if (!inWord) {
                inWord = true;
                ++wordCount;
            }
        } else {
            inWord = false;
        }
    }

    return wordCount;
}

void proofreadText() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter text to proofread: ";
    std::string inputText;
    std::getline(std::cin, inputText);


    std::cout << "Proofread text: " << inputText << std::endl;
}

void calculator() {
    char operation;
    double num1, num2, result;

    std::cout << "Enter first number: ";
    if (!(std::cin >> num1)) {
        std::cerr << "Error reading the first number. Exiting..." << std::endl;
        return;
    }

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    if (!(std::cin >> num2)) {
        std::cerr << "Error reading the second number. Exiting..." << std::endl;
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

void hangmanGame() {
    std::vector<std::string> words = {"hangman", "programming", "apple", "computer", "language", "hype", "samsung", "google", "terminal", "app", "technology", "retro", "gaming", "phone", "bluetooth", "ios", "android"};
    srand(static_cast<unsigned int>(time(nullptr)));
    std::string selectedWord = words[rand() % words.size()];
    std::string guessedWord(selectedWord.length(), '_');
    int incorrectAttempts = 0;
    const int maxIncorrectAttempts = 6;

    while (true) {
        std::cout << "Word: " << guessedWord << std::endl;
        std::cout << "Incorrect attempts: " << incorrectAttempts << "/" << maxIncorrectAttempts << std::endl;
        char guess;
        std::cout << "Enter a letter: ";
        if (!(std::cin >> guess)) {
            std::cerr << "Error reading the letter. Exiting..." << std::endl;
            return;
        }
        size_t found = selectedWord.find(guess);
        if (found != std::string::npos) {
            while (found != std::string::npos) {
                guessedWord[found] = guess;
                found = selectedWord.find(guess, found + 1);
            }
        } else {
            ++incorrectAttempts;
        }

        if (guessedWord == selectedWord) {
            std::cout << "Congratulations! You guessed the word: " << selectedWord << std::endl;
            break;
        }
        if (incorrectAttempts == maxIncorrectAttempts) {
            std::cout << "Sorry, you ran out of attempts. The word was: " << selectedWord << std::endl;
            break;
        }
    }
}

int main() {
    printf("===| HypeEm Beta 0.3 Build HypePack |===\n");

    while (true) {
        std::string command;
        printf("Enter a command: ");

        if (!(std::cin >> command)) {
            std::cerr << "Error reading input. Exiting..." << std::endl;
            return 1;
        }

        if (command == "help") {
            printf("HypeEm Beta 0.3 Build HypePack\n");
            printf("Copyright 2023-2024 TechDreams Innovations\n");
            printf("cal: Opens calculator\n");
            printf("cls: Clears the screen\n");
            printf("info: Displays detailed info about HypeEm\n");
            printf("exit: Exits HypeEm\n");
            printf("powershell: Run a PowerShell command\n");
            printf("wordcount: Counts words in entered text\n");
            printf("proofread: Proofreads entered text\n");
            printf("hangman: Play a text-based Hangman game\n");
        } else if (command == "cal") {
            calculator();
        } else if (command == "cls") {
            system("cls"); // for Windows
        } else if (command == "info") {
            printf("HypeEm Beta 0.3 Build HypePack x86 (Win32/Spider32) \n");
            printf("(C) 2023-2024 TechDreams Innovations, All rights reserved\n");
            printf("For more info, visit https://www.github.com/TechDreams-Innovations/HypeEm \n");
        } else if (command == "powershell") {
            printf("Enter the PowerShell command: ");
            std::string powerShellCommand;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, powerShellCommand);
            executePowerShellCommand(powerShellCommand);
        } else if (command == "wordcount") {
            printf("Input text to count words: ");
            std::string inputText;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, inputText);
            int words = countWords(inputText);
            std::cout << "Word count: " << words << std::endl;
        } else if (command == "proofread") {
            proofreadText();
        } else if (command == "hangman") {
            hangmanGame();
        } else if (command == "exit") {
            exit(0);
        } else {
            std::cerr << "\'" << command << "\'" << " is an invalid command." << std::endl;
        }
    }

    return 0;
}