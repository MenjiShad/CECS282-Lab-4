#ifndef _RATIONAL_H
#define _RATIONAL_H
#include <string>

class Rational
{
private: 

	// Holds the numerator
   int mNumerator;

	// Holds the denominator
	int mDenominator;

	// Reduces rational number to "normal" form
	// Simplest terms & (-n / d)
	void Normalize();

	// For use by Normalize only
	// Finds greatest common denominator
	int gcd(int a, int b);

public:

	// Default constructor
	Rational();

	// Constructor to initialize numberator and denominator
	Rational(const int& numerator, const int& denominator);

	// Numerator Mutator
	void SetNumerator(const int& numerator);

	// Denominator Mutator
	void SetDenominator(const int& denominator);

	// Numerator Accessor
	const int& GetNumerator() const;

	// Denominator Accessor
	const int& GetDenominator() const;

	// Checks to see if two Rational numbers are equal
	bool Equals(const Rational &other) const;

	// Adds together two Rational numbers
	Rational Add(const Rational &other) const;

	// Return string representation
	std::string ToString() const;
};
#endif
