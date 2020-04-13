#include "StringBuilder.h"
#include <iostream>
#include <string>

using namespace std;

std::string StringBuilder(vector<string>& super_strings)
{
    std::string s;
    for (int j = 0; j < super_strings.size(); j++)
    {
        s += super_strings[j];
    }
    return s;
}
