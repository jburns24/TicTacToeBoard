#include "TicTacToeBoard.h"
#include <iostream>
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (this->turn == X)
  {
    this->turn = O;
    return O;
  }
  else
  {
    this->turn = X;
    return this->turn;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece gameStatus = this->getWinner();
  if (gameStatus == Invalid)
  {
   if (this->getPiece(row, column) != Invalid)
    {
      if (this->board[row - 1][column - 1] == Blank)
      {
        Piece currentPiece =this->turn;
        this->board[row - 1][column - 1] = currentPiece;
        this->toggleTurn();
        return currentPiece;
      }
      else
      {
        return this->board[row - 1][column- 1];
      }
      
    }
    else
    {
      return Invalid;
    } 
  }
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row > 3 || column > 3) 
  {
    return Invalid;
  }
  if (row < 1 || column < 1)
  {
    return Invalid;
  }
  else
  {
    return (Piece)this->board[row - 1][column -1];
  }
  
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  bool x_wins = false;
  bool o_wins = false;
  Piece lastFound = Invalid;
  bool foundBlanks = false;
  std::string row = "";
  // check for wins in rows
  for (int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      lastFound = this->board[i][j];
      row += lastFound;
      if (lastFound == Blank)
        foundBlanks = true;
    }
    if (row == "XXX")
    {
      x_wins = true;
      break;
    }
    if (row == "OOO")
    {
      o_wins = true;
      break;
    }
    row = "";
  }
  
  if (x_wins)
    return X;
  if (o_wins)
    return O;
    
    
  lastFound = Invalid;
  row = "";
  x_wins = false;
  o_wins = false;  
  // check for wins in columns
  for (int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      lastFound = this->board[j][i];
      row += lastFound;
      if (lastFound == Blank)
        foundBlanks = true;
    }
    if (row == "XXX")
    {
      x_wins = true;
      break;
    }
    if (row == "OOO")
    {
      o_wins = true;
      break;
    }
    row = "";
  }
  
  if (x_wins)
    return X;
  if (o_wins)
    return O;

  // Check for wins on diagonal
  std::string diag1 = "";
  std::string diag2 = "";
  int opp = 2;
  for (int i = 0; i < 3; i++)
  {
    diag1 += this->board[i][i];
    diag2 += this->board[i][opp];
    opp--;
  }
  if (diag1 == "XXX" || diag2 == "XXX")
  {
    x_wins = true;
  }
  if (diag1 == "OOO" || diag2 == "OOO")
  {
    o_wins = true;
  }
  if (x_wins)
    return X;
  if (o_wins)
    return O;
    
  if (foundBlanks)
  {
    return Invalid;
  }
  
  return Blank;
}
