#ifndef HIGHSCORESGUI_H
#define HIGHSCORESGUI_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "../highscoresgui.cpp"

bool highscoresgui(std::string playername, std::string filepath);
void saveresults(std::string player, double speed, std::string filepath);

#endif
