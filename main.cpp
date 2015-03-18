#include "Rational.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
   Rational r1;
	const Rational r2(5, 12);

	cout << "r2: " << r2.ToString() << endl;

	r1.SetNumerator(48);
	r1.SetDenominator(36);

	cout << "r1's numerator: " << r1.GetNumerator() <<
		"\nr1's denominator: " << r1.GetDenominator() << endl;

	cout << "r1 = r2? " << (r1.Equals(r2) ? "true" : "false") << endl;

	cout << "r1 + r2 = " << r1.ToString() << " + " << r2.ToString() << " = "
		<< r1.Add(r2).ToString() << endl;
}
