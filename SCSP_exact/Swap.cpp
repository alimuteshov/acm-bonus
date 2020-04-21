#include "Swap.h"
#include <iostream>
using namespace std;


void Swap(int* a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}