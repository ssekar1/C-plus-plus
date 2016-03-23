// Sundar Sekar

#include <iostream>
#include "vector.h"
using namespace std;
 
int main() {
 // declare some vectors
 Vector myFirstVector(4, 5);
 Vector mySecondVector;
mySecondVector = myFirstVector;

Vector resultVector;

 // display the contents of the vectors
 cout << "Vector One Contains : "; cout << myFirstVector << endl;
 cout << "Vector Two Contains : "; cout << mySecondVector << endl;
 
 cout << endl;
 
 // add the two vectors
 cout << "ADDING VECTORS" << endl;
 resultVector = myFirstVector + (mySecondVector);
 
 // display the contents of the vectors
 cout << "Vector One Contains : "; cout << myFirstVector << endl;
 cout << "Vector Two Contains : "; cout << mySecondVector << endl;
 cout << "Result Vector Contains: "; cout << resultVector << endl;
 cout << endl;
 
 // subtract the two vectors
 cout << "SUBTRACTING VECTORS" << endl;
 resultVector = myFirstVector - (mySecondVector);
 
 // display the contents of the vectors
 cout << "Vector One Contains : "; cout << myFirstVector << endl;
 cout << "Vector Two Contains : "; cout << mySecondVector << endl;
 cout << "Result Vector Contains: "; cout << resultVector << endl;
 cout << endl;
 
 // display the magnitudes of the vectors
 cout << "DISPLAY MAGNITUDES" << endl;
 cout << "Vector One Magnitude : " << myFirstVector.GetMagnitude() << endl;
 cout << "Vector Two Magnitude : " << mySecondVector.GetMagnitude() << endl;
  
 return 0;
}