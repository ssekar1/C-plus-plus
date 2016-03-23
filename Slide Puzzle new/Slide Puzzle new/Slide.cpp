// Sundar Sekar
// description : Sliding tile puzzle

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <iomanip>
using namespace std;
#define WIDTH X
#define HEIGHT Y

// functions that perform elementary operations on the board
void initializeBoard(int **board,int X,int Y);
void printBoard(int **board,int X,int Y);
bool isBoardSolved(int**,int X,int Y);
void slideTile(int **board,int move,int X,int Y);
void scrambleBoard(int**,int X,int Y);




int main()
{
	int X;
	int Y;
	cout << "Please enter the number of columns: ";
	cin  >> Y;
	cout << "Please enter the number of rows: ";
	cin  >> X;
	system("CLS");
	int **puzzleBoard;
	// dynamically allocated 2d array
	puzzleBoard= new int*[X];
	for (int i=0; i<X ; ++i) 
	puzzleBoard[i]= new int[Y];
	char input;
	bool invalid = false;
	initializeBoard(puzzleBoard,X,Y);   
	printBoard(puzzleBoard,X,Y);		  
	cout << boolalpha;
	cout<<"isBoardSolved(): "<<isBoardSolved(puzzleBoard,X,Y)<<endl;
	cout<<"Press enter to begin"<<endl;
	cin.get();  
	cout<<"Scrambling the game tiles..."<<endl;
	scrambleBoard(puzzleBoard,X,Y);  
	cout<<"Scrambling complete, press enter to begin solving. "<<endl;
	cout<<"	Good Luck! "<<endl;
	cin.get();  
	system("CLS"); // clear the screen to began solving.


	printBoard(puzzleBoard,X,Y);
	cout<<endl<<endl;
	cout<<"[W - Up] [S - Down] [A - Left] [D - Right]"<<endl;
	cout<<"Input: ";

	// loop till the game is solved
	while(!isBoardSolved(puzzleBoard,X,Y))	
	{
		input = getch();
		system("CLS");

		// selecting the game controls
		switch(toupper(input))      
		{
			case 'W':
			  slideTile(puzzleBoard,2,X,Y);
			 break;
			case 'A':
			  slideTile(puzzleBoard,0,X,Y);
			  break;
			case 'S':
			  slideTile(puzzleBoard,3,X,Y);
			  break;
			case 'D':
			  slideTile(puzzleBoard,1,X,Y);
			  break;
			default:
				invalid = true;
		}
		printBoard(puzzleBoard,X,Y);
		cout<<endl<<endl;
		cout<<"[W - Up] [S - Down] [A - Left] [D - Right]"<<endl; // setting controls for user to understand
		if(invalid)
		{
			cout<<"Invalid Input - ["<<input<<"]"; // output invalid if user enters other letters
			invalid = false;
		}
		else
			cout<<"Last Input: "<<input;

		
	}
	cout<<endl;
	cout<<"Congratulations: BOARD SOLVED"<<endl;
	system("PAUSE");
	return 0;
}



void printBoard(int **board,int X,int Y)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for(int row = 0; row < WIDTH; row++)
	{
		for(int column = 0; column < HEIGHT; column++)
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
				if(board[row][column] == ((row*WIDTH)+(column+1)))   
					SetConsoleTextAttribute(hConsole, 9);
				else
					// if the number is not in the right position
					SetConsoleTextAttribute(hConsole, 13);		 

			    cout<<"  "<<setw(2)<<board[row][column];
			}
		}
		cout<<endl;
	}
	SetConsoleTextAttribute(hConsole, 12); // set text color
}



// board setup. initializing
void initializeBoard(int **board,int X,int Y)
{

	int i = 1;
	for(int row = 0; row < WIDTH; row++)
	{
		for(int column = 0; column < HEIGHT; column++)
		{
			board[row][column] = i;
			i++;
		}
		board[WIDTH-1][HEIGHT-1] = 0;
	}
}


// movements
void slideTile(int **board,int move,int X,int Y) 
{
	int emptyRow;
	int emptyColum;
	
	bool legalMoves[4] = {1,1,1,1}; 
	for(int row = 0; row < WIDTH; row++)
	{
		for(int column = 0; column < HEIGHT; column++)
		{
			if(board[row][column] == 0) 
			{
				emptyRow = row;
				emptyColum = column;
			}
		}
	}
	if(emptyRow + 1 > (X-1))      
		legalMoves[2] = false; 
	else if(emptyRow - 1 < 0)  
		legalMoves[3] = false;

	if(emptyColum - 1 < 0)	   
		legalMoves[1] = false;
	else if(emptyColum + 1 > (X-1) ) 
		legalMoves[0] = false;


	switch(move) 
	{
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


}
void scrambleBoard(int **board,int X,int Y)
{
	srand ( time(NULL) );
	int move;
	while(isBoardSolved(board,X,Y))   
	{
		for(int i = 0; i < 100000; i++) 
		{
			move  = rand() % 5;
			slideTile(board,move,X,Y); 
		}
	}

}
// is the board solved
bool isBoardSolved(int **board,int X,int Y)
{
	int **solvedBoard;	
	solvedBoard= new int*[X];
	for (int i=0; i<X ; ++i) 
	solvedBoard[i]= new int[Y];
	initializeBoard(solvedBoard, X,Y);
	bool boardSolved = true;
	int row = 0;
	int col = 0;
	while(boardSolved && row<= (X-1))
	{
		if(solvedBoard[row][col] == board[row][col]) 
		{

			col++;
			if(col >= WIDTH)
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

