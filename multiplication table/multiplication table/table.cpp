#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// 
	int rows = 0;
	int cols = 0;
	int i = 0, j = 0;

	// PROMPT ROWS AND COLUMNS
	cout << "Please enter the number of columns: ";
	cin  >> cols;
	cout << "Please enter the number of rows: ";
	cin  >> rows;

	// DISPLAY THE TABLE
	// display first row
	cout << "   " << "|";
	for(i = 1; i <= cols; i++) {
		cout << setw(3) << i << "|";
	}
	cout << endl;

	// display dividing grid
	cout << "   ";
	for(i = 1; i <= cols; i++) {
		cout << "+---";
	}
	cout << "+";
	cout << endl;

	// display subsequent rows
	for(i = 1; i <= rows; i++) {
		// display the first item in each row
		cout << setw(3) << i << "|";
		
		// display rest of items for a given row
		for(j = 1; j <= cols; j++) {
			cout << setw(3) << i * j << "|";
		}
		cout << endl;
	}

	return 0;
}
