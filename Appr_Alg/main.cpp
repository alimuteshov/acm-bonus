#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Prefix.h"
#include "StringBuilder.h"
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

    vector<vector<int>> cycles;
    vector<int> cycle;

    bool* mark = new bool[n];

    for (int j = 0; j < n; j++) {
        mark[j] = false;
    }


    for (int i = 0; i < n; i++)
    {
        if (mark[i])
        {
            continue;
        }

        cycle.push_back(i);
        mark[i] = true;

        if (m[i] == cycle[0])
        {
            cycles.push_back(cycle);
            cycle = vector<int>();
            i = 0;
        }
        else
        {
            i = m[i] - 1;
        }
    }

    vector<string> super_strings;
    vector<int> ovs;
    for (int i = 0; i < (cycles.size()); i++)
    {
        string str;
        ovs = vector<int>();
        for (int j = 0; j < cycles[i].size() - 1; j++)
        {
            ovs.push_back(table[cycles[i][j]][cycles[i][j + 1]]);
        }

        int min = table[cycles[i][cycles[i].size() - 1]][cycles[i][0]];
        int shift = 0;

        for (int i = 0; i < ovs.size(); i++)
        {
            if (ovs[i] < min)
            {
                min = ovs[i];
                shift = i + 1;
            }

        }

        rotate(cycles[i].begin(), cycles[i].begin() + shift, cycles[i].end());

        for (int j = 0; j < cycles[i].size() - 1; j++) {
            str = str + Prefix(list[cycles[i][j]].value,table[cycles[i][j]][cycles[i][j + 1]]);
        }

        str += list[cycles[i][cycles[i].size() - 1]].value;

        super_strings.push_back(str);
    }

    cout << (StringBuilder(super_strings)) << endl;
    cout << ((StringBuilder(super_strings))).length() << endl;

    return 0;
}