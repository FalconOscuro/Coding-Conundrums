#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void main()
{
	map<float, int> shoeMap;

	while (true)
	{
		string input;
		int number = 0;

		while (true)
		{
			cout << "Enter a shoe size or reset the program(r) or quit (q): ";
			getline(cin, input);

			stringstream myStream(input);
			if (myStream >> number)
				break;

			else if (input == "r" || input == "R")
			{
				shoeMap.clear();
				continue;
			}

			else if (input == "q" || input == "Q")
				return;

			cout << "Invalid input, please try again" << endl;
		}

		if (shoeMap.find(number) == shoeMap.end())
			shoeMap[number] = 1;

		else
			shoeMap[number] ++;

		for (std::pair<float, int> element : shoeMap)
			cout << element.second << " shoe(s) of size " << element.first << " have/has been sold" << endl;
	}
}