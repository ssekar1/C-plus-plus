// Sundar Sekar

// Specification file for the Fraction class


#ifndef FRACTION_H
#define FRACTION_H

// Fraction class declaration.

class Fraction
{
	private:

	int numerator; 
	int denominator;

		 //HELPER METHODS

		

public:
		// CONSTRUCTOR(S)

		Fraction();
		Fraction(int numerator, int denominator);

		
			// SETTERS
		 void setDenominator(int);
		 void setNumerator(int);

			// GETTERS
		int getDenominator();
		int getNumerator();


		// overloads
		Fraction operator+(Fraction addMe);
		Fraction operator-(Fraction subtractMe);
		Fraction operator*(Fraction multiplyMe);
		Fraction operator/(Fraction divideMe);

		void Reduce();
		void Print();
};

#endif