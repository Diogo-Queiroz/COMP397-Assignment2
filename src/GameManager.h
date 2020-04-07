#pragma once
#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__



class GameManager
{
public:
	static GameManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new GameManager();
			return  s_pInstance;
		}

		return s_pInstance;
	}

	int getScore();
	void decreaseScore(int score);

	int getBirdsCount() const;
	void addBirdsCount();

	int getBirdsDestroyed();
	void addBirdsDestroyed();

	int getBirdsAvoided();
	void addBirdsAvoided();
	
	int getPlayerLife();
	void setPlayerHealth(int health);
	
	void reset();
	
private:

	int m_score = 0;
	int m_birdsCount = 0;
	int m_birdsDestroyed = 0;
	int m_playerLife = 3;
	int m_birdsAvoided;
	GameManager();
	~GameManager();


	static  GameManager* s_pInstance;

};

typedef  GameManager TheGameManager;

#endif
