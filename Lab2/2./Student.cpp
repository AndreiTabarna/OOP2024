#include "Student.h"

void Student::SetName(std::string name)
{
    this->name = name;
}

std::string Student::GetName() const
{
    return name;
}

void Student::SetMathGrade(float grade)
{
    math_grade = grade;
}

float Student::GetMathGrade() const
{
    return math_grade;
}

void Student::SetEnglishGrade(float grade)
{
    english_grade = grade;
}

float Student::GetEnglishGrade() const
{
    return english_grade;
}

void Student::SetHistoryGrade(float grade)
{
    history_grade = grade;
}

float Student::GetHistoryGrade() const
{
    return history_grade;
}

float Student::GetAverage() const
{
    return (math_grade + english_grade + history_grade) / 3.0f;
}

int CompareByName(const Student& s1, const Student& s2)
{
    if (s1.GetName() == s2.GetName())
        return 0;
    else if (s1.GetName() > s2.GetName())
        return 1;
    else
        return -1;
}

int CompareByMathGrade(const Student& s1, const Student& s2)
{
    if (s1.GetMathGrade() == s2.GetMathGrade())
        return 0;
    else if (s1.GetMathGrade() > s2.GetMathGrade())
        return 1;
    else
        return -1;
}

int CompareByEnglishGrade(const Student& s1, const Student& s2)
{
    if (s1.GetEnglishGrade() == s2.GetEnglishGrade())
        return 0;
    else if (s1.GetEnglishGrade() > s2.GetEnglishGrade())
        return 1;
    else
        return -1;
}

int CompareByHistoryGrade(const Student& s1, const Student& s2)
{
    if (s1.GetHistoryGrade() == s2.GetHistoryGrade())
        return 0;
    else if (s1.GetHistoryGrade() > s2.GetHistoryGrade())
        return 1;
    else
        return -1;
}

int CompareByAverage(const Student& s1, const Student& s2)
{
    if (s1.GetAverage() == s2.GetAverage())
        return 0;
    else if (s1.GetAverage() > s2.GetAverage())
        return 1;
    else
        return -1;
}