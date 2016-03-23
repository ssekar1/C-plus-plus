// Sundar Sekar

// Specification file

#ifndef __VECTOR__
#define __VECTOR__
 
#include <iostream>
#include <math.h>
using namespace std;

class Vector {
private:
	// DATA MEMBERS
	double _v_x;
	double _v_y;
	double _magnitude;

	 //HELPER METHODS
 void CalculateMagnitude();
 
public:
 // CONSTRUCTOR(S)
 Vector();
 Vector(double _v_x, double _v_y);
 
 
 // SETTERS
 void SetVX(double _v_x);
 void SetVY(double _v_y); 
 
 // GETTERS
 double GetVX();
 double GetVY();
 double GetMagnitude();

	// overloads
	
	void operator=(Vector value);
	Vector operator+(Vector value);
	Vector operator-(Vector value);
	
	// overloading the stream output 
	friend ostream& operator<<(ostream& outputStream, Vector& theVector);
	
	
	void Display();
};	// end - Integer
#endif





 
// old Specification file. No use. 
// Just for my purpose.

//// CLASS SPECIFICATION
//class Vector {
//private:
// // DATA MEMBERS
// double _v_x;
// double _v_y;
// double _magnitude;
// 
// // HELPER METHODS
// void CalculateMagnitude();
// 
//public:
// // CONSTRUCTOR(S)
// Vector();
// Vector(double _v_x, double _v_y);
// 
// // SETTERS
// void SetVX(double _v_x);
// void SetVY(double _v_y); 
// 
// // GETTERS
// double GetVX();
// double GetVY();
// double GetMagnitude();
// 
// // OPERATIONS
// Vector AddVector(Vector addMe);
// Vector SubtractVector(Vector subtractMe);
//Vector operator + (const Vector &); // Overload +
//Vector operator - (const Vector &); // Overload -
//Vector operator = (const Vector &); // Overload =
//
// // DISPLAY METHODS
// void Display();
//};
// 
//#endif
// 