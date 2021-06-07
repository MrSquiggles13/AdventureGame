#pragma once
#include "Character.h"
class Enemies
{
private:
	std::string m_name;
	std::string m_type;
	int m_lvl;
	int m_gold;
	int m_health;
	int m_healthMax;
	int m_AC;
	int m_boostAC;
	int m_initiative;
	int m_turnOrder;
	int m_damageMin;
	int m_damageMax;
	int m_accuracy;

	int m_movement;
	int m_mapX;
	int m_mapY;


	std::vector<Item*> m_loot;

public:
	Enemies(std::string name = "", std::string type = "", int lvl = 1, int gold = 0, int health = 10, 
		int healthMax = 10, int AC = 10, int initiative = 0, int turnOrder = 0,  int damageMin = 1, int damageMax = 3, int accuracy = 1);

	inline const std::string& getName() const { return m_name; }
	inline const int& getAC() const { return m_AC; }
	inline const int& getLvl() const { return m_lvl; }
	inline const int& getInit() const { return m_initiative; }
	inline const int& getAccuracy() const { return m_accuracy; }
	inline const int& getDamageMin() const { return m_damageMin; }
	inline const int& getDamageMax() const { return m_damageMax; }
	inline const void takeDamage(int& damage) { m_health -= damage; }
	inline const int& getHealth() const { return m_health; }
	inline const int& getACboost() { return m_boostAC; }
	inline const int& getGold() { return m_gold; }
	inline const int& getMapX() { return m_mapX; }
	inline const int& getMapY() { return m_mapY; }
	inline const void setMapX(int coord) { m_mapX += coord; }
	inline const void setMapY(int coord) { m_mapY += coord; }
	inline const void setStartMapX(int coord) { m_mapX = coord; }
	inline const void setStartMapY(int coord) { m_mapY = coord; }
	inline const void setTurnOrder(int& turnOrder) { m_turnOrder = turnOrder; }
	inline const int& getTurnOrder() const { return m_turnOrder; }
	inline const void setACboost() { m_boostAC += 4; }
	inline const void resetACboost() { m_boostAC = m_AC; }
	friend std::ostream& operator<<(std::ostream& out, Enemies enemy);
	std::ostream& printEnem(std::ostream& out);
};