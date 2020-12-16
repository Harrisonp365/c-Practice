#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "Please enter expression(we can handle +,-, *, /); \n";
	cout << "add an x to end the expression(eg. 1+2*3x)"
	int lval = 0;
	int rval;

	cin >> lval;
	if (!cin) error("no first operand");

	for (char opp; cin >> opp;)
	{
		switch (opp)
		{
		case'+':
			lval += rval;
			break;
		case '-';
			lval -= rval;
			break;
		case '*';
			lval *= rval;
			break;
		case '/';
			lval /= rval;
			break;
		default:
			cout << "Result: " << lval << "\n";
			return 0;
		}
	}
	error("bad expression");
}