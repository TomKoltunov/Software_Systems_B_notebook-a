#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace ariel {

    class Notebook {

        unordered_map<int, vector<vector<char>>> notebook;

        public:

            Notebook();
            
            void write(int page, int row, int column, Direction direction, const string &toWrite);
            string read(int page, int row, int column, Direction direction, int toRead);
            void erase(int page, int row, int column, Direction direction, int toErase);
            void show(int page);
    };
}