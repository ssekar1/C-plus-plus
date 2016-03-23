// Sundar Sekar
// Assignment 06

// implementation file for the triangle class.

#include <iostream>
#include "Triangle.h"
#include <cstdlib>
#include <math.h>
#include <iomanip>
using namespace std;

// setOpposite sets the value
void Triangle::setOppositeLength(double w)
{
	if (w>=0)
		opposite=w;
	
else
	{
		cout <<"Invalid value";
		exit (EXIT_FAILURE);
	}
	area = (getOpposite() * getAdjacent())/2;
	hypotenuse = sqrt((getOpposite() * getOpposite()) + (getAdjacent() * getAdjacent()));
	perimeter = getOpposite() + getAdjacent() + getHypotenuseLength();
}

// setAdjacent sets the value
void Triangle::setAdjacentLength(double l)
{
	if (l>=0)
		adjacent=l;
	
	else
	{
		cout <<"Invalid value";
		exit (EXIT_FAILURE);
	}
	area = (getOpposite() * getAdjacent())/2; // set area
	hypotenuse = sqrt((getOpposite() * getOpposite()) + (getAdjacent() * getAdjacent())); // set hypo
	perimeter = getOpposite() + getAdjacent() + getHypotenuseLength(); // set perimeter
}


//getOpposite
double Triangle::getOpposite()const
{
	return opposite;
}

// getAdjacent
double Triangle::getAdjacent()const
{
	return adjacent;
}
// getAera
double Triangle::getArea()const
{
	
	return area;
}
// getPerimeter
double Triangle::getPerimeter()const
{
	
	return perimeter;
}
double Triangle::getHypotenuseLength()
{
	return hypotenuse;
}
//Functions
void Triangle::DisplayTriangle()
{
	cout << setprecision(2) << left;
	cout << setw(20) << "" << "*\n" << setw(20) << "" << "**\n" << setw(20) << "" << "* *\n" << setw(20) << "" << "*  *\n" << setw(20) << "" << "*   *\n";
	cout << "Opposite Side = " << getOpposite() << " " << "  *    *   ";
	cout << "Hypotenuse Side = " << getHypotenuseLength() << endl;
	cout << setw(20) << "" << "*     *\n" << setw(20) << "" << "*      *\n" << setw(20) << "" << "*       *\n" << setw(20) << "" << "**********\n\n";

	cout << setw(20) << "" << "Adjacent Side = " << getAdjacent() << endl << endl;

	cout << "The area of the triangle is" << setw(5) << "" << ": " << getArea() << endl;
	cout << "The perimeter of the triangle is: " << getPerimeter() << endl;
}