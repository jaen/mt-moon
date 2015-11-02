#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

enum PlotReadState
{
    SCENE_NUMBER,
    SCENE_TEXT,
    CHOICE_TEXT,
    CHOICE_NEXT_SCENE
};

struct Choice
{
    string text;
    int next_scene;
};

struct Scene
{
    int number;
    string text;
    vector<Choice> choices;
};

struct Game
{
    vector<Scene> scenes;
};

Game read_game(string filename) {
    Game game;

    ifstream plot_file;

    plot_file.open(filename, ifstream::in);

    Scene current_scene;
    Choice current_choice;
    PlotReadState plot_read_state = SCENE_NUMBER;

    while (plot_file.good()) {
        string line;

        getline(plot_file, line);

        switch(plot_read_state) {
            case SCENE_NUMBER:
                if (line[0] == '!') {
                    istringstream iss(line.substr(1));

                    iss >> current_scene.number;

                    plot_read_state = SCENE_TEXT;
                }
                break;
            case SCENE_TEXT:
                if (line != "===") {
                    current_scene.text += line += "\n";
                } else {
                    plot_read_state = CHOICE_TEXT;
                }
                break;
            case CHOICE_TEXT:
                if (line[0] == '-') {
                    current_choice.text = line.substr(2);

                    plot_read_state = CHOICE_NEXT_SCENE;
                } else if (line == "===") {
                    plot_read_state = SCENE_NUMBER;

                    game.scenes.push_back(current_scene);
                    current_scene = Scene();
                }
                break;
            case CHOICE_NEXT_SCENE:
                if (line.substr(0,2) == "=>") {
                    istringstream iss(line.substr(3));

                    iss >> current_choice.next_scene;

                    current_scene.choices.push_back(current_choice);
                    current_choice = Choice();

                    plot_read_state = CHOICE_TEXT;
                }
                break;
        }
    }

    plot_file.close();

    return game;
}

void print_game(Game game)
{
    for (Scene scene : game.scenes) {
        cout << endl << "~~~" << endl
             << "Scene " << scene.number << endl << endl
             << scene.text << endl << "===" << endl
             << endl;

        for (Choice choice : scene.choices) {
            cout << "- " << choice.text << endl
                 << "=> " << choice.next_scene << endl;
        }
    }
}

int main()
{
    Game game = read_game("plot.txt");

    cout << "Hello Kanto!" << endl;

    print_game(game);

    return 0;
}
