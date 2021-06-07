#include "Enemies.h"

std::ostream& operator<<(std::ostream& out, Enemies enemy)
{
	return enemy.printEnem(out);
}

std::ostream& Enemies::printEnem(std::ostream& out)
{
	out << "Name: " << m_name << " Type: " << m_type << " Health: " << m_health << '/' << m_healthMax;
	return out;
}

Enemies::Enemies(std::string name, std::string type, int lvl, int gold, int health,
	int healthMax, int AC, int initiative, int turnOrder, int damageMin, int damageMAx, int accuracy):
	m_name{ name }, m_type{ type }, m_lvl{ lvl }, m_gold{ gold }, m_health{ health }, m_healthMax{ healthMax },
	m_AC{ AC }, m_initiative{ initiative }, m_turnOrder{ turnOrder }, m_damageMin{ damageMin }, m_damageMax{ damageMAx }, m_accuracy{ accuracy }
{
	std::uniform_int_distribution initDie{ 0, 1 * m_lvl };
	int enInRoll = initDie(mersenne);
}