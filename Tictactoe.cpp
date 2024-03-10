
#include <iostream>
#include "Tictactoe.h" // The Tictactoe.h file contains our class "blueprint" we must include it so we can reference the class below

/*

  WRITE YOUR OUT-OF-CLASS constructors and methods HERE for the Tic Tac Toe class

  Start each constructor with the name of your class followed by the scope resolution operator like ::, and then the class name (again)

  Start each method with its return type, followed by the name of your class followed the scope resolution operator, and then the method name

  Use the Tictactoe.h file as a guide (along with the README.md file) to help guide which constructors and methods you need to implement.

*/
Tictactoe::Tictactoe() 
{
emptyToken = '-'; // Set the blank space variable to "-"
  for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
       {
         grid[i][j] = emptyToken;
       }
    }
}

Tictactoe::Tictactoe(char _emptyToken)
{
  emptyToken = _emptyToken;

    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
       {
         grid[i][j] = emptyToken;
       }
    }
}

Tictactoe::Tictactoe(char _emptyToken, std::vector<char> initTokens)
{
  emptyToken = '-';
  emptyToken = _emptyToken;
  // std::vector<char> initTokens = 'X';
    // Populate the grid with emptyToken
  for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
       {
         grid[i][j] = emptyToken;
       }
    }
}




void Tictactoe::printMe()
{
  std::cout << "   1 2 3" << std::endl;       // To print the top of the board
  for (int i = 0; i < 3; i++)
  {
    std::cout << " " << i + 1;
    for (int j = 0; j < 3; j++)
     {
      std::cout << " " << grid[i][j];
     }
    std::cout << std::endl;
  }
};

bool Tictactoe::takeTurn(int r, int c, char token)
{
  int rowSpot = r - 1;
  int columnSpot = c - 1;
  if( r <= 0 || r >= 4 || c >= 4|| c <= 0)
  {
    std::cout << "Must only enter numbers between 1 and 3." << std::endl;
    std::cout << "Please try again: " << std::endl; 
    return false;
  }
   else if(grid[rowSpot][columnSpot] == 'X' || grid[rowSpot][columnSpot] == 'O')
  {
    std::cout << "A player's mark is already on row " << r << " column " << c;
    std::cout <<std::endl << "Please pick another spot." << std::endl;
    return false;
  }
  else
  {
    grid[rowSpot][columnSpot] = token;
    return true;
  }
}

bool Tictactoe::takeTurnComputer(int r, int c, char token)
{
  int rowSpot = r - 1;
  int columnSpot = c - 1;
  if( r <= 0 || r >= 4 || c >= 4|| c <= 0)
  {
    return false;
  }
   else if(grid[rowSpot][columnSpot] == 'X' || grid[rowSpot][columnSpot] == 'O')
  {
    return false;
  }
  else
  {
    grid[rowSpot][columnSpot] = token;
    return true;
  }
}

bool Tictactoe::isWin(char playerChar)
{
  // Row Win (return true)
for(int i = 0; i < 2; i++)
  {
    if(grid[i][0] == playerChar && grid[i][1] == playerChar && grid[i][2] == playerChar)
      {
        return true;
      }
      else{}
  }
  // Column Win (return true)
for(int i = 0; i < 2; i++)
  {
    if(grid[0][i] == playerChar && grid[1][i] == playerChar && grid[2][i] == playerChar)
      {
        return true;
      }
      else{}
  }
  // Diagonal Win (return true)
  if(grid[0][0] == playerChar && grid[1][1] == playerChar && grid[2][2] == playerChar)
    {
      return true;
    }
  else if (grid[2][0] == playerChar && grid[1][1] == playerChar && grid[0][2] == playerChar)
    {
      return true;
    }
  else
    { }
  // No Win (Return false)
  return false;
}

bool Tictactoe::isTie()
{
  emptyToken = '-';
  // If there is a tie, return true
  //If there's no tie, return false
  for(int i = 0; i < 2; i++)
    {
      for(int j = 0; j < 2; j++)
        {
          if(grid[i][j] == emptyToken)
            {
              return false;
            }
          else { }    // Should be empty
        }
    }
  return true;
}
