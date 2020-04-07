#include "Game.h"
#include "ExitButton.h"

ExitButton::ExitButton()
	: Button("../Assets/textures/ExitButton.png",
		"exitButton", EXIT_BUTTON,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.9f)),
	m_isClicked(false)
{
}

ExitButton::~ExitButton()
{
}

bool ExitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheGame::Instance()->quit();
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
