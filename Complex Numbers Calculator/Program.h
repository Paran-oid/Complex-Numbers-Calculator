#include <iostream>
#include <vector>
#include "Complex_Number.h"
#include "string"
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

class Program
{
public:
	void run()
	{
		bool isRunning = true;
		bool firstTime = true;
		while (isRunning)
		{
			if (firstTime)
			{
				cout << "Hello User!" << endl << "would you like to: Add(+), Subtract(-), Multiply(*)?" << endl;

			}
			else
			{
				cout << "would you like to: Add(+), Subtract(-), Multiply(*)?" << endl;
			}

			string choice;
			bool cond = false;

			do
			{
				cin >> choice;
				if (choice == "+" || choice == "-" || choice == "*")
				{
					cond = true;
				}
				else
				{
					cout << "Please enter one of these: Add(+), Subtract(-), Multiply(*)";
				}
			} while (!cond);

			int amount;
			cout << "Enter amount of numbers you want to add" << endl;
			cin >> amount;
			while (amount <= 1)
			{
				cout << "Enter an amount bigger than 1!" << endl;
				cin >> amount;
			}

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

			cout << endl;
			Complex_Number result = handle_choice(complexNumbers, choice);
			display_result(result);

			cout << "repeat?(Y/N)" << endl;
			string leaveChoice;
			cin >> leaveChoice;
			transform(leaveChoice.begin(), leaveChoice.end(), leaveChoice.begin(), [](unsigned char c) {
				return tolower(c);
				});
			if (leaveChoice != "y")
			{
				isRunning = false;
				cout << "thank you for trying my app!" << endl;
				system("pause");

			}
			else
			{
				system("cls");
				firstTime = false;
			}

		}
	}
private:
	void display_result(Complex_Number result)
	{
		char op = result.getIm() > 0 && result.getRel() != 0 && result.getIm() != 0 ? '+' : '\0';
		cout << "result is: \n";
		string output;
		if (result.getRel() == 0)
		{
			output = to_string(result.getIm()) + "i \n";
		}
		else if (result.getIm() == 0)
		{
			output = to_string(result.getRel());
		}
		else
		{
			output = to_string(result.getRel()) + op + to_string(result.getIm()) + "i \n";
		}
		cout << output;
	}
	Complex_Number handle_choice(vector <Complex_Number> complexNumbers, string op)
	{
		Complex_Number res;
		if (op == "+")
		{
			res = add(complexNumbers);
		}
		else if (op == "-")
		{
			res = minus(complexNumbers);
		}
		else if (op == "*")
		{
			res = multiply(complexNumbers);
		}
		else
		{
			throw exception("unknown operator");
		}
		return res;
	}
	Complex_Number add(vector<Complex_Number> complexNumbers)
	{
		int rel = 0;
		int im = 0;
		for (int i = 0; i < complexNumbers.size(); i++)
		{
			rel += complexNumbers[i].getRel();
			im += complexNumbers[i].getIm();
		}

		Complex_Number result;
		result.setRel(rel);
		result.setIm(im);

		return result;
	}
	Complex_Number minus(vector<Complex_Number> complexNumbers)
	{
		int rel = complexNumbers[0].getRel();
		int im = complexNumbers[0].getIm();
		for (int i = 1; i < complexNumbers.size(); i++)
		{
			rel -= complexNumbers[i].getRel();
			im -= complexNumbers[i].getIm();
		}

		Complex_Number result;
		result.setRel(rel);
		result.setIm(im);

		return result;
	}
	Complex_Number multiply(vector<Complex_Number> complexNumbers)
	{
		int rel = complexNumbers[0].getRel();
		int im = complexNumbers[0].getIm();

		int tmp1;
		int tmp2;

		for (int i = 1; i < complexNumbers.size(); i++)
		{
			tmp1 = (rel * complexNumbers[i].getRel()) - (im * complexNumbers[i].getIm());
			tmp2 = (rel * complexNumbers[i].getIm()) + (im * complexNumbers[i].getRel());
			rel = tmp1;
			im = tmp2;
		}

		Complex_Number result;
		result.setRel(rel);
		result.setIm(im);

		return result;
	}
};

