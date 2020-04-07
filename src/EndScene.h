#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Background.h"
#include "StartButton.h"

class EndScene final : public Scene
{
public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	Label* m_label{};
	Label* m_enemiesDestroyed;
	Label* m_score;

	Background* m_pBackground;
	StartButton* m_pStartButton;
};

#endif /* defined (__END_SCENE__) */