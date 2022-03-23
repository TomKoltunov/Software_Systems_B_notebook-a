#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

const int ROWLENGTH = 100; // The provisions of the assignment state that each row's length is 100 characters

namespace ariel {

    /*
    The constructor "Notebook" receives no parameters and it initializes the unordered map named 'notebook' which was declared in
    the header file "Notebook.hpp". The way this constructor initializes the map is by placing '_' in each spot in the notebook.
    */
    Notebook::Notebook()
    {
        this -> notebook[0].assign(ROWLENGTH, vector<char>(ROWLENGTH, '_'));
    }

    /*
    The function "write" receives an integers called "page", "row" and "column" which represent the page number, row number
    and exact spot (respectively) where to start the writing. It also receives the direction of the writing that can only be 
    "Horizontal" or "Vertical", the direction type is 'Direction' and its declaration is in the header file "Direction.hpp".
    And the function receives a string called "toWrite" which represents the text we want to write in the notebook. 
    */
    void Notebook::write(int page, int row, int column, Direction direction, const string &toWrite) 
    {

    }

    /*
    The function "read" receives an integers called "page", "row" and "column" which represent the page number, row number
    and exact spot (respectively) where to start the reading, and an integer called "toRead" which is the number of characters
    we want to read. It also receives the direction of the reading that can only be "Horizontal" or "Vertical", the direction type 
    is 'Direction' and its declaration is in the header file "Direction.hpp". 
    Eventually "read" will return the text it read if succeeded.
    */
    string Notebook::read(int page, int row, int column, Direction direction, int toRead) 
    {
        return " ";
    }

    /*
    The function "read" receives an integers called "page", "row" and "column" which represent the page number, row number
    and exact spot (respectively) where to start the erasing, and an integer called "toErase" which is the number of characters
    we want to erase. It also receives the direction of the reading that can only be "Horizontal" or "Vertical", the direction type 
    is 'Direction' and its declaration is in the header file "Direction.hpp". 
    Erasing of a character id carried out by replacing it by the char '~'.
    */
    void Notebook::erase(int page, int row, int column, Direction direction, int toErase) 
    {

    }

    /*
    The function "show" receives an integer named "page" which represents the notebook's page it has to show on the screen.
    */
    void Notebook::show(int page) 
    {

    }
}
