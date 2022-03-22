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

    CHECK_NOTHROW(notebook.write(0, 0, 0, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 0, Direction::Vertical, toRead) == "a");
    notebook.erase(0, 0, 0, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 0, Direction::Vertical, toRead) == "~");

    toWrite = "A";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 1, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 1, Direction::Vertical, toRead) == "A");
    notebook.erase(0, 0, 1, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 1, Direction::Vertical, toRead) == "~");

    toWrite = "aaaaa";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 2, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 2, Direction::Vertical, toRead) == "aaaaa");
    notebook.erase(0, 0, 2, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 2, Direction::Vertical, toRead) == "~~~~~");

    toWrite = "AAAAA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 7, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 7, Direction::Vertical, toRead) == "AAAAA");
    notebook.erase(0, 0, 7, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 7, Direction::Vertical, toRead) == "~~~~~");

    toWrite = "AaAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 12, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 12, Direction::Vertical, toRead) == "AaAaA");
    notebook.erase(0, 0, 12, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 12, Direction::Vertical, toRead) == "~~~~~");

    toWrite = "aAaA";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 17, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 17, Direction::Vertical, toRead) == "aAaA");
    notebook.erase(0, 0, 17, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 17, Direction::Vertical, toRead) == "~~~~");

    toWrite = "zZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 95, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 95, Direction::Vertical, toRead) == "zZzZz");
    notebook.erase(0, 0, 95, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 95, Direction::Vertical, toRead) == "~~~~~");

    toWrite = "ZzZz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 91, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 91, Direction::Vertical, toRead) == "ZzZz");
    notebook.erase(0, 0, 91, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 91, Direction::Vertical, toRead) == "~~~~");

    toWrite = "ZZZZZ";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 86, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 86, Direction::Vertical, toRead) == "ZZZZZ");
    notebook.erase(0, 0, 86, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 86, Direction::Vertical, toRead) == "~~~~~");

    toWrite = "zzzzz";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 81, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 81, Direction::Vertical, toRead) == "zzzzz");
    notebook.erase(0, 0, 81, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 81, Direction::Vertical, toRead) == "~~~~~");

    toWrite = "Z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 80, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 80, Direction::Vertical, toRead) == "Z");
    notebook.erase(0, 0, 80, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 80, Direction::Vertical, toRead) == "~");

    toWrite = "z";
    toRead = toWrite.length();
    CHECK_NOTHROW(notebook.write(0, 0, 79, Direction::Vertical, toWrite));
    CHECK(notebook.read(0, 0, 79, Direction::Vertical, toRead) == "z");
    notebook.erase(0, 0, 79, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(0, 0, 79, Direction::Vertical, toRead) == "~");
}