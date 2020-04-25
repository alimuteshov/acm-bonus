#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include "Swap.h"
#include "NextSet.h"
#include "Overlap.h"

using namespace std;

int main()
{
    ifstream f("SCSP_in.txt");
    string str;
    int n = 0;

    set<int>clone; // для удаления строк, явл. подстроками
    vector <string> sub_strings;

    while (getline(f, str))
    {
        n++;
        sub_strings.push_back(str);
    }
    f.close();
    for (int i = 0; i < sub_strings.size(); i++)
    {
        for (int j = i+1; j < sub_strings.size(); j++)
        {
            if (sub_strings[i] == sub_strings[j])
            {
                clone.insert(j);
            }
        }
    }

    for (int i = 0; i < sub_strings.size(); i++) {
        string some_string;
        some_string = sub_strings[i];

        for (int j = 0; j < sub_strings.size(); j++) {
            if (clone.find(i) == clone.end() && clone.find(j) == clone.end()&&i!=j)
            {
                size_t pos = some_string.find(sub_strings[j]);
                if (pos != string::npos)
                {
                    clone.insert(j);
                }
            }
        }
    }

    struct strings {
        string value;
    };

    strings* list = new strings[n - clone.size()];

    int K = 0;
    int z = 0;

    for (int j = 0; j < n; j++)
    {
        int flag = 0;
        if (clone.find(j) != clone.end())
        {
            flag = 1;
        }

        if (flag == 0)
        {
            list[z].value = sub_strings[j];
            z++;
        }

        if (K < sub_strings[j].length())
        {
            K = sub_strings[j].length();
        }
    }
    K++;
    n = n - clone.size();

    int** table = new int* [n];
    for (int i = 0; i < n; i++)
    {
        table[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                table[i][j] = K - Overlap(list[i].value, list[j].value);
            }
            else
            {
                table[i][j] = 0;
            }
        }
    }

    int* a = new int[n];
    int path = 0;
    int* solution = new int[n];

    for (int i = 0; i < n; i++)
        a[i] = i;

    for (int i = 0; i < n - 1; i++)
    {
        path += table[a[i]][a[i + 1]];
    }

    for (int i = 0; i < n; i++)
    {
        solution[i] = a[i];
    }
    while (NextSet(a, n))
    {
        int temp = 0;
        for (int i = 0; i < n - 1; i++)
        {
            temp += table[a[i]][a[i + 1]];
        }
        if (temp < path)
        {
            path = temp;
            for (int i = 0; i < n; i++)
            {
                solution[i] = a[i];
            }
        }
    }
    delete[] a;
    for (int i = 0; i < n; ++i)
    {
        delete[] table[i];
    }
    string answer;
    for (int i = 0; i < (list[solution[0]].value).length(); i++)
    {
        answer += list[solution[0]].value[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = Overlap(list[solution[i - 1]].value, list[solution[i]].value); j < (list[solution[i]].value).length(); j++)
        {
            answer += list[solution[i]].value[j];
        }
    }
    delete[] list;
    delete[] solution;

    cout << "superstring:" << answer << endl;
    cout << answer.length() << endl;
    return 0;
}