#pragma once
#include "Enemies.h"

class Maps
{
private:
	std::vector<std::string> m_mapArr;
	//std::vector<std::string> m_tempArr;

public:

	Maps();
	
	void mapMove(int y, int x, Character& user);
	void mapMove(int y, int x, Enemies& enemy, int index);
	void setLocation(int y, int x, Character& user);
	void setLocation(int y, int x, Enemies& enemy, int index);
	void createMap();

	inline const std::vector<std::string> getMap()const { return m_mapArr; }
	//inline const std::vector<std::string> getNewMap()const { return m_tempArr; }
	inline const std::string getPos(int y, int x)const { return m_mapArr[y].substr(x, x+2); }
};

