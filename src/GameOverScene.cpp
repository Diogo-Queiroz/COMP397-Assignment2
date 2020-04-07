#include "GameOverScene.h"
#include <algorithm>
#include "Game.h"
#include "GameManager.h"
#include "glm/gtx/string_cast.hpp"

GameOverScene::GameOverScene()
{
	GameOverScene::start();
}

GameOverScene::~GameOverScene()
= default;

void GameOverScene::draw()
{
	m_pBackground->draw();
	m_label->draw();
	m_score->draw();
	m_enemiesDestroyed->draw();
	m_tryAgain->draw();
	m_pStartButton->draw();
}

void GameOverScene::update()
{
}

void GameOverScene::clean()
{
	delete m_pStartButton;

	m_pStartButton = nullptr;
	removeAllChildren();
}

void GameOverScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			}
			break;
		default:
			break;
		}
	}
}

void GameOverScene::start()
{
	m_pBackground = new Background();
	
	const SDL_Color green = { 50, 120, 50, 255 };
	m_label = new Label("GAME OVER", "Comicv2d", 80, green, glm::vec2(400.0f, 40.0f));
	m_label->setParent(this);
	addChild(m_label);

	m_score = new Label("Score: " 
		+ std::to_string(GameManager::Instance()->getScore()),
		"Comicv2d", 40, green, glm::vec2(400.0, 275.0f), 0, true);
	m_score->setParent(this);
	addChild(m_score);

	m_enemiesDestroyed = new Label("Birds Killed: " 
		+ std::to_string(GameManager::Instance()->getBirdsDestroyed()) 
		+ "/" + std::to_string(GameManager::Instance()->getBirdsCount()) 
		+ "\nBirds Avoided: " 
		+ std::to_string(GameManager::Instance()->getBirdsAvoided())
		+ "/" + std::to_string(GameManager::Instance()->getBirdsCount()),
		"Comicv2d", 40, green, glm::vec2(400.0f, 325.0f), 0, true);
	m_enemiesDestroyed->setParent(this);
	addChild(m_enemiesDestroyed);

	m_tryAgain = new Label("",
		"Comicv2d", 40, green, glm::vec2(400.0f, 500.0f), 0, true);
	m_tryAgain->setParent(this);
	addChild(m_tryAgain);


	m_pStartButton = new StartButton();
	m_pStartButton->setPosition(glm::vec2(400.0f, 500.0f));
	addChild(m_pStartButton);

}
