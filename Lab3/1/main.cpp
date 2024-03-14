#include "Math.h"
#include <iostream>

int main() {
    std::cout << "Math::Add(1, 2) = " << Math::Add(1, 2) << std::endl;
    std::cout << "Math::Add(1, 2, 3) = " << Math::Add(1, 2, 3) << std::endl;
    std::cout << "Math::Add(1.5, 2.5) = " << Math::Add(1.5, 2.5) << std::endl;
    std::cout << "Math::Add(1.5, 2.5, 3.5) = " << Math::Add(1.5, 2.5, 3.5) << std::endl;
    std::cout << "Math::Mul(2, 3) = " << Math::Mul(2, 3) << std::endl;
    std::cout << "Math::Mul(2, 3, 4) = " << Math::Mul(2, 3, 4) << std::endl;
    std::cout << "Math::Mul(2.5, 3.5) = " << Math::Mul(2.5, 3.5) << std::endl;
    std::cout << "Math::Mul(2.5, 3.5, 4.5) = " << Math::Mul(2.5, 3.5, 4.5) << std::endl;
    
    std::cout << "Math::Add(3, 1, 2, 3) = " << Math::Add(3, 1, 2, 3) << std::endl;
    
    char* result = Math::Add("Hello, ", "world!");
    if (result != nullptr) {
        std::cout << "Math::Add(\"Hello, \", \"world!\") = " << result << std::endl;
        delete[] result; // Free allocated memory
    } else {
        std::cout << "One of the strings is nullptr" << std::endl;
    }
    
    return 0;
}

