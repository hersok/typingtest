// Copyright 2021 Tyler Julian Herman
// Monday, April 26, 2021 at 9:13 AM
#include "headers/typingtest.h"

// vector of buttons that can be added from the sprites folder
std::vector<std::vector<std::string>> buttonVector = {
  {"sprites/menu_blue.png", "sprites/menu_pink.png"},
  {"sprites/train_blue.png", "sprites/train_pink.png"},
  {"sprites/ok_blue.png", "sprites/ok_pink.png"},
  {"sprites/user_blue.png", "sprites/user_pink.png"},
  {"sprites/add_blue.png", "sprites/add_pink.png"},
  {"sprites/podium_blue.png", "sprites/podium_pink.png"},
  {"sprites/test_blue.png", "sprites/test_pink.png"},
  {"sprites/redo_blue.png", "sprites/redo_pink.png"},
  {"sprites/ex_blue.png", "sprites/ex_pink.png"},
  {"sprites/test_text_blue.png", "sprites/test_text_pink.png"},
  {"sprites/start_blue.png", "sprites/start_pink.png"},
  {"sprites/ok_blue_big.png", "sprites/ok_pink_big.png"},
  {"sprites/menu_text_blue.png", "sprites/menu_text_pink.png"},
  {"sprites/exit_blue.png", "sprites/exit_pink.png"}
};

std::vector<bool> currentKeyboardState() {
  std::vector<bool> letterPress = {sf::Keyboard::isKeyPressed(sf::Keyboard::A),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::B),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::C),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::D),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::E),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::F),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::G),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::H),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::I),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::J),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::K),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::L),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::M),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::N),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::O),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::P),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Q),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::R),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::S),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::T),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::U),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::V),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::W),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::X),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Y),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Z),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::A) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::B) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::C) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::D) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::E) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::F) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::G) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::H) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::I) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::J) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::K) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::L) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::M) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::N) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::O) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::P) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::R) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::S) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::T) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::U) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::V) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::W) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::X) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Y) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Z) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Space),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Comma),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Period),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) and
                                   (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
                                    sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)),
                                   sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)
                                  };

  return letterPress;
};

const std::vector<char> letterVec = {'a',
                                     'b',
                                     'c',
                                     'd',
                                     'e',
                                     'f',
                                     'g',
                                     'h',
                                     'i',
                                     'j',
                                     'k',
                                     'l',
                                     'm',
                                     'n',
                                     'o',
                                     'p',
                                     'q',
                                     'r',
                                     's',
                                     't',
                                     'u',
                                     'v',
                                     'w',
                                     'x',
                                     'y',
                                     'z',
                                     'A',
                                     'B',
                                     'C',
                                     'D',
                                     'E',
                                     'F',
                                     'G',
                                     'H',
                                     'I',
                                     'J',
                                     'K',
                                     'L',
                                     'M',
                                     'N',
                                     'O',
                                     'P',
                                     'Q',
                                     'R',
                                     'S',
                                     'T',
                                     'U',
                                     'V',
                                     'W',
                                     'X',
                                     'Y',
                                     'Z',
                                     ' ',
                                     ',',
                                     '.',
                                     '(',
                                     ')',
                                     '\''
                                    };

// finds which key is being pressed
char whichletter() {
  char keypress;
  int index = 0;
  for (auto elem : currentKeyboardState()) {
    if (elem) {
      keypress = letterVec.at(index);
    }
    index++;
  }
  return keypress;
}

double besttime() {
  auto now = std::chrono::high_resolution_clock::now();
  auto dur = now.time_since_epoch();
  return dur.count() / 1'000'000'000.0;
}

const std::vector<std::vector<std::string>> allwords = brokenup();
const std::vector<std::string> words = allwords.at(0);

// outputs a vector of strings containing all of the words typed so far
std::vector<std::string> typedwords(std::vector<std::string> iw) {
  std::vector<std::string> ov;
  std::string tempv, current;
  char currentchar;
  int index = 0;
  for (auto elem : iw) {
    current = elem;
    while (tempv != current) {
      currentchar = whichletter();
      if (current.at(index) == currentchar) {
        index++;
        tempv.push_back(currentchar);
      }
    }
    ov.push_back(tempv);
    tempv.clear();
  }
  return ov;
}

std::string vecStrPrint(std::vector<std::string> toPrint) {
  std::string os;  // output string
  int counter = 0;
  for (auto elem : toPrint) {
    if (counter == 2) {
      counter = 0;
      os.push_back('\n');
    }
    os += elem;
  }
  return os;
}

// check_for_close adapted from jbc draw_cat.cpp
bool check_for_close(sf::RenderWindow& window) {
  sf::Event event;
  bool finish = false;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
      finish = true;
    }
  }
  return finish;
}

// figure out which words you should be checking for
std::string getrelevantstrings(std::vector<std::string> sv, int posindex, int numwords) {
  std::string os;
  if ((sv.size() - (numwords * posindex)) >= numwords) {
    for (int i = 0; i < numwords; i++) {
      os += sv.at(posindex * numwords + i);
    }
  } else {
    for (int i = 0; i < sv.size() - (numwords * posindex); i++) {
      os += sv.at(posindex * numwords + i);
    }
  }
  return os;
}

// the bulk of the code
// returns the speed result as a double
double typingTest() {
  char letterTest = whichletter();
  double time_now, time_then, delta;

  int positionindex = 0;
  int totalwords = 0;
  int numwords = 1;

  sf::RenderWindow window(sf::VideoMode(800, 600), "Typing Trainer");
  window.setFramerateLimit(120);
  window.setKeyRepeatEnabled(false);

  Button menu(buttonVector.at(13).at(0));
  menu.setPosition({300, 470});

  // zilla slab font import, relative path
  sf::Font zillaslab;
  zillaslab.loadFromFile("Zilla_Slab/ZillaSlab-Regular.ttf");

  // dividing line
  sf::RectangleShape line;
  line.setSize(sf::Vector2f(800, 4));
  line.setPosition(0, 160);

  // white outline box
  sf::RectangleShape typed;
  typed.setSize(sf::Vector2f(320, 60));
  typed.setPosition(240, 350);
  typed.setFillColor(sf::Color::Transparent);
  typed.setOutlineColor(sf::Color::White);
  typed.setOutlineThickness(2);

  sf::Text mytext;
  mytext.setFont(zillaslab);
  std::string literalstr = R"foo(The quick brown fox
  jumped over the lazy dogs.)foo";
  mytext.setString(literalstr);
  mytext.setCharacterSize(50);
  mytext.setPosition(280, 90);
  char currentchar;
  sf::Text typedText;
  typedText.setFont(zillaslab);
  typedText.setCharacterSize(50);
  typedText.setPosition(250.f, 342.f);
  typedText.setFillColor(sf::Color::Green);

  sf::Text results;
  results.setFont(zillaslab);
  results.setCharacterSize(40);
  results.setPosition(160.f, 80.f);
  results.setFillColor(sf::Color::Red);

  sf::Text realtimeresults;
  realtimeresults.setFont(zillaslab);
  realtimeresults.setCharacterSize(30);
  realtimeresults.setPosition(340.f, 250.f);
  realtimeresults.setFillColor(sf::Color::Magenta);

  int vecindex = 0;
  std::string wordToType = words.at(vecindex);
  std::vector<std::string> typedwords;

  std::string activestrings;
  std::string wordfragment;
  std::string fulloutput;
  bool toPrint = 1;
  int iter = 0;
  int printindex = 0;
  bool startClock = 1;
  bool printTime = 1;
  bool stopclock = 0;
  bool isover = 0;

  std::vector<bool> previousKeyboardState = currentKeyboardState();

  double timeElapsed, speed;

  while (window.isOpen()) {
    if (check_for_close(window)) break;
    window.clear();

    if (!isover) {
      activestrings = getrelevantstrings(words, positionindex, numwords);
      mytext.setString(activestrings);
      if (vecindex < words.size()) {
        wordToType = words.at(vecindex);
      } else if (printTime) {
        time_now = besttime();
        timeElapsed = time_now - time_then;
        std::cout << timeElapsed  << " seconds" << '\n';
        speed = (words.size() / timeElapsed) * 60;
        std::cout << "speed: " << speed << " WPM" << '\n';
        results.setString("Your speed: " + std::to_string(speed) + " WPM");
        printTime = 0;
        stopclock = 1;
        isover = 1;
      }

      // fixes the key repeat error
      if (previousKeyboardState != currentKeyboardState()) {
        currentchar = whichletter();
        previousKeyboardState = currentKeyboardState();
      }

      // if the character is correct, print it in green
      if (wordToType.at(iter) == currentchar) {
        iter++;
        wordfragment.push_back(currentchar);
        toPrint = 1;
        if (startClock) {
          time_then = besttime();
          startClock = 0;
        }
        currentchar = (char) 0;
      }
      // if a word is typed, append the word for window output
      if (wordToType == wordfragment) {
        iter = 0;
        typedwords.push_back(wordfragment);
        wordfragment.clear();
        toPrint = 1;
        vecindex++;
        totalwords++;
      }
      if (typedwords.size() == 0) {
        typedText.setString(wordfragment);
      } else {
        fulloutput = getrelevantstrings(typedwords, positionindex, numwords);
        typedText.setString(fulloutput + wordfragment);
        fulloutput.clear();
        toPrint = 0;
      }

      if (!stopclock) {
        time_now = besttime();
      }
      timeElapsed = time_now - time_then;
      speed = (typedwords.size() / timeElapsed) * 60;
      realtimeresults.setString(std::to_string((int)speed) + " WPM");

      positionindex = totalwords / numwords;
    }

    window.draw(mytext);
    window.draw(line);
    window.draw(typedText);
    window.draw(results);
    window.draw(realtimeresults);
    if (isover) {
      menu.drawTo(window);
    }
    window.draw(typed);
    window.display();
  }
  window.close();
  return speed;
}
