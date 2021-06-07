#include "Armour.h"

std::ostream& Armour::print(std::ostream& out) const
{
	out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " AC Bonus: " << m_ACbonus;
	return out;
}

Armour::Armour(int lvl, int rarity) : Item(lvl, rarity)
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
		std::uniform_int_distribution randComUnRareDie{ 0, static_cast<int>(randComUnRareArm.size()) - 1 };
		int randArmRoll = randComUnRareDie(mersenne);
		m_name = randComUnRareArm[randArmRoll].getName();
		m_type = randComUnRareArm[randArmRoll].getType();
	}
	if (rarity == 4 || rarity == 5)
	{
		std::uniform_int_distribution randEpicLegenDie{ 0, static_cast<int>(randEpicLegenArm.size()) - 1 };
		int randArmRoll = randEpicLegenDie(mersenne);
		m_name = randEpicLegenArm[randArmRoll].getName();
		m_type = randEpicLegenArm[randArmRoll].getType();
	}
	if (rarity == 6)
	{
		std::uniform_int_distribution randUniqueDie{ 0, static_cast<int>(randUniqueArm.size()) - 1 };
		int randArmRoll = randUniqueDie(mersenne);
		m_name = randUniqueArm[randArmRoll].getName();
		m_type = randUniqueArm[randArmRoll].getType();
	}

	m_rarity = rarity;

	if (rarity <= 2)
	{
		std::uniform_int_distribution randACDie{ ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + ( 1.0 / 5.0 * m_lvl) + m_rarity) + static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0)) / 2), ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + (1.0 / 5.0 * m_lvl) + m_rarity) + (static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0)))) };
		int ACRoll = randACDie(mersenne);
		m_valueBuy = m_lvl * m_rarity * 50;
		m_valueSell = m_valueBuy / 2;
		m_ACbonus = ACRoll;
	}
	if (rarity == 3)
	{
		std::uniform_int_distribution randACDie{ ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + (1.0 / 5.0 * m_lvl) + m_rarity) + static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0))), ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + (1.0 / 5.0 * m_lvl) + m_rarity) + (static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0)))) };
		int ACRoll = randACDie(mersenne);
		m_valueBuy = m_lvl * m_rarity * 100;
		m_valueSell = m_valueBuy / 2;
		m_ACbonus = ACRoll;
	}
	if (rarity == 4)
	{
		std::uniform_int_distribution randACDie{ ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + (1.0 / 5.0 * m_lvl) + m_rarity) + static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0)) / 2), ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + (1.0 / 5.0 * m_lvl) + m_rarity) + (static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0)))) };
		int ACRoll = randACDie(mersenne);
		m_valueBuy = m_lvl * m_rarity * 150;
		m_valueSell = m_valueBuy / 2;
		m_ACbonus = ACRoll;
	}
	if (rarity == 5)
	{
		std::uniform_int_distribution randACDie{ ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + (1.0 / 5.0 * m_lvl) + m_rarity) + static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0)) / 2), ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + (1.0 / 5.0 * m_lvl) + m_rarity) + (static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0)))) };
		int ACRoll = randACDie(mersenne);
		m_valueBuy = m_lvl * m_rarity * 300;
		m_valueSell = m_valueBuy / 2;
		m_ACbonus = ACRoll;
	}
	if (rarity == 6)
	{
		std::uniform_int_distribution randACDie{ ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + (1.0 / 5.0 * m_lvl) + m_rarity) + static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0)) / 2), ((static_cast<int>(((1.0 / 20.0) * m_lvl * m_lvl) + (1.0 / 5.0 * m_lvl) + m_rarity) + (static_cast<int>(1.0 / 50.0 * m_rarity * m_rarity * m_rarity + 1.0 / 4.0 * m_rarity * m_rarity + 1.0 / 15.0 * m_rarity + 1.0)))) };
		int ACRoll = randACDie(mersenne);
		m_valueBuy = m_lvl * m_rarity * 500;
		m_valueSell = m_valueBuy / 2;
		m_ACbonus = ACRoll;
	}
}

Armour::Armour(
	std::string name,
	std::string type,
	int lvl,
	int valueBuy,
	int valueSell,
	int rarity,
	int ACbonus ) :
	Item(
		name,
		type,
		lvl,
		valueBuy,
		valueSell,
		rarity),
	m_ACbonus{ ACbonus }
{
	
}

Armour* Armour::clone() const
{
	return new Armour(*this);
}

std::vector <Armour> Armour::randComUnRareArm;
std::vector <Armour> Armour::randEpicLegenArm;
std::vector <Armour> Armour::randUniqueArm;

void Armour::listArmour()
{
	Armour::randComUnRareArm.push_back(Armour("Hunter Vest", "Chest"));
	Armour::randComUnRareArm.push_back(Armour("Studded Hide", "Chest"));
	Armour::randComUnRareArm.push_back(Armour("Steel Plate", "Chest"));
	Armour::randComUnRareArm.push_back(Armour("Cottton", "Chest"));
	
	Armour::randEpicLegenArm.push_back(Armour("Elven Plate", "Chest"));
	Armour::randEpicLegenArm.push_back(Armour("Mithril Ringmail", "Chest"));
	Armour::randEpicLegenArm.push_back(Armour("Assassins Robes", "Chest"));
	Armour::randEpicLegenArm.push_back(Armour("Dark Steel", "Chest"));

	Armour::randUniqueArm.push_back(Armour("Solarus", "Chest"));
	Armour::randUniqueArm.push_back(Armour("Divinity", "Chest"));

}

Armour::~Armour()
{

}