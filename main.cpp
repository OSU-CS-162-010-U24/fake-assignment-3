#include <iostream>
#include <cstdlib>
#include <ctime>

#include "game.hpp"

int main() {
	// Seed PRNG
	srand(time(nullptr));

	game g;
	g.play();
}
