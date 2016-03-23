// Sundar Sekar

// Implementation file

#include <iostream>
#include "fraction.h"
#include <iomanip>
using namespace std;

// constructors

Fraction :: Fraction( ) // default constructor function
{      
  numerator=0;
  denominator=1 ;  // set numerator to 0 and denominator to 1
  }

 Fraction :: Fraction(int n, int d)  // non default constructor function
 {
   numerator = n;       
   denominator = d;
   Reduce( );   // reduce the fraction
 }

// setters

	// set denominator
void Fraction::setDenominator(int d)
{
	if (d==0){
		d=1;
	cout<<"Undefiened. You have entered zero in the denominator  "<<endl;
	}
	this->denominator=d;
}
	// set numerator
void Fraction::setNumerator(int n)
{
	this->numerator=n;
}

// getter

	// get denominator
int Fraction::getDenominator()
{
	return denominator;
}

	// get numerator
int Fraction::getNumerator()
{
	return numerator;
}

// reduce fraction function 
// use the greatest common factor to reduce the fraction
void Fraction::Reduce() 
{
 int gcf;           // gcf variable
   bool gotit=false;   // if we gotit gcf variable set to false
   if (denominator == 0) // checking if denom is 0. if ture change the denom to 1
      cout<<"Undefiened. You have entered zero in the denominator "<<endl;
   
   if (numerator < 0 && denominator < 0)  // checking if numerator and denom is negative
     {numerator = -numerator; // if true change it to positive
      denominator= -denominator; // if there are two negative, it will change to positive
     }
   // check if there is a minus sign in denominator
   if (numerator > 0 && denominator < 0) 
     {numerator= -numerator;
      denominator= -denominator;
     }
   // setting up gcf according to numerator and denom
   if (abs(numerator) > abs(denominator))  
     gcf = abs(denominator);
   else
     gcf = abs(numerator);
   // find gcf
   while ( !gotit && gcf  >= 2 )
    {
      if ( numerator % gcf == 0 && denominator % gcf == 0) 
       { 
		   // divide num and denom by gcf
		   numerator = numerator / gcf;
	 
         denominator = denominator / gcf;   
         gotit = true;
       }
      gcf--;
    }
 }



// overload operators

Fraction Fraction:: operator + (Fraction addMe)  // * overloaded operator function
  {
    Fraction temp(numerator*addMe.denominator + denominator*addMe.numerator, denominator*addMe.denominator);
            Fraction Reduce(temp);
			return temp;

  }

Fraction Fraction:: operator - (Fraction subtractMe)  // * overloaded operator function
  {
     Fraction temp(numerator*subtractMe.denominator - denominator*subtractMe.numerator, denominator*subtractMe.denominator);
           Fraction Reduce(temp);
           return temp;

  }

Fraction Fraction:: operator * (Fraction multiplyMe)  // * overloaded operator function
  {
    Fraction temp(numerator*multiplyMe.numerator, denominator*multiplyMe.denominator);
		  Fraction Reduce(temp);
          return temp;

  }

Fraction Fraction:: operator / (Fraction divideMe)  // * overloaded operator function
  {
    Fraction temp(numerator*divideMe.denominator, denominator*divideMe.numerator);
			Fraction Reduce(temp);
			return temp;

  }

void Fraction::Print() 
      {
		    cout<<"("<<numerator<<"/"<<denominator<<")";
      }