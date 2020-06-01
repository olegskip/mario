#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace config
{
	const std::string WINDOW_NAME = "mario remake CXC";
	const std::string TITLE_TEXT = "Programmer: Oleg Skip;\nDesigner: Zahar Sydoryk;\nGitHub: olegskip/mario-remake;";
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 980;
	const float WINDOW_ZOOM = 1.5f;
	const float FULL_SCREEN_TEXTURES_SCALE = config::WINDOW_HEIGHT / (config::WINDOW_HEIGHT * config::WINDOW_ZOOM); 
	const int DYING_Y = 200;

	const sf::Color BACKGROUND_COLOR = sf::Color(90, 180, 220);

	// ---animations---

		// ---run animation---
		const float RUN_ANIMATION_SPEED = 4.4f;
		const unsigned int RUN_ANIMATION_FRAMES_COUNT = 26, START_RUNNING_FRAME = 4, STOP_RUNNING_FRAME = 20;
		// ---run animation---

		// ---jump animation---
		const float JUMP_ANIMATION_SPEED = 3.f;
		const unsigned int JUMP_ANIMATION_FRAMES_COUNT = 4, JUMPING_FRAME = 3;
		// ---jump animation---

	// ---animations---

	// ---live objects constants---
		const float GRAVITY = 1.f;
		const float MAX_FALLING_SPEED = 22.f;

		// ---player constants---
			// ---jumping---
			const float PLAYER_JUMPING_ACCELERATION = 23.f;
			const float PLAYER_JUMPING_MAX_SPEED = 23.f; 
			// ---jumping---

			// ---running
			const float PLAYER_RUNNING_ACCELERATION = 0.3f;
			const float PLAYER_RUNNING_DECELERATION = 0.5f;
			const float PLAYER_RUNNING_MAX_SPEED = 10.f;

			const float PLAYER_RUNNIMG_ACCELERATION_ON_ICE= 0.23f;
			const float PLAYER_RUNNIMG_DECELARATION_ON_ICE = 0.35f;
			const float PLAYER_RUNNING_MAX_SPEED_ON_ICE = 12.f;
			// ---running

	// ---live objects constants---

	// ---backgrounds---
	const unsigned int MOUNTAINS_BACKGROUND_OFFSET_Y = 130;
	const unsigned int FIELD_BACKGROUND_OFFSET_Y = 760;
	const unsigned int FOREST_BACKGROUND_OFFSET_Y = 570;
	// ---backgrounds---
}
