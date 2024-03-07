#include "NumberList.h"
#include <algorithm>
#include <stdio.h>
using namespace std;

void NumberList::Init()
{
    count = 0;
}

bool NumberList::Add(int x)
{
    if (count >= 10)
        return false;

    numbers[count] = x;
    count++;

    return true;
}

void NumberList::Sort()
{
    sort(numbers, numbers + count);
}

void NumberList::Print()
{
    for (int i = 0; i < count; i++)
    {
        printf("%i", numbers[i]);
    }
}