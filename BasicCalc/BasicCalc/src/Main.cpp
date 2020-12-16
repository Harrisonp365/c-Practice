#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "Please enter expression(we can handle + or -); ";
	int lval = 0;
	int rval;
	char opp;
	int result;
	cin >> lval >> opp >> rval;

	if (opp == '+')
		result = lval + rval;
	else if (opp == '-')
		result = lval - rval;

	cout << "Result: " << result;
	return 0;
}