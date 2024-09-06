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
	void run();
private:
	void display_result(Complex_Number result);
	Complex_Number handle_choice(vector <Complex_Number> complexNumbers, string op);
	Complex_Number add(vector<Complex_Number> complexNumbers);
	Complex_Number minus(vector<Complex_Number> complexNumbers);
	Complex_Number multiply(vector<Complex_Number> complexNumbers);
};

