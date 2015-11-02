#pragma once

#include <string>
#include <vector>

struct Choice
{
    std::string text;
    int next_scene;
};

struct Scene
{
    int number;
    std::string text;
    std::vector<Choice> choices;
};

struct Game
{
    std::vector<Scene> scenes;
};
