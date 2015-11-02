#include <string>

#include "game.h"

using namespace std;

int main()
{
    Game game = read_game("plot.txt");

    cout << "Hello Kanto!" << endl;

    print_game(game);

    return 0;
}
