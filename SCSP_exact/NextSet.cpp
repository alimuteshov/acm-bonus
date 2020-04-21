#include "Swap.h"
#include "NextSet.h"
#include <iostream>
using namespace std;

bool NextSet(int* a, int n)
{
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false; // больше перестановок нет
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    Swap(a, j, k);
    int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
    while (l < r)
        Swap(a, l++, r--);
    return true;
}