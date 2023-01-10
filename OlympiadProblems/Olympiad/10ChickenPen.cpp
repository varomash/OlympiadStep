#include <iostream>
#include <fstream>
#include <math.h>
#include "10ChickenPen.h"
using namespace std;

void ChickenPen()
{
	ifstream file ("10ChickenPen.in");
	if (file.is_open())
	{
		double chickens = 0;
		file >> chickens;
		int innerChickenPenSide = ceil(sqrt(chickens));
		int outerChickenPenSide = innerChickenPenSide + 2;

		for (int i = 0; i < outerChickenPenSide; i++)
		{
			for (int j = 0; j < outerChickenPenSide; j++)
			{
				if ((i == 0) 
					|| (j == 0)
					|| (i == outerChickenPenSide - 1)
					|| (j == outerChickenPenSide - 1))
				{
					cout << 'X';
				}
				else
				{
					cout << ".";
				}
			}
			cout << '\n';
		}
	}
	else
	{
		cout << "unable to open file\n";
	}

	file.close();
}