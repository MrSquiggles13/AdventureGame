#pragma once
#include "FightSequence.h"
class Game : public Character
{
private:
	bool m_playing;
	int m_difficulty;
	Character user{ };
	FightSequence fightEvent;
public:

	Game(bool playing = true, int difficulty = 0);
	
	void playGame();
	void createChar();
	void mainMenu();
	void charMenu();
	void startJourney();

	inline const void setDifficulty() { m_difficulty = user.getDifficulty(); }
	const bool& getPlaying() const { return m_playing; }
	~Game();
};

