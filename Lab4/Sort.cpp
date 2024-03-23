#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <functional>
#include <random>
#include <sstream>

Sort::Sort() : m_data(nullptr), m_size(0) {}

Sort::Sort(int n, int minVal, int maxVal) : m_size(n)
{
    m_data = new int[m_size];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(minVal, maxVal);

    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = dis(gen);
    }
}

Sort::Sort(const int* list, int size) : m_size(size)
{
    m_data = new int[m_size];

    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = list[i];
    }
}

Sort::Sort(const char* str)
{
    std::stringstream ss(str);
    std::string token;

    // Count the number of elements
    m_size = 0;
    while (std::getline(ss, token, ','))
    {
        m_size++;
    }

    // Allocate memory for data
    m_data = new int[m_size];

    // Reset stringstream for extracting data
    ss.clear();
    ss.seekg(0);

    // Read and store the elements
    for (int i = 0; i < m_size; i++)
    {
        std::getline(ss, token, ',');
        m_data[i] = std::stoi(token);
    }
}


Sort::Sort(int count, ...)
{
    m_size = count;
    m_data = new int[m_size];

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        m_data[i] = va_arg(args, int);
    }

    va_end(args);
}

Sort::~Sort()
{
    delete[] m_data;
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < m_size; ++i)
    {
        int key = m_data[i];
        int j = i - 1;

        while (j >= 0 && (ascendent ? m_data[j] > key : m_data[j] < key))
        {
            m_data[j + 1] = m_data[j];
            --j;
        }

        m_data[j + 1] = key;
    }
}

void Sort::QuickSort(bool ascendent)
{
    std::function<void(int, int)> quickSort = [&](int left, int right)
    {
        if (left < right)
        {
            int pivot = m_data[left];
            int i = left - 1;
            int j = right + 1;

            while (true)
            {
                do
                {
                    ++i;
                } while (ascendent ? m_data[i] < pivot : m_data[i] > pivot);

                do
                {
                    --j;
                } while (ascendent ? m_data[j] > pivot : m_data[j] < pivot);

                if (i >= j)
                {
                    break;
                }

                std::swap(m_data[i], m_data[j]);
            }

            quickSort(left, j);
            quickSort(j + 1, right);
        }
    };

    quickSort(0, m_size - 1);
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < m_size - 1; i++)
    {
        for (int j = 0; j < m_size - i - 1; j++)
        {
            if (ascendent ? m_data[j] > m_data[j + 1] : m_data[j] < m_data[j + 1])
            {
                std::swap(m_data[j], m_data[j + 1]);
            }
        }
    }
}

void Sort::Print() const
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount() const
{
    return m_size;
}

int Sort::GetElementFromIndex(int index) const
{
    return m_data[index];
}
