#pragma once
#include "ErrorHandling.h"
class Item
{
protected:
	std::string m_name;
	std::string m_type;
	int m_lvl;
	int m_valueBuy;
	int m_valueSell;
	int m_rarity;
	
public:
	Item(int lvl, int rarity);

	Item(
	std::string name = "NONE",
	std::string type = "",
	int lvl = 0,
	int valueBuy = 0,
	int ValueSell = 0,
	int rarity = 0);

	inline const std::string printRarity(int rarity) const
	{
		switch (rarity)
		{
		case 1:
			return "Common";
		case 2:
			return "Uncommon";
 		case 3:
			return "Rare";
		case 4:
			return "Epic";
		case 5:
			return "Legendary";
		case 6:
			return "Unique";
		default:
			return "Undefined";
		}
	}

	void generateRandomItem();
	inline const std::string& getName() const { return m_name; }
	inline const std::string& getType() const { return m_type; }
	inline const int& getLvl() const { return m_lvl; }
	inline const int& getBuyValue() const { return m_valueBuy; }
	inline const int& getSellValue() const { return m_valueSell; }
	inline const int& getRarity() const { return m_rarity; }

	
	friend std::ostream& operator<<(std::ostream& out, Item& item);
	virtual std::ostream& print (std::ostream& out) const = 0;
	virtual Item* clone() const = 0;

	~Item();
};

