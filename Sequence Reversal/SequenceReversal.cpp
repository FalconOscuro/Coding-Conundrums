#include <iostream>
#include <sstream>
#include <string>
#include <stack>

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
		stack<int> numbers;
		int iterations;

		while (true)
		{
			iterations = GetSafeIntInput("How many numbers do you wish to input? ");

			if (iterations > 0)
				break;

			cout << "Invalid input, please try again" << endl;
		}

		for (int i = 0; i < iterations; i++)
			numbers.push(GetSafeIntInput("Enter a number: "));
		
		for (int i = 0; i < iterations; i++)
		{
			cout << numbers.top() << endl;
			numbers.pop();
		}

		string quitting;
		cout << "Run again (Y/N)? ";
		getline(cin, quitting);
		cout << endl;

		if (quitting == "n" || quitting == "N")
			return;

		while (!numbers.empty())
			numbers.pop();
	}
}