#include "Potions.h"

std::ostream& Potions::print(std::ostream& out) const
{
	if (m_type.find("Health") != std::string::npos)//health potion
	{
		if (m_hpMod == 0)
			out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " HP Mod: FULL";
		else
			out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " HP Mod: " << m_hpMod;
	}
	if (m_type.find("Magica") != std::string::npos)//magica potion
	{
		if (m_magMod == 0)
			out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " Mag Mod: FULL";
		else
			out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " Mag Mod: " << m_magMod;
	}
	if (m_type.find("Stamina") != std::string::npos)//stamina potion
	{
		if (m_stamMod == 0)
			out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " Stam Mod: FULL";
		else
			out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " Stam Mod: " << m_stamMod;
	}
	if (m_type.find("Damage") != std::string::npos)//damage potions
	{
		if (m_magMod == 0 && m_stamMod == 0)
		{
			out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " Throw Range: " << m_throwRange << " HP Mod: " << m_hpMod;
		}
		else
			out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " Throw Range: " << m_throwRange << " HP Mod: " << m_hpMod << " Stam Mod: " << m_stamMod << " Mag Mod: " << m_magMod;
	}
	
	if (m_type.find("Multi") != std::string::npos)//Multi Pots
		out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity)  << " HP Mod: " << m_hpMod << " Stam Mod: " << m_stamMod << " Mag Mod: " << m_magMod;
	
	if (m_type.find("Escape") != std::string::npos)// escape potions
		out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " Escape Boost: " << m_escapeMod;
	
	if (m_type.find("Boost") != std::string::npos)//stat increase
		out << "Name: " << m_name << " Type: " << m_type << " Level: " << m_lvl << " Sell Value: " << m_valueSell << " Rarity: " << printRarity(m_rarity) << " Throw Range: " << m_throwRange << " HP Mod: " << m_hpMod << " Stam Mod: " << m_stamMod << " Mag Mod: " << m_magMod;
	return out;
}

Potions::Potions(int lvl, int rarity) : Item(lvl, rarity)
{
	m_throwRange = 0;
	m_hpMod = 0;
	m_stamMod = 0;
	m_magMod = 0;
	m_statMod = 0;
	m_escapeMod = 0;
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
	if (rarity == 1)
	{
		std::uniform_int_distribution randCommonDie{ 0, static_cast<int>(randCommonPots.size()) - 1 };
		int randPotsRoll = randCommonDie(mersenne);
		m_name = randCommonPots[randPotsRoll].getName();
		m_type = randCommonPots[randPotsRoll].getType();
		m_valueBuy = m_lvl * rarity * 15;
	}
	if (rarity == 2)
	{
		std::uniform_int_distribution randUnCommonDie{ 0, static_cast<int>(randUnCommonPots.size()) - 1 };
		int randPotsRoll = randUnCommonDie(mersenne);
		m_name = randUnCommonPots[randPotsRoll].getName();
		m_type = randUnCommonPots[randPotsRoll].getType();
		m_valueBuy = m_lvl * rarity * 25;
	}
	if (rarity == 3)
	{
		std::uniform_int_distribution randRareDie{ 0, static_cast<int>(randRarePots.size()) - 1 };
		int randPotsRoll = randRareDie(mersenne);
		m_name = randRarePots[randPotsRoll].getName();
		m_type = randRarePots[randPotsRoll].getType();
		m_valueBuy = m_lvl * rarity * 40;
	}
	if (rarity == 4 || rarity == 5)
	{
		std::uniform_int_distribution randEpicLegenDie{ 0, static_cast<int>(randEpicLegenPots.size()) - 1 };
		int randPotsRoll = randEpicLegenDie(mersenne);
		m_name = randEpicLegenPots[randPotsRoll].getName();
		m_type = randEpicLegenPots[randPotsRoll].getType();
		m_valueBuy = m_lvl * rarity * 80;
	}
	if (rarity == 6)
	{
		std::uniform_int_distribution randUniqueDie{ 0, static_cast<int>(randUniquePots.size()) - 1 };
		int randPotsRoll = randUniqueDie(mersenne);
		m_name = randUniquePots[randPotsRoll].getName();
		m_type = randUniquePots[randPotsRoll].getType();
		m_valueBuy = m_lvl * rarity * 500;
	}

	m_rarity = rarity;

	if (m_type.find("Health") != std::string::npos)
	{
		m_throwRange = 0;
		m_stamMod = 0;
		m_magMod = 0;
		if (rarity == 1)
		{
			std::uniform_int_distribution randHealthDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity};
			int randPotsRoll = randHealthDie(mersenne);
			m_hpMod = randPotsRoll;
		}
		if (rarity == 2)
		{
			std::uniform_int_distribution randHealthDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
			int randPotsRoll = randHealthDie(mersenne);
			m_hpMod = randPotsRoll;
		}
		if (rarity == 3)
		{
			std::uniform_int_distribution randHealthDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
			int randPotsRoll = randHealthDie(mersenne);
			m_hpMod = randPotsRoll;
		}
		if (rarity == 4 || rarity == 5)
		{
			m_hpMod = 0;
			//special handled in using potion
		}
		if (rarity == 6)
		{
			std::uniform_int_distribution randHealthDie{ (m_lvl * m_rarity - m_lvl - m_rarity) / 3, (m_lvl * m_rarity + m_lvl + m_rarity) / 3 };
			int randPotsRoll = randHealthDie(mersenne);
			m_hpMod = randPotsRoll;

		}
	}
	if (m_type.find("Stamina") != std::string::npos)
	{
		m_hpMod = 0;
		m_magMod = 0;
		m_throwRange = 0;
		if (rarity == 1)
		{
			std::uniform_int_distribution randStamDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
			int randPotsRoll = randStamDie(mersenne);
			m_stamMod = randPotsRoll;
		}
		if (rarity == 2)
		{
			std::uniform_int_distribution randStamDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
			int randPotsRoll = randStamDie(mersenne);
			m_stamMod = randPotsRoll;
		}
		if (rarity == 3)
		{
			std::uniform_int_distribution randStamDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
			int randPotsRoll = randStamDie(mersenne);
			m_stamMod = randPotsRoll;
		}
		if (rarity == 4 || rarity == 5)
		{
			//Handled in use of potion
			m_stamMod = 0;
		}
		if (rarity == 6)
		{
			std::uniform_int_distribution randStamDie{ (m_lvl * m_rarity - m_lvl - m_rarity) / 3, (m_lvl * m_rarity + m_lvl + m_rarity) / 3 };
			int randPotsRoll = randStamDie(mersenne);
			m_stamMod = randPotsRoll;
		}
	}
	if (m_type.find("Magica") != std::string::npos)
	{
		m_throwRange = 0;
		m_hpMod = 0;
		m_stamMod = 0;
		if (rarity == 1)
		{
			std::uniform_int_distribution randMagDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
			int randPotsRoll = randMagDie(mersenne);
			m_magMod = randPotsRoll;
		}
		if (rarity == 2)
		{
			std::uniform_int_distribution randMagDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
			int randPotsRoll = randMagDie(mersenne);
			m_magMod = randPotsRoll;
		}
		if (rarity == 3)
		{
			std::uniform_int_distribution randMagDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
			int randPotsRoll = randMagDie(mersenne);
			m_magMod = randPotsRoll;
		}
		if (rarity == 4 || rarity == 5)
		{
			//handled in use of potion
			m_magMod = 0;
		}
		if (rarity == 6)
		{
			std::uniform_int_distribution randMagDie{ (m_lvl * m_rarity - m_lvl - m_rarity) / 3, (m_lvl * m_rarity + m_lvl + m_rarity) / 3 };
			int randPotsRoll = randMagDie(mersenne);
			m_magMod = randPotsRoll;
		}
	}
	if (m_type.find("Damage") != std::string::npos)
	{
		m_throwRange = 20;
		m_magMod = 0;
		m_stamMod = 0;
		if (rarity == 1)
		{
			std::uniform_int_distribution<int> randHealthDie{ -1 * (m_lvl * m_rarity + m_lvl + m_rarity) / 2, -1 * (m_lvl * m_rarity - m_lvl - m_rarity) / 2 };
			int randPotsRoll = randHealthDie(mersenne);
			m_hpMod = randPotsRoll;
		}
		if (rarity == 2)
		{
			std::uniform_int_distribution<int> randHealthDie{ -1 * (m_lvl * m_rarity + m_lvl + m_rarity) / 2, -1 * (m_lvl * m_rarity - m_lvl - m_rarity) / 2 };
			int randPotsRoll = randHealthDie(mersenne);
			m_hpMod = randPotsRoll;
		}
		if (rarity == 3)
		{
			std::uniform_int_distribution<int> randHealthDie{ -1 * (m_lvl * m_rarity + m_lvl + m_rarity) / 2, -1 * (m_lvl * m_rarity - m_lvl - m_rarity) / 2 };
			int randPotsRoll = randHealthDie(mersenne);
			m_hpMod = randPotsRoll;
		}
		if (rarity == 4 || rarity == 5)
		{
			std::uniform_int_distribution<int> randHealthDie{ -1 * (m_lvl * m_rarity + m_lvl + m_rarity) / 2, -1 * (m_lvl * m_rarity - m_lvl - m_rarity) / 2 };
			int randPotsRoll = randHealthDie(mersenne);
			m_hpMod = randPotsRoll / 2;
			randPotsRoll = randHealthDie(mersenne);
			m_magMod = randPotsRoll / 2;
			randPotsRoll = randHealthDie(mersenne);
			m_stamMod = randPotsRoll / 2;
			
		}
	}
	if (m_type.find("Boost") != std::string::npos)
	{
		m_throwRange = 0;
		std::uniform_int_distribution randStatDie{ (m_lvl * m_rarity - m_lvl - m_rarity) / 4, (m_lvl * m_rarity + m_lvl + m_rarity) / 4 };
		int randPotsRoll = randStatDie(mersenne);
		m_statMod = randPotsRoll;
	}
	if (m_type.find("Multi") != std::string::npos)
	{
		m_throwRange = 0;
		std::uniform_int_distribution randMagDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
		int randPotsRoll = randMagDie(mersenne);
		m_magMod = randPotsRoll;
		std::uniform_int_distribution randStamDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
		randPotsRoll = randStamDie(mersenne);
		m_stamMod = randPotsRoll;
		std::uniform_int_distribution randHealthDie{ m_lvl * m_rarity - m_lvl - m_rarity, m_lvl * m_rarity + m_lvl + m_rarity };
		randPotsRoll = randHealthDie(mersenne);
		m_hpMod = randPotsRoll;
	}
	if (m_type.find("Escape") != std::string::npos)
	{
		m_hpMod = 0;
		m_stamMod = 0;
		m_magMod = 0;
		m_throwRange = 0;
		std::uniform_int_distribution randEscapeDie{ (m_lvl * m_rarity - m_lvl - m_rarity) / 4, (m_lvl * m_rarity + m_lvl + m_rarity) / 4 };
		int randPotsRoll = randEscapeDie(mersenne);
		m_escapeMod = randPotsRoll;
	}
	m_valueSell = m_valueBuy / 2;
}

Potions::Potions(
	std::string name,
	std::string type,
	int lvl,
	int valueBuy,
	int valueSell,
	int rarity,
	int throwRange,
	int hpMod,
	int stamMod,
	int magMod,
	int statMod,
	int escapeMod) :
	Item(
		name,
		type,
		lvl,
		valueBuy,
		valueSell,
		rarity),
	m_throwRange { throwRange },
	m_hpMod { hpMod },
	m_stamMod{ stamMod },
	m_magMod{ magMod },
	m_statMod{ statMod },
	m_escapeMod{ escapeMod }
{

}

Potions* Potions::clone() const
{
	return new Potions(*this);
}

std::vector <Potions> Potions::randCommonPots;
std::vector <Potions> Potions::randUnCommonPots;
std::vector <Potions> Potions::randRarePots;
std::vector <Potions> Potions::randEpicLegenPots;
std::vector <Potions> Potions::randUniquePots;

void Potions::listPotions()
{
	Potions::randCommonPots.push_back(Potions("Minor Healing Potion", "Health"));
	Potions::randCommonPots.push_back(Potions("Minor Magica Potion", "Magica"));
	Potions::randCommonPots.push_back(Potions("Minor Stamina Potion", "Stamina"));
	Potions::randCommonPots.push_back(Potions("Minor Poison Potion", "Damage"));

	Potions::randUnCommonPots.push_back(Potions("Healing Potion", "Health"));
	Potions::randUnCommonPots.push_back(Potions("Magica Potion", "Magica"));
	Potions::randUnCommonPots.push_back(Potions("Stamina Potion", "Stamina"));
	Potions::randUnCommonPots.push_back(Potions("Poison Potion", "Damage"));

	Potions::randRarePots.push_back(Potions("Major Healing Potion", "Health"));
	Potions::randRarePots.push_back(Potions("Major Magica Potion", "Magica"));
	Potions::randRarePots.push_back(Potions("Major Stamina Potion", "Stamina"));
	Potions::randRarePots.push_back(Potions("Major Poison Potion", "Damage"));

	Potions::randEpicLegenPots.push_back(Potions("Rainbow Potion", "Multi"));
	Potions::randEpicLegenPots.push_back(Potions("Full Heal Potion", "Health"));
	Potions::randEpicLegenPots.push_back(Potions("Full Magica Potion", "Magica"));
	Potions::randEpicLegenPots.push_back(Potions("Full Stamina Potion", "Stamina"));
	Potions::randEpicLegenPots.push_back(Potions("Crippling Potion", "Damage"));
	Potions::randEpicLegenPots.push_back(Potions("Swirling Mist Potion", "Escape"));

	Potions::randUniquePots.push_back(Potions("Stat Enhance Potion", "Boost"));
	Potions::randUniquePots.push_back(Potions("Max Health Boost Potion", "Health"));
	Potions::randUniquePots.push_back(Potions("Max Stamina Boost Potion", "Stamina"));
	Potions::randUniquePots.push_back(Potions("Max Magica Boost Potion", "Magica"));

}

Potions::~Potions()
{

}