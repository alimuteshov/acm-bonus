#include "findSets.h"
#include "printSets.h"
#include <iostream>
#include <string>

using namespace std;

bool findSets(int arr[], int n, vector<int>& set1, vector<int>& set2, int sum1, int sum2, int pos)
{
    if (pos == n) 
    {
        if (sum1 == sum2) {
            printSets(set1, set2);
            return true;
        }

        else
            return false;
    }

    set1.push_back(arr[pos]);

    bool res = findSets(arr, n, set1, set2, sum1 + arr[pos],
        sum2, pos + 1);

    if (res)
        return res;

    set1.pop_back();
    set2.push_back(arr[pos]);

    res = findSets(arr, n, set1, set2, sum1, sum2 + arr[pos],
        pos + 1);
    if (res == false)
        if (!set2.empty())
            set2.pop_back();

    return res;
}