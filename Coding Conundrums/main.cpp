#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string ConvertIntToString(int number)
{
	if (number < 1 || number > 199)
		return "";

	string returned = "";

	div_t result = div(number, 10);

	string prefixArray[10] = { "", "", "twen", "thir", "four", "fif", "six", "seven", "eigh", "nine" };
	string numberArray[10] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	if (result.quot == 1)
	{
		switch (result.rem)
		{
		case 0:
			returned = "ten";
			break;

		case 1:
			returned = "eleven";
			break;

		case 2:
			returned = "twelve";
			break;

		default:
			returned += prefixArray[result.rem] + "teen";
		}
	}

	else
	{
		if (result.quot > 9)
		{
			returned += "one hundred and ";
			result.quot -= 10;
		}

		returned += prefixArray[result.quot];

		if (prefixArray[result.quot] != "")
			returned += "ty ";

		returned += numberArray[result.rem];
	}

	return returned;
}

int ConvertStringToInt(string numberString)
{
	string numbers[12] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve" };

	for (int i = 0; i < 12; i++)
		if (numbers[i] == numberString)
			return i + 1;

	return -1;
}

void main()
{
	string input;

	while (true)
	{
		int number = 0;

		while (true)
		{
			cout << "Input a number from 1 - 12: ";
			getline(cin, input);
			cout << endl;

			stringstream myStream(input);

			if (myStream >> number)
				if (number > 0 && number < 13)
					break;

			for (uint64_t i = 0; i < input.size(); i++)
				input[i] = tolower(input[i]);

			string numbers[12] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve" };

			number = ConvertStringToInt(input);
			if (number > 0)
				break;

			cout << "Invalid input plaease try again" << endl;
		}

		string inputAsString = ConvertIntToString(number);
		for (int i = 1; i < 13; i++)
			cout << ConvertIntToString(i) << " times " << inputAsString << " is " << ConvertIntToString(i * number) << endl;

		string quitting;
		cout << "Run again (Y/N)? ";
		getline(cin, quitting);
		cout << endl;

		if (quitting == "n" || quitting == "N")
			return;
	}
}