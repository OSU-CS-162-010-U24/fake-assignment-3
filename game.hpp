#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "deck.hpp"
#include "card.hpp"

class game {
private:
	player user;
	player npc;
	deck d;
	card top_of_discard_pile;

	bool game_over() const;
	void print_result() const;
	void play_user_turn();
	void play_npc_turn();
	std::string prompt_for_wildcard_color() const;
public:
	game();
	void play();
};

#endif
