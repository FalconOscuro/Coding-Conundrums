#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <limits>

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
	map<string, int> fishMap;
	pair<string, int> heaviestFish = {"", 0};
	pair<string, int> lightestFish = { "", numeric_limits<int>::max() };
	string popularFish = "";
	int totalWeight = 0;

	while (true)
	{
		pair<string, int> newFish;

		while (true)
		{
			cout << "Enter the species of fish or Finished to exit the program and see the readout: ";
			getline(cin, newFish.first);

			if (newFish.first != "")
				break;

			cout << "Invalid input, please try again" << endl;
		}

		for (int i = 0; i < newFish.first.size(); i++)
			newFish.first[i] = tolower(newFish.first[i]);

		if (newFish.first == "finished")
		{
			if (popularFish == "")
				cout << "No fish were caught";

			else
			{
				cout << "The heaviest fish was a " << heaviestFish.first << " weighing " << heaviestFish.second << "g." << endl;
				cout << "The lightest fish was a " << lightestFish.first << " weighing " << lightestFish.second << "g." << endl;
				cout << "The most popular fish was a " << popularFish << " caught a total of " << fishMap.at(popularFish) << " times" << endl;
				cout << "In total " << totalWeight << "g of fish were caught";
			}
			return;
		}

		if (fishMap.find(newFish.first) == fishMap.end())
			fishMap[newFish.first] = 1;

		else
			fishMap[newFish.first]++;

		if (popularFish == "" || (newFish.first != popularFish && fishMap.at(newFish.first) > fishMap.at(popularFish)))
			popularFish = newFish.first;

		while (true)
		{
			newFish.second = GetSafeIntInput("Enter the weight of your fish in g: ");

			if (newFish.second > 0)
				break;

			cout << "Invalid input, please try again" << endl;
		}

		totalWeight += newFish.second;

		if (newFish.second > heaviestFish.second)
			heaviestFish = newFish;

		if (newFish.second < lightestFish.second)
			lightestFish = newFish;
	}
}