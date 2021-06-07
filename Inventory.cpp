#include "Inventory.h"

Inventory::Inventory() 
{
	m_bulk = 6; m_numOfItem = 0; m_itemArr.reserve(m_bulk);
}

Inventory::Inventory(std::vector<Item*> itemArr, int bulk, int numOfItem): m_itemArr{itemArr}, m_bulk{bulk}, m_numOfItem{numOfItem}
{  }

void Inventory::addItem(const Item& item)
{
	if (m_numOfItem >= m_bulk)
		std::cout << "Not Enough Room!!";
	else
	{
		m_itemArr.push_back(item.clone());
		m_numOfItem++;
	}
}

void Inventory::removeItem(int index)
{
	if (m_itemArr.size() < index - 1)
		std::cout << "\nNo such item exists\n";
	else
	{
		m_itemArr.erase(m_itemArr.begin() + index - 1);
		m_numOfItem--;
	}
}

void Inventory::viewItem(int index)
{
	if (m_itemArr.size() < index - 1)
		std::cout << "\nNo such item exists\n";
	else
		std::cout << *m_itemArr[index - 1]->clone();
}

void Inventory::printInvList()
{
	int count{ 1 };
	for (size_t i = 0; i < m_numOfItem; i++)
	{
		std::cout << count++ << ". " << m_itemArr[i]->getName() << '\n';
	}
}

Inventory::~Inventory()
{
	
}