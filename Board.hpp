#pragma once
#include "Direction.hpp"
#include <string>

namespace ariel
{
    class Board
    {
    public:

        Board();
        void post(unsigned int row, unsigned int column, Direction direction, const std::string &message);
        static std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    };
}