#include "InstructionsImage.h"
#include "Game.h"

InstructionsImage::InstructionsImage()
	: Button("../Assets/textures/WASD.png",
		"instructionsImage", INSTRUCTIONS_IMAGE,
		glm::vec2(Config::SCREEN_WIDTH * 0.2f, Config::SCREEN_HEIGHT * 0.7f)),
	m_isClicked(false)
{
}

InstructionsImage::~InstructionsImage()
{
}

bool InstructionsImage::ButtonClick()
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
