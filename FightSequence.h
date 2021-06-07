#pragma once
#include "Maps.h"

class FightSequence
{
private:
	Enemies m_enemy;
	Maps map;
	std::vector<Enemies*> m_enemies;
	std::vector<Item*> m_loot;

public:

	FightSequence();

	void userTurn(std::vector<Enemies*>& enemies, Character& user, bool& escape);
	void enemyTurn(Enemies& enemy, Character& user, int index);
	void chooseTurn(std::vector<Enemies*>& enemies, Character& user);
	void setMap(std::vector<Enemies*>& enemies, Character& user);
	void randEncounter(Character& user);
	void setEncounter(std::vector<Enemies*>& enemies, Character& user);

	inline const std::vector<Item*>& getLootArr() { return m_loot; }
	inline const std::vector<Enemies*>& getEmenyArr() const { return m_enemies; }
};

