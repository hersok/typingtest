#ifndef TYPINGTEST_H
#define TYPINGTEST_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <chrono>
#include "../typingtest.cpp"

std::string vecStrPrint(std::vector<std::string> toPrint);
std::vector<std::string> typedwords(std::vector<std::string> iw);
double besttime();
char whichletter();
std::vector<bool> currentKeyboardState();
std::string getrelevantstrings(std::vector<std::string> sv, int posindex, int numwords);
double typingTest();

#endif
