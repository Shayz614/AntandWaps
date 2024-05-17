/**
 *   @file: wasp.h
 * @author: Nasseef Abukamail
 *   @date: July 28, 2022
 *  @brief: Wasp class
 */
#ifndef WASP_H
#define WASP_H

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "bug.h"
using namespace std;

class Wasp : public Bug {
   public:
    Wasp() :Bug() {
        starve = 0;
        sinceEaten = 0;
    };
    Wasp(size_t newR, size_t newC);
    void move(Bug* grid[][GRID_SIZE]);
    void breed(Bug* grid[][GRID_SIZE]);
   
   private:
    size_t starve; 
    size_t sinceEaten;
};


#endif  