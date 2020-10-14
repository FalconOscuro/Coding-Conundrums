#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

map<string, int> g_IngredientMap;

size_t g_State = 0;

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

bool SetState(string newState)
{
	if (newState == "enter")
		g_State = 0;

	else if (newState == "search")
		g_State = 1;

	else if (newState == "list")
		g_State = 2;

	else if (newState == "end")
		g_State = -1;

	else
		return false;

	return true;
}

void Add()
{
	string ingredient;
	int amount;

	while (true)
	{
		cout << "Input the name of the ingredient or the name of a state to switch to it: ";
		getline(cin, ingredient);

		for (int i = 0; i < ingredient.size(); i++)
			ingredient[i] = tolower(ingredient[i]);

		if (SetState(ingredient))
			return;

		if (ingredient != "")
			break;

		cout << "Invalid input, please try again" << endl;
	}

	while (true)
	{
		amount = GetSafeIntInput("Input the amount of the ingredient you have: ");

		if (amount != 0)
			break;

		cout << "Invalid input, please try again" << endl;
	}

	if (g_IngredientMap.find(ingredient) == g_IngredientMap.end())
		g_IngredientMap[ingredient] = amount;

	else
	{
		g_IngredientMap[ingredient] += amount;

		if (g_IngredientMap[ingredient] <= 0)
			g_IngredientMap.erase(ingredient);
	}
}

void Search()
{
	string searchTerm;

	while (true)
	{
		cout << "Input the name of the ingredient to search for or the name of a state to switch to it: ";
		getline(cin, searchTerm);

		for (int i = 0; i < searchTerm.size(); i++)
			searchTerm[i] = tolower(searchTerm[i]);

		if (SetState(searchTerm))
			return;

		if (searchTerm != "")
			break;

		cout << "Invalid input, please try again" << endl;
	}

	if (g_IngredientMap.find(searchTerm) == g_IngredientMap.end())
		cout << "You do not have any " << searchTerm << endl;

	else
		cout << "You have " << g_IngredientMap[searchTerm] << " of " << searchTerm << endl;
}

void List()
{
	for (std::pair<string, int> element : g_IngredientMap)
		cout << "You have " << element.second << " of " << element.first <<  endl;

	while (true)
	{
		cout << "Enter the name of a state to switch to: ";
		
		string input;
		getline(cin, input);

		for (int i = 0; i < input.size(); i++)
			input[i] = tolower(input[i]);

		if (SetState(input))
			return;

		cout << "Invalid input, please try again" << endl;
	}
}

void main()
{
	cout << "Names of states avaiable: Enter, Search, List, End" << endl;
	cout << "Setting state Search" << endl;

	while (true)
	{
		switch (g_State)
		{
		case 0:
			Add();
			break;

		case 1:
			Search();
			break;

		case 2:
			List();
			break;

		default:
			return;
		}
	}
}