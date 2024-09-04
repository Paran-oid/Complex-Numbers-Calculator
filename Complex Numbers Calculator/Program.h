#include <iostream>
#include <vector>
#include "Complex_Number.h"
#include "string"
using namespace std;

class Program
{
public:
	void run()
	{
		cout << "Hello User!" << endl << "would you like to: Add(+), Subtract(-), Multiply(*)?" << endl;
		string choice;
		cin >> choice;

		int amount;
		cout << "Enter amount of numbers you want to add" << endl;
		cin >> amount;

		vector<Complex_Number> complexNumbers(amount);

		for (int i = 0; i < amount; i++)
		{
			Complex_Number model;
			int tmp;

			cout << "Give the " << i + 1 << " real number \n";
			cin >> tmp;
			model.setRel(tmp);

			cout << "Give the " << i + 1 << " imaginary number \n";
			cin >> tmp;
			model.setIm(tmp);

			complexNumbers[i] = model;
		}

		cout << "You entered the following: \n";

		for (int i = 0; i < amount; i++)
		{
			char op = complexNumbers[i].getIm() > 0 ? '+' : '-';
			cout << to_string(complexNumbers[i].getRel()) << " " << op << " " << to_string(complexNumbers[i].getIm()) + "i " << endl;
		}

	}
private:
	Complex_Number Add(vector<Complex_Number> complexNumbers, int amount)
	{

	}
};

