#include "Sort.h"
#include <iostream>

int main()
{
    std::cout << "Creating Sort object using default constructor\n";
    Sort s1;
    s1.Print();

    std::cout << "\nCreating Sort object using constructor with random values\n";
    Sort s2(10, 1, 100);
    s2.Print();

    std::cout << "\nCreating Sort object using constructor with initializer list\n";
    int initList[] = { 5, 2, 7, 1, 8, 4 };
    Sort s3(initList, 6);
    s3.Print();

    std::cout << "\nCreating Sort object using constructor with variadic arguments\n";
    Sort s5(4, 5, 2, 8, 1);
    s5.Print();

    std::cout << "\nCreating Sort object using constructor with string\n";
    Sort s6("10,40,100,5,70");
    s6.Print();

    std::cout << "\nInsertSort (ascending):\n";
    s3.InsertSort(true);
    s3.Print();

    std::cout << "\nQuickSort (descending):\n";
    s2.QuickSort(false);
    s2.Print();

    std::cout << "\nBubbleSort (ascending):\n";
    s1.BubbleSort(true);
    s1.Print();

    std::cout << "\nNumber of elements in s5: " << s5.GetElementsCount() << std::endl;
    std::cout << "Element at index 2 in s5: " << s5.GetElementFromIndex(2) << std::endl;

    return 0;
}
