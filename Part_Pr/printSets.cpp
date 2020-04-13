#include "printSets.h"
#include <iostream>
#include <string>

using namespace std;

void printSets(vector<int> set1, vector<int> set2)
{
    int i;
    for (i = 0; i < set1.size(); i++) {
        cout << set1[i] << " ";
    }

    cout << "\n";
    for (i = 0; i < set2.size(); i++) {
        cout << set2[i] << " ";
    }
}