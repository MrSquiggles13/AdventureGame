#include "Character.h"

std::ostream& operator<< (std::ostream& out, const slowPrint& str)
{
	for (const auto& c : str.data)
	{
		out << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(str.delay));
	}
	return out;
}

Character::Character(std::string name,
	int difficulty,
	std::string charClass,
	std::string alignment,
	int lvl,

	int gold,

	int posMain,
	int posSide,

	int AC,
	int damageMin,
	int damageMax,
	int initiative,
	int health,
	int healthMax,
	int stamina,
	int staminaMax,
	int magica,
	int magicaMax,
	int expCurrent,
	int expNext,

	int movement,
	int turnOrder,
	bool isAlive,

	int str,
	int con,
	int dex,
	int wis,
	int intl,
	int chrs,
	int luck,

	int accuracy,
	int appraise,
	int deftness,
	int engineering,
	int espionage,
	int handleAnimals,
	int influence,
	int medicinal,
	int perception,

	int skillPoints,
	int statPoints):

	m_name{ name },
	m_difficulty{ difficulty },
	m_class{ charClass },
	m_alignment{ alignment },
	m_lvl{lvl},

	m_gold{gold},

	m_posMain{ posMain },
	m_posSide{ posSide },

	m_AC { AC },
	m_damageMin {damageMin},
	m_damageMax {damageMax},
	m_initiative {initiative},
	m_health{ health },
	m_healthMax{ healthMax },
	m_stamina{ stamina },
	m_staminaMax{ staminaMax },
	m_magica{ magica },
	m_magicaMax{ magicaMax },
	m_expCurrent { expCurrent },
	m_expNext { expNext = static_cast<int>((50/3)*((pow(m_lvl, 3) - 6*pow(m_lvl,2)) + 17 * m_lvl -12) + 100)  },

	m_movement {movement},
	m_turnOrder{turnOrder},
	m_isAlive {isAlive},

	m_str{ str },
	m_con{ con },
	m_dex{ dex },
	m_wis{ wis },
	m_intl{ intl },
	m_chrs{ chrs },
	m_luck{ luck },

	m_accuracy{ accuracy },
	m_appraise{ appraise },
	m_deftness{ deftness },
	m_engineering{ engineering },
	m_espionage{ espionage },
	m_handleAnimals{ handleAnimals },
	m_influence{ influence },
	m_medicinal{ medicinal },
	m_perception{ perception },

	m_skillPoints{ skillPoints },
	m_statPoints{ statPoints }
	{
		
	}

std::string_view Character::selectCharClass()
{
	int select;
	do
	{
		std::cout << slowPrint{ "Remember to choose wisely...\n" };
		std::cout << slowPrint{ " 1. Warrior\n 2. Hunter\n 3. Thief\n 4. Wizard\n 5. Druid\n 6. Monk\n" };
		std::cout << "Make your selection (1 - 6): ";
		std::cin >> select;

		errorHandle(select);
		
		switch (select)
		{
		case(1):
			return "Warrior";
		case(2):
			return "Hunter";
		case(3):
			return "Thief";
		case(4):
			return "Wizard";
		case(5):
			return "Druid";
		case(6):
			return "Monk";
		default:
			return "Wrong";

		}
	} while (select < 1 && select > 6);
}

bool Character::charDescription(std::string_view userChar)
{
	if (userChar == "Warrior")
	{
		std::cout << slowPrint{ "\n A hardened veteran fighting off the hordes of undead that ravaged the borders of the Empire"
			"\n   Now turned mercenary you fight those that you are paid to slaughter \n Stripped of honor and title you now wander "
			"the plains always searching for the next purse\n   Until one day your Destiny changed forever... \n\n" };
	}
	if (userChar == "Hunter")
	{
		std::cout << slowPrint{ "\n The woods are your home and you have spent your life knowing each tree bush and blade of grass"
			"\n   When you first saw the horde approaching it seemed it was the end\n But you refused to give up your only home and"
			"decided to face this evil head on\n   This would be your path, Your Destiny... \n\n" };
	}
	if (userChar == "Thief")
	{
		std::cout << slowPrint{ "\n Growing up in the heart of the city in poverty you did whatever it took to survive"
			"\n   What seemed like the final job turned into a nightmare\n A horde of undead attacked the city and raided the"
			" dwelling you were robbing\n   You knew then and there Destiny had other plans...\n\n"};
	}
	if (userChar == "Wizard")
	{
		std::cout << slowPrint{ "\n The only solitude you found in life is through the acquisition of knowledge"
			"\n   With no family or place to call home you wander from inn to inn \n You could hear the screams from outside"
			" room and through the window you saw horrors like no other\n   Destiny's call seemed to be for you once more... \n\n" };
	}
	if (userChar == "Druid")
	{
		std::cout << slowPrint{ "\n Nature has always spoke to you in many ways through all forms of life and being"
			"\n   The sounds mostly peaceful sent out a harrowing shriek in unsion that pierced your ears\n When you went to check on"
			" the sacred ground you resided the desemation sent pain through your whole body\n    A faint whisper entered your mind 'Destiny awaits...' \n\n" };
	}
	if (userChar == "Monk")
	{
		std::cout << slowPrint{ "\n Life in the monastery was always that of peace solitude and meditation"
			"\n   As a monk combat was never on your mind yet you have been trained in self-defence\n Out in the fields tending the sheep"
			" you noticed smoke billowing from the monastary\n   It seems your old ways would be changed by Destiny\n\n"};
	}
	if (userChar == "Wrong")
		return false;

	char select;
	do
	{
		std::cout << "Would you like to be a " << userChar << "? [y/n]";
		std::cin >> select;
		errorHandle(select);
		if (select == 'y')
			return true;
		else if (select == 'n')
			return false;
		else
			std::cout << "Invalid Input!\n";
	} while (select != 'y' || select != 'n');

}

void Character::assignCharClass()
{
	bool checkValidChar;
	do
	{
		system("cls");
		m_class = selectCharClass();
		checkValidChar = charDescription(m_class);
	} while (!checkValidChar);
}

void Character::pickCharName()
{
	char select;
	bool validName{ false };
	do
	{
		system("cls");
		std::cout << slowPrint{ "Now tell me what do they call you?: " };
		std::string chooseName;
		getline(std::cin, chooseName);
		m_name = chooseName;
		std::cout << slowPrint{ "So they call you " } << slowPrint{ m_name } << slowPrint{ " is that correct?: [y/n]" };
		std::cin >> select;
		errorHandle(select);
		if (select == 'y')
			validName = true;
		else if (select == 'n')
			validName = false;
		else
			std::cout << "Invalid input!\n";

	} while ((select != 'y' || select != 'n') && !validName);
}

void Character::rollForStats()
{
	system("cls");
	std::array<int, 7> rolls{};
	bool validRoll{ false };
	char select;
	int rollAmount{ 3 };
	int diceIdent{ 1 };
	std::uniform_int_distribution die{ 6, 18 };
	std::cout << slowPrint{ "Now lets roll some dice!!\n Your rolls are from [6 - 18] \nAnd will be assigned to your stats\n" };
	do
	{
		
		if (rollAmount <= 0)
		{
			std::cout << slowPrint{ "You have ran out of rolls!\n" };
			break;
		}
		std::cout << slowPrint{ "\nYou have " } <<  rollAmount << slowPrint{ " rerolls left\n" };
		for (int inc{ 0 }; inc < rolls.size(); ++inc)
			rolls[inc] = die(mersenne);
		for (int inc{ 0 }; inc < rolls.size(); ++inc)
			std::cout << diceIdent++ << ". " << rolls[inc] << "| ";

		std::cout << slowPrint{ "\n Would you like to keep these rolls? [y/n]" };
		std::cin >> select;
		errorHandle(select);
		if (select == 'y')
			validRoll = true;
		else if (select == 'n')
		{
			validRoll = false;
			--rollAmount;
			diceIdent = 1;
		}
		else
			std::cout << "Invalid input!\n";
	} while ((select != 'y' || select != 'n') && !validRoll);
	system("cls");
	assignRolls(rolls);
}

int Character::validateRoll(std::array<int, 7>& rolls)
{
	int selectRoll;
	do
	{
		std::cout << slowPrint{ "\n Pick a dice roll: " };
		std::cin >> selectRoll;
		selectRoll = errorHandle(selectRoll);
		switch (selectRoll)
		{
		case 0:
			std::cout << slowPrint{ "Strength is being able to crush a tomato\n Dexterity is being able to dodge a tomato\n"
				"Constitution is being able to eat a bad tomato\n Intelligence is knowing a tomato is a fruit\n"
				"Wisdowm is knowing not to put a tomato in a fruit salad\n Charisma is being able to sell a tomato-based fruit salad\n"
				"Luck is being able to find gold inside of a tomato\n" };
			selectRoll = -1;
			break;
		case 1:
			selectRoll = rolls[0];
			rolls[0] = -1;
			return selectRoll;
		case 2:
			selectRoll = rolls[1];
			rolls[1] = -1;
			return selectRoll;
		case 3:
			selectRoll = rolls[2];
			rolls[2] = -1;
			return selectRoll;
		case 4:
			selectRoll = rolls[3];
			rolls[3] = -1;
			return selectRoll;
		case 5:
			selectRoll = rolls[4];
			rolls[4] = -1;
			return selectRoll;
		case 6:
			selectRoll = rolls[5];
			rolls[5] = -1;
			return selectRoll;
		case 7:
			selectRoll = rolls[6];
			rolls[6] = -1;
			return selectRoll;
		default:
			std::cout << "Invalid Input";
			selectRoll = -1;
			break;
		}
	} while (selectRoll == -1);
}

void Character::validateStat(int selectRoll, std::array<int, 7>& rolls)
{
	char selectStat;
	do {
		std::cout << slowPrint{ "\nNow pick a stat to assign your dice value to: " };
		std::cin >> selectStat;
		selectStat = errorHandle(selectStat);
		switch (selectStat)
		{
		case '0':
			std::cout << slowPrint{ "Strength is being able to crush a tomato\n Dexterity is being able to dodge a tomato\n"
				"Constitution is being able to eat a bad tomato\n Intelligence is knowing a tomato is a fruit\n"
				"Wisdowm is knowing not to put a tomato in a fruit salad\n Charisma is being able to sell a tomato-based fruit salad\n"
				"Luck is being able to find gold inside of a tomato\n" };
			selectStat = '1';
			break;
		case 'S':
		case 's':
			m_str = selectRoll;
			break;
		case 'D':
		case 'd':
			m_dex = selectRoll;
			break;
		case 'C':
		case 'c':
			m_con = selectRoll;
			break;
		case 'I':
		case 'i':
			m_intl = selectRoll;
			break;
		case 'W':
		case 'w':
			m_wis = selectRoll;
			break;
		case 'H':
		case 'h':
			m_chrs = selectRoll;
			break;
		case 'L':
		case 'l':
			m_luck = selectRoll;
			break;
		default:
			std::cout << "Invalid Entry\n";
			selectStat = '1';
			break;
		}
	} while (selectStat == '1');
}

void Character::assignRolls(std::array<int, 7>& rolls)
{
	char selectClar;
	bool varify;
	std::array <int, 7> tempArray;
	
	do
	{
		tempArray = rolls;
		
		for (int numOfSelect{ 1 }; numOfSelect <= 7; ++numOfSelect)
		{
			int diceIdent{ 1 };
			int inc{ 0 };
			std::cout << "[S]trength:"  << m_str << "\t\t" << diceIdent++ << ". " << tempArray[inc++] << "| \n" <<  " [D]exterity:"  << m_dex 
				<< "\t\t" << diceIdent++ << ". " << tempArray[inc++] << "| \n" <<  "[C]onstitution:"  << m_con
				<< "\t" << diceIdent++ << ". " << tempArray[inc++] << "| \n" <<  " [I]ntelligence:" << m_intl << "\t" << diceIdent++ << ". " << tempArray[inc++] << "| \n"
				<<  "[W]isdom:"  << m_wis << "\t\t" << diceIdent++ << ". " << tempArray[inc++] << "| \n" <<  " C[h]arisma:"  << m_chrs 
				<< "\t\t" << diceIdent++ << ". " << tempArray[inc++] << "| \n" << "[L]uck:" << m_luck << "\t\t" << diceIdent++ << ". " << tempArray[inc++] << "| \n";
			if (numOfSelect == 1)
					std::cout << slowPrint{ "\n Please assign your stats\n"
				"To assign stats first select dice roll order number \n Then the letter that corresponds to a stat\n"
				"For stat explanation enter 0\n" };
			else
				std::cout << "\n Please assign your stats\n"
				"To assign stats first select dice roll order number \n Then the letter that corresponds to a stat\n"
				"For stat explanation enter 0\n" ;

			int selectRoll;
			selectRoll = validateRoll(tempArray);
			validateStat(selectRoll, tempArray);
			
			
			system("cls");
		}
		std::cout << slowPrint{ "Are you okay with your stat selection?\n" };
		std::cout << slowPrint{ "\n Strength: " } << m_str << slowPrint{ "\n Dexterity: " } << m_dex << slowPrint{ "\n Constitution: " } << m_con << slowPrint{ "\n Intelligence: " } << m_intl
			<< slowPrint{ "\n Wisdom: " } << m_wis << slowPrint{ "\n Charisma: " } << m_chrs << slowPrint{ "\n Luck: " } << m_luck;
		std::cout << "\n\nSelect [y/n]";
		
		std::cin >> selectClar;
		errorHandle(selectClar);
		if (selectClar == 'y')
			varify = true;
		else if (selectClar == 'n')
			varify = false;
		else
			std::cout << "Invalid input!\n";
		system("cls");
	} while ((selectClar == 'y' || selectClar == 'n') && !varify);
}

void Character::alignment()
{
	int alignmentScore{ 0 };
	std::cout << slowPrint{ "\nNow to see where your morale compass points, just a few questions...\n" };
	std::cout << "\n\t\t|----------Press Any Key To Continue----------|\n";
	_getch();
	int choice;
		do
		{
			system("cls");
			std::cout << slowPrint{"\nIf you were to see a coin purse on the side of the road would you : \n 1. Pick it up and keep it\n 2. Keep some of it and put it back\n 3. Try to find the owner\n 4. Give to your local orphanage\nSelect[1 / 2 / 3 / 4]: " };
			std::cin >> choice;
			errorHandle(choice);
			switch (choice)
			{
			case 1:
				alignmentScore -= 2;
				break;
			case 2:
				alignmentScore -= 1;
				break;
			case 3:
				alignmentScore += 2;
				break;
			case 4:
				alignmentScore += 1;
				break;
			default:
				std::cout << "Invalid Choice";
				break;
			}
		} while (choice > 4 || choice < 1);

		do
		{
			system("cls");
			std::cout << slowPrint{ "\nSay you saw a dying man on the ground what would you do?: \n 1. Pick him up and carry him to get help \n 2. Wait with him whilst he dies\n 3. Give him a merciful death\n 4. Rob him blind and spit on his face\nSelect [1/2/3/4]: " };
			std::cin >> choice;
			errorHandle(choice);
			switch (choice)
			{
			case 1:
				alignmentScore += 2;
				break;
			case 2:
				alignmentScore += 1;
				break;
			case 3:
				alignmentScore -= 1;
				break;
			case 4:
				alignmentScore -= 2;
				break;
			default:
				std::cout << "Invalid Choice";
				break;
			}
		} while (choice > 4 || choice < 1);

		do {
			system("cls");
			std::cout << slowPrint{ "\nA monster lives in a cave and the townsfolk hire you to kill the beast\n When you get to the cave you find the beast is sentient even friendly\nWhat is the creatures fate?: \n 1. Return to the townsfolk and try to convince them to spare the creature\n"
				" 2. Slay the beast without mercy \n 3. Try to befriend the creature \n 4. Capture the beast and return to the town\nSelect [1/2/3/4]: " };
			std::cin >> choice;
			errorHandle(choice);
			switch (choice)
			{
			case 1:
				alignmentScore += 1;
				break;
			case 2:
				alignmentScore -= 2;
				break;
			case 3:
				alignmentScore += 2;
				break;
			case 4:
				alignmentScore -= 1;
				break;
			default:
				std::cout << "Invalid Choice";
				break;
			}
		} while (choice > 4 || choice < 1);

		do {
			system("cls");
			std::cout << slowPrint{ "\nThe town you are staying at is being attacked and the invading forces are inside the walls do you: \n 1. Start looting the local stores... they're busy\n 2. Gather the women and children and help them escape or defend them\n"
				" 3. Help the local guard defend the town\n 4. Join the attacking force in the pillaging\nSelect [1/2/3/4]: " };
			std::cin >> choice;
			errorHandle(choice);
			switch (choice)
			{
			case 1:
				alignmentScore -= 1;
				break;
			case 2:
				alignmentScore += 2;
				break;
			case 3:
				alignmentScore += 1;
				break;
			case 4:
				alignmentScore -= 2;
				break;
			default:
				std::cout << "Invalid Choice";
				break;
			}
		} while (choice > 4 || choice < 1);

		do {
			system("cls");
			std::cout << slowPrint{ "\nAn orphan beggar comes up to you begging for what small scraps you can spare what do you do?: \n 1. Push the kid to the ground and laugh at her pain\n 2. Go to put coin in her cup and actaully slyly steal some of her own\n 3. Without stopping flip a coin at the girl \n"
				" 4. Bend down and put a hefty sum in the girl's cup while offering to put her up for the night at the local inn\nSelect [1/2/3/4]: " };
			std::cin >> choice;
			errorHandle(choice);
			switch (choice)
			{
			case 1:
				alignmentScore -= 2;
				break;
			case 2:
				alignmentScore -= 1;
				break;
			case 3:
				alignmentScore += 1;
				break;
			case 4:
				alignmentScore += 2;
				break;
			}
		} while (choice > 4 || choice < 1);
		system("cls");
	if (alignmentScore > 8)
	{
		m_alignment = "Lawful Good";
		std::cout << slowPrint{ "\nThe law is your life and all that is good guides your path and hand\n Though wrongdoing maybe tempting to some you could never conceive of it\nRighteousness is all you know and is all you ever live for" };
	}
	if (alignmentScore <= 8 && alignmentScore > 6)
	{
		m_alignment = "Neutral Good";
		std::cout << slowPrint{ "\nAlthough you may never hurt a nonthreatening creature you would be hesitant to help a helpless one either\n Your own kin maybe excluded from that but you are very wary of those outside your circle\nSome may call you selfish but you know the good in your heart is reserved for those closest to you" };
	}
	if (alignmentScore <= 6 && alignmentScore > 3)
	{
		m_alignment = "Chaotic Good";
		std::cout << slowPrint{ "\nResults are what matter to you most and you make sure to get things done\n Your tactics maybe unorthodox but it is always with the purest intentions to benefit good\nSometimes those same intentions might do more harm than good in certain situations" };
	}
	if (alignmentScore <= 3 && alignmentScore > 0)
	{
		m_alignment = "Lawful Neutral";
		std::cout << slowPrint{ "\nThe only thing that matters to you is structure order and law\n No matter the situation whatever structure in place says goes under any circumstance\nYou vow to uphold this creed through life and limb and appose all those that stand against it" };
	}
	if (alignmentScore == 0)
	{
		m_alignment = "True Neutral";
		std::cout << slowPrint{ "\nYou are truly impartial to every situation that you experience\n The balance of good and eveil right and wrong is weighed carefully in every situation\nOnly that which is purely logical and the most beneficial will win out every time" };
	}
	if (alignmentScore < 0 && alignmentScore >= -3)
	{
		m_alignment = "Chaotic Neutral";
		std::cout << slowPrint{ "\nThere is only you and fuck everyone else\n if it will lean towards your favor or benefit you will act on it\nOnly thing that matters in your life is how you will prosper and succeed" };
	}
	if (alignmentScore < -3 && alignmentScore >= -6)
	{
		m_alignment = "Lawful Evil";
		std::cout << slowPrint{ "\nThe world is just full of things waiting to be yours\n A strong regime and carefully crafter malice will bring you all that you desire\nYou will bring down all that stand in your way" };
	}
	if (alignmentScore < -6 && alignmentScore >= -8)
	{
		m_alignment = "Neutral Evil";
		std::cout << slowPrint{ "\nLife is full of wicked deeds wainting to be done\n As long as you bring a little torment and despair your calling is fulfilled\nYou just wish to bring others to ruin" };
	}
	if (alignmentScore < -8)
	{
		m_alignment = "Chaotic Evil";
		std::cout << slowPrint{ "\nChaos rules your life there is only darkness and hate\n If it breathes kill it if it is not yours steal it if it stands tear it down\nYou just want to watch the world burn" };
	}
	std::cout << slowPrint{ "\n\n\t\t=*You are " } << slowPrint{ m_alignment } << "*=\n";
	std::cout << "\n\t\t|----------Press Any Key To Continue----------|\n";
	_getch();
}

void Character::difficulty()
{
	bool validateDiff{ false };
	char choice;
	int select;
	do {
		do {
			system("cls");
			std::cout << slowPrint{ "Choose Your Difficulty" };
			std::cout << slowPrint{ "\n 1. I'm Too Young to Die - Easy\n 2. Hurt Me Plenty - Normal\n 3. Ultra-Violence - Hard\n 4. Nightmare - Very Hard\n Select[1/2/3/4]: " };
			std::cin >> select;
			errorHandle(select);
			switch (select)
			{
			case 1:
				m_difficulty = 1;
				break;
			case 2:
				m_difficulty = 2;
				break;
			case 3:
				m_difficulty = 3;
				break;
			case 4:
				m_difficulty = 4;
				break;
			default:
				std::cout << "invalid Choice";
				break;
			}

		} while (select > 4 || select < 1);
		std::cout << slowPrint{ "\nDo you want it on " } << slowPrint{ printDiff(m_difficulty) } << slowPrint{ " difficulty?: [y/n]" };
		std::cin >> choice;
		errorHandle(choice);
		if (choice == 'y')
			validateDiff = true;
		else if (choice == 'n')
			validateDiff = false;
		else
			std::cout << "Invalid Input!\n";
	} while (!validateDiff);

}

void Character::setBoosts()
{
	if (m_class == "Warrior")
	{m_str += 2; m_con += 1; m_intl -= 1; m_deftness += 2; m_accuracy += 2; m_influence += 2;}
	if (m_class == "Hunter")
	{ m_dex += 2; m_con += 1; m_wis -= 1; m_handleAnimals += 2; m_accuracy += 2; m_perception += 2;}
	if (m_class == "Thief")
	{ m_luck += 2; m_dex += 1; m_con -= 1; m_deftness += 2; m_espionage += 2; m_perception += 2;}
	if (m_class == "Wizard")
	{ m_intl += 2; m_wis += 1;m_str -= 1;  m_appraise += 2; m_medicinal += 2; m_engineering += 2;}
	if (m_class == "Druid")
	{ m_wis += 2;m_str += 1; m_dex -= 1;  m_deftness += 2; m_handleAnimals += 2; m_perception += 2;}
	if (m_class == "Monk")
	{ m_dex += 2; m_wis += 1; m_chrs -= 1;  m_deftness += 2; m_accuracy += 2; m_perception += 2;}

	if (m_alignment == "Lawful Good")
	{ m_chrs += 1;  m_con += 1;}
	if (m_alignment == "Neutral Good")
	{ m_wis += 1; m_luck += 1;}
	if (m_alignment == "Chaotic Good")
	{ m_dex += 1;m_chrs += 1;}
	if (m_alignment == "Lawful Neutral")
	{ m_wis += 1; m_con += 1;}
	if (m_alignment == "True Neutral")
	{ m_wis += 1;  m_intl += 1;}
	if (m_alignment == "Chaotic Neutral")
	{ m_dex += 1; m_luck += 1;}
	if (m_alignment == "Lawful Evil")
	{m_chrs += 1; m_str += 1;}
	if (m_alignment == "Neutral Evil")
	{ m_intl += 1; m_dex += 1;}
	if (m_alignment == "Chaotic Evil")
	{m_str += 1; m_con += 1;}

	m_AC += (m_dex / 2);
	m_initiative += (m_dex / 2);
	m_healthMax += (m_con / 2);
	m_magicaMax += (m_intl / 2);
	m_staminaMax += (m_dex / 2);
	m_health = m_healthMax;
	m_magica = m_magicaMax;
	m_stamina = m_staminaMax;
	if (((m_dex - 10) / 2) > 0)
		m_movement += ((m_dex - 10) / 2);
	m_inv.setBulk(m_str);
	m_accuracy += (m_dex - 10) / 2;
	m_appraise += (m_wis - 10) / 2;
	m_deftness += (m_str - 10) / 2;
	m_engineering += (m_intl - 10) / 2;
	m_espionage += (m_dex - 10) / 2;
	m_handleAnimals += (m_chrs - 10) / 2;
	m_influence += (m_chrs - 10) / 2;
	m_medicinal += (m_intl - 10) / 2;
	m_perception += (m_wis - 10) / 2;
}

void Character::addEquipment()
{
	m_wep = { "Dark Blade", "Dagger", 1, 50, 10, 0, 2, 4 };
	equipWeapon(m_wep);
	m_arm = { "Basic Cloth", "Chest", 1, 15, 3, 0, 0 };
	equipArmour(m_arm);
	m_inv.addItem(Potions("HP pot", "Health Potion", 1, 50, 10, 0, 0, 4, 0, 0));
}

void Character::printStats()
{
	system("cls");
	std::cout << "\n\tStats for " << m_name << " a level " << m_lvl << ' ' << m_class << "\nStrength:" << m_str << "\t Health: " << m_health << '/' << m_healthMax << "\nDexterity:" << m_dex
		<< "\t Stamina: " << m_stamina << '/' << m_staminaMax << "\nConstitution:" << m_con << "\t Magica: " << m_magica << '/' << m_magicaMax << "\nIntelligence:" << m_intl
		<< "\t Armour Class: " << m_AC << "\nWisdom:" << m_wis << "\t Current Exp: " << m_expCurrent << "\nCharisma:" << m_chrs << "\t Exp until next level: " << m_expNext
		<< "\nLuck:" << m_luck << "\t\t Alignment: " << m_alignment << "\n\nSkills: " "\nAccuracy:" << m_accuracy << "\t\tAppraise:" << m_appraise
		<< "\nDeftness:" << m_deftness << "\t\tEngineering:" << m_engineering
		<< "\nEspionage:" << m_espionage << "\t\tHandle Animal:" << m_handleAnimals
		<< "\nInfluence:" << m_influence << "\t\tMedicinal:" << m_medicinal
		<< "\nPerception:" << m_perception;
	std::cout << "\n\nHit any key to return to menu: "; _getch();
}

void Character::manageInv()
{
	system("cls");
	std::vector<Item*> itemArr;
	Armour* NewArm{ &Armour() };
	Weapon* NewWep{ &Weapon() };
	Potions* NewPotion{ &Potions() };
	Item* NewItem;
	int choice;
	do {
		itemArr = getItemArr();
		std::cout << "Items in inventory: \n";
		int selectItm;
		printInvList();

		std::cout << "\nWould you like to:\n 0. Return to Menu\n 1. Remove Item\n 2. Item Description\n 3. Equipped Items\n 4. Use Item \nChoose [0-3]: ";
		std::cin >> choice;
		errorHandle(choice);
		switch (choice)
		{
		default:
			std::cout << "Invalid Input";
			system("cls");
			break;
		case 0:
			break;
		case 4:
			std::cout << "\n Select item you would like to use: ";
			std::cin >> selectItm;
			errorHandle(selectItm);
			NewPotion = dynamic_cast<Potions*>(itemArr[selectItm - 1]->clone());
			if (NewPotion != nullptr)
			{
				if (NewPotion->getType() == "Damage")
					std::cout << "Be careful you do not want to drink that...";
				else if (NewPotion->getType() == "Escape")
					std::cout << "Where you runnin off to bud?";
				else
				{
					if (NewPotion->getName().find("Max") != std::string::npos)
					{
						m_healthMax += NewPotion->getHpMod();
						m_staminaMax += NewPotion->getStamMod();
						m_magicaMax += NewPotion->getMagMod();
					}
					m_health += NewPotion->getHpMod();
					m_stamina += NewPotion->getStamMod();
					m_magica += NewPotion->getMagMod();
					m_statPoints += NewPotion->getStatMod();


					if (m_health > m_healthMax || (NewPotion->getType() == "Health" && NewPotion->getHpMod() == 0))
						m_health = m_healthMax;
					if (m_stamina > m_staminaMax || (NewPotion->getType() == "Stamina" && NewPotion->getStamMod() == 0))
						m_stamina = m_staminaMax;
					if (m_magica > m_magicaMax || (NewPotion->getType() == "Magica" && NewPotion->getMagMod() == 0))
						m_magica = m_magicaMax;

					removeItem(selectItm);
				}
			}
			else
				std::cout << "Not a usable item";
			system("cls");
			break;
		case 1:
			std::cout << "\n Select item you would like to remove: ";
			std::cin >> selectItm;
			errorHandle(selectItm);
			removeItem(selectItm);
			system("cls");
			break;
		case 2:
			std::cout << "\n Select item you would like to view: ";
			std::cin >> selectItm;
			errorHandle(selectItm);
			viewItem(selectItm);
			std::cout << "\n\nHit any key to return back to Inventory: ";
			_getch();
			system("cls");
			break;
		case 3:
			int selectEquip;
			do {
				itemArr = getItemArr();
				system("cls");
				std::cout << "Items in inventory: \n";
				printInvList();
				std::cout << "\nItems Equipped: \n" << "1. " << m_wep.getName() << '\n' << "2. " << m_arm.getName();
				std::cout << "\nWould you like to: \n 0. Return to Inventory\n 1. Equip Item\n 2. Unequip Item\n 3. View Equipped";
				std::cout << "\n\n Choose [0-3]: ";
				std::cin >> selectEquip;
				errorHandle(selectEquip);
				switch (selectEquip)
				{
				case 0: //Return
					system("cls");
					break;
				case 1: //Equip
					std::cout << "Which item would you like to Equip?\n Choose an item from inventory: ";
					std::cin >> selectItm;
					errorHandle(selectItm);
					NewWep = dynamic_cast<Weapon*>(itemArr[selectItm - 1]->clone());
					if (NewWep != nullptr)
					{
						if (m_wep.getName() != "")
							addItem(m_wep);
						equipWeapon(*NewWep);
						removeItem(selectItm);
						delete NewWep;
						NewWep = nullptr;
					}
					NewArm = dynamic_cast<Armour*>(itemArr[selectItm - 1]->clone());
					if (NewArm != nullptr)
					{
						if (m_arm.getName() != "")
							addItem(m_arm);
						equipArmour(*NewArm);
						removeItem(selectItm);
						delete NewArm;
						NewArm = nullptr;
					}
					break;
				case 2: //Unequip
					std::cout << "Which item would you like to unequip?\n Choose [1.Weapon, 2.Armour]: ";
					std::cin >> selectEquip;
					errorHandle(selectEquip);
					if (selectEquip == 1)
					{
						NewItem = m_wep.clone();
						addItem(*NewItem); equipWeapon({ "", "", 0, 0, 0, 0, 0, 0 });
					}
					if (selectEquip == 2)
					{
						NewItem = m_arm.clone();
						m_inv.addItem(*NewItem); equipArmour({ "", "", 0, 0, 0, 0, 0 });
					}
					break;
				case 3://View Item
					std::cout << "\nWhich item would you like to view?\n Choose [1.Wepon or 2.Armour]: ";
					std::cin >> selectEquip;
					errorHandle(selectEquip);
					if (selectEquip == 1)
						std::cout << *m_wep.clone();
					else if (selectEquip == 2)
						std::cout << *m_arm.clone();
					else
						std::cout << "Invalid Selection";
					std::cout << "\nPress any key to continue: ";
					_getch();
					break;
				default:
					std::cout << "Invalid Input";
					system("cls");
					break;
				}
			} while (selectEquip != 0);
			break;
		}
	} while (choice != 0);
}

void Character::lvlUp()
{
	if (m_expCurrent >= m_expNext)
	{
		m_expCurrent -= m_expNext;
		m_lvl++;
		m_expNext = static_cast<int>((50 / 3) * ((pow(m_lvl, 3) - 6 * pow(m_lvl, 2)) + 17 * m_lvl - 12) + 100);
		m_statPoints += 3;
		m_skillPoints += 7 + ((m_wis - 10)/2);
		m_healthMax += m_con / 2;
		m_magicaMax += m_intl / 4;
		m_staminaMax += m_dex / 4;
	}
	system("cls");
	char select;
	int tempStatpoints;
	char selectClar;
	bool varify;
	if (m_statPoints > 0)
	{
		do
		{
			tempStatpoints = m_statPoints;
			int tempStr{ m_str }; int tempDex{ m_dex }; int tempCon{ m_con }; int tempInt{ m_intl };
			int tempWis{ m_wis }; int tempChar{ m_chrs }; int tempLuck{ m_luck };
			do
			{

				std::cout << "\n[S]trength:" << tempStr << "\n [D]exterity:" << tempDex
					<< "\n[C]onstitution:" << tempCon << "\n [I]ntelligence:" << tempInt
					<< "\n[W]isdom:" << tempWis << "\n C[h]arisma:" << tempChar
					<< "\n[L]uck:" << tempLuck << "\t\tStat Points Left to Spend: " << tempStatpoints;
				if (m_lvl == 2 && tempStatpoints == m_statPoints)
					std::cout << slowPrint{ "\n\n Please assign your stats\n"
					"Select letter that corresponds to a stat\n"
					"For stat explanation enter 0 to not assign points enter Q\n"
					"Enter the stat you want to upgrade: " };
				else
					std::cout << "\n\n Please assign your stats\n"
					"Select letter that corresponds to a stat\n"
					"For stat explanation enter 0 to not assign points enter Q\n"
					"Enter the stat you want to upgrade: ";
				std::cin >> select;
				errorHandle(select);
				switch (select)
				{
				case '0':
					system("cls");
					std::cout << slowPrint{ "Strength is being able to crush a tomato\n Dexterity is being able to dodge a tomato\n"
						"Constitution is being able to eat a bad tomato\n Intelligence is knowing a tomato is a fruit\n"
						"Wisdowm is knowing not to put a tomato in a fruit salad\n Charisma is being able to sell a tomato-based fruit salad\n"
						"Luck is being able to find gold inside of a tomato\n" };
					std::cout << "\n\t\t|----------Press Any Key To Continue----------|\n";
					_getch();
					break;
				case 'S':
				case 's':
					tempStr += 1;
					tempStatpoints -= 1;
					break;
				case 'D':
				case 'd':
					tempDex += 1;
					tempStatpoints -= 1;
					break;
				case 'C':
				case 'c':
					tempCon += 1;
					tempStatpoints -= 1;
					break;
				case 'I':
				case 'i':
					tempInt += 1;
					tempStatpoints -= 1;
					break;
				case 'W':
				case 'w':
					tempWis += 1;
					tempStatpoints -= 1;
					break;
				case 'H':
				case 'h':
					tempChar += 1;
					tempStatpoints -= 1;
					break;
				case 'L':
				case 'l':
					tempLuck += 1;
					tempStatpoints -= 1;
					break;
				default:
					select = '1';
					break;
				}
				system("cls");
			} while (tempStatpoints != 0 && select != '1');
			std::cout << slowPrint{ "Are you okay with your stat selection?\n" };
			std::cout << slowPrint{ "\n Strength: " } << tempStr << slowPrint{ "\n Dexterity: " } << tempDex << slowPrint{ "\n Constitution: " } << tempCon << slowPrint{ "\n Intelligence: " } << tempInt
				<< slowPrint{ "\n Wisdom: " } << tempWis << slowPrint{ "\n Charisma: " } << tempChar << slowPrint{ "\n Luck: " } << tempLuck;
			std::cout << "\n\nSelect [y/n]";

			std::cin >> selectClar;
			errorHandle(selectClar);
			if (selectClar == 'y')
			{
				m_initiative -= (m_dex / 2);
				m_movement -= (m_dex / 2);
				m_initiative += (tempDex / 2);
				m_movement += (tempDex / 2);
				m_health = m_healthMax;
				m_magica = m_magicaMax;
				m_stamina = m_staminaMax;
				varify = true;
				m_accuracy -= (m_dex - 10) / 2;
				m_appraise -= (m_wis - 10) / 2;
				m_deftness -= (m_str - 10) / 2;
				m_engineering -= (m_intl - 10) / 2;
				m_espionage -= (m_dex - 10) / 2;
				m_handleAnimals -= (m_chrs - 10) / 2;
				m_influence -= (m_chrs - 10) / 2;
				m_medicinal -= (m_intl - 10) / 2;
				m_perception -= (m_wis - 10) / 2;
				m_str = tempStr; m_dex = tempDex; m_con = tempCon; m_intl = tempInt;
				m_wis = tempWis; m_chrs = tempChar; m_luck = tempLuck; m_statPoints = tempStatpoints;
				m_accuracy += (m_dex - 10) / 2;
				m_appraise += (m_wis - 10) / 2;
				m_deftness += (m_str - 10) / 2;
				m_engineering += (m_intl - 10) / 2;
				m_espionage += (m_dex - 10) / 2;
				m_handleAnimals += (m_chrs - 10) / 2;
				m_influence += (m_chrs - 10) / 2;
				m_medicinal += (m_intl - 10) / 2;
				m_perception += (m_wis - 10) / 2;
				m_inv.setBulk(m_str);
				equipArmour(m_arm);
				equipWeapon(m_wep);
			}
			else if (selectClar == 'n')
				varify = false;
			else
			{
				std::cout << "Invalid input!\n";
				varify = false;
			}
			system("cls");
		} while ((selectClar == 'y' || selectClar == 'n') && !varify);
	}
	int selectSkill;
	int tempSkillPoints;
	if (m_skillPoints > 0)
	{
		do
		{
			tempSkillPoints = m_skillPoints;
			int tempAccuracy{ m_accuracy }; int tempAppraise{ m_appraise }; int tempDeftness{ m_deftness }; 
			int tempEngineering{ m_engineering };int tempEspionage{ m_espionage }; int tempHandleAnimals{ m_handleAnimals }; 
			int tempInfluence{ m_influence }; int tempMedicinal{ m_medicinal };int tempPerception{ m_perception };
			do
			{

				std::cout << "\n1.Accuracy:" << tempAccuracy << "\t\t2.Appraise:" << tempAppraise
					<< "\n3.Deftness:" << tempDeftness << "\t\t4.Engineering:" << tempEngineering
					<< "\n5.Espionage:" << tempEspionage << "\t\t6.Handle Animal:" << tempHandleAnimals
					<< "\n7.Influence:" << tempInfluence << "\t\t8.Medicinal:" << tempMedicinal 
					<< "\n9.Perception:" << tempPerception << "\t\tSkill Points Left to Spend: " << tempSkillPoints;
				if (m_lvl == 2 && tempSkillPoints == m_skillPoints)
					std::cout << slowPrint{ "\n\n Now you get to assign some skills!\n"
					"Here is a breakdown of each skill...\n\n"
					"Accuracy: how often you can hit\n"
					"Appraise: used to determine an items worth and properties\n"
					"Deftness: how well you can move your body\n"
					"Engineering: being able to craft and create items\n"
					"Espionage: stealth disguise etc anything a spy could do\n"
					"Handle Animal: how well you can tame and ride creatures\n"
					"Influence: how well you can interact with people\n"
					"Medicinal: being able to bandge and stitch up wounds\n"
					"Perception: being aware of one surroundings\n\n"
					"Choose the number that corresponds to the skill you want to upgrade\n"
					"To not assign points enter Q\n"
					"Enter the stat you want to upgrade: " };
				else
					std::cout << "\n\n Please assign your skills\n"
					"Select the number that corresponds to a skill\n"
					"for skill explanation enter 0 to not assign points enter Q\n"
					"Enter the stat you want to upgrade: ";
				std::cin >> selectSkill;
				selectSkill = errorHandle(selectSkill);
				switch (selectSkill)
				{
				case 0:
					std::cout << slowPrint{ "Accuracy: how often you can hit\n"
					"Appraise: used to determine an items worth and properties\n"
					"Deftness: how well you can move your body\n"
					"Engineering: being able to craft and create items\n"
					"Espionage: stealth disguise etc anything a spy coulld do\n"
					"Handle Animal: how well you can tame and ride creatures\n"
					"Influence: how well you can interact with people\n"
					"Medicinal: being able to bandge and stitch up wounds\n"
					"Perception: being aware of one surroundings\n" };
					break;
				case 1:
					tempAccuracy += 1;
					tempSkillPoints -= 1;
					break;
				case 2:
					tempAppraise += 1;
					tempSkillPoints -= 1;
					break;
				case 3:
					tempDeftness += 1;
					tempSkillPoints -= 1;
					break;
				case 4:
					tempEngineering += 1;
					tempSkillPoints -= 1;
					break;
				case 5:
					tempEspionage += 1;
					tempSkillPoints -= 1;
					break;
				case 6:
					tempHandleAnimals += 1;
					tempSkillPoints -= 1;
					break;
				case 7:
					tempInfluence += 1;
					tempSkillPoints -= 1;
					break;
				case 8:
					tempMedicinal += 1;
					tempSkillPoints -= 1;
					break;
				case 9:
					tempPerception += 1;
					tempSkillPoints -= 1;
					break;
				default:
					select = -1;
					break;
				}
				system("cls");
			} while (tempSkillPoints != 0 && selectSkill != -1);
			std::cout << slowPrint{ "Are you okay with your skill selection?\n" };
			std::cout << slowPrint{ "\n Accuracy: " } << tempAccuracy << slowPrint{ "\n Appraise: " } << tempAppraise << slowPrint{ "\n Deftness: " } << tempDeftness 
				<< slowPrint{ "\n Engineering: " } << tempEngineering << slowPrint{ "\n Espionage: " } << tempEspionage << slowPrint{ "\n Handle Animal: " } << tempHandleAnimals 
				<< slowPrint{ "\n Influence: " } << tempInfluence << slowPrint{ "\n Medicinal: " } << tempMedicinal << slowPrint{ "\n Perception: " } << tempPerception;
			std::cout << "\n\nSelect [y/n]";

			std::cin >> selectClar;
			errorHandle(selectClar);
			if (selectClar == 'y')
			{
				varify = true;
				m_accuracy = tempAccuracy; m_appraise = tempAppraise; m_deftness = tempDeftness;
				m_engineering = tempEngineering; m_espionage = tempEspionage; m_handleAnimals = tempHandleAnimals;
				m_influence = tempInfluence; m_medicinal = tempMedicinal; m_perception = tempPerception; m_skillPoints = tempSkillPoints;
			}
			else if (selectClar == 'n')
				varify = false;
			else
			{
				std::cout << "Invalid input!\n";
				varify = false;
			}
			system("cls");
		} while ((selectClar == 'y' || selectClar == 'n') && !varify);
	}
	int selectSpell;
	std::vector<Spells*> tempSpellList;
	tempSpellList.reserve(2);
	do
	{
		for (int spell1{0}; spell1 < Spells::level1.size(); ++spell1)
			tempSpellList.push_back(Spells::level1[spell1]);

		for (int spells{0}; spells < tempSpellList.size(); ++spells)
		{
			std::cout << spells << ": " << *tempSpellList[spells] << '\n';
		}
		std::cout << "Select a spell to add to your spell book";
		std::cin >> selectSpell;
		errorHandle(selectSpell);
		std::cout << "Do you want to add " << tempSpellList[selectSpell]->getName() << " to your spell book?\n Select[y/n]";
		std::cin >> selectClar;
		if (selectClar == 'y')
		{
			varify = true;
			addSpell(*tempSpellList[selectSpell]);
		}
		else if (selectClar == 'n')
			varify = false;
		else
		{
			std::cout << "\n\nInvalid Input";
			varify = false;
		}
	} while (!varify);

}

void Character::addSpell(Spells& spell)
{
	m_spellBook.push_back(spell.spellClone());
}

Character::~Character()
{

}
