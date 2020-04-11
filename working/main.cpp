#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Prefix.h"

using namespace std;
int Overlap(string s1, string s2)
{
    int overlap = 0;
    int len = 0;
    if (s1.length() <= s2.length())
    {
        len = s1.length();
    }
    else
    {
        len = s2.length();
    }
    for (int i = 0; i < len; i++)
    {
        string temp1;
        for (int j = 0; j <= i; j++)
        {
            char temp = s1[s1.length() - 1 - j];
            temp1 = temp + temp1;
        }
        string temp2;
        for (int j = 0; j <= i; j++)
        {
            char temp = s2[j];
            temp2 = temp2 + temp;
        }
        if (temp1 == temp2)
        {
            if (overlap < i + 1)
            {
                overlap = i + 1;
            }
        }
    }
    return overlap;
}