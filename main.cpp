#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
int main(int argc, char** argv) {

    unsigned int Ancho = 720u;
    unsigned int Alto = 480u;

    int posX = 0;
    int posY = 0;

    sf::RenderWindow window(sf::VideoMode(Ancho, Alto), "Tuto");
    sf::RectangleShape cuadrado;
    sf::Vector2f tamanio(50,50);
    cuadrado.setSize(tamanio);
    cuadrado.setPosition(posX,posY);
    cuadrado.setFillColor(sf::Color::Green);

    while (window.isOpen()){
        sf::Event evento;
        while (window.pollEvent(evento)){
            switch (evento.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (evento.MouseButtonPressed){
                        cuadrado.setPosition(posX+=10, posY+=10);

                        sf::Mouse::getPosition();
                    }
            }
        }

        window.clear();
        window.draw(cuadrado);
        window.display();
    }

    return 0;
}