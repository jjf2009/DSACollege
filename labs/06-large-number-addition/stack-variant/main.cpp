//main.cpp
#include "AOFBN.hpp"
#include <iostream>

int main() {
    while (true) {
        int dataType;
        std::cout << "\nChoose data type:\n"
                  << "1. int\n"
                  << "2. long\n"
                  << "3. long long\n"
                  << "4. float\n"
                  << "5. double\n"
                  << "Enter choice: ";
        std::cin >> dataType;
        
        std::cout << "Enter first number: ";
        double firstNum; 
        std::cin >> firstNum;
        
        std::cout << "Enter second number: ";
        double secondNum;
        std::cin >> secondNum;
        
        switch (dataType) {
            case 1: {
                BigAdder<int> calculator(static_cast<int>(firstNum), static_cast<int>(secondNum));
                calculator.number_to_stack();
                calculator.add();
                calculator.show_result();
                break;
            }
            case 2: {
                BigAdder<long> calculator(static_cast<long>(firstNum), static_cast<long>(secondNum));
                calculator.number_to_stack();
                calculator.add();
                calculator.show_result();
                break;
            }
            case 3: {
                BigAdder<long long> calculator(static_cast<long long>(firstNum), static_cast<long long>(secondNum));
                calculator.number_to_stack();
                calculator.add();
                calculator.show_result();
                break;
            }
            case 4: {
                BigAdder<float> calculator(static_cast<float>(firstNum), static_cast<float>(secondNum));
                calculator.number_to_stack();
                calculator.add();
                calculator.show_result();
                break;
            }
            case 5: {
                BigAdder<double> calculator(firstNum, secondNum);
                calculator.number_to_stack();
                calculator.add();
                calculator.show_result();
                break;
            }
            default:
                std::cout << "Invalid choice!" << std::endl;
                continue;
        }
        
        int continueChoice;
        std::cout << "\nAdd more numbers? (1=Yes, 0=Exit): ";
        std::cin >> continueChoice;
        if (continueChoice == 0) break;
    }
    return 0;
}