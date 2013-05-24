


/* @desc	A driver program to test class Maze.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include "Maze.h"
using namespace std;

int main()
{
	//variable declaration
	bool setFlag = false; //sentinel value for while loop
	int row;
	int col;
	Maze maze1; //instantiate Maze object
	
	//begin program function
	maze1.printMaze(); //display Maze

	//set start position
	while ( setFlag == false )
	{
		cout << "Enter your starting position by first entering the row number.\n"
			<< "Enter the row from 0 to " << (ROWS - 1) << endl;
		cin >> row;
		cout << "Now enter the column from 0 to " << (COLUMNS - 1) << endl;
		cin >> col;
		cout << endl;
		cout << "The value you entered was: " << row << ", " << col << endl;
		if ( maze1.getCell( row, col ) != '+' && maze1.getCell( row, col ) != 'E' )
		{
			maze1.setStart( row, col ); //set starting position on maze
			setFlag = true;
		}
		else //position is either a block or an exit
		{
			cout << "That position isn't open. Please select again." << endl;
			cout << endl;
		} //end if to set start position
	} //end while

	cout << endl;
	maze1.printMaze(); //display maze
	cout << "Starting backTrack..." << endl;
	cout << endl;
	if ( maze1.backTrack( row, col ) == true )
	{
		cout << "Congratulations!" << endl;
	}
	else
	{
		cout << "Sorry, you didn't find the exit." << endl;	
	}
	maze1.printMaze(); //display maze
	
} //end function main



