#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Swap.h"
#include "NextSet.h"
#include "Overlap.h"

using namespace std;

//void print(int* a, int n)
//{
//    static int num = 1; 
//    cout.width(3);
//    cout << num++ << ": ";
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << endl;
//}

int main()
{
    ifstream f("SCSP_in.txt");
    string str;
    int n = 0;

    vector <string> sub_strings;
    vector <int> magic; // для удаления строк, явл. подстроками

    while (getline(f, str))
    {
        n++;
        sub_strings.push_back(str);
    }
    f.close();

    for (int i = 0; i < sub_strings.size(); i++) {
        string some_string;
        some_string = sub_strings[i];

        for (int j = 0; j < sub_strings.size(); j++) {

            size_t pos = some_string.find(sub_strings[j]);
            if (i != j) {
                if (pos != string::npos) {
                    int a = 0;
                    for (int k = 0; k < magic.size(); k++) {
                        if (j == magic[k]) {
                            a = 1;
                        }
                    }
                    if (a == 0) {
                        magic.push_back(j);
                    }
                }
            }
        }
    }

    struct strings {
        string value;
    };

    strings* list = new strings[n - magic.size()];

    ifstream fl("SCSP_in.txt");
    string s;

    int K = 0;
    int z = 0;

    for (int j = 0; j < n; j++)
    {
        getline(fl, s);
        int flag = 0;
        for (int i = 0; i < magic.size(); i++)
        {
            if (j == magic[i])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            list[z].value = s;
            z++;
        }

        if (K < s.length())
        {
            K = s.length();
        }
    }

    for (int i = 0; i < n - magic.size(); i++)
    {
        cout << list[i].value << endl;
    }

    K++;

    n = n - magic.size();

    int** table = new int* [n];
    for (int i = 0; i < n; i++)
    {
        table[i] = new int[n];
    }

    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < n; j++)
    //    {
    //        if (i != j)
    //        {
    //            table[i][j] = Overlap(list[i].value, list[j].value);
    //        }
    //        else
    //        {
    //            table[i][j] = 0;
    //        }
    //    }
    //}

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
    cout << "superstring:" << answer << endl;

    cout << answer.length() << endl;

    return 0;
}