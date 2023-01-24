#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int CountBunnies(int months);
int CountBunniesNotRecursive(int months);

void Bunnies()
{
	int months = 45;
	cout << "For months:" << months << " I have raised: " << CountBunniesNotRecursive(months) << endl;
}

int CountBunnies(int months)
{
	if ((months == 0) || (months == 1))
	{
		return 1;
	}
	else
	{
		return CountBunnies(months - 1) + CountBunnies(months - 2);
	}
}

int CountBunniesNotRecursive(int months)
{
	if (months <= 1)
	{
		return 1;
	}

	int sum = 0;

	int prev = 1;
	int prevprev = 1;

	for (int i = 2; i < months; i++)
	{
		int sum = prev + prevprev;
		prevprev = prev;
		prev = sum;
	}

	return prev + prevprev;
}

