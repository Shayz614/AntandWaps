/**
 *   @file: bug.h
 * @author: Akshay Patel
 *   @date: Aug, 05 2023
 *  @brief: Bug base class
 */


#ifndef BUG_H
#define BUG_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const size_t GRID_SIZE = 20;
class Bug{
public:
    Bug() {
        symbol = ' ';
        row = -1;
        col = -1;
        steps = 0;
        moved = false;
    }
    
    Bug(int bugRow, int bugCol) {
        steps = 0;
        row = bugRow;
        col = bugCol;
        symbol = ' ';
        moved = false;
    }

     size_t getRow() const{return row;}
     size_t getCol() const{return col;}
     size_t getSteps() const{return steps;};
    char getSymbol() const{return symbol;}

    void setRow(size_t r){row = r;}
    void setCol(size_t c){col = c;}
    void setSteps(size_t s){steps = s;}
    void setMoved(bool mov) { moved = mov; }
    void setSymbol(char s){symbol = s;}yuuqyuuu
    char getSymbol(){return symbol;}
    bool getMoved() { return moved; }
    virtual void move(Bug* grid[][GRID_SIZE]){};
    virtual void breed(Bug* grid[][GRID_SIZE]) {};
    virtual ~Bug(){}
private:
    size_t steps;
    size_t row; //row location
    size_t col; //col location
    char symbol; //character to represent a bugyiuisdkjnn ikkxhtrrrrqttttwjjjklam,mx,c powere/*---+6
    bool moved;
};


#endif