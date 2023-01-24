#include <iostream>
#include <fstream>

using namespace std;

void ReadDataSet(ifstream& file);
void CowSpeak()
{
	ifstream file("cowspeak.in");

	if (file.is_open())
	{
		int dataSetCount = 0;
		file >> dataSetCount;
		if (dataSetCount > 0)
		{
			char c = file.get();
		}

		for (int i = 0; i < dataSetCount; i++)
		{
			ReadDataSet(file);
		}
	}
	else
	{
		cout << "Unable to open the file";
	}
}

void ReadDataSet(ifstream& file)
{
	char cIn = '\0';
	char letter;
	
	char currChar = 'M';
	short countM = 0;
	short countO = 0;
	while ((cIn = file.get()) != '\n')
	{
		switch (cIn) 
		{
			case 'M':
				countM++;
			break;

			case 'O':
				countO++;

			break;

			case ' ':
				letter = countO + 16 * countM;
				cout << letter;
				countM = 0;
				countO = 0;
			break;
		}
	}

	if (countM > 0 || countO > 0)
	{
		letter = countO + 16 * countM;
		cout << letter;
	}

	cout << endl;
}

