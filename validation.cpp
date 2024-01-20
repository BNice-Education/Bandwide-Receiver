#include "validation.h"
#include <iostream>
#include <limits>

// Function for clearing input stream/errors
void QuickClear() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function for String Validation v2 (Prompts and Returns value)
std::string ValidateStringDef(const std::string& prompt) {
    std::string value;
    do {
        std::cout << prompt;
        std::getline(std::cin, value);

        if (!value.empty()) {
            return value;  // Return the valid non-empty string
        } else {
            std::cout << Prompts::InvalidInEmpty;
        }
    } while (true);
}

// Validate double v2 within a defined range & return that value
double ValidateDoubleDef(const std::string& prompt, double minOption, double maxOption) {
    double value;
    do {
        std::cout << prompt;
        std::cin >> value;

        // Check if input is a valid double and within the specified range
        if (std::cin.fail() || value < minOption || value > maxOption) {
            std::cout << "Invalid value. Please enter a number between " << minOption << " and " << maxOption << ".\n";
            QuickClear();
        } else {
            QuickClear();
            return value; // Valid input
        }
    } while (true);
}

// Validate Int v2, within a defined range & return that value
int ValidateIntDef(const std::string& prompt, int minOption, int maxOption) {
    int value;
    do {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < minOption || value > maxOption) {
            std::cout << "Invalid value. Please enter an Integer between " << minOption << " and " << maxOption << ".\n";
            QuickClear();
        } else {
            QuickClear(); 
            return value;  // Valid input
        }
    } while (true);
}

// Output Text For Boolean Toggle
void BoolToggleOut(std::string toggleName, std::string startVal, std::string endVal) {
    std::cout << "\n" + toggleName + " has been changed from " + startVal + " to " + endVal + ".";
}

// Function for User Menu loop
int UserMenuSelection(const std::string& menuText, int minOption, int maxOption) {
    int selection;
    do {
        std::cout << menuText;
        std::cin >> selection;
        if (std::cin.fail() || selection < minOption || selection > maxOption) {
            std::cout << "Invalid Selection. Choose a valid option with an integer between " << minOption << " and " << maxOption << ".\n";
            QuickClear();
        } else {
            QuickClear(); 
            return selection;  // Valid input
        }
    } while (true);
}

// Require User to Press Enter to continue
void UserConfirm() {
    std::cout << Prompts::EnterToContinue;
    std::string confirm; std::getline(std::cin, confirm);
}
