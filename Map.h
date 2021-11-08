/* -----------------------------------------------------------------------------
 *
 * File Name:  Map.h
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 BLOBLAB
 * Description:  This program will create a blob simulator.
 * Date: 11/1/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#ifndef MAP_H
#define MAP_H
#include <string>

class Map
{
    public:
    /**
    * @post Class is constructed. 
    * @param file name 
    */
    Map(std::string filename);
    /**
    * @post Class is destroyed. 
    *       
    */
    ~Map();
    /** 
    * @pre row and column are within boundaries
    * @post Changes a character on the map
    * @param Map
    * @throw None
    **/
    void changeChar(int row, int col, char c);
    /** 
    * @pre None
    * @post populates map
    * @param None
    * @throw None
    **/
    void populate();
    /** 
    * @pre None
    * @post Prints map
    * @param None
    * @throw None
    **/
    void printMap();
    /** 
    * @pre None
    * @post Returns character at location
    * @param row, col
    * @throw None
    **/
    char charAt(int row, int col);
    /** 
    * @pre None
    * @post Returns starting x position
    * @param None
    * @throw None
    **/
    int getStartX();
    /** 
    * @pre None
    * @post Returns starting y position
    * @param None
    * @throw None
    **/
    int getStartY();
    /** 
    * @pre None
    * @post Returns rows
    * @param None
    * @throw None
    **/
    int getRows();
    /** 
    * @pre None
    * @post Returns columns
    * @param None
    * @throw None
    **/
    int getCols();
    private:
    char** arr;
    int rows;
    int cols;
    int startX;
    int startY;
};

#endif