#include "FightSequence.h"

FightSequence::FightSequence()
{

}

void FightSequence::userTurn(std::vector<Enemies*>& enemies, Character& user, bool& escape)
{
	int select;
	char selectMove;
	int attackTurns{ 2 };
	int moveTurns{ 2 };
	int move = user.getMove();
	do
	{
		user.resetACboost();
		std::uniform_int_distribution hitDie{ 1 + user.getAccuracy() / 4, 20 + user.getAccuracy() };
		int attackRoll = hitDie(mersenne);
		std::uniform_int_distribution damageDie{ user.getDamageMin(), user.getDamageMax() };
		int damageRoll = damageDie(mersenne);
		if (damageRoll < 0)
			damageRoll = 0;
		std::uniform_int_distribution escapeDie{ 1 + ((user.getLuck() - 10) / 8), 20 + ((user.getLuck() - 10) / 2) };
		int escapeRoll = escapeDie(mersenne);
		std::cout << "\n\nWould you like to: \n 1. Attack\n 2. Defend\n 3. Escape\n 4. Move\n\n Choose[1-4]: ";
		int tempEsc{ 0 };
		std::cin >> select;
		select = errorHandle(select);
		if (select == -1)
		{
			std::cout << "\nInvalid Input\n"; break;
		}
		switch (select)
		{
		case 1: //attack
			std::cout << slowPrint{ "\nWhich enemy do you want to attack?: " };
			std::cin >> select;
			errorHandle(select);

			if (select > enemies.size())
			{
				std::cout << slowPrint{ "You did not select and enemy" };
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				break;
			}
			if (attackRoll >= (enemies[select - 1]->getACboost() > enemies[select - 1]->getAC() ? enemies[select - 1]->getACboost() : enemies[select - 1]->getAC()))
			{
				std::cout << slowPrint{ "\nHit!\t You did " } << damageRoll << slowPrint{ " damage!" };
				enemies[select - 1]->takeDamage(damageRoll);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				if (enemies[select - 1]->getHealth() <= 0)
				{
					enemies.erase(enemies.begin() + select - 1);
					std::cout << slowPrint{ "\nYou have killed an enemy!!" };
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				}
			}
			else
			{
				std::cout << slowPrint{ "\nYou Missed!!" };
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			attackTurns--;
			moveTurns--;
			break;
		case 2: //defend
			user.setACboost();
			break;
		case 3: //escape
			for (size_t enemy = 0; enemy < enemies.size(); ++enemy)
			{
				tempEsc += (enemies[enemy]->getAC() + 4 + (enemies[enemy]->getLvl() / 2));
			}
			tempEsc /= enemies.size();
			if (escapeRoll >= tempEsc)
			{
				std::cout << slowPrint{ "\nYou have escaped!!" };
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				escape = true;
			}
			else
			{
				std::cout << slowPrint{ "\nStay in the fight!! You got this!!" };
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			break;
		case 4://movement
			system("cls");
			do
			{
				std::vector<std::string> tempArr;
				tempArr = map.getMap();
				for (int line{ 0 }; line < tempArr.size(); ++line)
					std::cout << tempArr[line] << '\n';
				std::cout << "\nWhich direction would you like to move: "
					"\n[w=up d=right s=down a=left q=stop]";
				std::cin >> selectMove;
				errorHandle(selectMove);
				switch (selectMove)
				{
				case 'w':
					// manipulate move y for player
					user.setMapY(-1);
					map.mapMove(user.getMapY(), user.getMapX(), user);
					move -= 1;
					break;
				case'd':
					user.setMapX(2);
					map.mapMove(user.getMapY(), user.getMapX(), user);
					move -= 1;
					break;
				case's':
					user.setMapY(1);
					map.mapMove(user.getMapY(), user.getMapX(), user);
					move -= 1;
					break;
				case'a':
					user.setMapX(-2);
					map.mapMove(user.getMapY(), user.getMapX(), user);
					move -= 1;
					break;
				case'q':
					break;
				default:
					std::cout << "Invalid Input";
					break;
				}
				system("cls");
			} while (move > 0 && selectMove != 'q');
			attackTurns--;
			moveTurns--;
			break;
		default:
			select = 0;
			break;
		}
	} while (select == 0);
}

void FightSequence::enemyTurn(Enemies& enemy, Character& user, int index)
{
	std::uniform_int_distribution choiceDie{ 1, 100 };
	int enemyRoll = choiceDie(mersenne);
	enemy.resetACboost();
	if (enemyRoll < 70)
	{
		std::cout << '\n' << enemy.getName() << slowPrint{ " Attacks" };
		std::uniform_int_distribution hitDie{ 1, 20 };
		int attackRoll = hitDie(mersenne);
		std::uniform_int_distribution damageDie{ enemy.getDamageMin(), enemy.getDamageMax() };
		int damageRoll = damageDie(mersenne);
		if (attackRoll >= (user.getACboost() > user.getAC() ? user.getACboost() : user.getAC()))
		{
			std::cout << '\n' << enemy.getName() << slowPrint{ " hits for " } << damageRoll << slowPrint{ " damage!" };
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			user.takeDamage(damageRoll);
			if (user.getHealth() <= 0)
			{
				std::cout << slowPrint{ "\nYou Have Died..." };
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				user.setDead();
			}
		}
		else
		{
			std::cout << '\n' << enemy.getName() << slowPrint{ " Misses!!" };
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
	else
	{
		std::cout << '\n' << enemy.getName() << slowPrint{ " stands their ground..." };
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		enemy.setACboost();
	}
}

void FightSequence::chooseTurn(std::vector<Enemies*>& enemies, Character& user)
{
	std::uniform_int_distribution initDie{ 1 + ((user.getDexterity() - 10) / 2), 20 + ((user.getDexterity() - 10) / 2) };
	int initRoll = initDie(mersenne);
	user.setTurnOrder(initRoll);
	for (size_t enemy = 0; enemy < enemies.size(); ++enemy)
	{

		std::uniform_int_distribution initDie{ 1 + (enemies[enemy]->getInit()), 20 + (enemies[enemy]->getInit()) };
		int enInRoll = initDie(mersenne);
		enemies[enemy]->setTurnOrder(enInRoll);
	}
	
}

void FightSequence::setMap(std::vector<Enemies*>& enemies, Character& user)
{
	map.createMap();
	std::vector<std::string> tempArr = map.getMap();
	user.setStartMapY(map.getMap().size() - 2);
	user.setStartMapX(map.getMap()[map.getMap().size() - 2].size() / 2);
	for (int enemyIndex{ 0 }; enemyIndex < enemies.size(); enemyIndex++)
	{
		enemies[enemyIndex]->setStartMapY(2);
		enemies[enemyIndex]->setStartMapX(map.getMap()[map.getMap().size() - 2].size() / 2);
		map.setLocation(enemies[enemyIndex]->getMapY(), enemies[enemyIndex]->getMapX(), *enemies[enemyIndex], enemyIndex);
	}
	map.setLocation(user.getMapY(), user.getMapX(), user);
}

void FightSequence::randEncounter(Character& user)
{

}



void FightSequence::setEncounter(std::vector<Enemies*>& enemies, Character& user)
{
	system("cls");
	chooseTurn(enemies, user);
	bool escape = false;
	std::vector<Enemies*> lootEnemies = enemies;
	do
	{
		bool playerWent = false;
		for (int enemy{ 0 }; enemy <= enemies.size(); ++enemy)
		{
			for (int line{ 0 }; line < map.getMap().size(); ++line)
				std::cout << map.getMap()[line] << '\n';
			for (size_t enemyIndex{ 0 }; enemyIndex < enemies.size(); ++enemyIndex)
				std::cout << enemyIndex + 1 << ". " << *enemies[enemyIndex] << '\n';

			std::cout << "\nYour Health: " << user.getHealth() << '/' << user.getHealthMax() << " Stamina: " << user.getStam() << '/' << user.getStamMax() << " Magica: " << user.getMag() << '/' << user.getMagMax();
			
			if (enemy >= enemies.size())
			{
				if (playerWent)
				{
					system("cls");
					break;
				}
				else
					userTurn(enemies, user, escape);
			}
			else if (user.getTurnOrder() > enemies[enemy]->getTurnOrder() && !playerWent)
			{
				userTurn(enemies, user, escape);
				playerWent = true;
				--enemy;
			}
			else if (enemies.empty())
				break;
			else
			{
				enemyTurn(*enemies[enemy], user, enemy);

				if (!user.getIsAlive())
					break;
			}
			system("cls");
		}
	} while (!enemies.empty() && !escape && user.getIsAlive());

	if (!escape && user.getIsAlive())
	{
		std::cout << slowPrint{ "You Have Won!" };
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		system("cls");
		for (size_t enemy = 0; enemy < lootEnemies.size(); enemy++)
		{
			user.setGold(lootEnemies[enemy]->getGold());
			std::cout << slowPrint{ "You have gained " } << lootEnemies[enemy]->getGold() << slowPrint{ " gold!" };
			std::this_thread::sleep_for(std::chrono::milliseconds(750));
			system("cls");
		}
		for (size_t enemy = 0; enemy < lootEnemies.size(); enemy++)
		{
			user.setExp(lootEnemies[enemy]->getLvl() * 15 + lootEnemies[enemy]->getHealth() * 3);
			std::cout << slowPrint{ "You have gained " } << lootEnemies[enemy]->getLvl() * 15 + lootEnemies[enemy]->getHealth() * 3 << slowPrint{ " experience!\n" };
			std::this_thread::sleep_for(std::chrono::milliseconds(750));
			if (user.getExpCurrent() > user.getExpNext())
				std::cout << "\n\t**LEVEL UP**";
			system("cls");
		}
		std::uniform_int_distribution lootDie{ 1 , 100 };
		std::uniform_int_distribution itemAmntDie{ 0 , static_cast<int>(lootEnemies.size() * 3) };
		int itemAmnt = itemAmntDie(mersenne);
		int lootItemArrSize{ 0 };
		for (int lootItem{ 0 }; lootItem < itemAmnt; ++lootItem)
		{
			int lootRoll = lootDie(mersenne);
			if (lootRoll < 35)
				++lootItemArrSize;
		}
		for (int loot{ 0 }; loot <= lootItemArrSize; ++loot)
		{
			int rarity{ 1 };
			int lootRoll = lootDie(mersenne);
			if (lootRoll + ((user.getLuck() - 10)/2) < 0)
				lootRoll = 0;
			else
				lootRoll += ((user.getLuck() - 10)/2);
			if (lootRoll > 20)
			{
				rarity = 1;
				if (lootRoll > 40)
				{
					rarity = 2;
					if (lootRoll > 80)
					{
						rarity = 3;
						if (lootRoll > 90)
						{
							rarity = 4;
							if (lootRoll > 95)
							{
								rarity = 5;
								if (lootRoll > 98)
								{
									rarity = 6;
								}
							}
						}
					}
				}
			}
			lootRoll = lootDie(mersenne);
			if (lootRoll < 60)
				m_loot.push_back(Potions(user.getLvl(), rarity).clone());
			else if (lootRoll >= 60 && lootRoll <= 80)
				m_loot.push_back(Weapon(user.getLvl(), rarity).clone());
			else if (lootRoll > 80)
				m_loot.push_back(Armour(user.getLvl(), rarity).clone());
		}
		int select;
		int numList{ 1 };
		do
		{
			numList = 1;
			for (int loot{ 0 }; loot < m_loot.size(); ++loot)
				std::cout << numList++ << ". " << *m_loot[loot]->clone() << "\n\n";

			std::cout << "\nSelect which loot you want\n Hit 0 to stop adding items to inventory: ";
			std::cin >> select;
			errorHandle(select);
			if (select == 0)
			{
				system("cls");
				break;
			}
			else if (select <= m_loot.size() && select > 0)
			{
				user.addItem(*m_loot[select - 1]);
				m_loot.erase(m_loot.begin() + select - 1);
			}
			else
				std::cout << "Invalid Entry\n";
			system("cls");
		} while (!m_loot.empty() && select != 0);
	}
}