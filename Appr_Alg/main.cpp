#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Overlap.h"

using namespace std;
int main()
{
    ifstream f("SCSP_in.txt");
    string str;
    int n = 0;

    while (getline(f, str))
    {
        n++;
    }
    f.close();

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
            arr[i][j] = table[i][j];
        }
    }

    int* m = new int[n];

    for (int i = 0; i < n; i++)
    {
        int max = -1;
        int max_i;
        int max_j;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                max_i = i;
                max_j = j;
            }
        }
        for (int k = 0; k < n; k++)
        {
            arr[max_i][k] = -1;
            arr[k][max_j] = -1;
        }
        m[max_i] = max_j;
    }

    return 0;
}