#include "Spells.h"

std::ostream& operator<<(std::ostream& out, Spells& spell)
{
	return spell.printSpell(out);
}

Spells::Spells(std::string name,
	std::string description,
	int lvl,
	int manaCost,
	int castingTime,
	int range):

	m_name{name},
	m_description{description},
	m_lvl{ lvl },
	m_manaCost{manaCost},
	m_castingTime{castingTime},
	m_range{range}
{}

Fire_Bolt::Fire_Bolt(std::string name,
	std::string description,
	int lvl,
	int manaCost,
	int castingTime,
	int range,

	int hpModMin,
	int hpModMax):

	Spells(name,
		description,
		lvl,
		manaCost,
		castingTime,
		range),
	m_hpModMin{ hpModMin },
	m_hpModMax{ hpModMax }
{}

Ice_Bolt::Ice_Bolt(std::string name,
	std::string description,
	int lvl,
	int manaCost,
	int castingTime,
	int range,

	int hpModMin,
	int hpModMax,
	int stamModMin,
	int stamModMax) :

	Spells(name,
		description,
		lvl,
		manaCost,
		castingTime,
		range),
	m_hpModMin{ hpModMin },
	m_hpModMax{ hpModMax },
	m_stamModMin{ stamModMin },
	m_stamModMax{ stamModMax }
{}

Fire_Bolt* Fire_Bolt::spellClone() const { return new Fire_Bolt(*this); }
Ice_Bolt* Ice_Bolt::spellClone() const { return new Ice_Bolt(*this); }

void Spells::lvlUpSpell()
{

}

std::vector <Spells*> Spells::level1;
std::vector <Spells*> Spells::level2;
std::vector <Spells*> Spells::level3;
std::vector <Spells*> Spells::level4;
std::vector <Spells*> Spells::level5;
std::vector <Spells*> Spells::level6;
std::vector <Spells*> Spells::level7;
std::vector <Spells*> Spells::level8;
std::vector <Spells*> Spells::level9;

void Spells::listSpells()
{
	Spells::level1.push_back(Fire_Bolt("Fire Bolt", "A small burst of flame shoots from your fingertips", 2, 1, 6, 3, 5).spellClone());
	Spells::level1.push_back(Ice_Bolt("Ice Bolt", "A sharp icicle flys out your palm", 2, 1, 6, 2, 4, 1, 3).spellClone());

	/*Spells::level2.push_back(Spells(""));
	Spells::level2.push_back(Spells(""));

	Spells::level3.push_back(Spells(""));
	Spells::level3.push_back(Spells(""));

	Spells::level4.push_back(Spells(""));
	Spells::level4.push_back(Spells(""));*/
}

std::ostream& Fire_Bolt::printSpell(std::ostream& out) const { return out << m_name << ":\n\n" << m_description; }
std::ostream& Ice_Bolt::printSpell(std::ostream& out) const { return out << m_name << ":\n\n" <<  m_description; }