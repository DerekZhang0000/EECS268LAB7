/* -----------------------------------------------------------------------------
 *
 * File Name:  CeoOfBlob.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 BLOBLAB
 * Description:  This program will create a blob simulator.
 * Date: 11/1/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include "CeoOfBlob.h"
#include <fstream>
#include <iostream>
#include <string>
int eaten;
bool sewerInPath;

CeoOfBlob::CeoOfBlob(std::string filename)
{   //initializing variables
    origMap = new Map(filename);
    blobMap = new Map(filename);
    startX = blobMap->getStartX();
    startY = blobMap->getStartY();
    currentX = startX;
    currentY = startY;
    eaten = 0;
    sewerInPath = false;
}
void CeoOfBlob::run()
{   //runs main program
    try
    {
        if (canSpread(startX, startY) == false)
        {   //if starting position is invalid
            throw(std::runtime_error("Error: Invalid starting position."));
        }
        else
        {
            blobMap = blob(blobMap);    //begins recursion
            origMap->printMap();    //prints original and blobbified maps
            std::cout << "\n";
            blobMap->printMap();
            std::cout << "\n";
            std::cout << "Total eaten: " << eaten << "\n";  //prints total people eaten
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
}
Map* CeoOfBlob::blob(Map* map)
{
    spread(currentX, currentY); //blob recursion
    if (sewerInPath == true)
    {
        searchSewers(); //if a sewer is in path, teleports blob to all other sewers
    }
    return map;
}
void CeoOfBlob::searchSewers()
{
    for (int x = 0; x < blobMap->getRows(); x++)
    {
        for (int y = 0; y < blobMap->getCols(); y++)
        {
            if (blobMap->charAt(x, y) == '@')
            {   //spreads blob to each sewer it finds in the map
                spread(x, y);
            }
        }
    }
    for (int x = 0; x < blobMap->getRows(); x++)
    {
        for (int y = 0; y < blobMap->getCols(); y++)
        {
            if (blobMap->charAt(x, y) == '%')
            {   //reverts used sewers back to original state
                blobMap->changeChar(x, y, '@');
            }
        }
    }
}
void CeoOfBlob::mark(int row, int col)
{
    if (blobMap->charAt(row, col) == 'P')
    {   //consume human
        eaten++;
        blobMap->changeChar(row, col, 'B');
    }
    else if (blobMap->charAt(row, col) == 'S')
    {   //uses street
        blobMap->changeChar(row, col, 'B');
    }
    else if (blobMap->charAt(row, col) == '@')
    {   //uses sewer
        blobMap->changeChar(row, col, '%');
        sewerInPath = true;
    }
}
void CeoOfBlob::spread(int row, int col)
{   //blob spreading recursion
    if (canSpread(row, col))
    {
        mark(row, col);
        spread(row, col);
    }
    if (canSpread(row - 1, col) == true)
    {   //if can move up
        mark(row - 1, col);
        spread(row - 1, col);
    }
    if (canSpread(row, col + 1) == true)
    {   //if can move right
        mark(row, col + 1);
        spread(row, col + 1);
    }
    if (canSpread(row + 1, col) == true)
    {   //if can move down
        mark(row + 1, col);
        spread(row + 1, col);
    }
    if (canSpread(row, col - 1) == true)
    {   //if can move left
        mark(row, col - 1);
        spread(row, col - 1);
    }
}
bool CeoOfBlob::canSpread(int row, int col)
{
    if (inBounds(row, col) == true)
    {   //if position is within boundaries of map
        char tempChar = blobMap->charAt(row, col);
        if(tempChar == 'P' || tempChar == 'S' || tempChar == '@')
        {   //if blob encounters spreadable space
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool CeoOfBlob::inBounds(int row, int col)
{
    if (blobMap->getRows() <= 0 || blobMap-> getCols() <= 0)
    {   //if rows and/or columns are less than 1
        throw(std::runtime_error("Error: Invalid map dimensions."));
    }
    else if(row >= 0 && row < blobMap->getRows() && col >= 0 && col < blobMap->getCols())
    {   //if position is within map boundaries
        return true;
    }
    else
    {   //if position is out of bounds
        return false;
    }
}
CeoOfBlob::~CeoOfBlob()
{

}