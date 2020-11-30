#include <iostream>
#include <string>
using namespace std;

Class Fraction{
private:
	int num, den; //numerator and denominator

public:
	void set(int n, int d) { num = n; den = d; normalize(); }
	int getNum() { return num; }
	int getDen() { return den; }

private:
	void normalize();

	int gcf(int a, int b); //greatest common factor
	int lcm(int a, int b); // lowest common denominator
};


int main()
{
	int a, b;
	string str;
	Fraction fract;

	while (true) {
		cout << "Enter a numerator: ";
		cin >> a;
		cout << "Enter a denominator: ";
		cin >> b;
		fract.set(a, b);

		cout << "Numerator is : " << fract.getNum() << endl;
		cout << "Denominator is : " << fract.getDen() << endl;

		cout << "Do it again? (Y/N) ";
		cin >> str;

		if (!(str[0] == 'Y' || str[0] == 'N'))
			break;
	}
	return 0;
}


void Fraction::normalize() {
	//Handle case involving 0

	if (den == 0 || num == 0) {
		num = 0;
		den = 1;
	}

	// Put neg. sign in numerator only.
	if (den < 0) {
		num *= -1;
		den *= -1;
	}

	// Factor out GCF from numerator and denominator

	int n = gcf(num, den);
	num = num / n;
	den = den / n;
}

int Fraction::gcf(int a, int b) {
	if (b == 0)
		return abs(a);
	else
		return gcf(b, a % b);
}

int Fraction::lcm(int a, int b) {
	int n = gcf(a, b);
	return a / n * b;
}