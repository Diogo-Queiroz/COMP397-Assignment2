#pragma once
#ifndef __INSTRUCTIONS_IMAGE__
#define __INSTRUCTIONS_IMAGE__

#include "Button.h"

class InstructionsImage : public Button
{
public:
	InstructionsImage();
	~InstructionsImage();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__INSTRUCTIONS_IMAGE__) */