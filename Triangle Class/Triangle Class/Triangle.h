// Sundar Sekar
// Assignment 06

// Specification file for the triangle class


#ifndef TRIANGLE_H
#define TRIANGLE_H
 
// triangle class declaration.

class Triangle
{
	// constructors
private:
	double opposite;
	double adjacent;
	double hypotenuse;
	double area;
	double perimeter;
public:
	// setters
	void setOppositeLength(double); 
	void setAdjacentLength(double);
	void DisplayTriangle(); //Displays a triangle
	// getters
	double getOpposite() const;
	double getAdjacent() const;
	double getArea() const;
	double getPerimeter() const;
	double getHypotenuseLength();
	
};
#endif

