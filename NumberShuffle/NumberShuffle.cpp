#include <time.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>

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
	srand(time(NULL));

	while (true)
	{
		int iterations;
		vector<int> numbers;

		while (true)
		{
			iterations = GetSafeIntInput("How many numbers do you wish to input? ");

			if (iterations > 0)
				break;

			cout << "Invalid input, please try again" << endl;
		}

		for (int i = 0; i < iterations; i++)
			numbers.push_back(i);

		for (int i = 0; i < iterations; i++)
		{
			int randNo = rand() % iterations;
			int x;

			x = numbers[i];
			numbers[i] = numbers[randNo];
			numbers[randNo] = x;
		}

		for (int i = 0; i < iterations; i++)
			cout << numbers[i] << "  ";

		string quitting;
		cout << "Run again (Y/N)? ";
		getline(cin, quitting);
		cout << endl;

		if (quitting == "n" || quitting == "N")
			return;

		numbers.clear();
	}
}