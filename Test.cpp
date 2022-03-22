#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
using namespace ariel;

const int ROWLENGTH = 100;

TEST_CASE("Good input")
{

    Notebook notebook;
    string toWrite = "a";
    int toRead = toWrite.length();
    int page = 0, row = 0, column = 0;

    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "a");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 1;
    toWrite = "A";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "A");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 79;
    toWrite = "z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    toRead = toWrite.length(); 
    row = 500, column = 0;

    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "a");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 1;
    toWrite = "A";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "A");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 79;
    toWrite = "z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    toRead = toWrite.length();
    row = 1000, column = 0;

    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "a");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 1;
    toWrite = "A";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "A");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 79;
    toWrite = "z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    ///////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    toRead = toWrite.length(); 
    row = 1500, column = 0;

    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "a");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 1;
    toWrite = "A";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "A");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 79;
    toWrite = "z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    toRead = toWrite.length();
    page = 2000, row = 0, column = 0;

    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "a");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 1;
    toWrite = "A";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "A");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 79;
    toWrite = "z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    toRead = toWrite.length(); 
    row = 500, column = 0;

    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "a");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 1;
    toWrite = "A";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "A");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 79;
    toWrite = "z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    toRead = toWrite.length();
    row = 1000, column = 0;

    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "a");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 1;
    toWrite = "A";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "A");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 79;
    toWrite = "z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    ///////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    toRead = toWrite.length(); 
    row = 1500, column = 0;

    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "a");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 1;
    toWrite = "A";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "A");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 79;
    toWrite = "z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    /////////////////////////////////////////////////////////////////////////////////

    
}

