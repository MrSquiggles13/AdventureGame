#pragma once
#include "Item.h"
class Armour: public Item
{
private:
	int m_ACbonus;
public:

	Armour(int lvl, int rarity);

	Armour(
		std::string name = "",
		std::string type = "",
		int lvl = 1,
		int valueBuy = 0,
		int valueSell = 0,
		int rarity = 1,
		int ACbonus = 5 );

	virtual Armour* clone() const;
	virtual std::ostream& print(std::ostream& out) const;

	inline const int getACbonus() const { return m_ACbonus; }

	static std::vector <Armour> randComUnRareArm;
	static std::vector <Armour> randEpicLegenArm;
	static std::vector <Armour> randUniqueArm;
	static void listArmour();
	~Armour();
};

