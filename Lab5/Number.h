#ifndef NUMBER_H
#define NUMBER_H

class Number
{
private:
    char* value;
    int base;
    int size;

    void RemoveMostSignificantDigit();
    void RemoveLeastSignificantDigit();

public:
    Number(const char* value, int base);
    Number(int value);
    Number(const Number& other);
    Number(Number&& other) noexcept;
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;

    friend Number operator+(const Number& left, const Number& right);
    friend Number operator-(const Number& left, const Number& right);
    char& operator[](int index);
    Number& operator--();
    Number operator--(int);
    bool operator==(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator>=(const Number& other) const;

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

};

#endif
