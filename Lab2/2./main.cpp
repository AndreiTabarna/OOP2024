#include "Student.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    Student s1, s2, s3;
    s1.SetName("Andrei");
    s1.SetMathGrade(8.5f);
    s1.SetEnglishGrade(7.2f);
    s1.SetHistoryGrade(6.9f);
    s2.SetName("Tudor");
    s2.SetMathGrade(6.8f);
    s2.SetEnglishGrade(7.9f);
    s2.SetHistoryGrade(8.7f);
    s3.SetName("Ion");
    s3.SetMathGrade(9.3f);
    s3.SetEnglishGrade(8.4f);
    s3.SetHistoryGrade(7.1f);

    std::cout << "Compare by name: " << CompareByName(s1, s2) << std::endl;
    std::cout << "Compare by name: " << CompareByName(s2, s3) << std::endl;
    std::cout << "Compare by name: " << CompareByName(s1, s3) << std::endl;

    std::cout << "Compare by math grade: " << CompareByMathGrade(s1, s2) << std::endl;
    std::cout << "Compare by math grade: " << CompareByMathGrade(s2, s3) << std::endl;
    std::cout << "Compare by math grade: " << CompareByMathGrade(s1, s3) << std::endl;

    std::cout << "Compare by english grade: " << CompareByEnglishGrade(s1, s2) << std::endl;
    std::cout << "Compare by english grade: " << CompareByEnglishGrade(s2, s3) << std::endl;
    std::cout << "Compare by english grade: " << CompareByEnglishGrade(s1, s3) << std::endl;
}