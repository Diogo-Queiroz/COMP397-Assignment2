#pragma once
#ifndef __INSTRUCTIONS_SCENE__
#define __INSTRUCTIONS_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Button.h"
#include "StartButton.h"
#include "InstructionsButton.h"
#include "ExitButton.h"
#include "Background.h"
#include "InstructionsImage.h"

class InstructionsScene final : public Scene
{
public:
	InstructionsScene();
	~InstructionsScene();

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

	InstructionsImage* m_pInstructionsImage;

};

#endif /* defined (__INSTRUCTIONS_SCENE__) */