#pragma once
#include "Weapon.h"
#include "Armour.h"
#include "Potions.h"
class Inventory
{
private:
	std::vector<Item*> m_itemArr;
	int m_bulk;
	int m_numOfItem;
	

public:
	Inventory();
	Inventory(std::vector<Item*> itemArr, int bulk = 6, int numOfItem = 0);
	
	
	void addItem(const Item& item);
	void removeItem(int index);
	void viewItem(int index);

	inline int setBulk(int str) { m_bulk += ((str - 10) / 2); return m_bulk; }
	inline std::vector<Item*> getItemArr() const { return m_itemArr; }
	void printInvList();

	~Inventory();
};

