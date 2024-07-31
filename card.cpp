#include <iostream>

#include "card.hpp"
#include "display_color.hpp"

card::card() {}

card::card(const std::string& color, const std::string& symbol) :
		color(color),
		symbol(symbol) {}

void card::print() const {
	if (this->color == "red") {
		print_red(this->symbol);
	} else if (this->color == "yellow") {
		print_yellow(this->symbol);
	} else if (this->color == "green") {
		print_green(this->symbol);
	} else if (this->color == "blue") {
		print_blue(this->symbol);
	} else {
		print_rainbow(this->symbol);
	}
}

bool card::is_playable(const card& top_of_discard_pile) const {
	if (this->color == top_of_discard_pile.color) {
		return true;
	}

	if (this->symbol == top_of_discard_pile.symbol) {
		return true;
	}

	if (this->symbol == "wild") {
		return true;
	}

	return false;
}

void card::declare_color_of_wildcard(const std::string& color) {
	if (this->symbol != "wild") {
		std::cout << "Error! declare_color_of_wildcard called on a " <<
			"card that isn't a wildcard!" << std::endl;
		return;
	}

	if (this->color != "wild") {
		std::cout << "Error! declare_color_of_wildcard called on " <<
			"the same card twice!" << std::endl;
		return;
	}

	this->color = color;
}

std::string card::get_symbol() const {
	return this->symbol;
}
