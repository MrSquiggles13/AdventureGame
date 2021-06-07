#include "Weapon.h"

std::ostream& Weapon::print(std::ostream& out) const
{
	out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " Range: " << m_range << " Damage: " << m_damageMin << '-' << m_damageMax;
	return out;
}

Weapon::Weapon(int lvl, int rarity) : Item(lvl, rarity)
{
	if (lvl < 4)
	{
		std::uniform_int_distribution randLvlDie{ 1, lvl + 2 };
		int randLvlRoll = randLvlDie(mersenne);
		if (randLvlRoll > lvl)
			randLvlRoll = randLvlDie(mersenne);
		m_lvl = randLvlRoll;
	}
	else
	{
		std::uniform_int_distribution randLvlDie{ lvl - 3, lvl + 2 };
		int randLvlRoll = randLvlDie(mersenne);
		if (randLvlRoll > lvl)
			randLvlRoll = randLvlDie(mersenne);
		m_lvl = randLvlRoll;
	}
	
	if (rarity <= 3)
	{
		std::uniform_int_distribution randComUnRareDie{ 0, static_cast<int>(randComUnRareWep.size()) - 1 };
		int randWepRoll = randComUnRareDie(mersenne);
		m_name = randComUnRareWep[randWepRoll].getName();
		m_type = randComUnRareWep[randWepRoll].getType();
	}
	if (rarity == 4 || rarity == 5)
	{
		std::uniform_int_distribution randEpicLegenDie{ 0, static_cast<int>(randEpicLegenWep.size()) - 1 };
		int randWepRoll = randEpicLegenDie(mersenne);
		m_name = randEpicLegenWep[randWepRoll].getName();
		m_type = randEpicLegenWep[randWepRoll].getType();
	}
	if (rarity == 6)
	{
		std::uniform_int_distribution randUniqueDie{ 0, static_cast<int>(randUniqueWep.size()) - 1 };
		int randWepRoll = randUniqueDie(mersenne);
		m_name = randUniqueWep[randWepRoll].getName();
		m_type = randUniqueWep[randWepRoll].getType();
	}

	m_rarity = rarity;

	std::uniform_int_distribution randDamageDie{ static_cast<int>( ((31.0 / 1295.0 * m_lvl * m_lvl + 9881.0 / 11655.0 * m_lvl + 7292.0 / 2331.0) * (1.0 / 30.0 * m_rarity * m_rarity * 11.0 / 30.0 * m_rarity + 3.0 / 5.0)) * 0.75), static_cast<int>(((31.0 / 1295.0 * m_lvl * m_lvl + 9881.0 / 11655.0 * m_lvl + 7292.0 / 2331.0) * (1.0 / 30.0 * m_rarity * m_rarity * 11.0 / 30.0 * m_rarity + 3.0 / 5.0)) * 1.25) };
	int damageRoll = randDamageDie(mersenne);
	m_damageMax = damageRoll;

	if (rarity <= 2)
		m_valueBuy = m_lvl * m_rarity * 50 + m_damageMax;
	if (rarity == 3)
		m_valueBuy = m_lvl * m_rarity * 100 + m_damageMax;
	if (rarity == 4)
		m_valueBuy = m_lvl * m_rarity * 150 + m_damageMax;
	if (rarity == 5)
		m_valueBuy = m_lvl * m_rarity * 300 + m_damageMax;
	if (rarity == 6)
		m_valueBuy = m_lvl * m_rarity * 500 + m_damageMax;

	m_damageMin = m_damageMax / 2 + (m_damageMax / 4);
	m_valueSell = m_valueBuy / 2;

	if (m_type.find("Bow") != std::string::npos)
		m_range = 6;
	else
		m_range = 2;
}

Weapon::Weapon(
	std::string name,
	std::string type,
	int lvl,
	int valueBuy,
	int valueSell,
	int rarity,
	int damageMin,
	int damageMax,
	int range) :
	Item(
		name,
		type,
		lvl,
		valueBuy,
		valueSell,
		rarity),
	m_damageMin{ damageMin },
	m_damageMax{ damageMax },
	m_range{ range }
{
	
}

Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}

std::vector<Weapon> Weapon::randComUnRareWep;
std::vector<Weapon> Weapon::randEpicLegenWep;
std::vector<Weapon> Weapon::randUniqueWep;

void Weapon::listWeapons()
{
	Weapon::randComUnRareWep.push_back(Weapon("Steel Claymore" , "Sword"));
	Weapon::randComUnRareWep.push_back(Weapon("Iron Dirk" , "Dagger"));
	Weapon::randComUnRareWep.push_back(Weapon("Iron Gladius", "Sword"));
	Weapon::randComUnRareWep.push_back(Weapon("Recurve Bow", "Bow"));

	Weapon::randEpicLegenWep.push_back(Weapon("Dark Blade", "Dagger"));
	Weapon::randEpicLegenWep.push_back(Weapon("Crimson Cleaver", "Axe"));
	Weapon::randEpicLegenWep.push_back(Weapon("Dark Bow", "Bow"));
	Weapon::randEpicLegenWep.push_back(Weapon("Frigid Slicer", "Sword"));

	Weapon::randUniqueWep.push_back(Weapon("Nightwing", "Bow"));
	Weapon::randUniqueWep.push_back(Weapon("Halo", "Sword"));
}

Weapon::~Weapon()
{

}