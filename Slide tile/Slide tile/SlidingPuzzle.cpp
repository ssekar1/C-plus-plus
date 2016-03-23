// Sundar Sekar


// implementation file for the Sliding puzzle.

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include "SlidingPuzzle.h"
using namespace std;


// board setup. initializing
void SlidingPuzzle::InitializeBoard()
{
    int i = 1;
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            board[row][column] = i;
            i++;
        }
        board[2][2] = 0;
    }
}



// is the board solved
bool SlidingPuzzle::isBoardSolved()
{
    int solvedBoard[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
    bool boardSolved = true;
    int row = 0;
    int col = 0;
    while(boardSolved && row<=2)
    {
        if(solvedBoard[row][col] == board[row][col]) 
        {
            col++;
            if(col >= 3)
            {
                row++;
                col = 0;
                
            }
            
        }
        else 
            boardSolved = false;
    }
    return boardSolved;
    
}




// movements
bool SlidingPuzzle::slideTile(int move) 
{
    int emptyRow;
    int emptyColum;
    int emptySpace[2];
    bool legalMoves[4] = {1,1,1,1}; 
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            if(board[row][column] == 0) 
            {
                emptyRow = row;
                emptyColum = column;
            }
        }
    }
    if(emptyRow + 1 > 2)      
        legalMoves[2] = false; 
    else if(emptyRow - 1 < 0)  
        legalMoves[3] = false;

    if(emptyColum - 1 < 0)       
        legalMoves[1] = false;
    else if(emptyColum + 1 > 2)  
        legalMoves[0] = false;


    switch(move) 
    {
		//  validating legal moves
        case 0:
            if(legalMoves[move])
            {
                board[emptyRow][emptyColum] = board[emptyRow][emptyColum + 1];  
                board[emptyRow][emptyColum + 1] = 0;
                emptyColum = emptyColum+1;
            }
            break;
        case 1:
            if(legalMoves[move])
            {
                board[emptyRow][emptyColum] = board[emptyRow][emptyColum - 1];
                board[emptyRow][emptyColum- 1] = 0;
                emptyColum = emptyColum-1;
            }
            break;
        case 2:
            if(legalMoves[move])
            {
                    board[emptyRow][emptyColum] = board[emptyRow+1][emptyColum];
                    board[emptyRow+1][emptyColum] = 0;
                    emptyRow = emptyRow+1;
            }
            break;
        case 3:
            if(legalMoves[move])
            {
                    board[emptyRow][emptyColum] = board[emptyRow-1][emptyColum];
                    board[emptyRow-1][emptyColum] = 0;
                    emptyRow = emptyRow-1;
            }
            break;
    }
	return false;
}
// scramble puzzle
void SlidingPuzzle::scrambleBoard()
{
    srand ( time(NULL) );
    int move;
    while(isBoardSolved())   
    {
        for(int i = 0; i < 9000; i++) 
        {
            move  = rand() % 5; // random fuction to genertate moves
            slideTile(move); 
        }
    }

}
// setting the colors of the board
void SlidingPuzzle::PrintBoard()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            if(board[row][column] == 0)
            {
                // setting colors 
                SetConsoleTextAttribute(hConsole, 6);            
                cout<<"  *";
            }
            else
            {
                // if the number is in the right position
                if(board[row][column] == ((row*3)+(column+1)))   
                    SetConsoleTextAttribute(hConsole, 9);
                else
                    // if the number is not in the right position
                    SetConsoleTextAttribute(hConsole, 13);         

                cout<<"  "<<board[row][column];
            }
        }
        cout<<endl;
    }
    SetConsoleTextAttribute(hConsole, 12); // set text color
}
 SlidingPuzzle::SlidingPuzzle()
 {
 }

