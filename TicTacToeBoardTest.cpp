/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TICTACTOEBOARDTEST, SANITYCHECK)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(true);
}

TEST(TICTACTOEBOARDTEST, ToggleToO)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(board->toggleTurn() == O);
}

TEST(TICTACTOEBOARDTEST, ToggleToX)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->toggleTurn();
	ASSERT_TRUE(board->toggleTurn() == X);
}

TEST(TICTACTOEBOARDTEST, getInvalidPieceAtRowPositive)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(board->getPiece(4, 3) == Invalid);
}

TEST(TICTACTOEBOARDTEST, getInvalidPieceAtRowNegative)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(board->getPiece(-1, 3) == Invalid);
}

TEST(TICTACTOEBOARDTEST, getInvalidPieceAtColumnPositive)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(board->getPiece(3, 4) == Invalid);
}

TEST(TICTACTOEBOARDTEST, getInvalidPieceAtColumnNegative)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(board->getPiece(3, -4) == Invalid);
}

TEST(TICTACTOEBOARDTEST, getValidPiece)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(board->getPiece(3, 3) == Blank);
}

TEST(TICTACTOEBOARDTEST, placeValidPiece)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(board->placePiece(3, 3) == X);
}

TEST(TICTACTOEBOARDTEST, placeOutOfBoundLargeNumber)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(board->placePiece(6, 6) == Invalid);
}

TEST(TICTACTOEBOARDTEST, placeOutOfBoundsSmall)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	ASSERT_TRUE(board->placePiece(0, 0) == Invalid);
}

TEST(TICTACTOEBOARDTEST, placePieceTogglesTurn)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 1);
	ASSERT_TRUE(board->placePiece(2, 2) == O);
}

TEST(TICTACTOEBOARDTEST, placePieceWherePieceAlreadyIs)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 1);
	ASSERT_TRUE(board->placePiece(1, 1) == X);
}

TEST(TICTACTOEBOARDTEST, placePieceWherePieceAlreadyIsDoesntToggleTurn)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 1);
	board->placePiece(1, 1);
	ASSERT_TRUE(board->placePiece(2, 2) == O);
}

TEST(TICTACTOEBOARDTEST, xWinsInRow)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 1);
	board->placePiece(3, 1);
	board->placePiece(1, 2);
	board->placePiece(3, 2);
	board->placePiece(1, 3);
	Piece winner = board->getWinner();
	ASSERT_TRUE(winner == X);
}

TEST(TICTACTOEBOARDTEST, oWinsInRow)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(3, 1);
	board->placePiece(2, 1);
	board->placePiece(1, 1);
	board->placePiece(2, 2);
	board->placePiece(1, 2);
	board->placePiece(2, 3);
	Piece winner = board->getWinner();
	ASSERT_TRUE(winner == O);
}

TEST(TICTACTOEBOARDTEST, xWinsInColumn)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 1);
	board->placePiece(3, 3);
	board->placePiece(2, 1);
	board->placePiece(3, 2);
	board->placePiece(3, 1);
	Piece winner = board->getWinner();
	ASSERT_TRUE(winner == X);
}

TEST(TICTACTOEBOARDTEST, oWinsInColumn)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(3, 3);
	board->placePiece(1, 1);
	board->placePiece(3, 2);
	board->placePiece(2, 1);
	board->placePiece(1, 3);
	board->placePiece(3, 1);
	Piece winner = board->getWinner();
	ASSERT_TRUE(winner == O);
}

TEST(TICTACTOEBOARDTEST, xWinsOnDiagonal)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 1);
	board->placePiece(2, 1);
	board->placePiece(2, 2);
	board->placePiece(3, 1);
	board->placePiece(3, 3);
	Piece winner = board->getWinner();
	ASSERT_TRUE(winner == X);
}

TEST(TICTACTOEBOARDTEST, oWinsOnDiagonal)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 1);
	board->placePiece(1, 3);
	board->placePiece(2, 1);
	board->placePiece(2, 2);
	board->placePiece(3, 3);
	board->placePiece(3, 1);
	Piece winner = board->getWinner();
	ASSERT_TRUE(winner == O);
}

TEST(TICTACTOEBOARDTEST, gameNotOver)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 1);
	board->placePiece(1, 3);
	Piece winner = board->getWinner();
	ASSERT_TRUE(winner == Invalid);
}

TEST(TICTACTOEBOARDTEST, drawGame)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 3);
	board->placePiece(3, 1);
	board->placePiece(2, 2);
	board->placePiece(3, 3);
	board->placePiece(3, 2);
	board->placePiece(1, 2);
	board->placePiece(2, 1);
	board->placePiece(2, 3);
	board->placePiece(1, 1);
	Piece winner = board->getWinner();
	ASSERT_TRUE(winner == Blank);
}

TEST(TICTACTOEBOARDTEST, putPieceAfterWinTurnDoesntChange)
{
	TicTacToeBoard* board = new TicTacToeBoard();
	board->placePiece(1, 1); // x turn
	board->placePiece(3, 1); // o turn
	board->placePiece(1, 2); // x turn
	board->placePiece(3, 2); // o turn
	board->placePiece(1, 3); // x turn x wins turn changes to o
	board->placePiece(2, 2); // turn should not change to x
	// turn should have remained o so toggles to x
	ASSERT_TRUE(board->toggleTurn() == X);
}
