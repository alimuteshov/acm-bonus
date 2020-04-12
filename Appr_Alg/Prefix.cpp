#include "Prefix.h"
#include <iostream>
#include <string>

using namespace std;


string Prefix(string s1, int ov)
{
    return s1.substr(0, s1.length() - ov);
}