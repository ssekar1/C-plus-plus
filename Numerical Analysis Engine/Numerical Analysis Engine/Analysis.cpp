// Sundar Sekar

#include <iostream>

using namespace std;
// DEFINES

#ifndef __TRUE_FALSE__

#define __TRUE_FALSE__

#define TRUE 1

#define FALSE 0

#endif



// FUNCTION PROTOTYPES

int DisplayMenuSelections();
void SetTestNumber();
void SignTest();
void EvenOddTest();
void PrimalityTest();
int num=159753;
int gTestNumber = 0;
bool gTestNumberSet = false;

int main() {
	
	// loop till exit
	while(gTestNumberSet == false) {
		switch (gTestNumber) {
		case 1:
			SetTestNumber();
			break;
		case 2:
			SignTest();
			break;
		case 3:
			EvenOddTest();
			break;
		case 4:
			PrimalityTest();
			break;
		case 5:
			cout << "EXITING PROGRAM" << endl;
			system("pause");
			return 1;
			break;
		}
			
		system("pause");
		system("cls");
		gTestNumber = DisplayMenuSelections();
	}


	return 0;
}
// FUNCTION IMPLEMENTATIONS
// returns the user's menu selection code
int DisplayMenuSelections() {
	int gTestNumber;
	
	//Initial Menu 
	cout << "+-------------------------------+" << endl;
	cout << "$  NUMERICAL ANALYSIS ENGINE $" << endl;
	cout << "+-------------------------------+" << endl;

	cout << "The current test number is: ";
	if(num==159753) {
		cout << "NOT YET SET" << endl << endl;
	} else {
		cout << num << endl << endl;
	}

	cout << "THE MENU" << endl;
	
	//The default menu
	cout << "1.) Set the test number." << endl;
	if(num !=159753) {
		cout << "2.) Test for sign." << endl;
		cout << "3.) Test for even/odd." << endl;
		cout << "4.) Test for primality." << endl;
	}
	cout << "5.) Exit program" << endl;

	// user will select from the menu
	cout << endl << "Please input your selection from the menu above: ";
	cin >> gTestNumber;

	return (gTestNumber);
}
// set the number
void SetTestNumber() {
	cout << "Enter the number would you like to test: ";
	cin >> num;
}
// check for sign of the number
void SignTest() {
	if(num > 0) {
		cout << "The number is Positive" << endl;
	}
	if(num < 0) {
		cout << "The number is Negative" << endl;
	
	}
	if (num==0) {
		cout << "The number is NEUTRAL" << endl;

	}
}
// check for even or odd
void EvenOddTest() {
	int leftOvers = 1;
	leftOvers = num % 2;
	if(leftOvers == 0) {
		cout << "The number is EVEN" << endl;
	}
	if (leftOvers != 0) {
		cout << "The number is ODD" << endl;
	}
	
}
// check for prime, composite
void PrimalityTest() {
	int testA = 0;
	int testB = 0;
	bool prime = true;

	if(num > 0) {
		for(int i = 2; i < num; i++) {
			testA = num % i;
			testB = num / i;
			if(testA == 0 && testB != num && testB != 1) {
				prime = false;
			}
		}
		if(prime == true) {
		cout << "The number you have selected is PRIME" << endl;
	}
		if(prime == false) {
		cout << "The number you have selected is COMPOSITE" << endl;
		}
	}
	if(num <= 0) {
		cout << "The number is neither PRIME or COMPOSITE" << endl;
	}

}
	