#pragma once
#include "ErrorHandling.h"

class Spells
{
protected:

	std::string m_name;
	std::string m_description;
	int m_lvl;
	int m_manaCost;
	int m_castingTime;
	int m_range;

public:

	Spells(std::string name = "",
		std::string description = "",
		int lvl = 0,
		int manaCost = 0,
		int castingTime = 0,
		int range = 0);

	void lvlUpSpell();
	virtual Spells* spellClone() const = 0;
	friend std::ostream& operator<<(std::ostream& out, Spells& spell);
	virtual std::ostream& printSpell(std::ostream& out) const = 0;

	static std::vector <Spells*> level1;
	static std::vector <Spells*> level2;
	static std::vector <Spells*> level3;
	static std::vector <Spells*> level4;
	static std::vector <Spells*> level5;
	static std::vector <Spells*> level6;
	static std::vector <Spells*> level7;
	static std::vector <Spells*> level8;
	static std::vector <Spells*> level9;

	static void listSpells();

	inline const std::string& getName() const { return m_name; }
};

class Fire_Bolt : public Spells
{
private:

	int m_hpModMin;
	int m_hpModMax;

public:

	Fire_Bolt(std::string name = "",
		std::string description = "",
		int lvl = 0,
		int manaCost = 0,
		int castingTime = 0,
		int range = 0,
		
		int hpModMin = 0,
		int hpModMax = 0);
	
	virtual Fire_Bolt* spellClone() const;
	virtual std::ostream& printSpell(std::ostream& out) const;

};

class Ice_Bolt : public Spells
{
private:

	int m_hpModMin;
	int m_hpModMax;
	int m_stamModMin;
	int m_stamModMax;

public:

	Ice_Bolt(std::string name = "",
		std::string description = "",
		int lvl = 0,
		int manaCost = 0,
		int castingTime = 0,
		int range = 0,
		
		int hpModMin = 0,
		int hpModMax = 0,
		int stamModMin = 0,
		int stamModMax = 0);

	virtual Ice_Bolt* spellClone() const;
	virtual std::ostream& printSpell(std::ostream& out) const;

};