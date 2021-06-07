#include "Path.h"

Path::Path()
{}

void Path::startJourney()
{
	system("cls");
	std::cout << slowPrint{ "It has been a long time since you have traveled to the main city\n"
		"You wander along the road towards Verdensy and notice a cart overturned along your Path\n"
		"A couple of wanderers like yourself sit by the cart and look to be in some trouble" };

	std::cout << slowPrint{ "\n\n *Your First Encounter!!* this is where your Path starts to unfold..."
	"\nJust type out what you would like to do and see your possibilities become reality" };
	bool valid = false;
	do {
		std::cout << slowPrint{ "\n\nNow tell me how would you like to proceed?: " };
		std::string choice;
		std::getline(std::cin, choice);
		if (choice.find("kill") != std::string::npos || choice.find("murder") != std::string::npos || choice.find("attack") != std::string::npos || choice.find("threaten") != std::string::npos)
		{
			system("cls");
			std::cout << slowPrint{ "Your hostile advances have caused the owners of the cart to strike back at you!!"
				"\n\n Pepare to FIGHT!!" };
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			//fight encounter function here
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
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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
			std::cout << slowPrint{ "What you have asked to do is either impossible or does not make sense in the current situation"
			"\nPlease try using all lowercase characters and make it as brief and concise as possible such as"
			"\n 'look at the stranger' 'jump the cliff' 'attack the beast'" };
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			valid = false;
		}
	} while (!valid);
}