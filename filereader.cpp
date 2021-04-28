// Copyright 2021 Tyler Julian Herman
// Monday, April 19, 2021 at 1:44 PM
#include "headers/filereader.h"

// location of testing text file
const std::string filepath = "text_files/davidcopperfield.txt";

std::vector<std::string> stringsFromFile();
std::vector<std::vector<std::string>> brokenup();

std::vector<std::vector<std::string>> brokenup() {
  std::vector<std::vector<std::string>> allstrings;
  std::vector<std::string> sv;
  sv = stringsFromFile();
  std::vector<std::string> ov;
  std::vector<int> indices;

  // this method breaks up a vector of strings by spaces
  // result is word by word output
  for (auto inputStr : sv) {
    for (int i = 0; i < inputStr.size(); i++) {
      if (inputStr.at(i) == ' ') {
        indices.push_back(i);
      }
    }
    for (int i = 0; i <= indices.size(); i++) {
      if (i == 0) {
        ov.push_back(inputStr.substr(0, indices.at(i) + 1));
      } else if (i == indices.size()) {
        ov.push_back(inputStr.substr(indices.at(i - 1) + 1));
      } else {
        ov.push_back(inputStr.substr(indices.at(i - 1) + 1, indices.at(i) - indices.at(i - 1)));
      }
    }
    allstrings.push_back(ov);
    ov.clear();
    indices.clear();
  }
  return allstrings;
}

std::vector<std::string> stringsFromFile() {
  // this method converts an input file into a string vector
  std::string fileline;
  std::vector<std::string> stringvec;
  std::ifstream wordsfile(filepath);
  if (wordsfile.is_open()) {
    while (getline(wordsfile, fileline)) {
      stringvec.push_back(fileline);
    }
    wordsfile.close();
  }
  return stringvec;
}
