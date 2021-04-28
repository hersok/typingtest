// Copyright 2021 Tyler Julian Herman
// Monday, April 26, 2021 at 9:26 AM
#include "headers/welcomewindow.h"

bool welcomewindow() {
  // this method returns true if the blue button is pressed
  // this method returns false if the "x" button is pressed
  bool ob = 0;

  sf::RenderWindow welcome(sf::VideoMode(800, 600), "Welcome", sf::Style::Default);
  welcome.setFramerateLimit(120);
  sf::Font zillaslab;
  zillaslab.loadFromFile("Zilla_Slab/ZillaSlab-Regular.ttf");
  welcome.clear(sf::Color::Blue);

  //Welcome!
  sf::Text text1;
  text1.setFont(zillaslab);
  text1.setString("Welcome");
  text1.setCharacterSize(150);
  sf::Color purple(217, 96, 248);
  sf::Color skyblue(22, 141, 239);
  text1.setFillColor(sf::Color::White);
  text1.setStyle(sf::Text::Style::Italic);
  text1.setOutlineColor(skyblue);
  text1.setOutlineThickness(10);
  text1.setPosition({90, 100});

  //Typing Test
  sf::Text text2;
  text2.setFont(zillaslab);
  text2.setString("TypingTest Simulator");
  text2.setCharacterSize(50);
  text2.setFillColor(skyblue);
  text2.setOutlineColor(sf::Color::White);
  text2.setOutlineThickness(4);
  text2.setPosition({150, 300});

  //Click to Start
  Button start(buttonVector.at(10).at(0));
  start.setPosition({300, 400});

  while(welcome.isOpen()) {

    sf::Event evnt;

    while(welcome.pollEvent(evnt)) {
      switch (evnt.type) {

      case sf::Event::Closed:
        welcome.close();
        break;

      case sf::Event::MouseMoved:
        if(start.isMouseOver(welcome)) {
          start.setNewImg(buttonVector.at(10).at(1));
        } else {
          start.setNewImg(buttonVector.at(10).at(0));
        }
        break;

      case sf::Event::MouseButtonPressed:
        if(start.isMouseOver(welcome)) {
          ob = 1;
          welcome.close();
        }
        break;

      };

    }
    welcome.clear();
    welcome.draw(text1);
    welcome.draw(text2);
    start.drawTo(welcome);
    welcome.display();
  };
  return ob;
}
