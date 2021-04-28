// Copyright 2021 Tyler Julian Herman
// Monday, April 26, 2021 at 9:34 AM
#include "headers/askforname.h"

std::string askforname() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Type your name:");
  window.setFramerateLimit(120);

  // zilla slab font import, relative path
  sf::Font zillaslab;
  zillaslab.loadFromFile("Zilla_Slab/ZillaSlab-Regular.ttf");

  sf::Text mytext;
  mytext.setFont(zillaslab);
  std::string literalstr = R"foo(Please enter your name: )foo";
  mytext.setString(literalstr);
  mytext.setCharacterSize(40);
  mytext.setPosition(190.f, 50.f);

  sf::RectangleShape outlinebox;
  outlinebox.setSize({320, 50});
  outlinebox.setPosition(240.f, 150.f);
  outlinebox.setOutlineThickness(2);
  outlinebox.setFillColor(sf::Color::Transparent);
  outlinebox.setOutlineColor(sf::Color::White);

  std::string wordfragment;
  char currentchar;
  std::vector<bool> previousKeyboardState = currentKeyboardState();

  sf::Text typedText;
  typedText.setFont(zillaslab);
  typedText.setCharacterSize(36);
  typedText.setPosition(260.f, 150.f);
  typedText.setFillColor(sf::Color::Green);

  Button ok(buttonVector.at(11).at(0));
  ok.setPosition({325, 400});

  // ensures that no characters are registered
  // unless there was a moment where the keyboard was not being pressed
  // prevents redundant character entry
  std::string currentname;
  std::vector<bool> zerobool = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0
                               };

  while(window.isOpen()) {

    // if the keyboard state changes, find which letter was pressed
    // this code prevents a letter hold error, as the keyboard isKeyPressed function
    // does not account of held keys
    if (previousKeyboardState != currentKeyboardState()) {
      if (previousKeyboardState == zerobool) {
        currentchar = whichletter();
      }
      previousKeyboardState = currentKeyboardState();
    }

    // backspace functionality
    if (wordfragment.size() > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
      wordfragment = wordfragment.substr(0, wordfragment.size() - 1);
    }

    // only lowercase letters are accepted
    if (wordfragment.size() < 15) {
      if ((currentchar - '0' >= 49) && (currentchar - '0' <= 74)) {
        wordfragment.push_back(currentchar);
      }
      currentchar = (char) 0;
    }
    typedText.setString(wordfragment);

    sf::Event event;
    while(window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::MouseMoved:
        if(ok.isMouseOver(window)) {
          ok.setNewImg(buttonVector.at(11).at(1));
        } else {
          ok.setNewImg(buttonVector.at(11).at(0));
        }
        break;

      case sf::Event::MouseButtonPressed:
        if(ok.isMouseOver(window)) {
          // std::cout << "Okay\n";
          currentname = wordfragment;
          window.close();
        }
        break;
      }
    }
    window.clear();
    ok.drawTo(window);
    window.draw(mytext);
    window.draw(typedText);
    window.draw(outlinebox);
    window.display();
  }
  window.close();
  return currentname;
}
