/**
 *   @file: Wasp.cc
 * @author: Akshay Patel
 *   @date: Aug, 05 2023
 *  @brief: Wasp Cell file
 */

#include "wasp.h"


//Default constructor
Wasp::Wasp(size_t newR, size_t newC) :Bug(newR, newC) {
	starve = 3;
	setSymbol('w');
	sinceEaten = 0;
}

void Wasp::move(Bug* grid[][GRID_SIZE])
{
	int row = this->getRow();
	int col = this->getCol();

	//Randomly generate a variable to move randomly.
	int move = (rand() % 4) + 1;

	//move up
	if (move == 1) {

		//if up cell is empty or there is an ant there
		if (row - 1 >= 0 && (grid[row - 1][col] == nullptr  ||
			grid[row-1][col]->getSymbol() == ';') ) {


			//if  there is ant, eat it
			if (grid[row - 1][col] != nullptr)
			{
				delete grid[row - 1][col];
				grid[row - 1][col] = nullptr;
				sinceEaten = -1;
			}

			this->setRow(row - 1);
			grid[row - 1][col] = grid[row][col];
			grid[row][col] = nullptr;
		}
	}

	//move right
	if (move == 2) {
		//if right cell is empty or there is an ant there
		if (col + 1 < GRID_SIZE && (grid[row][col+1] == nullptr ||
			grid[row][col+1]->getSymbol() == ';')) {
			//if  there is ant, eat it
			if (grid[row][col + 1] != nullptr)
			{
				delete grid[row][col+1];
				grid[row][col+1] = nullptr;
				sinceEaten = -1;
			}

			this->setCol(col + 1);
			grid[row][col + 1] = grid[row][col];
			grid[row][col] = nullptr;
		}
	}

	//move bottom
	if (move == 3) {
		//if bottom cell is empty or there is an ant there
		if (row + 1 < GRID_SIZE && (grid[row + 1][col] == nullptr ||
			grid[row + 1][col]->getSymbol() == ';')) {
			//if  there is ant, eat it
			if (grid[row + 1][col] != nullptr)
			{
				delete grid[row + 1][col];
				grid[row + 1][col] = nullptr;
				sinceEaten = -1;
			}

			this->setRow(row + 1);
			grid[row + 1][col] = grid[row][col];
			grid[row][col] = nullptr;
		}
	}

	//move left
	if (move == 4) {

		//if top cell is empty or there is an ant there
		if (col - 1 >= 0 && (grid[row][col-1] == nullptr ||
			grid[row][col-1]->getSymbol() == ';')) {
			//if  there is ant, eat it
			if (grid[row][col - 1] != nullptr)
			{
				delete grid[row][col - 1];
				grid[row][col-1] = nullptr;
				sinceEaten = -1;
			}

			this->setCol(col - 1);
			grid[row][col - 1] = grid[row][col];
			grid[row][col] = nullptr;
		}
	}

	this->setSteps(getSteps() + 1);
	sinceEaten++;
	
}

void Wasp::breed(Bug* grid[][GRID_SIZE])
{
	if (this->getSteps() < 8) {

		//if this wasp is to starve,  delete it.
		if (starve == sinceEaten) {
			int row = getRow();
			int col = getCol();
			delete grid[row][col];
			grid[row][col] = nullptr;
		}
		return;

	}

	//if any adjacent cells are empty, brred there
	int row = this->getRow();
	int col = this->getCol();

	if (row - 1 >= 0 && grid[row - 1][col] == nullptr) {
		grid[row - 1][col] = new Wasp(row - 1, col);
	}

	else if (col + 1 < GRID_SIZE && grid[row][col + 1] == nullptr) {
		grid[row][col + 1] = new Wasp(row, col + 1);
	}

	if (row + 1 < GRID_SIZE && grid[row + 1][col] == nullptr) {
		grid[row + 1][col] = new Wasp(row + 1, col);
	}

	else if (col - 1 >= 0 && grid[row][col - 1] == nullptr) {
		grid[row][col - 1] = new Wasp(row, col - 1);
	}

	this->setSteps(0);
	//if this wasp is to starve,  delete it.
	if (starve == sinceEaten) {
		int row = getRow();
		int col = getCol();
		delete grid[row][col];
		grid[row][col] = nullptr;
	}
}