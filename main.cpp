/*
Name: Shindelus, Rachel
Compiler: repl.it
Due Date: 02-22-21
Purpose: Homework 2: Tic Tac Toe
  Directions found in "README.md"
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Tictactoe.h" // This file contains our class "blueprint" we must include it so we can reference the class below

using namespace std;

  // Initializations
int rowOne[3] = {0, 0, 0};
int rowTwo[3] = {0, 0, 0};
int rowThree[3] = {0, 0, 0};
char yesNo = 'n';

// Functions found under main
void printBoard();  // Print out the board pattern/grid
void howToPlay();   // Prints the directions on how to play
void printDirectionsOrNot();    // Does player want directions printed?
int easyComputerRow(int computerRowInput);
int easyComputerColumn(int computerColumnInput);
bool playAgainstComputer();


int main() {
  cout << "Let's Play Tic Tac Toe...\n";
  cout << endl;
  // YOUR CODE GOES HERE
  srand(time(NULL));
  const char playerOnesToken = 'X';
  const char playerTwosToken = 'O';
  int playerRowInput = 0;
  int playerColumnInput = 0;

  printDirectionsOrNot();   // Determines if the directions should be printed. 
 // playAgainstComputer();


// if (playAgainstComputer() == false)
{
  cout << "Starting Board: " << endl;
  Tictactoe myGame('-');
  myGame.printMe();
  // Starting the Game
cout << endl;
for(int z = 0; z < 9; z++)
{
 cout << "Player " << (z % 2) + 1 << "'s Turn: ";
 cin >> playerRowInput >> playerColumnInput;
 if(z % 2 == 0)
  {
         if (myGame.takeTurn(playerRowInput, playerColumnInput, playerOnesToken) == false)
      {
        cin >> playerRowInput >> playerColumnInput;
        myGame.takeTurn(playerRowInput, playerColumnInput, playerOnesToken);
      }
        else 
          { 
            if(myGame.isWin(playerOnesToken) == true)
              {
                myGame.printMe();
                cout << "Player 1 has won the game!" << endl;
                cout << "Goodbye!";
                return 0;
              }
              else{}
          }
  }
 else if (z % 2 == 1)
  {
     if (myGame.takeTurn(playerRowInput, playerColumnInput, playerTwosToken) == false)
      {
        cin >> playerRowInput >> playerColumnInput;
        myGame.takeTurn(playerRowInput, playerColumnInput, playerTwosToken);
      }
      else 
       { 
          if(myGame.isWin(playerTwosToken) == true)
            {
            if(myGame.isWin(playerTwosToken) == true)
              {
                myGame.printMe();
                cout << "Player 2 has won the game!" << endl;
                cout << "Goodbye!";
                return 0;
              }
             }
          else{}
        }
  }
  else 
  { 
    cout << "ERROR";
    break;
  }
 myGame.printMe();
 cout << endl;
}

if(myGame.isTie() == true)
  {
    cout << "It's a tie." << endl << "Goodbye" << endl;
  }
}
/*
else
{
  {
  cout << "Starting Board: " << endl;
  Tictactoe myGame('-');
  myGame.printMe();
  // Starting the Game
cout << endl;
for(int z = 0; z < 9; z++)
{
 cout << "Player " << (z % 2) + 1 << "'s Turn: ";
 if(z % 2 == 0)  // Player 1 (Human)
  {
     cin >> playerRowInput >> playerColumnInput;
         if (myGame.takeTurn(playerRowInput, playerColumnInput, playerOnesToken) == false)
      {
        cin >> playerRowInput >> playerColumnInput;
        myGame.takeTurn(playerRowInput, playerColumnInput, playerOnesToken);
      }
        else 
          { 
            if(myGame.isWin(playerOnesToken) == true)
              {
                myGame.printMe();
                cout << "Player 1 has won the game!" << endl;
                cout << "Goodbye!";
                return 0;
              }
              else{}
          }
  }
 else if (z % 2 == 1) // Player 2 (Computer)
  {
    playerRowInput = easyComputerRow(playerRowInput);
    playerColumnInput = easyComputerColumn(playerColumnInput);
     if (myGame.takeTurnComputer(playerRowInput, playerColumnInput, playerTwosToken) == false)
      {
        while(myGame.takeTurnComputer(playerRowInput, playerColumnInput, playerTwosToken) == false)
        {
          playerRowInput = easyComputerRow(playerRowInput);
          playerColumnInput = easyComputerColumn(playerColumnInput);
          myGame.takeTurnComputer(playerRowInput, playerColumnInput, playerTwosToken);
               if (myGame.takeTurnComputer(playerRowInput, playerColumnInput, playerTwosToken) == true)
               {break;}
        }
      }
      else 
       { 
          if(myGame.isWin(playerTwosToken) == true)
            {
            if(myGame.isWin(playerTwosToken) == true)
              {
                myGame.printMe();
                cout << "Player 2 has won the game!" << endl;
                cout << "Goodbye!";
                return 0;
              }
             }
          else{}
        }
  }
  else 
  { 
    cout << "ERROR";
    break;
  }
 myGame.printMe();
 cout << endl;
}

if(myGame.isTie() == true)
  {
    cout << "It's a tie." << endl << "Goodbye" << endl;
  }
}
}
*/
cout << endl;
return 0;
} //End of main

// *************************************Functions************************************
void printBoard() 
{
  cout << "  1 2 3";        // To print the top of the board
  cout << endl;
  // To print the first row
  cout << "1";
  for(int i = 0; i < 3 ; i++)
  {
    if (rowOne[i] == 0)
      {
        cout << " -";
      }
    else
      {
        cout << " " << rowOne[i];
      }
  } //End of for-loop for the first row
  cout << endl;
  // To print the Second row
  cout << "2";
  for(int i = 0; i < 3 ; i++)
  {
    if (rowTwo[i] == 0)
      {
        cout << " -";
      }
    else
      {
        cout << " " << rowTwo[i];
      }
  } //End of for-loop for the second row
  cout << endl;
    // To print the Third row
  cout << "3";
  for(int i = 0; i < 3 ; i++)
  {
    if (rowThree[i] == 0)
      {
        cout << " -";
      }
    else
      {
        cout << " " << rowThree[i];
      }
  } //End of for-loop for the second row
  cout << endl << endl;
}

void howToPlay()
{
cout << "  ______________________________________________________" << endl;
cout << setw(35) << "HOW TO PLAY: " << endl;
cout << " The game is played on a grid that's 3 squares by 3 squares." << endl;
cout << setw(31) << "  1 2 3 " << endl;
cout << setw(31) << "1 - - - " << endl;
cout << setw(31) << "2 - - - " << endl;
cout << setw(31) << "3 - - - " << endl;
cout << endl;
cout << "  You will enter two numbers (1-3). The first number will" << endl;
cout << " determine which row you want to mark. The second number" << endl;
cout << " will determine which column. PLAYER 1 will represent \"X\"" << endl;
cout << " and PLAYER 2 will represent \"O\"" << endl;
cout << endl;
cout << "  Example: " << endl;
cout << "    PLAYER 1's turn: " << endl;
cout << "      Enter a move like \"1 2\" for row 1, column 2." << endl;
cout << setw(44) << "  1 2 3  ← COLUMN #" << endl;
cout << setw(31) << "1 - X - " << endl;
cout << setw(31) << "2 - - - " << endl;
cout << setw(31) << "3 - - - " << endl;
cout << setw(26) << "↑" << endl;
cout << setw(24) << "R" << endl;
cout << setw(24) << "O" << endl;
cout << setw(24) << "W" << endl;
cout << setw(24) << "#" << endl;
cout << endl;
cout << "  Players will take turns filling the empty marks on the" << endl;
cout << " grid. The first player who gets three of their marks in" << endl;
cout << " the same row, column, or a diagonal line wins. If the" << endl;
cout << " board fills up, then the game is over." << endl;
cout << "\t  1 2 3         1 2 3         1 2 3         1 2 3" << endl;
cout << "\t1 X X -       1 - X O       1 O X X       1 X X O" << endl;
cout << "\t2 O O O       2 O X -       2 X O -       2 O X X" << endl;
cout << "\t3 - - X       3 - X -       3 - X O       3 X O O" << endl;
cout << "\tRow Win      Column Win   Diagonal Win   No Winner" << endl;
cout << "  ______________________________________________________" << endl << endl;
}

void printDirectionsOrNot()
{
    // Does the player want the directions to be printed or not?
      cout << "Would you like to read the directions?" << endl;
  cout << "(Y/N): ";
  cin >> yesNo;
  cout << endl;
{
    if ((yesNo == 'Y') || (yesNo =='y'))
      {
        howToPlay();
      }
    else if((yesNo == 'N') || (yesNo == 'n')) // Continue without printing instructions
      {  }    // Should be empty to continue      
    else
      {
        while((yesNo != 'N') || (yesNo != 'n') || (yesNo != 'Y') || (yesNo !='y'))
        {
          cout << "Invalid Input. Try again (Y/N): ";
          cin >> yesNo;
            if ((yesNo == 'Y') || (yesNo =='y'))
              {
                howToPlay();
                break;
              }
            else if((yesNo == 'N') || (yesNo == 'n')) // Continue without printing instructions
              { 
                break; 
              }      
            else {}   // Do nothing so the loop will continue until there's a proper input.
        }
      }
} // End of direction chunk
}

bool playAgainstComputer()
{
  cout << "Would you like to play against the computer?" << endl;
  cout << "(Y/N): ";
  cin >> yesNo;

  if ((yesNo == 'Y') || (yesNo =='y'))
    {
      cout << endl;
      return true;
    }
  else
    {
      cout << endl;
      return false;
    }
}

int easyComputerRow(int row)
{
  row = 1 + rand() % 3;

  return row;
}

int easyComputerColumn(int col)
{
    col = 1 + rand() % 3;
    
    return col;
}
