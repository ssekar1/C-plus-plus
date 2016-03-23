
#include <iostream>
#include "SlidingPuzzle.h"
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
	SlidingPuzzle mySlidingPuzzle;

    
    char input;
    bool invalid = false;
	mySlidingPuzzle.InitializeBoard() ; 
    mySlidingPuzzle.PrintBoard();         
    cout << boolalpha;
    cout<<"isBoardSolved(): "<<mySlidingPuzzle.isBoardSolved()<<endl;
    cout<<"Press enter to begin"<<endl;
    cin.get();  
    cout<<"Scrambling the game tiles..."<<endl;
    mySlidingPuzzle.scrambleBoard();  
    cout<<"Scrambling complete, press enter to begin solving. "<<endl;
    cout<<"    Good Luck! "<<endl;
    cin.get();  
    system("CLS"); // clear the screen to began solving.


    mySlidingPuzzle.PrintBoard();
    cout<<endl<<endl;
    cout<<"[W - Up] [S - Down] [A - Left] [D - Right]"<<endl;
    cout<<"Input: ";

    // loop till the game is solved
    while(!mySlidingPuzzle.isBoardSolved())    
    {
        input = getch();
        system("CLS");

        // selecting the game controls
        switch(toupper(input))      
        {
            case 'W':
              mySlidingPuzzle.slideTile(2);
             break;
            case 'A':
              mySlidingPuzzle.slideTile(0);
              break;
            case 'S':
              mySlidingPuzzle.slideTile(3);
              break;
            case 'D':
              mySlidingPuzzle.slideTile(1);
              break;
            default:
                invalid = true;
        }
        mySlidingPuzzle.PrintBoard();
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