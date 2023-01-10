#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void Acres()
{
	// 1 bag  = 5 acres
	// 1 acre = 4840 sq yards
	ifstream file ("7Acres.in");
	if (file.is_open())
	{
		double width = 100;
		double height = 1000;
		file >> width >> height;
		double acres = ceil((width * height) / 4840.0);
		double bags = ceil(acres / 5.0);
		cout << (int)bags << endl;
	}
	else
	{
		cout << "unable to open file\n";
	}

	file.close();
}
