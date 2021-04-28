// Copyright 2021 Tyler Julian Herman
// Tuesday, April 20, 2021 at 12:48 PM
#include "headers/highscores.h"

// this file contains methods for finding high scores
// once found, scores are displayed in the HighScoresgui window

std::vector<double> maxscores(std::map<std::string, std::vector<double>> sm);
std::vector<std::string> maxnames(std::map<std::string, std::vector<double>> sm, std::vector<double> tt);
std::vector<std::string> filetostrings(std::string filepath);
std::map<std::string, std::vector<double>> vecToMap(std::vector<std::string> os);
void saveresultstofile(std::map<std::string, std::vector<double>> sm, std::string filepath);

std::vector<double> maxscores(std::map<std::string, std::vector<double>> sm) {
  std::vector<double> ov, topthree;

  // iterate through the input map
  std::map<std::string, std::vector<double>>::iterator it;
  for (it = sm.begin(); it != sm.end(); ++it) {
    for (auto elem : it->second) {
      ov.push_back(elem);
    }
  }
  // sort the vector of doubles in descending order, highest scores first
  std::sort(ov.begin(), ov.end(), std::greater<double>());

  // return only the top three values
  for (int i = 0; i < 3; i++) {
    topthree.push_back(ov.at(i));
  }
  ov = topthree;
  return ov;
}

std::vector<std::string> maxnames(std::map<std::string, std::vector<double>> sm, std::vector<double> tt) {
  std::vector<std::string> os;
  std::map<std::string, std::vector<double>>::iterator it;

  // given a double of top three scores,
  // traverse the map and return the key string
  // when the double value is found
  for (int i = 0; i < tt.size(); i++) {
    for (it = sm.begin(); it != sm.end(); ++it) {
      for (auto elem : it->second) {
        if (elem == tt.at(i)) {
          os.push_back(it->first);
        }
      }
    }
  }
  return os;
}

std::vector<std::string> filetostrings(std::string filepath) {
  std::string fileline;
  std::vector<std::string> stringvec;
  std::ifstream wordsfile(filepath);

  // convert the input text file into a vector of strings
  if (wordsfile.is_open()) {
    while (getline(wordsfile, fileline)) {
      stringvec.push_back(fileline);
    }
    wordsfile.close();
  }
  return stringvec;
}

std::map<std::string, std::vector<double>> vecToMap(std::vector<std::string> os) {
  std::vector<std::string> namesVector;
  std::vector<int> nameIndices;
  std::vector<int> numberstart, numberend;
  int index = 0;
  for (auto elem : os) {
    // [a-'0', z-'0'] = [49, 74]
    // finds only lines that start with a-z chars e.g. names
    if (((elem.at(0) - '0' >= 49) && (elem.at(0) - '0' <= 74))) {
      nameIndices.push_back(index);
    }
    // [A-'0', Z-'0'] = [17, 42]
    // finds the index of every line starting with A-Z chars e.g. name lines
    else if (((elem.at(0) - '0' >= 17) && (elem.at(0) - '0' <= 42))) {
      nameIndices.push_back(index);
    }
    index++;
  }

  // extract the player names given a set of indices
  for (auto elem : nameIndices) {
    namesVector.push_back(os.at(elem));
  }

  bool firstnumber = 1;
  index = 0;
  for (auto elem : os) {
    // if the line starts with digits 0-9, save the index
    // only the first number associated with the name is saved
    if (firstnumber && ((elem.at(0) - '0' >= 0) && (elem.at(0) - '0' <= 9))) {
      numberstart.push_back(index);
      firstnumber = 0;
    }
    // '-' - 0 = -3, so elem - '0' < 0 is used as the comparison
    // stops when a dash is reached (-)
    else if (elem.at(0) - '0' < 0) {
      numberend.push_back(index);
      firstnumber = 1;
    }
    index++;
  }

  // given a vector of indices, push back all values to a vector of doubles
  std::vector<std::vector<double>> allspeeds;
  std::vector<double> tempdouble;
  for (int i = 0; i < namesVector.size(); i++) {
    for (int j = numberstart.at(i); j < numberend.at(i); j++) {
      tempdouble.push_back(std::stod(os.at(j)));
    }
    allspeeds.push_back(tempdouble);
    tempdouble.clear();
  }

  // convert the data found so far (names, speeds) into a map
  std::map<std::string, std::vector<double>> sm;
  index = 0;
  for (auto elem : namesVector) {
    sm[elem] = allspeeds.at(index);
    index++;
  }
  return sm;
}

void saveresultstofile(std::map<std::string, std::vector<double>> sm, std::string filepath) {
  std::ofstream outputfile;
  outputfile.open(filepath);
  std::map<std::string, std::vector<double>>::iterator it;

  // this function converts an input of a map into database-readable format
  for (it = sm.begin(); it != sm.end(); ++it) {
    outputfile << it->first << '\n';
    for (auto elem : it->second) {
      outputfile << elem << '\n';
    }
    outputfile << "-\n";
  }
  outputfile.close();
}
