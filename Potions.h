#pragma once
#include "Item.h"
class Potions : public Item
{
private:
	int m_throwRange;
	int m_hpMod;
	int m_stamMod;
	int m_magMod;
	int m_statMod;
	int m_escapeMod;
public:

	Potions(int lvl, int rarity);

	Potions(
		std::string name = "",
		std::string type = "",
		int lvl = 1,
		int valueBuy = 0,
		int valueSell = 0,
		int rarity = 1,
		int throwRange = 20,
		int hpMod = 0,
		int stamMod = 0,
		int magMod = 0,
		int statMod = 0,
		int escapeMod = 0);

	virtual std::ostream& print(std::ostream& out) const;
	virtual Potions* clone() const;

	static void listPotions();
	static std::vector <Potions> randCommonPots;
	static std::vector <Potions> randUnCommonPots;
	static std::vector <Potions> randRarePots;
	static std::vector <Potions> randEpicLegenPots;
	static std::vector <Potions> randUniquePots;

	inline const int& getHpMod() const { return m_hpMod; }
	inline const int& getStamMod() const { return m_stamMod; }
	inline const int& getMagMod() const { return m_magMod; }
	inline const int& getStatMod() const { return m_statMod; }
	inline const int& getEscapeMod() const { return m_escapeMod; }
	inline const int& getThrowRange() const { return m_throwRange; }

	~Potions();
};

