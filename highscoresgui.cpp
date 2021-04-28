// Copyright 2021 Tyler Julian Herman
// Monday, April 26, 2021 at 9:42 AM
#include "headers/highscoresgui.h"

bool highscoresgui(std::string playername, std::string filepath) {
  bool ob = 0;
  Button test(buttonVector.at(9).at(0));
  test.setPosition({325, 510});

  std::vector<std::string> stringvec;
  stringvec = filetostrings(filepath);

  std::map<std::string, std::vector<double>> sm;
  sm = vecToMap(stringvec);

  std::vector<double> topthreescores;
  topthreescores = maxscores(sm);

  std::vector<std::string> topthreenames;
  topthreenames = maxnames(sm, topthreescores);

  sf::RenderWindow highscores(sf::VideoMode(800, 600), "High Scores", sf::Style::Default);
  highscores.setFramerateLimit(120);
  sf::Font zillaslab;
  zillaslab.loadFromFile("Zilla_Slab/ZillaSlab-Regular.ttf");


  //Welcome
  sf::Text Welcometext;
  Welcometext.setFont(zillaslab);
  Welcometext.setString("Welcome");
  Welcometext.setCharacterSize(80);
  Welcometext.setFillColor(sf::Color::White);
  Welcometext.setStyle(sf::Text::Style::Italic);
  Welcometext.setPosition({80, 50});

  //High Scores
  sf::Text HighScoretext;
  HighScoretext.setFont(zillaslab);
  HighScoretext.setString("High Scores");
  HighScoretext.setCharacterSize(45);
  HighScoretext.setFillColor(sf::Color::White);
  HighScoretext.setPosition({280, 160});

  //Name of User
  std::string UserName = playername;
  sf::Text Nametext;
  Nametext.setFont(zillaslab);
  Nametext.setString(UserName);
  Nametext.setCharacterSize(80);
  Nametext.setFillColor(sf::Color::White);
  Nametext.setPosition({440, 50});

  //Rectangles
  sf::RectangleShape rectangle1(sf::Vector2f(400, 500));
  rectangle1.setSize(sf::Vector2f(180, 250));
  rectangle1.setPosition({65, 230});

  sf::RectangleShape rectangle2(sf::Vector2f(400, 500));
  rectangle2.setSize(sf::Vector2f(180, 250));
  rectangle2.setPosition({310, 230});

  sf::RectangleShape rectangle3(sf::Vector2f(400, 500));
  rectangle3.setSize(sf::Vector2f(180, 250));
  rectangle3.setPosition({555, 230});

  //Names of High Scores
  std::string Player1 = topthreenames.at(0);
  std::string Player2 = topthreenames.at(1);
  std::string Player3 = topthreenames.at(2);

  sf::Text HighScoreName1;
  sf::Text HighScoreName2;
  sf::Text HighScoreName3;

  HighScoreName1.setFont(zillaslab);
  HighScoreName2.setFont(zillaslab);
  HighScoreName3.setFont(zillaslab);

  HighScoreName1.setString(Player1);
  HighScoreName2.setString(Player2);
  HighScoreName3.setString(Player3);

  HighScoreName1.setCharacterSize(30);
  HighScoreName2.setCharacterSize(30);
  HighScoreName3.setCharacterSize(30);

  HighScoreName1.setFillColor(sf::Color::Black);
  HighScoreName2.setFillColor(sf::Color::Black);
  HighScoreName3.setFillColor(sf::Color::Black);

  HighScoreName1.setPosition({120, 250});
  HighScoreName2.setPosition({365, 250});
  HighScoreName3.setPosition({610, 250});

  //Numerical HighScores
  double speed1 = topthreescores.at(0);
  double speed2 = topthreescores.at(1);
  double speed3 = topthreescores.at(2);

  int Numspeed1 = (int)round(speed1);
  int Numspeed2 = (int)round(speed2);
  int Numspeed3 = (int)round(speed3);

  sf::Text Results1;
  sf::Text Results2;
  sf::Text Results3;

  Results1.setStyle(sf::Text::Bold);
  Results2.setStyle(sf::Text::Bold);
  Results3.setStyle(sf::Text::Bold);

  Results1.setFont(zillaslab);
  Results2.setFont(zillaslab);
  Results3.setFont(zillaslab);

  Results1.setString(std::to_string(Numspeed1));
  Results2.setString(std::to_string(Numspeed2));
  Results3.setString(std::to_string(Numspeed3));

  Results1.setCharacterSize(50);
  Results2.setCharacterSize(50);
  Results3.setCharacterSize(50);

  Results1.setFillColor(sf::Color::Black);
  Results2.setFillColor(sf::Color::Black);
  Results3.setFillColor(sf::Color::Black);

  Results1.setPosition({130, 320});
  Results2.setPosition({375, 320});
  Results3.setPosition({620, 320});

  //WPM
  std::string wordsperminute = "WPM";

  sf::Text WPM1;
  sf::Text WPM2;
  sf::Text WPM3;

  WPM1.setFont(zillaslab);
  WPM2.setFont(zillaslab);
  WPM3.setFont(zillaslab);

  WPM1.setString(wordsperminute);
  WPM2.setString(wordsperminute);
  WPM3.setString(wordsperminute);

  WPM1.setCharacterSize(30);
  WPM2.setCharacterSize(30);
  WPM3.setCharacterSize(30);

  WPM1.setFillColor(sf::Color::Black);
  WPM2.setFillColor(sf::Color::Black);
  WPM3.setFillColor(sf::Color::Black);

  WPM1.setPosition({120, 380});
  WPM2.setPosition({365, 380});
  WPM3.setPosition({610, 380});

  while(highscores.isOpen()) {

    sf::Event evnt;

    while(highscores.pollEvent(evnt)) {
      switch (evnt.type) {

      case sf::Event::Closed:
        highscores.close();
        ob = 1;
        break;

      case sf::Event::MouseMoved:
        if(test.isMouseOver(highscores)) {
          test.setNewImg(buttonVector.at(9).at(1));
        } else {
          test.setNewImg(buttonVector.at(9).at(0));
        }
        break;

      case sf::Event::MouseButtonPressed:
        if(test.isMouseOver(highscores)) {
          highscores.close();
        }
        break;

      };

    }

    highscores.clear();
    highscores.draw(HighScoretext);
    highscores.draw(Welcometext);
    highscores.draw(Nametext);
    highscores.draw(rectangle1);
    highscores.draw(rectangle2);
    highscores.draw(rectangle3);
    highscores.draw(HighScoreName1);
    highscores.draw(HighScoreName2);
    highscores.draw(HighScoreName3);
    highscores.draw(Results1);
    highscores.draw(Results2);
    highscores.draw(Results3);
    highscores.draw(WPM1);
    highscores.draw(WPM2);
    highscores.draw(WPM3);
    test.drawTo(highscores);
    highscores.display();
  }
  return ob;
}

void saveresults(std::string player, double speed, std::string filepath) {
  std::vector<std::string> stringvec;
  stringvec = filetostrings(filepath);
  std::map<std::string, std::vector<double>> sm;
  sm = vecToMap(stringvec);
  sm[player].push_back(speed);
  if (player != "") {
    saveresultstofile(sm, filepath);
  }
}
