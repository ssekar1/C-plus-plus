// Author:Sundar Sekar
// The program will then determine whether or not the number is prime.

#include <iostream>
#include <cmath>
#include <limits>
#include <conio.h>
	
using namespace std;									 
														 
// Is the interger prime?
bool xPrime(int number) 
{
	// using ceil fuction to round up.
	int upper_limit = ceil(sqrt((double)number)); // do we have to use ceil, double up=sqrttdouble number
	// try to find a divisor of number
	bool FacFound = false;
	int count = 2;
	// loop for prime factor
	while((count <= upper_limit && !FacFound) && number != 2) 
	{
		if(number%count == 0)
	// loop for all integers to cutoff point
			FacFound = true; 
		count++;
	}
	return !FacFound; 
}
// Find Prime Factors
void PrimeFac(int number)
{
	if(xPrime(number))  
	{
		cout<<number<<" has been found as a prime factor."<<endl;
		return;
	}
	int upper_limit = ceil(sqrt((double)number));
	int count = 2;

	while(count <= upper_limit && number %count !=0) 
		count++;
	// output prime factors
		cout<<count<<" has been found as a prime factor."<<endl; 
		PrimeFac(number/count); 
		
}

int main()
{
	int input = 0;
	bool invalid;
		
	cout<<"Please enter a positive integer: ";
	cin>>input;

	// consider only positive intergers
	// if the user enters a negative integer, ask to enter positive number again
	while(input<=1) 
	{
		cout<<input<<" is out of our field of consideration. Please enter positive number: "<<endl; // numbers in our bounds only
		cin>>input;
	}
	if(xPrime(input)) {
		cout<<input<<" is a PRIME NUMBER"<<endl;
	}
	else{
		cout<<input<<" is a COMPOSITE NUMBER"<<endl;
		PrimeFac(input);
	}
	system("PAUSE"); // getch() is not working properly for me

	
	return 0;

}