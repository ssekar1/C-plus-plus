// Sundar Sekar

// Implementation file

#include "vector.h"
 
// METHOD IMPLEMENTATIONS
// helper methods
void Vector::CalculateMagnitude() {
 _magnitude = sqrt( pow(abs(_v_x), 2) + pow(abs(_v_y), 2) );
}
 
// overloaded binary + operator
Vector Vector::operator+(Vector right)
{
	Vector returnMe;
 
 // add corresponding vector components
	returnMe.SetVX(_v_x + right._v_x);
	returnMe.SetVY(_v_y + right._v_y);
 return returnMe;
}

// overloaded binary - operator
 Vector Vector::operator-( Vector right)
{
	Vector returnMe;
 
 // Sub corresponding vector components
	returnMe.SetVX(_v_x - right._v_x);
	returnMe.SetVY(_v_y - right._v_y);
 return returnMe;
 }

 // overloaded binary = operator
 void Vector::operator=( Vector right)
{
	Vector returnMe;
 
 // Equal corresponding vector components
	returnMe.SetVX(_v_x = right._v_x);
	returnMe.SetVY(_v_y = right._v_y);
 
 }
 // overloading the stream output
 ostream& operator<<(ostream& outputStream, Vector& theVector) {
	 outputStream << "<" << theVector._v_x<< ", " <<theVector._v_y<< ">";
	return outputStream;
 }
// constructors
Vector::Vector() {
 _v_x = 0.0;
 _v_y = 0.0;
 CalculateMagnitude();
}
 
Vector::Vector(double _v_x, double _v_y) {
 this->_v_x = _v_x;
 this->_v_y = _v_y;
 CalculateMagnitude();
}
 
// setters
void Vector::SetVX(double _v_x) {
 this->_v_x = _v_x;
 CalculateMagnitude();
}
 
void Vector::SetVY(double _v_y) {
 this->_v_y = _v_y;
 CalculateMagnitude();
}
 
// getters
double Vector::GetVX() {
 return _v_x;
}
 
double Vector::GetVY() {
 return _v_y;
}
 
double Vector::GetMagnitude() {
	CalculateMagnitude();
 return _magnitude;
}
 
//// operations
//Vector Vector::AddVector(Vector addMe) {
// // create a temp vector
// Vector returnMe;
// 
// // add corresponding vector components
// returnMe.SetVX(_v_x + addMe.GetVX());
// returnMe.SetVY(_v_y + addMe.GetVY());
// 
// // return the tempVector
// return returnMe;
//}
// 
//Vector Vector::SubtractVector(Vector subtractMe) {
// // create a tempVector
// Vector returnMe;
// 
// // subtract corresponding vector components
// returnMe.SetVX(_v_x - subtractMe.GetVX());
// returnMe.SetVY(_v_y - subtractMe.GetVY());
// 
// // return the tempVector
// return returnMe;
//}
 
// display methods
void Vector::Display() {
 cout << "<" << this->_v_x << ", " << this->_v_y << ">";
}