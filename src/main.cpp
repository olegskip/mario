#include <SFML/Graphics.hpp>
#include "game_logic.h"

// g++ main.cpp gamelogic.cpp raincontroller.cpp texturesLoader.cpp GameObjects/animationcontroller.cpp GameObjects/gameobject.cpp GameObjects/playergameobject.cpp GameObjects/blockgameobject.cpp -o ./output -lsfml-graphics -lsfml-window -lsfml-system

int main()
{
	GameLogic gameLogic = GameLogic();
	sf::RenderWindow window(sf::VideoMode(config::WINDOW_WIDTH, config::WINDOW_HEIGHT), config::WINDOW_NAME);
	sf::View view(sf::Vector2f((config::WINDOW_WIDTH / 2) * config::WINDOW_ZOOM, (config::WINDOW_HEIGHT / 2) * config::WINDOW_ZOOM),
				  sf::Vector2f(config::WINDOW_WIDTH, config::WINDOW_HEIGHT));
	view.zoom(config::WINDOW_ZOOM);
	window.setView(view);
	window.setFramerateLimit(60);
	
	std::vector<LabelController> labels; // all labels: time, score, etc
	labels.push_back(LabelController(gameLogic.fontsLoader.getObject(std::string("digital7")), 40 * config::WINDOW_ZOOM, sf::Color::White, std::string(), sf::Vector2f(5, 5))); // time

	bool isFocused = true;
	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::M)
					gameLogic.toggleMute();
			}
			if(event.type == sf::Event::GainedFocus)
				isFocused = true;
			else if(event.type == sf::Event::LostFocus)
				isFocused = false;
		}
		gameLogic.updateTime();

		if(isFocused)
			gameLogic.keysManager();

		

		window.clear(config::BACKGROUND_COLOR);

		gameLogic.update();
		labels[0].setText(std::to_string(gameLogic.getSpeed()));

		const auto cameraPosition = gameLogic.cameraController(view.getCenter());
		view.move(cameraPosition);
		
		window.setView(view);
		gameLogic.scrollBackground(cameraPosition);

		for(auto &label: labels) {
			label.move(cameraPosition);
			label.draw(window);
		}

		gameLogic.draw(window);
		window.display();
	}

	window.close();
	return EXIT_SUCCESS;
}
