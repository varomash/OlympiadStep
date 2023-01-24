#include <iostream>
#include <fstream>
#include <math.h>
#include "8TractorPath.h"
using namespace std;
bool TraverseFromPoint(char** field, int i, int j, int fieldSize);

void TractorPath()
{
	//ifstream file ("tractorPath03.in");
	//ifstream file ("tractorPath04.in");
	ifstream file ("tractorPath05.in");
	if (file.is_open())
	{
		int fieldSize = 0;
		file >> fieldSize;
		char** field = new char* [fieldSize];
		field[0] = new char[fieldSize*fieldSize];
		memset(field[0], '.', fieldSize * fieldSize);

		for (int i = 1; i < fieldSize; i++)
		{
			field[i] = field[i - 1] + fieldSize;
		}

		for (int i = 0; i < fieldSize; i++)
		{

			for (int j = 0; j < fieldSize; j++)
			{
				file >> field[i][j];
				//cout <<"["<<i<<"]"<<"["<<j<<"]"<<field[i][j];
				cout <<field[i][j];
			}
			cout << endl;
		}

		if (TraverseFromPoint(field, 0, 0, fieldSize) == true)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}

		delete[] field[0];
		delete[] field;
	}
	else
	{
		cout << "unable to open file\n";
	}

	file.close();
}

bool TraverseFromPoint(char** field, int i, int j, int fieldSize)
{
	if ((i >= fieldSize) || (j >= fieldSize))
	{
		return false;
	}
	else if ((i == fieldSize - 1) && (j == fieldSize - 1))
	{
		return field[i][j] == '.';
	}
	else if (field[i][j] == '.')
	{
		field[i][j] = 'p';
		bool downResult = false;
		bool rightResult = false;
		// down 
		if ((i < fieldSize - 1) && (field[i+1][j] == '.'))
		{
			downResult = TraverseFromPoint(field, i + 1, j, fieldSize);
			// down didn't work try going right now
			if (downResult == true)
			{
				return downResult;
			}

		}

		if ((!downResult) && ((j < fieldSize - 1) && (field[i][j+1] == '.')))
		{
			rightResult = TraverseFromPoint(field, i, j+1, fieldSize);
			if (rightResult == true)
			{
				return rightResult;
			}
		}

	}

	return false;
}

