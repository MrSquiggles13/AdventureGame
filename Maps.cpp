#include "Maps.h"

Maps::Maps()
{}

void Maps::mapMove(int y, int x, Character& user)
{
	//m_tempArr = m_mapArr;
	for (int line = 0;line < m_mapArr.size(); ++line)
	{
		if (m_mapArr[line].find("YU") != std::string::npos)
		{
			size_t pos = m_mapArr[line].find("YU");
			m_mapArr[line].replace(pos, 2, " .");
		}
	}
	m_mapArr[y].replace(x, 2, "YU");
}

void Maps::mapMove(int y, int x, Enemies& enemy, int index)
{
	for (int line = 0; line < m_mapArr.size(); ++line)
	{
		if (m_mapArr[line].find("YU") != std::string::npos)
		{
			size_t pos = m_mapArr[line].find(("E" + std::to_string(index + 1)));
			m_mapArr[line].replace(pos, 2, " .");
		}
	}
	m_mapArr[y].replace(x, 2, ("E" + std::to_string(index + 1)));
}

void Maps::setLocation(int y, int x, Character& user)
{
	m_mapArr[y].replace(x, 2, "YU");
}

void Maps::setLocation(int y, int x, Enemies& enemy, int index)
{
	m_mapArr[y].replace(x, 2, ("E" + std::to_string(index + 1)));
}

void Maps::createMap()
{
	m_mapArr = {
		{"###################################################################"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"# . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . #"},
		{"###################################################################"}
	};

	//m_tempArr = m_mapArr;

	//add replace to temp arr print temp arr take input for movement
	//
	/*int moveY = 1;
	int moveX = 3;
	m_tempArr[moveY].replace(moveX, 2, "YU");
	for (int line{ 0 }; line < m_tempArr.size(); ++line)
		std::cout << m_tempArr[line] << '\n';

	_getch();

	moveX -= 2;
	m_tempArr = m_mapArr;

	m_tempArr[moveY].replace(moveX, 2, "YU");

	for (int line{ 0 }; line < m_tempArr.size(); ++line)
		std::cout << m_tempArr[line] << '\n';

	_getch();

	moveY += 1;
	m_tempArr = m_mapArr;

	m_tempArr[moveY].replace(moveX, 2, "YU");

	for (int line{ 0 }; line < m_tempArr.size(); ++line)
		std::cout << m_tempArr[line] << '\n';

	_getch();*/
}