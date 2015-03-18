#include "Rational.h"
#include <iostream>

using namespace std;

void Rational::Normalize() {

	// reduce to simplest terms
	int divisor = gcd(mNumerator, mDenominator);

	mNumerator /= divisor;
	mDenominator /= divisor;

	// if Rational number is negative
	// make numer negative and denom positive
	if (mNumerator * mDenominator < 0)
	{
	   if (mNumerator > 0) {
			mNumerator = -mNumerator;
			mDenominator = -mDenominator;
		}
	}
}

int Rational::gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

// Default constructor initializes Rational number as 0 / 1
Rational::Rational()
	: mNumerator(0), mDenominator(1)
{
	
}

Rational::Rational(const int& numerator, const int& denominator)
	: mNumerator(numerator)
{
	SetDenominator(denominator);
}

void Rational::SetNumerator(const int& numerator) {
	mNumerator = numerator;
	Normalize();
}

// Denominator can't be equal to 0
void Rational::SetDenominator(const int& denominator) {
	if (denominator == 0) {
		mDenominator = 1;
		cout << "denominator cannot be equal to 0." << endl;
		cout << "denominator will be set to default value, 1." << endl;
	}
	else
		mDenominator = denominator;
	Normalize();
}

const int& Rational::GetNumerator() const {
	return mNumerator;
}

const int& Rational::GetDenominator() const {
	return mDenominator;
}

bool Rational::Equals(const Rational &other) const {
	return mNumerator == other.mNumerator && 
		mDenominator == other.mDenominator;
}

//  (A / B) + (C / D) = [(A * D) + (B * C)] / (B * D)
Rational Rational::Add(const Rational &other) const {
	int newDenominator = mDenominator * other.mDenominator;
	int newNumerator = mNumerator * other.mDenominator + 
		other.mNumerator * mDenominator;
	Rational newRationalNum(newNumerator, newDenominator);
	return newRationalNum;
}

string Rational::ToString() const {
	if (mDenominator == 1)
		return to_string(mNumerator);
	else
		return to_string(mNumerator) + "/" + to_string(mDenominator);
}
