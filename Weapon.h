#pragma once
#include "Item.h"
class Weapon : public Item
{
private:
	int m_damageMin;
	int m_damageMax;
	int m_range;
public:

	Weapon(int lvl, int rarity);

	Weapon(
		std::string name = "",
		std::string type = "",
		int lvl = 1,
		int valueBuy = 0,
		int valueSell = 0,
		int rarity = 1,
		int damageMin = 1,
		int damageMax = 5,
		int range = 2);

	virtual Weapon* clone() const;
	virtual std::ostream& print(std::ostream& out) const;

	static std::vector <Weapon> randComUnRareWep;
	static std::vector <Weapon> randEpicLegenWep;
	static std::vector <Weapon> randUniqueWep;

	static void listWeapons();

	
	inline const int getDamageMin() const { return m_damageMin; }
	inline const int getDamageMax() const { return m_damageMax; }

	~Weapon();
};

