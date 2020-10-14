#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int GetSafeIntInput(string question)
{
	string input;
	int output = 0;
	while (true)
	{
		cout << question;
		getline(cin, input);

		stringstream myStream(input);
		if (myStream >> output)
				return output;

		cout << "Invalid input, please try again" << endl;
	}
}

void main()
{
	while (true)
	{
		int iterations;
		int total = 0;
		float mean;
		float standardDeviation = 0;
		int ignored = 0;
		int input;
		vector<int> numbers;

		while (true)
		{
			iterations = GetSafeIntInput("Please input how many marks you wish to enter: ");

			if (iterations > 1)
				break;

			cout << "Invalid input, please try again" << endl;
		}

		for (int i = 0; i < iterations; i++)
		{
			while (true)
			{
				input = GetSafeIntInput("Please input the marks out of 100: ");

				if (input >= 0 && input <= 100)
					break;

				cout << "Invalid input, please try again" << endl;
			}

			if (input != 0)
			{
				total += input;
				numbers.push_back(input);
			}

			else
				ignored++;
		}

		iterations -= ignored;
		mean = float(total) / float(iterations);

		for (int i = 0; i < numbers.size(); i++)
			standardDeviation += pow((float(numbers[i]) - mean), 2);
		standardDeviation /= iterations - 1;
		standardDeviation = sqrt(standardDeviation);

		cout << "The average mark was " << mean << " with a standard deviation of " << standardDeviation << endl;

		string quitting;
		cout << "Run again (Y/N)? ";
		getline(cin, quitting);
		cout << endl;

		if (quitting == "n" || quitting == "N")
			return;

		numbers.clear();
	}
}