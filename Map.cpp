/* -----------------------------------------------------------------------------
 *
 * File Name:  Map.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 BLOBLAB
 * Description:  This program will create a blob simulator.
 * Date: 11/1/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include "Map.h"
#include <string>
#include <iostream>
#include <fstream>
char** arr = nullptr;
std::ifstream inFile;

Map::Map(std::string fileName)
{
    inFile.open(fileName);
    populate();
    inFile.close();
}
void Map::populate()
{   //fills 2D array with the values in file
    inFile >> rows; //initializes variables
    inFile >> cols;
    inFile >> startX;
    inFile >> startY;
    arr = new char*[rows];
    for (int x = 0; x < rows; x++)
    {
        arr[x] = new char[cols];
    }
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            inFile >> arr[x][y];
        }
    }
}
void Map::printMap()
{   //prints stored 2D array
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            std::cout << arr[x][y];
        }
        std::cout << "\n";
    }
}
void Map::changeChar(int row, int col, char c)
{   //changes character at specified location
    arr[row][col] = c;
}
char Map::charAt(int row, int col)
{   //returns character at specified location
    return arr[row][col];
}
int Map::getStartX()
{
    return startX;
}
int Map::getStartY()
{
    return startY;
}
int Map::getRows()
{
    return rows;
}
int Map::getCols()
{
    return cols;
}
Map::~Map()
{

}