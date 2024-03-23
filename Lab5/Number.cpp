#include "Number.h"
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;


Number::Number(const char* value, int base) {
    size = strlen(value);
    this->value = new char[size + 1];
    strcpy(this->value, value);
    this->base = base;
}


Number::Number(int value) {
    this->value = new char[11];
    sprintf(this->value, "%d", value);
    this->size = strlen(this->value);
    this->base = 10;
}


Number::Number(const Number& other) {
    this->value = new char[other.size + 1];
    strcpy(this->value, other.value);
    this->base = other.base;
    this->size = other.size;
}


Number::Number(Number&& other) noexcept {
    this->value = other.value;
    this->base = other.base;
    this->size = other.size;
    other.value = nullptr;
    other.size = 0;
}


Number::~Number() {
    delete[] value;
}


Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        value = new char[other.size + 1];
        strcpy(value, other.value);
        base = other.base;
        size = other.size;
    }
    return *this;
}


Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        value = other.value;
        base = other.base;
        size = other.size;
        other.value = nullptr;
        other.size = 0;
    }
    return *this;
}


Number operator+(const Number& left, const Number& right) {
    int maxSize = max(left.size, right.size);
    char* result = new char[maxSize + 2];
    result[maxSize + 1] = '\0';
    int carry = 0;
    int digitSum;
    for (int i = 0; i < maxSize; i++) {
        int leftDigit = (i < left.size) ? left.value[left.size - 1 - i] - '0' : 0;
        int rightDigit = (i < right.size) ? right.value[right.size - 1 - i] - '0' : 0;
        digitSum = leftDigit + rightDigit + carry;
        carry = digitSum / left.base;
        result[maxSize - i] = (digitSum % left.base) + '0';
    }
    if (carry > 0) {
        result[0] = carry + '0';
        return Number(result, left.base);
    }
    else {
        return Number(result + 1, left.base);
    }
}

Number operator-(const Number& left, const Number& right) {
    int maxSize = max(left.size, right.size);
    char* result = new char[maxSize + 1];
    result[maxSize] = '\0';
    int borrow = 0;
    int digitDiff;
    for (int i = 0; i < maxSize; i++) {
        int leftDigit = (i < left.size) ? left.value[left.size - 1 - i] - '0' : 0;
        int rightDigit = (i < right.size) ? right.value[right.size - 1 - i] - '0' : 0;
        digitDiff = leftDigit - rightDigit - borrow;
        if (digitDiff < 0) {
            digitDiff += left.base;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result[maxSize - 1 - i] = digitDiff + '0';
    }
    int new_size = maxSize;
    while (new_size > 1 && result[new_size - 1] == '0') {
        new_size--;
    }
    char* new_result = new char[new_size + 1];
    new_result[new_size] = '\0';
    for (int i = 0; i < new_size; i++) {
        new_result[i] = result[i];
    }
    delete[] result;
    return Number(new_result, left.base);
}


char& Number::operator[](int index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return value[size - 1 - index];
}


bool Number::operator==(const Number& other) const {
    if (size != other.size || base != other.base) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (value[i] != other.value[i]) {
            return false;
        }
    }
    return true;
}


bool Number::operator<(const Number& other) const {
    if (size < other.size) {
        return true;
    }
    if (size > other.size) {
        return false;
    }
    for (int i = size - 1; i >= 0; i--) {
        if (value[i] < other.value[i]) {
            return true;
        }
        if (value[i] > other.value[i]) {
            return false;
        }
    }
    return false;
}


bool Number::operator>(const Number& other) const {
    return !(*this == other || *this < other);
}


bool Number::operator<=(const Number& other) const {
    return (*this == other || *this < other);
}


bool Number::operator>=(const Number& other) const {
    return !(*this < other);
}


void Number::SwitchBase(int newBase) {
    if (base == newBase) {
        return;
    }
    int num = 0;
    for (int i = 0; i < size; i++) {
        num = num * base + (value[i] - '0');
    }
    if (num == 0) {
        value[0] = '0';
        value[1] = '\0';
        size = 1;
        base = newBase;
        return;
    }
    char* new_value = new char[99999];
    int new_size = 0;
    while (num > 0) {
        new_value[new_size++] = (num % newBase) + '0';
        num /= newBase;
    }
    for (int i = 0; i < new_size / 2; i++) {
        char temp = new_value[i];
        new_value[i] = new_value[new_size - i - 1];
        new_value[new_size - i - 1] = temp;
    }
    new_value[new_size] = '\0';
    delete[] value;
    value = new_value;
    size = new_size;
    base = newBase;
}

void Number::RemoveMostSignificantDigit() {
    if (size > 1) {
        char* new_value = new char[size];
        for (int i = 0; i < size - 1; i++) {
            new_value[i] = value[i];
        }
        new_value[size - 1] = '\0';
        delete[] value;
        value = new_value;
        size--;
    }
    else {
        value[0] = '0';
    }
}

void Number::RemoveLeastSignificantDigit() {
    if (size > 1) {
        size--;
        value[size] = '0';
    }
}

Number& Number::operator--() {
    RemoveMostSignificantDigit();
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    RemoveLeastSignificantDigit();
    return temp;
}

void Number::Print() const {
    std::cout << value << std::endl;
}


int Number::GetDigitsCount() const {
    return size;
}


int Number::GetBase() const {
    return base;
}