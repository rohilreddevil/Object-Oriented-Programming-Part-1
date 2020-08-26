//Rohil Khakhar
//id- 109270173
//workhop5

#include<iostream>
#include"Fraction.h"// TODO: insert header files

using namespace std;
// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = 1;

	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int den) {
		if (num >= 0 && den > 0) {
			numerator = num;
			denominator = den;
		}
		else
		{
			*this = Fraction(); // referring the current object to the constructor
		}

	}
	// TODO: implement the max query
	int Fraction::max() const {
		int result;
		if (numerator > denominator) {
			result = numerator;
		}
		else {
			result = denominator;
		}
		return result;
	}
	// TODO: implement the min query

	int Fraction::min() const {
		int outcome;
		if (numerator < denominator) {
			outcome = numerator;
		}
		else {
			outcome = denominator;
		}
		return outcome;
	}



	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		if (!isEmpty()) {
			int GCD = gcd();
			

			numerator = numerator / GCD;
			denominator = denominator / GCD;
		}
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored" << flush;
		}
		else if (denominator == gcd()) {
			cout << numerator / gcd() << flush;
		}
		else {
			cout << numerator / gcd() << "/" << denominator / gcd() << flush;
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool flag = false;
		if (numerator == 0 && denominator == 1) {
			flag = true;
		}
		else {
			flag = false;
		}
		return flag;
		//*this = Fraction();
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+ (const Fraction& frac) const {
		Fraction fra;
		if (!this->isEmpty() && !frac.isEmpty()) {
			fra.numerator = this->numerator *frac.denominator + frac.numerator * this->denominator;
			fra.denominator = this->denominator * frac.denominator;
			fra.reduce();
		}
		return fra;
	}

	Fraction Fraction::operator* (const Fraction& frac) const {
		Fraction product;
		if (!this->isEmpty() && !frac.isEmpty()) {
			product.numerator = numerator*frac.denominator;
			product.denominator = denominator*frac.denominator;
			product.reduce();
		}
		if (this->isEmpty() || frac.isEmpty()) {
			product.denominator = 1;// denominator for that particular object
		}
		return product;
	}

	bool Fraction::operator== (const Fraction& frac) const {
		bool outcome = false;
		if (!this->isEmpty() || !frac.isEmpty()) {
			if (numerator*frac.denominator == denominator*frac.numerator) {
				outcome = true;
			}
		}
		if (this->isEmpty() || frac.isEmpty()) { // if either operands are empty fractions
			outcome = false;
		}
		return outcome; 
	}

	bool Fraction::operator!= (const Fraction& frac) const {
		bool flag = false;
		if (!this->isEmpty() || !frac.isEmpty()) {
			if (numerator*frac.denominator != denominator*frac.numerator) {// non empty fractions of unequal value
				flag = true;
			}
		}
			if (this->isEmpty() || frac.isEmpty()) { // if either operands are empty fractions
			flag = false;
		}
		return flag;
	}
	Fraction Fraction::operator+= (const Fraction& frac) {
		
		if (!isEmpty() && !frac.isEmpty()) {
			this->numerator = (numerator * frac.denominator) + (frac.numerator * denominator);
			this->denominator = denominator * frac.denominator;
			this->reduce();
		}
		if (isEmpty() || frac.isEmpty()) {
			this->denominator = 1;
		}

		return *this;
	}

}
