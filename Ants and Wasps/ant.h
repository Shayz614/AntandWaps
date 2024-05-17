/**
 *   @file: ant.h
 * @author: Nasseef Abukamail
 *   @date: July 28, 2022
 *  @brief: Ant class
 */


#ifndef ANT_H
#define ANT_H

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "bug.h"
using namespace std;

class Ant : public Bug {
   public:
    Ant() : Bug() { setSymbol(';');}
    Ant(size_t newR, size_t newC);
    void move(Bug* grid[][GRID_SIZE]);
    void breed(Bug* grid[][GRID_SIZE]);
};

#endif  // ANT_H
