// Copyright 2021 Tyler Julian Herman
// Monday, April 26, 2021 at 9:03 AM
// created version 0_8

// reads text input file
#include "headers/filereader.h"
// imports Button class
#include "headers/Button.h"
// for saving and recalling high scores
#include "headers/highscores.h"
// typing test window
#include "headers/typingtest.h"
// welcome window
#include "headers/welcomewindow.h"
// dialog window that asks for name
#include "headers/askforname.h"
// highscores GUI window
#include "headers/highscoresgui.h"


int main() {
  if (welcomewindow()) {
    std::string playername = askforname();
    while (!highscoresgui(playername, "scores/highscores.txt")) {
      double speed = typingTest();
      saveresults(playername, speed, "scores/highscores.txt");
    }
  }
  return 0;
}
