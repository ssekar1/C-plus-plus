// Sundar Sekar

#include <iostream>
#include "fraction.h"
using namespace std;
 
int main() {
 // make some Fractions
 Fraction frac1;
 Fraction frac2;
 Fraction result;
 
 // set values
 frac1.setNumerator(10);
 frac1.setDenominator(5);
 frac2.setNumerator(18);
 frac2.setDenominator(4);
 
 // test operations
 result = frac1 + frac2;
 frac1.Print(); cout << " + "; frac2.Print(); cout << " = "; result.Print();
 cout << endl;
 
 result = frac1 - frac2;
 frac1.Print(); cout << " - "; frac2.Print(); cout << " = "; result.Print();
 cout << endl;
 
 result = frac1 * frac2;
 frac1.Print(); cout << " * "; frac2.Print(); cout << " = "; result.Print();
 cout << endl;
 
 result = frac1 / frac2;
frac1.Print(); cout << " / "; frac2.Print(); cout << " = "; result.Print();
 cout << endl;
 
 return 0;
}