#include <iostream>

constexpr long double operator""_Kelvin(unsigned long long k) {
    return k - 273.15;
}

constexpr long double operator""_Fahrenheit(unsigned long long f) {
    return (f - 32.00) * 5 / 9;
}


int main() {


    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin is " << a << " Celsius." << std::endl;
    std::cout << "120 Fahrenheit is " << b << " Celsius." << std::endl;

    return 0;
}
