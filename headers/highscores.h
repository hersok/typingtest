#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "../highscores.cpp"

std::vector<double> maxscores(std::map<std::string, std::vector<double>> sm);
std::vector<std::string> maxnames(std::map<std::string, std::vector<double>> sm, std::vector<double> tt);
std::vector<std::string> filetostrings(std::string filepath);
std::map<std::string, std::vector<double>> vecToMap(std::vector<std::string> os);
void saveresultstofile(std::map<std::string, std::vector<double>> sm, std::string filepath);

#endif
