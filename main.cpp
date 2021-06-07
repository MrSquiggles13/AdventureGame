#include "Game.h"

int main()
{
	Game game;
	
	while (game.getPlaying())
	{
		game.playGame();
	}
}

// **create character (*name, *weapon, *difficulty, *class, *roll for stats assign 7 rolls to stats,)
// create enemies (monster type, attack type, health, dificulty scaling, special abilities)
// levels (terrain type, size, print basic map, entrance exit hazzards, connect to other levels)
// experience and leveling up (what gives experience and how, stat increase mechanism, how much exp gives level)
// items (stats, level restrictions, what and where dropped*loot*, where  to buy and sell inventory space)
// start game and how to save it
// story for game