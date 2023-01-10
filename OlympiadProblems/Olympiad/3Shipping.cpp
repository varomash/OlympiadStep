#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

float GetSumFromDataSet(ifstream& file);
float GetSumFromLine(ifstream& file);
void Shipping()
{
	ifstream file ("3Shipping.in");
	if (file.is_open())
	{
		int dsCount;
		file >> dsCount;
		for (int i = 0; i < dsCount; i++)
		{
			cout << fixed << setprecision(2) 
				<< GetSumFromDataSet(file) << endl;
		}
	}
	else
	{
		cout << "unable to open file\n";
	}

	file.close();
}

float GetSumFromDataSet(ifstream& file)
{
	int lineCount;
	file >> lineCount;
	float totalSum = 0;
	for (int i = 0; i < lineCount; i++)
	{
		totalSum += GetSumFromLine(file);
	}
	return totalSum;
}

float GetSumFromLine(ifstream& file)
{
	string name;
	float count;
	float price;
	
	file >> name >> count >> price;
	return count * price;
}


