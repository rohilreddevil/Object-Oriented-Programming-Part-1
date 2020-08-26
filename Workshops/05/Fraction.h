//Rohil Khakhar
//id- 109270173
//workhop5

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: header file guard

// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction { //fractions consist of numerator and denominator
		// TODO: declare instance variables 
		int numerator;
		int denominator;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	
		// TODO: declare private member functions

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int num, int den);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& frac)const;
		Fraction operator*(const Fraction& frac)const;
		bool operator==(const Fraction& frac) const;
		bool operator!=(const Fraction&frac)const;
		Fraction operator+=(const Fraction& frac);
	
	};
}


#endif // !SICT_FRACTION_H
