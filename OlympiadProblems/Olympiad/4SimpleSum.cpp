#include <iostream>
#include <fstream>
#include "4SimpleSum.h"
using namespace std;

void SimpleSum()
{
	ifstream file ("4SimpleSum.in");
	if (file.is_open())
	{
		int a, b, sum;
		char plus, equals;
		file >> a >> plus >> b >> equals >> sum;
		if (a + b != sum) 
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
	else
	{
		cout << "unable to open file\n";
	}

	file.close();
}



