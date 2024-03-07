#include <string>

class Student
{
    std::string name;
    float math_grade;
    float english_grade;
    float history_grade;

public:
    void SetName(std::string name);
    std::string GetName() const;
    void SetMathGrade(float grade);
    float GetMathGrade() const;
    void SetEnglishGrade(float grade);
    float GetEnglishGrade() const;
    void SetHistoryGrade(float grade);
    float GetHistoryGrade() const;
    float GetAverage() const;
};

int CompareByName(const Student& s1, const Student& s2);
int CompareByMathGrade(const Student& s1, const Student& s2);
int CompareByEnglishGrade(const Student& s1, const Student& s2);
int CompareByHistoryGrade(const Student& s1, const Student& s2);
int CompareByAverage(const Student& s1, const Student& s2);