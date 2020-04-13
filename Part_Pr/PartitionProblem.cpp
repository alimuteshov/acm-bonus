#include"isPartitionFeasible.h"
#include"findSets.h"
#include"printSets.h"
#include<vector>
#include<iostream>
#include <fstream>
using namespace std;

int main()
{

	vector <int> temp;

	ifstream in_file("input.txt");

	if (in_file)

		while (!in_file.eof())
		{
			int read_value;

			if (in_file >> read_value) 
			{
				temp.push_back(read_value);
			}
		}
	in_file.close();
	int *arr = new int[temp.size()];
	for (int j = 0; j < temp.size(); j++)
	{
		arr[j] = temp[j];
	}
	if (!isPartitionFeasible(arr, temp.size()))
	{
		cout << "-1";
	}
	return 0;
}