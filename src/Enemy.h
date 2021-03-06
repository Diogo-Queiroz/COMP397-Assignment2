#pragma once
#ifndef __BIRD__
#define __BIRD__

#include "DisplayObject.h"
#include "PlayerAnimationState.h"
#include "Animation.h"
#include "SpriteSheet.h"
#include <unordered_map>


#include "EnemyMovementType.h"
#include "Move.h"

class Enemy : public DisplayObject
{
public:
	Enemy();
	~Enemy();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void move(EnemyMovementType movement);



	// setters
	void setAnimationState(PlayerAnimationState new_state);
	void setAnimation(const Animation& animation);

	void setSpeed(float speed);

	void setMovementType(EnemyMovementType movementType);
	glm::vec2 startPosition;
	bool destroyed;
	void checkBounds();
private:

	glm::vec2 offset;

	void m_buildAnimations();
	
	float m_speed;
	EnemyMovementType m_movementType = FOWARD;

	SpriteSheet* m_pSpriteSheet;

	int m_currentFrame;

	PlayerAnimationState m_currentAnimationState;
	std::unordered_map<std::string, Animation> m_pAnimations;
};

#endif /* defined (__BIRD__) */