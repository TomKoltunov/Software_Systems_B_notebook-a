#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

const int ROWLENGTH = 100;

namespace ariel {

    Notebook::Notebook()
    {
        this -> notebook[0].assign(ROWLENGTH, vector<char>(ROWLENGTH, '_'));
    }

    void write(int page, int row, int column, Direction direction, const string &toWrite) 
    {

    }

    string read(int page, int row, int column, Direction direction, int toRead) 
    {
        return " ";
    }

    void erase(int page, int row, int column, Direction direction, int toErase) 
    {

    }

    void show(int page) 
    {

    }
}