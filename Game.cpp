#include "Game.h"

Game::Game(bool playing, int difficulty) : m_playing{ playing }, m_difficulty{difficulty}
{
	/*std::cout <<
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"_____________________________________________________\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"_______________________/\\___________________________\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                       /\\                           \n"
		"______________________/ww\\__________________________\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                          \n"
		"_____________________/____\\____________/\\__________\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"____________________/wwwwww\\__________/__\\_________\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"______/\\___________/________\\________/wwww\\_______\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"_____/ww\\_________/__________\\______/______\\______\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                                                     \n"
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"____/____\\_______/____________\\ ___/________\\_____\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"___/______\\_____/______________\\__/__________\\____\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		" ><                   /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"     ><               /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"        ><            /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"             ><       /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                 ><   /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                   >< /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\ ><                       \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\   ><                     \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\      ><                  \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\           ><             \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\              ><          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                 ><       \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                      ><  \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                        ><\n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
	std::cout <<
		"                                                     \n"
		"                       /\\                           \n"
		"                      /ww\\                          \n"
		"                     /    \\            /\\          \n"
		"                    /wwwwww\\          /  \\         \n"
		"      /\\           /        \\        /wwww\\       \n"
		"     /ww\\         /          \\      /      \\      \n"
		"    /    \\       /            \\    /        \\     \n"
		"   /      \\     /              \\  /          \\    \n"
		"__/________\\___/________________\\/____________\\___\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	system("cls");
    std::cout << slowPrint{ "\t\t\tWelcome to Morph!\n   The text based role-playing game inspired by Pathfinder\n\n"
            " A long adventure awaits you...\n\nSo please choose your Path wisely\n" };
    std::cout << "\n\t\t|----------Press Any Key To Continue----------|\n";
    _getch();*/
}

void Game::createChar()
{
	user.assignCharClass();
	user.pickCharName();
	user.rollForStats();
	user.alignment();
	user.difficulty();
	setDifficulty();
	user.setBoosts();
	user.addEquipment();
}

void Game::mainMenu()
{

	system("cls");
	std::cout << slowPrint{ "\t\t\t###Main Menu###" };
	std::cout << slowPrint{ "\n\n 1.Start New Game" };
	std::cout << slowPrint{ "\t\t\t 2.Load Game" };
	std::cout << "\n\nChoose [1/2]: ";
	int select;
	std::cin >> select;
	errorHandle(select);
	if (select == 1)
		createChar();
	else if (select == 2)
	{}
	else
		std::cout << "Invalid Input";

}

void Game::charMenu()
{
	
	int choice;
	do {
		system("cls");
		std::cout << "\t\t\t***Character Menu***";
		if (user.getExpCurrent() > user.getExpNext())
			std::cout << "\n**LEVEL UP AVAILABLE**";
		std::cout << "\n 0. To Return to Game\n 1. Start New Game\n 2. Save Game\n 3. Load Game\n 4. Character Stats\n 5. Inventory\n 6. Level Up\n 7. Quit Game";
		std::cout << slowPrint{ "\n\nSelect an option[1-7]: " };
		std::cin >> choice;
		errorHandle(choice);
		switch (choice)
		{
		case 0:
			system("cls");
			break;
		case 1:
			mainMenu();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			user.printStats();
			break;
		case 5:
			user.manageInv();
			break;
		case 6:
			user.lvlUp();
			break;
		case 7:
			exit(0);
			break;
		default:
			std::cout << "Invalid";
			break;
		}
	} while (choice != 0 && choice != 7);
}

void Game::startJourney()
{
	user.setPosMain();
	system("cls");
	std::vector<Enemies*> enemyArr;
	Enemies en1 = { "Goran", "Human", 1, 50, 10, 10, 10, 3, 1, 3};
	Enemies en2 = { "Truel", "Elf", 1, 50, 10, 10, 10, 3, 1, 3};
	Enemies en3 = { "Benst", "Human", 1, 50, 10, 10, 10, 3, 1, 3};
	bool valid = false;
	do {
		std::cout << slowPrint{ "It has been a long time since you have traveled to the main city\n"
		"You wander along the road towards Verdensy and notice a cart overturned along your Path\n"
		"A couple of wanderers like yourself sit by the cart and look to be in some trouble" };

		std::cout << slowPrint{ "\n\n *Your First Encounter!!* this is where your Path starts to unfold..."
		"\nJust type out what you would like to do and see your possibilities become reality"
		"\nYou can also enter Menu to pull up your Character Menu" };
		std::cout << slowPrint{ "\n\nNow tell me how would you like to proceed?: " };
		std::string choice;
		std::getline(std::cin, choice);
		std::transform(choice.begin(), choice.end(), choice.begin(), std::tolower);
		if (choice.find("menu") != std::string::npos)
		{
			charMenu(); valid = false;
		}
		else if (choice.find("kill") != std::string::npos || choice.find("murder") != std::string::npos || choice.find("attack") != std::string::npos || choice.find("threaten") != std::string::npos)
		{
			system("cls");
			std::cout << slowPrint{ "Your hostile advances have caused the owners of the cart to strike back at you!!"
				"\n\n Pepare to FIGHT!!" };
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			enemyArr.push_back(&en1);
			enemyArr.push_back(&en2);
			enemyArr.push_back(&en3);
			fightEvent.setEncounter(enemyArr, user);
			if (!user.getIsAlive())
				mainMenu();
			valid = true;
		}
		else if (choice.find("observe") != std::string::npos || choice.find("look") != std::string::npos || choice.find("listen") != std::string::npos || choice.find("hear") != std::string::npos || choice.find("see") != std::string::npos)
		{
			system("cls");
			std::cout << slowPrint{ "The travelers look weary like yourself\n You can hear faint mutterings between them"
			" but it is not easy to hear what they are saying\n One of the three looks up from their work and beckons you over" };
			std::cout << "\n\n Walk over or Walk away?: "; std::getline(std::cin, choice);
			if (choice.find("over") != std::string::npos)
			{
				system("cls");
				std::cout << slowPrint{ "\n\n\n\n\n\t\t\t\t\t\t**First Quest**" };//doFirstQuest
				std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // why no time.sleep?!
				valid = true;
			}
			else
			{
				system("cls");
				std::cout << slowPrint{ "You ignore the elven man and continue on your way" };
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				valid = true;
			}
		}
		else if (choice.find("spy") != std::string::npos || choice.find("sneak") != std::string::npos || choice.find("quietly") != std::string::npos || choice.find("silently") != std::string::npos)
		{
			system("cls");
			std::cout << slowPrint{ "You silently move towards the nearby trees and make yourself unseen"
				"\nMoving past them you get far enough to move onwards unperturbed" };
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			valid = true;
		}
		else if (choice.find("approach") != std::string::npos || choice.find("walk up") != std::string::npos || choice.find("hi") != std::string::npos || choice.find("hello") != std::string::npos)
		{
			system("cls");
			std::cout << slowPrint{ "You greet the travelers and they ask you if you could help with a problem they are having" };
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << slowPrint{ "\n\n\n\n\n\t\t\t\t\t\t**First Quest**" };//doFirstQuest
			valid = true;
		}
		else if (choice.find("ignore") != std::string::npos || choice.find("pass") != std::string::npos || choice.find("walk up") != std::string::npos)
		{
			system("cls");
			std::cout << slowPrint{ "You keep your head down and continue on your journey\nYou hear the travelers call out to you but you proceed to keep moving along the road" };
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			valid = true;
		}
		else
		{
			system("cls");
			std::cout << slowPrint{ "What you have asked to do is either impossible\n Rr does not make sense in the current situation"
			"\nPlease try to make it as brief and concise as possible such as"
			"\n 'look at the stranger' 'jump the cliff' 'attack the beast'" };
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			valid = false;
		}
	} while (!valid);
}

void Game::playGame()
{
	Weapon::listWeapons();
	Armour::listArmour();
	Potions::listPotions();
	Spells::listSpells();
	/*std::vector<Enemies*> enemyArr;
	Enemies en1 = { "Goran", "Human", 1, 50, 10, 10, 10, 3, 1, 3 };
	enemyArr.push_back(&en1);
	fightEvent.setEncounter(enemyArr, user);*/
	mainMenu();
	//startJourney();
	//user.addItem(Potions(1, 6));
	//user.addItem(Potions(1, 6));
	//user.addItem(Potions(1, 6));
	//user.addItem(Potions(1, 6));
	//user.addItem(Potions(1, 6));
	//user.addItem(Potions(1, 6));
	//user.setExp(7500);
	//charMenu();
}

Game::~Game() {}