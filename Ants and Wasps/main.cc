/**
 *   @file: predator-prey.cc
 * @author: Akshay Patel
 *   @date: Aug, 05 2023
 *  @brief: Predator Pray game of wasps and ants.
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include "ant.h"
#include "bug.h"
#include "wasp.h"
#include <time.h>
using namespace std;

/// Constants and function prototypes
const size_t NUM_WASPS = 5;
const size_t NUM_ANTS = 95;

void initializeGrid(Bug* grid[][GRID_SIZE]);
void displayGrid(Bug* grid[][GRID_SIZE]);
void timeStep(Bug* grid[][GRID_SIZE]);

void deleteGrid(Bug* grid[][GRID_SIZE]);

int main(int argc, char const* argv[]) {
    
    Bug* grid[GRID_SIZE][GRID_SIZE];
    srand(time(nullptr));

    initializeGrid(grid);
    string ans = "";
    do
    {
        displayGrid(grid);
        timeStep(grid);
        cout << "hit enter to move again, type n to quit: ";
        getline(cin, ans);
    } while (ans == "");
    
    //if you want, you run the simulation a certain number of times
    //uncomment the following
    
   /* displayGrid(grid);
    for (size_t i = 0; i < 1000; i++)
    {
        timeStep(grid);
    }
    displayGrid(grid);*/
    

    deleteGrid(grid);
    return 0;
}  /// main

void initializeGrid(Bug* grid[][GRID_SIZE])
{
    //Initalize the complete grid to null values
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }

    //Place ants 
    int antsPlaced = 0;
    while (antsPlaced < NUM_ANTS) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        //if the randomly selected cell is not occupied
        if (grid[row][col] == nullptr) {
            grid[row][col] = new Ant(row, col);
            antsPlaced++;
        }
    }

    //place wasps
    int waspsPlaced = 0;
    while (waspsPlaced < NUM_WASPS) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        //if the randomly selected cell is not occupied
        if (grid[row][col] == nullptr) {
            grid[row][col] = new Wasp(row, col);
            waspsPlaced++;
        }
    }

}

//Function displays the grid
void displayGrid(Bug* grid[][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE*2 + 3; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << setw(2) << right << i << "|";
        for (int j = 0; j < GRID_SIZE; j++) {

            //If the cell is occupied, show symbol of occupier
            if (grid[i][j] != nullptr)
                cout << grid[i][j]->getSymbol() << "|";
            //show empty space
            else
                cout << " |";
        }
        cout << endl;
    }

    for (int i = 0; i < GRID_SIZE*2 +3 ; i++)
        cout << "-";
    cout << endl;
}

void timeStep(Bug* grid[][GRID_SIZE])
{
    //Move all wasps
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr && grid[i][j]->getSymbol() == 'w' &&
                grid[i][j]->getMoved() == false) {
                grid[i][j]->setMoved(true);
                grid[i][j]->move(grid);
            }

        }
    }

    //move all ants
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr && grid[i][j]->getSymbol() == ';' &&
                grid[i][j]->getMoved() == false) {
                grid[i][j]->setMoved(true);
                grid[i][j]->move(grid);                
            }

        }
    }

    //Breed all wasps and ants
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->breed(grid);
            }
        }
    }

   

    //Reset the moved variable of all ants and wasps to false.
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->setMoved(false);
            }
        }
    }
}

//Deallocates all the memory
void deleteGrid(Bug* grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j];
                grid[i][j] = nullptr; 
            }
        }
    }
}

