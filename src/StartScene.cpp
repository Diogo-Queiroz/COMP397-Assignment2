#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	
	m_pBackground->draw();

	m_pStartLabel->draw();
	m_pInstructionsLabel->draw();

	m_pStartButton->draw();
	m_pInstructionsButton->draw();
	m_pExitButton->draw();
}

void StartScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();

	m_pInstructionsButton->setMousePosition(m_mousePosition);
	m_pInstructionsButton->ButtonClick();

	m_pExitButton->setMousePosition(m_mousePosition);
	m_pExitButton->ButtonClick();
}

void StartScene::clean()
{
	std::cout << "Clean called on StartScene" << std::endl;
	
	delete m_pStartLabel;
	m_pStartLabel = nullptr;
	
	delete m_pInstructionsLabel;
	m_pInstructionsLabel = nullptr;

	delete m_pStartButton;
	delete m_pInstructionsButton;
	delete m_pExitButton;

	m_pStartButton = nullptr;
	m_pInstructionsButton = nullptr;
	m_pExitButton = nullptr;
	
	removeAllChildren();
}

void StartScene::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
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
				TheGame::Instance()->changeSceneState(SceneState::INSTRUCTIONS_SCENE);
				break;
			case SDLK_3:
				TheGame::Instance()->quit();
			}
			break;

		default:
			break;
		}
	}
}

void StartScene::start()
{
	const SDL_Color green = { 90, 200, 90, 255 };
	m_pStartLabel = new Label("SUPERMAN DODGING BIRDS", "Comicv2d", 65, green, glm::vec2(400.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pInstructionsLabel = new Label("", "Comicv2d", 40, green, glm::vec2(400.0f, 120.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

	m_pBackground = new Background();
	addChild(m_pBackground);

	m_pStartButton = new StartButton();
	addChild(m_pStartButton);

	m_pInstructionsButton = new InstructionsButton();
	addChild(m_pInstructionsButton);

	m_pExitButton = new ExitButton();
	addChild(m_pExitButton);
	
}

glm::vec2 StartScene::getMousePosition()
{
	return m_mousePosition;
}


