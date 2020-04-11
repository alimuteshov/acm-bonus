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
string Prefix(string s1, int ov)
{
    return s1.substr(0, s1.length() - ov);
}

string StringBuilder(vector<string>& super_strings)
{
    string s;
    for (int j = 0; j < super_strings.size(); j++)
    {
        s += super_strings[j];
    }
    return s;
}


int main()
{
    /*string s1;
    string s2;
    cin >> s1;
    cin >> s2;*/


    ifstream f("SCSP_in.txt");
    string str;
    int n = 0;

    while (getline(f, str))
    {
        n++;
    }
    f.close();

    cout << n << endl;
    struct strings {
        string value;
    };
    strings* list = new strings[n];

    ifstream fl("SCSP_in.txt");
    string s;

    for (int j = 0; j < n; j++)
    {
        getline(fl, s);
        list[j].value = s;
    }

    for (int j = 0; j < n; j++)
    {
        cout << list[j].value << endl;
    }


    int** table = new int* [n];
    for (int i = 0; i < n; i++)
    {
        table[i] = new int[n];
    }

    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                table[i][j] = Overlap(list[i].value, list[j].value);
            }
            else
            {
                table[i][j] = 0;
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}
