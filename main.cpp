/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 BLOBLAB
 * Description:  This program will create a blob simulator.
 * Date: 11/1/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
#include <fstream>
#include "CeoOfBlob.h"

int main(int argc, char** argv)
{   //takes input from command line
    std::ifstream inFile;
    if (argc > 1)
    {   //if there is more than 1 argument
        std::string input = "";
        input = argv[1];
        std::string fileName = "";
        fileName = argv[1]; //second argument is the file name
        inFile.open(fileName);  //attempts to open file
        if (!inFile.is_open())
        {   //error if file could not be opened
            std::cout << "Error: File could not be opened.\n";
        }
        else
        {
            CeoOfBlob ceo(fileName);
            ceo.run();  //runs CeoOfBlob
            inFile.close();
        }
    }
}