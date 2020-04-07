#include "Game.h"
#include "InstructionsButton.h"

InstructionsButton::InstructionsButton()
	: Button("../Assets/textures/InstructionsButton.png",
		"instructionsButton", INSTRUCTIONS_BUTTON,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.7f)),
	m_isClicked(false)
{
}

InstructionsButton::~InstructionsButton()
{
}

bool InstructionsButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheGame::Instance()->changeSceneState(SceneState::INSTRUCTIONS_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
