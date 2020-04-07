#include "GameManager.h"

GameManager* GameManager::s_pInstance = nullptr;


int GameManager::getScore()
{
	return m_score;
}

void GameManager::decreaseScore(int score)
{
	m_score -= score;
}

int GameManager::getBirdsCount() const
{
	return m_birdsCount;
}

void GameManager::addBirdsCount()
{
	m_birdsCount++;
}

int GameManager::getBirdsDestroyed()
{
	return m_birdsDestroyed;
}

void GameManager::addBirdsDestroyed()
{
	m_birdsDestroyed++;
}

int GameManager::getBirdsAvoided()
{
	return m_birdsAvoided;
}

void GameManager::addBirdsAvoided()
{
	m_birdsAvoided++;
}

int GameManager::getPlayerLife()
{
	return m_playerLife;
}

void GameManager::setPlayerHealth(int health)
{
	m_playerLife = health;
}

void GameManager::reset()
{
	m_birdsCount = 0;
	m_birdsDestroyed = 0;
	m_birdsAvoided = 0;
	m_score = 5000;
	m_playerLife = 30;
}

GameManager::GameManager(){

}

GameManager::~GameManager()
= default;


