/**
 *   @file: ant.cc
 * @author: Akshay Patel
 *   @date: Aug, 05 2023
 *  @brief: Ant cell file
 */

#include "ant.h"

Ant::Ant(size_t newR, size_t newC):Bug(newR,newC)
{
	setSymbol(';');

}

void Ant::move(Bug* grid[][GRID_SIZE])
{
	int row = this->getRow();
	int col = this->getCol();
	int move = (rand() % 4) + 1;

	//move up
	if (move == 1) {

		//if up cell is empty
		if (row - 1 >= 0 && grid[row - 1][col] == nullptr) {
			this->setRow(row - 1);
			grid[row - 1][col] = grid[row][col];
			grid[row][col] = nullptr;
		}
	}

	//move right
	if (move == 2) {
		//if right cell is empty
		if (col + 1 < GRID_SIZE && grid[row][col + 1] == nullptr) {
			this->setCol(col + 1);
			grid[row][col+1] = grid[row][col];
			grid[row][col] = nullptr;
		}
	}

	//move bottom
	if (move == 3) {
		//if bottom cell is empty
		if (row + 1 < GRID_SIZE && grid[row + 1][col] == nullptr) {
			this->setRow(row + 1);
			grid[row + 1][col] = grid[row][col];
			grid[row][col] = nullptr;
		}
	}

	//move left
	if (move == 4) {
		//if left cell is empty
		if (col - 1 >= 0 && grid[row][col - 1] == nullptr) {
			this->setCol(col - 1);
			grid[row][col-1] = grid[row][col];
			grid[row][col] = nullptr;
		}
	}

	this->setSteps(getSteps() + 1);
}

void Ant::breed(Bug* grid[][GRID_SIZE])
{
	//if it hasn't survived 3 time stamps yet don't brred
	if (this->getSteps() <= 3) {
		return;
	}
	int row = this->getRow();
	int col = this->getCol();

	//Find the adjacent empty cell and create a new ant there
	if (row - 1 >= 0 && grid[row - 1][col] == nullptr) {
		grid[row - 1][col] = new Ant(row - 1, col);
	}

	else if (col + 1 < GRID_SIZE && grid[row][col + 1] == nullptr) {
		grid[row][col+1] = new Ant(row, col+1);
	}

	if (row + 1 < GRID_SIZE && grid[row + 1][col] == nullptr) {
		grid[row + 1][col] = new Ant(row + 1, col);
	}

	else if (col - 1 >= 0 && grid[row][col - 1] == nullptr) {
		grid[row][col - 1] = new Ant(row, col - 1);
	}

	//Set steps if this ant to 0.
	this->setSteps(0);
	
}
