#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;
using namespace std;
#include <string>

TEST_CASE("Test case number 1"){
    Board board;
    string name = "My name is Alon";
    board.post(0, 0, Direction::Horizontal, name);
    CHECK(board.read(0, 0, Direction::Horizontal, name.length()) == name);
    string water = "water";
    string something = "something";
    string fox = "fox";
    board.post(0, 0, Direction::Vertical, water);
    CHECK(board.read(0, 0, Direction::Vertical, water.length()) == water);
    CHECK(board.read(0, 0, Direction::Horizontal, name.length()) == "wy name is Alon");
    board.post(0, 9, Direction::Vertical, fox);
    CHECK(board.read(0, 9, Direction::Vertical, fox.length()) == fox);
    CHECK(board.read(0, 0, Direction::Horizontal, name.length()) == "wy name if Alon");
    board.post(1, 1, Direction::Horizontal, something);
    CHECK(board.read(1, 0, Direction::Horizontal, something.length() + 1) == "a" + something);
    CHECK(board.read(0, 9, Direction::Vertical, fox.length()) == "fgx");
}

TEST_CASE("Test case number 2"){
    Board board;
    string away = "away";
    string over = "over";
    string going = "going";
    string popular = "popular";
    string strong = "strong";

    board.post(0, 0, Direction::Vertical, away);
    board.post(0, 1, Direction::Vertical, over);
    board.post(0, 2, Direction::Vertical, going);
    board.post(0, 3, Direction::Vertical, popular);
    board.post(0, 4, Direction::Vertical, strong);

    CHECK(board.read(0, 0, Direction::Vertical, away.length()) == away);
    CHECK(board.read(0, 1, Direction::Vertical, over.length()) == over);
    CHECK(board.read(0, 2, Direction::Vertical, going.length()) == going);
    CHECK(board.read(0, 3, Direction::Vertical, popular.length()) == popular);
    CHECK(board.read(0, 4, Direction::Vertical, strong.length()) == strong);

    string giveaway = "giveaway";
    board.post(2, 0, Direction::Horizontal, giveaway);

    CHECK(board.read(2, 0, Direction::Horizontal, giveaway.length()) == giveaway);
    CHECK(board.read(1, 0, Direction::Horizontal, 5) == "wvoot");
    CHECK(board.read(3, 0, Direction::Horizontal, 8) == "yrnuo___");
    CHECK(board.read(0, 4, Direction::Vertical, strong.length() + 1) == "staong_");
}

TEST_CASE("Test case number 3"){
    Board board;
    string why_not = "why not";
    string simple = "simple";
    string amazing = "This is amazing";
    string first_time = "first time";
    string compare = "compare";

    board.post(98, 8, Direction::Horizontal, why_not);
    board.post(98, 15, Direction::Vertical, simple);
    board.post(100, 8, Direction::Vertical, amazing);

    CHECK(board.read(98, 8, Direction::Horizontal, why_not.length() + 2) == "whf nots_");
    CHECK(board.read(100, 8, Direction::Horizontal, amazing.length()) == "Thrs ismamazing");
    CHECK(board.read(98, 15, Direction::Vertical, simple.length() + 3) == "simple___");
    CHECK(board.read(98, 10, Direction::Horizontal, first_time.length()) == first_time);

    board.post(102, 11, Direction::Horizontal, compare);
    CHECK(board.read(102, 8, Direction::Horizontal, compare.length() + 4) == "__tcompare_");
    CHECK(board.read(98, 8, Direction::Vertical, 4) == "w_T_");
    CHECK(board.read(100, 15, Direction::Vertical, 4) == "mpae");


}