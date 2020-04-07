#include "Level1Scene.h"
#include "Game.h"
#include "GameManager.h"
#include "Util.h"

Level1Scene::Level1Scene()
{
	Level1Scene::start();
}

Level1Scene::~Level1Scene()
= default;

void Level1Scene::draw()
{
	m_pBackground->draw();

	drawDisplayList();
	ExplosionManager::Instance()->draw();
	
}

void Level1Scene::update()
{
	std::cout << GameManager::Instance()->getBirdsCount() << std::endl;
	std::cout << GameManager::Instance()->getBirdsAvoided() << std::endl;
	m_pBackground->update();
	m_pFinishLevel->update();
	updateDisplayList();
	ExplosionManager::Instance()->update();
	m_pScoreLabel->setText("Score: " + std::to_string(TheGameManager::Instance()->getScore()));

	
	checkCollisions();
	
	if (m_pPlayer->getPosition().x > m_pFinishLevel->getPosition().x)
	{
		TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
	}

	if(TheGameManager::Instance()->getScore() <= 0)
	{
		TheGame::Instance()->changeSceneState(SceneState::GAME_OVER_SCENE);

	}
	
}

void Level1Scene::clean()
{

	removeAllChildren();
}

void Level1Scene::handleEvents()
{
	auto wheel = 0;

	SDL_Keycode keyPressed;
	SDL_Keycode keyReleased;
	
	SDL_Event event;

	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_S]) {
		m_pPlayer->move(DOWN);
		m_pPlayer->yBrakeDirection = EMPTY;
	}

	if (state[SDL_SCANCODE_W]) {
		m_pPlayer->move(UP);
		m_pPlayer->yBrakeDirection = EMPTY;
	}

	if (state[SDL_SCANCODE_A]) {
		m_pPlayer->move(LEFT);
		m_pPlayer->xBrakeDirection = EMPTY;
	}

	if (state[SDL_SCANCODE_D]) {
		m_pPlayer->move(RIGHT);
		m_pPlayer->xBrakeDirection = EMPTY;
	}
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			keyPressed = event.key.keysym.sym;
			switch (keyPressed)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			}
			
			break;
		case SDL_KEYUP:
			keyReleased = event.key.keysym.sym;

			
			if (keyReleased == SDLK_w)
			{
				m_pPlayer->yBrakeDirection = UP;

			}

			if (keyReleased == SDLK_s)
			{
				m_pPlayer->yBrakeDirection = DOWN;

			}
			if (keyReleased == SDLK_a)
			{
				m_pPlayer->xBrakeDirection = LEFT;
			}

			if (keyReleased == SDLK_d)
			{
				m_pPlayer->xBrakeDirection = RIGHT;

			}
			
			break;
			
		}
	}
}

void Level1Scene::start()
{
	TheGameManager::Instance()->reset();
	
	m_pBackground = new Background();
	
	m_pPlayer = new Player();
	m_pPlayer->setPosition(glm::vec2(70.0f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pPlayer);
	
	buildEnemies();
	
	TheSoundManager::Instance()->load("../Assets/audio/Explosion.mp3",
		"explosion", sound_type::SOUND_SFX);

	TheSoundManager::Instance()->load("../Assets/audio/Hit.mp3",
		"hit", sound_type::SOUND_SFX);
	
	const SDL_Color white = { 255, 255, 255, 255 };

	m_pScoreLabel = new Label("Score: 000000", "Comicv2d", 25, white, glm::vec2(650, 20), 0, false);
	addChild(m_pScoreLabel);

	m_pFinishLevel = new FinishLevel();
	m_pFinishLevel->setPosition(glm::vec2(6000,0));
	
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::buildEnemies()
{
	bool isToPush = false;
	int horizontalStart = 1000;
	for (size_t i = 0; i < 20; i++)
	{
		isToPush = false;
		auto enemy = new Enemy();
		if (i >= 1 && i < 10)
		{
			isToPush = true;
			GameManager::Instance()->addBirdsCount();
			enemy->setPosition(
				glm::vec2(
					horizontalStart + i * 50,
					-60 + 60 * i
				)
			);
		}
		else if (i >= 12 && i < 19)
		{
			isToPush = true;
			GameManager::Instance()->addBirdsCount();
			enemy->setPosition(
				glm::vec2(
					horizontalStart + i * 50,
					540 - (60 * (i - 12))
				)
			);
		}
		enemy->setMovementType(FOWARD);
		enemy->startPosition = enemy->getPosition();
		if (isToPush)
		{
			m_pFirstWaveEnemies.push_back(enemy);
			addChild(enemy);
		}
	}
	horizontalStart += 1000;
	for (size_t i = 0; i < 20; i++)
	{
		isToPush = false;
		auto enemy = new Enemy();
		if (i >= 1 && i < 9)
		{
			isToPush = true;
			GameManager::Instance()->addBirdsCount();
			enemy->setPosition(
				glm::vec2(
					horizontalStart + i * 50,
					60 + 60 * i
				)
			);
		}
		else if (i >= 13 && i < 20)
		{
			isToPush = true;
			GameManager::Instance()->addBirdsCount();
			enemy->setPosition(
				glm::vec2(
					horizontalStart + i * 50,
					540 - (60 * (i - 12))
				)
			);
		}
		enemy->setMovementType(FOWARD);
		enemy->startPosition = enemy->getPosition();
		if (isToPush)
		{
			m_pFirstWaveEnemies.push_back(enemy);
			addChild(enemy);
		}
	}
	horizontalStart += 1000;
	for (size_t i = 0; i < 20; i++)
	{
		isToPush = false;
		auto enemy = new Enemy();
		if (i >= 1 && i < 8)
		{
			isToPush = true;
			GameManager::Instance()->addBirdsCount();
			enemy->setPosition(
				glm::vec2(
					horizontalStart + i * 50,
					60 * i
				)
			);
		}
		else if (i >= 13 && i < 19)
		{
			isToPush = true;
			GameManager::Instance()->addBirdsCount();
			enemy->setPosition(
				glm::vec2(
					horizontalStart + i * 50,
					540 - (60 * (i - 12))
				)
			);
		}
		enemy->setMovementType(FOWARD);
		enemy->startPosition = enemy->getPosition();
		if (isToPush)
		{
			m_pFirstWaveEnemies.push_back(enemy);
			addChild(enemy);
		}
	}

	horizontalStart += 1000;
	for (size_t i = 0; i < 20; i++)
	{
		isToPush = false;
		auto enemy = new Enemy();
		if (i >= 1 && i < 8)
		{
			isToPush = true;
			GameManager::Instance()->addBirdsCount();
			enemy->setPosition(
				glm::vec2(
					horizontalStart + i * 120,
					60 * i
				)
			);
			enemy->setSpeed(7);
		}
		else if (i >= 13 && i < 19)
		{
			isToPush = true;
			GameManager::Instance()->addBirdsCount();
			enemy->setPosition(
				glm::vec2(
					horizontalStart + i * 200,
					540 - (60 * (i - 12))
				)
			);
			enemy->setSpeed(8);
		}
		enemy->setMovementType(FOWARD);
		enemy->startPosition = enemy->getPosition();
		if (isToPush)
		{
			m_pFirstWaveEnemies.push_back(enemy);
			addChild(enemy);
		}
	}
}

void Level1Scene::checkCollisions()
{
	for (auto bird : m_pFirstWaveEnemies)
	{
		CollisionManager::squaredRadiusCheck(m_pPlayer, bird);
	}
}
