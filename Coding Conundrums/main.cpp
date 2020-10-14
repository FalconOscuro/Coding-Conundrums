#include <iostream>
#include <stdlib.h>

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

int main()
{
	int input;

	cout << "Input a number from 1 - 12: ";
	cin >> input;
	string inputAsString = ConvertIntToString(input);
	cout << endl;

	for (int i = 1; i < 13; i ++)
		cout << ConvertIntToString(i) << " times " << inputAsString << " is " << ConvertIntToString(i * input) << endl;
}