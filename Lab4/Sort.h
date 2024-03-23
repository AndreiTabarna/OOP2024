#ifndef OOP4_1_SORT_H
#define OOP4_1_SORT_H

#endif //OOP4_1_SORT_H

#pragma once

class Sort
{
private:
    int* m_data;
    int m_size;
public:
    Sort(); // default constructor
    Sort(int numElements, int minValue, int maxValue); // constructor for generating random data
    Sort(const int* list, int size); // constructor for initializing using initializer list
    Sort(const char* str); // constructor for initializing from string
    Sort(int count, ...); // constructor for initializing using variadic arguments
    ~Sort(); // destructor
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print() const;
    int GetElementsCount() const;
    int GetElementFromIndex(int index) const;
};
