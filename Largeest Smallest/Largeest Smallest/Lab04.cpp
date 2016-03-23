// author: Sundar Sekar
// Highest and Lowest assignment

// INCLUDES AND NAMESPACES
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

#define ARRAY_SIZE 20

//Prototypes
int ReturnLargest(int[]);
int ReturnSmallest(int*);
int ToUpperCase(char*);


int main() {
	int numbers[ARRAY_SIZE]={7,12,33,44,55,96,27,788,59,110,-811,-98512,2513,1214,15,136,187,11258,199,-5620};
	int* pNumbers = NULL;
	pNumbers=numbers;
	char characters[ARRAY_SIZE] = "MyFavoRiteMovIesAre";
	char* pCharacters = NULL;
	pCharacters=characters;
	
	
	int largest=ReturnLargest(numbers);
	cout << "The Largest number in the array: " << largest << endl << endl;
	int smallest=ReturnSmallest(numbers);
	cout << "The Smallest number in the array: " << smallest << endl << endl;
	int charaupper=ToUpperCase(characters);
	cout << "Characters converted to Upper Case: " << charaupper << endl << endl;
	
	getch();
	return 0;
}
int ReturnLargest(int numbers[ARRAY_SIZE]) {
	int highest=numbers[0];
	for(int i = 1; i < ARRAY_SIZE; i++) {
		if(numbers[i] > highest) {
			highest = numbers[i];
		}
	}
		
	return highest;
}

int ReturnSmallest(int* numbers) {
	int lowest=numbers[0];
	for(int i = 1; i < ARRAY_SIZE; i++) {
		if(*(numbers +i) < lowest) {
			lowest = *(numbers + i);
		}
	}
	
	return lowest;
}

int ToUpperCase(char* characters) {
	int change=0;
	cout<<"Character changed to uppercase are: ";
	for(int i = 0; i < ARRAY_SIZE; i++) {
		if((characters[i]) >= 97 && (characters[i]) <= 122) {
			characters[i] -= 32;
			change ++;
		 cout<<characters[i];
		}
	}
	cout<<"\n\n";
	return change;
}
