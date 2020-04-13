#include <iostream>
#include <string>
#include "findSets.h"

using namespace std;

bool isPartitionFeasible(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    vector<int> set1, set2;

    return findSets(arr, n, set1, set2, 0, 0, 0);
}