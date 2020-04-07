#include "Enemy.h"
#include "Game.h"
#include "TextureManager.h"
#include "Util.h"
#include "GameManager.h"

Enemy::Enemy() : m_currentFrame(0), m_currentAnimationState(PLAYER_RIGHT), m_speed(6)
{
	TheTextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/atlas.txt",
		"../Assets/sprites/atlas.png",
		"spritesheet", TheGame::Instance()->getRenderer());

	m_pSpriteSheet = TheTextureManager::Instance()->getSpriteSheet("spritesheet");

	// set frame width
	setWidth(70);

	// set frame height
	setHeight(56);

	setPosition(glm::vec2(800.0f, 0));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(ENEMY);
	offset = glm::vec2(Util::RandomRange(0, 2), Util::RandomRange(0, 30));
	m_buildAnimations();
}

Enemy::~Enemy()
= default;

void Enemy::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->playAnimation("spritesheet", m_pAnimations["enemy"],
		getPosition().x, getPosition().y, m_currentFrame, 2.0f,
		TheGame::Instance()->getRenderer(), 0, 255, true, SDL_FLIP_HORIZONTAL);


}

void Enemy::update()
{

	if(getPosition().x > (Config::SCREEN_WIDTH + 50) && m_movementType != BACKWARDS)
	{
		move(FOWARD);
	}else
	{
		move(m_movementType);
	}
}

void Enemy::clean()
{
}

void Enemy::move(EnemyMovementType movement)
{
	if (!destroyed)
	{
		auto frame = TheGame::Instance()->getFrames();
		switch (movement)
		{
		case FOWARD:
			setVelocity(glm::vec2(-m_speed, 0));
			setPosition(getPosition() + getVelocity());
			break;
		case BACKWARDS:
			setVelocity(glm::vec2(m_speed + 1, 0));
			setPosition(getPosition() + getVelocity());
			break;
		case UP_DIAGONAL:
			setVelocity(glm::vec2(-2*m_speed, -m_speed));
			setPosition(getPosition() + getVelocity());
			break;
		case DOWN_DIAGONAL:
			setVelocity(glm::vec2(-2*m_speed, m_speed));
			setPosition(getPosition() + getVelocity());
			break;
		}
	}	
}

void Enemy::setAnimationState(const PlayerAnimationState new_state)
{
	m_currentAnimationState = new_state;
}

void Enemy::setAnimation(const Animation & animation)
{
	m_pAnimations[animation.name] = animation;
}

void Enemy::setSpeed(float speed)
{
	m_speed = speed;
}

void Enemy::setMovementType(EnemyMovementType movementType)
{
	m_movementType = movementType;
}

void Enemy::checkBounds()
{
	
}

void Enemy::m_buildAnimations()
{
	Animation enemyAnimation = Animation();

	enemyAnimation.name = "enemy";

	for (int i = 1; i < 13; ++i)
	{
		enemyAnimation.frames.push_back(m_pSpriteSheet->getFrame("Bird-" + std::to_string(i)));

	}
	m_pAnimations["enemy"] = enemyAnimation;
}
