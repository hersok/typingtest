#include <SFML/Graphics.hpp>
#include <iostream>

class Button{
  public:
    Button() { }

    Button(std::string imgpath) {
      box.loadFromFile(imgpath);
      texture.loadFromImage(box);
      sprite.setTexture(texture);
    }

    void setNewImg(std::string imgpath){
      box.loadFromFile(imgpath);
      texture.loadFromImage(box);
      sprite.setTexture(texture);
    }

    void setPosition(sf::Vector2f pos){
      sprite.setPosition(pos);
    }

    void drawTo(sf::RenderWindow &window){
      window.draw(sprite);
    }


    bool isMouseOver(sf::RenderWindow &window){
      float mouseX = sf::Mouse::getPosition(window).x;
      float mouseY = sf::Mouse::getPosition(window).y;

      float btnPosX = sprite.getPosition().x; //left boundary
      float btnPosY = sprite.getPosition().y; //Botton boundary

      float btnxPosWidth = btnPosX + sprite.getLocalBounds().width; //Right end of sprite
      float btnyPosHeight = btnPosY + sprite.getLocalBounds().height;

      if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY){
        return true;
      }

      return false;
    }


  private:
    sf::Image box;
    sf::Texture texture;
    sf::Sprite sprite;
};
