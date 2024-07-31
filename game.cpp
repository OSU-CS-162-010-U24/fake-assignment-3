#include <iostream>

#include "game.hpp"

game::game() {
	// At this point, I need to deal 7 cards to each player
	for (int i = 0; i < 7; i++) {
		// Deal the card at the top of the deck to the user
		card drawn_card = this->d.draw_card();
		this->user.append_card(drawn_card);
	}

	for (int i = 0; i < 7; i++) {
		// Deal the card at the top of the deck to the NPC
		card drawn_card = this->d.draw_card();
		this->npc.append_card(drawn_card);
	}

	// Draw the top card of the deck to be the top of the discard pile
	card drawn_card = this->d.draw_card();
	this->top_of_discard_pile = drawn_card;
}

bool game::game_over() const {
	return this->user.is_out_of_cards() || this->npc.is_out_of_cards() ||
		this->d.is_empty();
}

void game::play() {
	bool users_turn = true;
	do {
		if (users_turn) {
			this->play_user_turn();
		} else {
			this->play_npc_turn();
		}
		users_turn = !users_turn;
	} while(!this->game_over());

	this->print_result();
}

void game::print_result() const {
	if (this->user.is_out_of_cards()) {
		std::cout << "The user won!" << std::endl;
	} else if (this->npc.is_out_of_cards()) {
		std::cout << "The NPC won!" << std::endl;
	} else {
		std::cout << "It's a draw!" << std::endl;
	}
}

void game::play_user_turn() {
	// Check whether the user has playable cards
	if (this->user.has_playable_cards(this->top_of_discard_pile)) {
		// If so, prompt for playable card selection
		int index_to_play = this->user.prompt_for_playable_card(
			this->top_of_discard_pile
		);

		// Play the card
		this->top_of_discard_pile = this->user.remove_card(
			index_to_play
		);

		if (this->top_of_discard_pile.get_symbol() == "wild") {
			// Ask the user for the effective color of wild card
			std::string color = this->prompt_for_wildcard_color();

			// Change effective color of wildcard
			this->top_of_discard_pile.declare_color_of_wildcard(
				color
			);
		}
	} else {
		// Otherwise, draw a card from the top of the deck
		std::cout << "Sorry! You don't have any playable cards! " <<
			"Type anything to draw a card: " << std::endl;
		std::string dummy;
		std::cin >> dummy;

		card drawn_card = this->d.draw_card();
		
		// Check if drawn card is playable
		if (drawn_card.is_playable(this->top_of_discard_pile)) {
			// If so, play it and notify user.
			this->top_of_discard_pile = drawn_card;
			std::cout << "You drew a playable card and played it!"
				<< std::endl << std::endl;
		} else {
			// Otherwise, silently add it to the user's hand
			this->user.append_card(this->d.draw_card());
		}
	}
}

void game::play_npc_turn() {
	// Check whether the NPC has playable cards
	if (this->npc.has_playable_cards(this->top_of_discard_pile)) {
		// If so, prompt for playable card selection
		int index_to_play = this->npc.get_index_of_first_playable_card(
			this->top_of_discard_pile
		);

		// Play the card
		this->top_of_discard_pile = this->npc.remove_card(
			index_to_play
		);

		if (this->top_of_discard_pile.get_symbol() == "wild") {
			// Change effective color of wildcard
			this->top_of_discard_pile.declare_color_of_wildcard(
				"red"
			);
		}
		
	} else {
		// Otherwise, draw a card from the top of the deck
		card drawn_card = this->d.draw_card();
		
		// Check if drawn card is playable
		if (drawn_card.is_playable(this->top_of_discard_pile)) {
			// If so, play it
			this->top_of_discard_pile = drawn_card;
		} else {
			// Otherwise, silently add it to the NPC's hand
			this->npc.append_card(this->d.draw_card());
		}
	}
}

std::string game::prompt_for_wildcard_color() const {
	bool first = true;
	std::string card_color;
	do {
		if (!first) {
			std::cout << "Error! Invalid selection!" <<
				std::endl << std::endl;
		}
		std::cout << "What color would you like your wildcard to be?"
			<< std::endl << "(red | yellow | green | blue): ";
		std::cin >> card_color;
		first = false;
	} while(
		card_color != "red" &&
		card_color != "yellow" &&
		card_color != "green" &&
		card_color != "blue");

	return card_color;
}
