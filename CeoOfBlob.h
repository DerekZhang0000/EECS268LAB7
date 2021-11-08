/* -----------------------------------------------------------------------------
 *
 * File Name:  CeoOfBlob.h
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 BLOBLAB
 * Description:  This program will create a blob simulator.
 * Date: 11/1/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#ifndef CEOOFBLOB_H
#define CEOOFBLOB_H
#include <string>
#include "Map.h"

class CeoOfBlob
{
    public:
    /**
    * @post Class is constructed. 
    * @param file name
    */
    CeoOfBlob(std::string filename);
    /**
    * @post Class is destroyed. 
    *       
    */
    ~CeoOfBlob();
    /** 
    * @pre None
    * @post Runs program
    * @param None
    * @throw None
    **/
    void run();
    /** 
    * @pre valid starting position
    * @post Returns blobbified map
    * @param map
    * @throw None
    **/
    Map* blob(Map* map);
    /** 
    * @pre None
    * @post Returns whether or not blob can spread to surroundings (not including sewers)
    * @param Current posiiton
    * @throw None
    **/
    bool canSpread(int row, int col);
    /**
    * @pre None
    * @post Teleports blob to sewer exit(s) if they exist
    * @param None
    * @throw None
    **/
    void searchSewers();
    /**
    * @pre canSpread is true
    * @post Returns whether blob has moved and changes current position
    * @param Current position
    * @throw None
    **/
    void spread(int row, int col);
   /** 
    * @pre None
    * @post Marks specified location on map
    * @param row, column
    * @throw None
    **/
   void mark(int row, int col);
   /** 
    * @pre None
    * @post returns whether coordinates are within map boundaries
    * @param row, col
    * @throw None
    **/
   bool inBounds(int row, int col);
   private:
   int currentX;
   int currentY;
   int startX;
   int startY;
   Map* origMap;
   Map* blobMap;
};

#endif