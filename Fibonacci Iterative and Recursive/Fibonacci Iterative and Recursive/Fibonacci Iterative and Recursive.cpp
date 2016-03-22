// Sundar Sekar

// INCLUDES AND NAMESPACES
#include<iostream>
#include <iomanip>

using namespace std;

// PROTOTYPES

int Fibonacci_I(int);

int Fibonacci_R(int);


int main()
{			
	cout<< "First 21 numbers in the Fibonacci Sequence\n\n";
    cout << " element| iterative| recursive\n"
                 "--------------------------------\n" ;
	// for loop for first 21 nunber
    for ( int i = 0 ; i <= 20 ; ++i )
    {													
        cout <<setw(7) << i                           
          << setw(9) << Fibonacci_R(i)                  // display Fibonacci Iterative and recursive
          << setw(9) << Fibonacci_I(i) << '\n' ;
    }
	system ("pause");
	return 0;
}

// returns F_i of the Fibonacci sequence (iterative)
// iterative version

int Fibonacci_I(int n)
{
	int fib[] = {0,1,1};
	for(int i=2; i<=n; i++)
	{												// f(n) = f(n - 1) + f(n - 2)
		fib[i%3] = fib[(i-1)%3] + fib[(i-2)%3];   // determine the index of the next element
	}
	return fib[n%3];
}
// returns F_i of the Fibonacci sequence (recursive)
/* Fibonacci: recursive version */

int Fibonacci_R(int n)
{
	if(n<=0) return 0;
	else if(n==1) return 1;
	else return Fibonacci_R(n-1)+Fibonacci_R(n-2);	//definition for the Fibonacci sequence. f(n) = f(n - 1) + f(n - 2)
}