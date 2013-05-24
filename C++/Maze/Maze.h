


/*	@desc	A class to operate a 2-dimensional Maze for transit by recursion.
* 	@auth	Richard Dunks richarddunks@gmail.com
*/
#ifndef MAZE_H
#define MAZE_H

#include <iostream>
using namespace std;

static const int ROWS = 4;
static const int COLUMNS = 5;

class Maze
{
public:
	Maze(); //default constructor
	void printMaze(); //print out maze
	void writeBlock(); //write blocks in maze
	void writeExit(); //write exit from maze
	void setStart( int row, int col ); //set start location
	char getCell( int row, int col ); //get cell contents
	void setCell( int row, int col, char val ); //set cell contents
	bool backTrack( int row, int col ); //algorithm to recursively find exit
private:
	char maze[ ROWS ][ COLUMNS ];


}; //end class Maze


#endif



