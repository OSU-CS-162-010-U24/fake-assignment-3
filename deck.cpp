#include <string>

#include "deck.hpp"

deck::deck() : cards(80) {
	std::string colors[] {"red", "yellow", "green", "blue"};
	int running_index = 0;
	for (int color_index = 0; color_index < 4; color_index++) {
		for (int set_index = 0; set_index < 2; set_index++) {
			for (int symbol = 1; symbol <= 9; symbol++) {
				std::string symbol_string = std::to_string(symbol);
				std::string color_string = colors[color_index];

				card c(color_string, symbol_string);
				this->cards.at(running_index) = c;
				running_index++;
			}
		}
	}
	
	for (int color_index = 0; color_index < 4; color_index++) {
		std::string color_string = colors[color_index];
		card c(color_string, "0");
		this->cards.at(running_index) = c;
		running_index++;
	}

	for (int i = 0; i < 4; i++) {
		card c("wild", "wild");
		this->cards.at(running_index) = c;
		running_index++;
	}

	for (int i = 0; i < 80; i++) {
		// Pick a random index j
		int j = rand() % 80;

		// Swap card at index i with card at index j
		card temp = this->cards.at(i);
		this->cards.at(i) = this->cards.at(j);
		this->cards.at(j) = temp;
	}
}

card deck::draw_card() {
	return this->cards.remove_from_end();
}

bool deck::is_empty() const {
	return this->cards.size() == 0;
}
