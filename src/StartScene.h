#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Button.h"
#include "StartButton.h"
#include "InstructionsButton.h"
#include "ExitButton.h"
#include "Background.h"

class StartScene final : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	glm::vec2 getMousePosition();
	
private:
	Label* m_pStartLabel{};
	Label* m_pInstructionsLabel{};

	Background* m_pBackground;

	glm::vec2 m_mousePosition;

	StartButton* m_pStartButton;
	InstructionsButton* m_pInstructionsButton;
	ExitButton* m_pExitButton;

};

#endif /* defined (__START_SCENE__) */