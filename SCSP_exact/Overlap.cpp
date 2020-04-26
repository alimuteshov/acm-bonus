#include "Overlap.h"
#include <iostream>
#include <string>

using namespace std;

int Overlap(string s1, string s2)
{
    /*KMP */
    int s1_length = s1.length();
    int s2_length = s2.length();
    if (s1_length == 0 || s2_length == 0)
    {
        return 0;
    }
    if (s1_length > s2_length)
    {
        string temp;
        for (int i = s1_length - s2_length; i < s1_length; i++)
        {
            temp += s1[i];
        }
        s1 = temp;
    }
    else if (s1_length < s2_length)
    {
        string temp;
        for (int i = 0; i < s1_length; i++)
        {
            temp += s2[i];
        }
        s2 = temp;
    }
    int text_length = 0;
    if (s1_length <= s2_length)
    {
        text_length = s1_length;
    }
    else
    {
        text_length = s2_length;
    }
    if (s1 == s2)
    {
        return text_length;
    }
    int* array = new int[text_length];
    for (int i = 0; i < text_length; i++)
    {
        array[i] = 0;
    }
    array[0] = -1;
    int pos = 2;
    int cnd = 0;
    while (pos < text_length)
    {
        if (s2[pos - 1] == s2[cnd])
        {
            cnd += 1;
            array[pos] = cnd;
            pos += 1;
        }
        else if (cnd > 0)
        {
            cnd = array[cnd];
        }
        else
        {
            array[pos] = 0;
            pos += 1;
        }
    }
    int m = 0;
    int i = 0;
    while (m + i < text_length)
    {
        if (s2[i] == s1[m + i])
        {
            i += 1;
            if (m + i == text_length)
            {
                delete[] array;
                return i;
            }
        }
        else
        {
            m += i - array[i];
            if (array[i] > -1)
            {
                i = array[i];
            }
            else
            {
                i = 0;
            }
        }
    }
    delete[] array;
    return 0;
}