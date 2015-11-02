#pragma once
// odpowiada
// #ifndef GAME_H_INCLUDED
// #define GAME_H_INCLUDED

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <sstream>

    #include "common.h"

    Game read_game(std::string filename);
    void print_game(Game game);

// #endif
