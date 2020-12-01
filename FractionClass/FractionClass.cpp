#include <iostream>
using namespace std;

class Fraction{
private:
	int num, den; //numerator and denominator

public:
	Fraction() { set(0, 1); }
	Fraction(int n, int d) { set(n, d); }
	Fraction(const Fraction& src);

	void set(int n, int d) { num = n; den = d; normalize(); }
	int getNum() const { return num; }
	int getDen() const { return den; }
	Fraction add(const Fraction& other);
	Fraction mult(const Fraction& other);
	Fraction operator+(const Fraction& other) { return add(other); }
	Fraction operator*(const Fraction& other) { return mult(other); }

private:
	void normalize();

	int gcf(int a, int b); //greatest common factor
	int lcm(int a, int b); // lowest common denominator
};


int main()
{
	Fraction f1(1, 2);
	Fraction f2(1, 3);
	Fraction f3 = f1 + f2;

	cout << "1/2 + 1/3 = ";
	cout << f3.getNum() << "/";
	cout << f3.getDen() << ".";

	return 0;
}


Fraction::Fraction(Fraction const& src) {
	num = src.num;
	den = src.den;
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

Fraction Fraction::add(const Fraction& other) {
	int lcd = lcm(den, other.den);
	int quot1 = lcd / other.den;
	int quot2 = lcd / den;
	
	return Fraction(num * quot1 + other.num * quot2, lcd);
}

Fraction Fraction::mult(const Fraction& other) {
	return Fraction(num * other.num, den * other.den);
}