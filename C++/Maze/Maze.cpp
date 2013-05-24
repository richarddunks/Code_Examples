

/*	@desc	A class to operate a 2-dimensional Maze for transit by recursion.
* 	@auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include "Maze.h"
using namespace std;

Maze::Maze() //default constructor
{
	char def = 'O';
	for ( int i = 0; i < ROWS; i++ ) //loop through rows
	{
		for (int j = 0; j < COLUMNS; j++ ) //loop through columns of current row
		{
			//set row and column for cell
			maze[ i ][ j ] = def; 
		} //end-for loop through columns
	} //end-for loop through rows
	writeBlock(); //write block positions into maze
	writeExit(); //write exit position into maze
} //end default constructor

void Maze::printMaze()
{
	for ( int i = 0; i < ROWS; i++ )
	{
		cout << "+---+---+---+---+---+\n";
		//loop through columns of current row
		for ( int j = 0; j < COLUMNS; j++ )
		{
			cout << "| " << maze[ i ][ j ] << " ";
		}
		cout << "|" << endl; //start new line of output
	}
	cout << "+---+---+---+---+---+" << endl;
} //end function printMaze

//function to write blocks to the maze
void Maze::writeBlock()
{
	int x = 1;
	int y = 4;
	char block = '+';
	maze[ x ][ y ] = block; //set block at 1,4
	maze[ ++x ][ y ] = block; //set block at 2,4
	maze[ ++x ][ y ] = block; //set block at 3,4
	maze[ x ][ --y ] = block; //set block at 3,3
	--y; //y = 2
	maze[ x ][ --y ] = block; //set block at 3,1
	maze[ x ][ --y ] = block; //set block at 3,0
	--x; //x = 2
	maze[ --x ][ ++y ] = block; //set block at 1,1
	maze[ --x ][ ++y ] = block; //set block at 0,2		
} //end function writeBlock

//function to set the exit location from the maze
void Maze::writeExit()
{
	maze[ 0 ][ 3 ] = 'E'; //set exit at 0,3
} //end function writeExit

//function to set the starting position in the maze
void Maze::setStart( int row, int col )
{
	setCell( row, col, 'S' );	
} //end function setStart

char Maze::getCell( int row, int col )
{
	char cell = maze[ row ][ col ];
	return cell;
} //end function getCell

void Maze::setCell( int row, int col, char val )
{
	maze[ row ][ col ] = val;
} //end function setCell

//function to recursively find the exit from a starting position
//true value indicates found the exit, false indicates found a block or went off the maze
bool Maze::backTrack( int row, int col )
{

//if we are still searching 
    // base case 1

	if ( row < 0 || col < 0 || row >= ROWS || col >= COLUMNS ) //search off the maze
	{
		cout << "Cell " << row << ", " << col << " is out of bounds!" << endl;
		return false;
	}
	else if ( getCell( row, col ) == '+' )
	{
		cout << "You found a block at cell " << row << ", " << col << endl;
		return false;
	}
	else if ( getCell( row, col ) == 'X' )
	{
		cout << "You've already visited cell " << row << ", " << col << endl;
		return false;
	}
    //if the position we are trying is the exit, we are done and do not need to search any further
	else if ( getCell( row, col ) == 'E' )
	{
		cout << "You found the Exit!" << endl;
		return true;
	}
	else // recursive case
    {
    	setCell( row, col, 'X' ); //indicate cell has already been visited
	// search each adjacent row and column position, but only if the exit has not been found.
    	if ( backTrack( (row - 1), col ) == true )
    	{
    		return true;
    	}
    	else if ( backTrack( row, (col + 1) ) == true )
    	{
			return true;
		}
		else if ( backTrack( row, (col - 1) ) == true )
		{
			return true;
		}
    	else if ( backTrack( (row + 1), col ) == true )
    	{
    		return true;
    	}
    	else
    	{
    		return false;
     	}//end if
    //if the position is an open position then we continue the search
          	// mark the position we are in so we know we have visited it

	} //end if
} //end function backTrack



