#include "Item.h"

std::ostream& operator<<(std::ostream& out, Item& item)
{
	return item.print(out);
}

Item::Item(int lvl, int rarity)
{

}

Item::Item(
std::string name,
std::string type,
int lvl,
int valueBuy,
int valueSell,
int rarity):
m_name{ name },
m_type{ type },
m_lvl{ lvl },
m_valueBuy{ valueBuy },
m_valueSell{ valueSell },
m_rarity{ rarity }
{

}

void Item::generateRandomItem()
{
	//std::uniform_int_distribution level
}

Item::~Item()
{

}