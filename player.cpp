#include <iostream>

#include "player.hpp"

void player::append_card(const card& to_append) {
	this->hand.append_card(to_append);
}

card player::remove_card(int index) {
	return this->hand.remove(index);
}

void player::print_hand() const {
	std::cout << "Your hand: " << std::endl;
	for (int i = 0; i < this->hand.size(); i++) {
		// Print the ith card in the player's hand
		std::cout << (i + 1) << ". ";
		this->hand.at(i).print();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int player::prompt_for_playable_card(const card& top_of_discard_pile) const {
	bool first = true;
	int card_number;
	do {
		if (!first) {
			std::cout << "Error! Invalid selection!" <<
				std::endl << std::endl;
		}
		std::cout << "Discard pile: ";
		top_of_discard_pile.print();
		std::cout << std::endl;
		this->print_hand();
		std::cout << "Which card would you like to play?: ";
		card_number;
		std::cin >> card_number;
		first = false;
	} while(card_number <= 0 || card_number > this->hand.size() ||
		!this->hand.at(card_number - 1)
			.is_playable(top_of_discard_pile));

	return card_number - 1;
}

int player::get_index_of_first_playable_card(
		const card& top_of_discard_pile) const {
	for (int i = 0; i < this->hand.size(); i++) {
		if (this->hand.at(i).is_playable(top_of_discard_pile)) {
			return i;
		}
	}

	std::cout << "Error! get_index_of_first_playable_card() called on " <<
		"player object without any playable cards" << std::endl;
	return -1;
}

bool player::has_playable_cards(const card& top_of_discard_pile) const {
	for (int i = 0; i < this->hand.size(); i++) {
		if (this->hand.at(i).is_playable(top_of_discard_pile)) {
			return true;
		}
	}

	return false;
}

bool player::is_out_of_cards() const {
	return this->hand.size() == 0;
}
