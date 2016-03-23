

// Specification file for the Sliding class


#ifndef SlidingPuzzle_H
#define SlidingPuzzle_H

#include <iostream>
using namespace std;

#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

// sliding class declaration.

class SlidingPuzzle {

private:

int board[3][3];
      
 
public:

 // CONSTRUCTOR Method

 SlidingPuzzle();
  

// Methods
void InitializeBoard();
void PrintBoard();
bool isBoardSolved();
bool slideTile(int);
void scrambleBoard();

// Accesors and Mutators not needed.

}; 

 #endif

 