#pragma once
#ifndef __EXIT_BUTTON__
#define __EXIT_BUTTON__

#include "Button.h"

class ExitButton : public Button
{
public:
	ExitButton();
	~ExitButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__EXIT_BUTTON__) */