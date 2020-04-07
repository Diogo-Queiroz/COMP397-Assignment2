#include "InstructionsScene.h"
#include "Game.h"

InstructionsScene::InstructionsScene()
{
	InstructionsScene::start();
}

InstructionsScene::~InstructionsScene()
{
}

void InstructionsScene::draw()
{
	m_pBackground->draw();
	m_pInstructionsImage->draw();
	m_pStartLabel->draw();
	m_pInstructionsLabel->draw();

	m_pStartButton->draw();
	m_pExitButton->draw();
}

void InstructionsScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();


	m_pExitButton->setMousePosition(m_mousePosition);
	m_pExitButton->ButtonClick();
}

void InstructionsScene::clean()
{
	std::cout << "Clean called on StartScene" << std::endl;

	delete m_pStartLabel;
	m_pStartLabel = nullptr;

	delete m_pInstructionsLabel;
	m_pInstructionsLabel = nullptr;

	delete m_pStartButton;
	delete m_pExitButton;

	m_pStartButton = nullptr;
	m_pExitButton = nullptr;

	removeAllChildren();
}

void InstructionsScene::handleEvents()
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

void InstructionsScene::start()
{
	const SDL_Color green = { 90, 200, 90, 255 };
	m_pStartLabel = new Label("SUPERMAN DODGING BIRDS", "Comicv2d", 65, green, glm::vec2(400.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pInstructionsLabel = new Label("You are flying, need to avoid the birds. Be careful.", "Comicv2d", 28, green, glm::vec2(400.0f, 120.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

	m_pBackground = new Background();
	addChild(m_pBackground);

	m_pStartButton = new StartButton();
	m_pStartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 460));
	addChild(m_pStartButton);

	m_pExitButton = new ExitButton();
	m_pExitButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 560));
	addChild(m_pExitButton);

	m_pInstructionsImage = new InstructionsImage();
	m_pInstructionsImage->setPosition(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f);
	addChild(m_pInstructionsImage);
}

glm::vec2 InstructionsScene::getMousePosition()
{
	return m_mousePosition;
}
