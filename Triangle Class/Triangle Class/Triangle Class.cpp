// Sundar Sekar
// Assignment 06



#include <iostream>
#include <iomanip>
#include "Triangle.h"
#include <math.h>
using namespace std;

 

 

int main() {

 // instantiate the class

 Triangle myTriangle;

 // load the values

int Opposite;
int Adjacent;
cout << "Please enter Opposite value : ";
cin >> Opposite;
cout << "\n Please enter adjacent value: ";
cin >> Adjacent;

 myTriangle.setOppositeLength(Opposite);

 myTriangle.setAdjacentLength(Adjacent);

 

 // display the rectangle

 myTriangle.DisplayTriangle();

 

 return 0;

}