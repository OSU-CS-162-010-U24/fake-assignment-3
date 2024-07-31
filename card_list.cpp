#include <iostream>

#include "card_list.hpp"

card_list::card_list() {}

card_list::card_list(int n_cards) :
		n_cards(n_cards),
		cards(new card[n_cards]) {}

card_list::~card_list() {
	if (this->cards != nullptr) {
		delete [] this->cards;
		this->cards = nullptr;
	}
}

card_list::card_list(const card_list& other) :
		n_cards(other.n_cards),
		cards(new card[other.n_cards]) {
	for (int i = 0; i < other.n_cards; i++) {
		this->cards[i] = other.cards[i];
	}
}

card_list& card_list::operator=(const card_list& other) {
	if (this == &other) {
		return *this;
	}
	
	if (this->cards != nullptr) {
		delete [] this->cards;
		this->cards = nullptr;
	}

	this->n_cards = other.n_cards;
	this->cards = new card[other.n_cards];
	for (int i = 0; i < other.n_cards; i++) {
		this->cards[i] = other.cards[i];
	}

	return *this;
}

void card_list::append_card(const card& to_append) {
	card* new_array = new card[this->n_cards + 1];
	for (int i = 0; i < this->n_cards; i++) {
		new_array[i] = this->cards[i];
	}
	new_array[this->n_cards] = to_append;

	if (this->cards != nullptr) {
		delete [] this->cards;
	}
	this->cards = new_array;
	this->n_cards++;
}

card card_list::remove_from_end() {
	card result = this->cards[this->n_cards - 1];
	
	card* new_array;
	if (this->n_cards <= 1) {
		new_array = nullptr;
	} else {
		new_array = new card[this->n_cards - 1];
	}

	for (int i = 0; i < this->n_cards - 1; i++) {
		new_array[i] = this->cards[i];
	}

	if (this->cards != nullptr) {
		delete [] this->cards;
	}
	this->cards = new_array;
	this->n_cards--;
	return result;
}

card card_list::remove(int index) {
	card result = this->cards[index];

	card* new_array;

	if (this->n_cards <= 1) {
		new_array = nullptr;
	} else {
		new_array = new card[this->n_cards - 1];
	}

	// Copy first 'index' elements from old array into new array
	for (int i = 0; i < index; i++) {
		new_array[i] = this->cards[i];
	}

	// Copy remaining elements, starting from 'index + 1', into the new
	// array, shifting their indices as we go
	for (int i = index + 1; i < this->n_cards; i++) {
		new_array[i - 1] = this->cards[i];
	}
	
	if (this->cards != nullptr) {
		delete [] this->cards;
	}
	this->cards = new_array;
	this->n_cards--;
	return result;
}

int card_list::size() const {
	return this->n_cards;
}

card& card_list::at(int index) {
	if (index < 0 || index >= this->n_cards) {
		std::cout << "Error! card_list at() function given out " <<
			"of bounds index!" << std::endl;
		return this->cards[0];
	}

	return this->cards[index];
}

const card& card_list::at(int index) const {
	if (index < 0 || index >= this->n_cards) {
		std::cout << "Error! card_list at() function given out " <<
			"of bounds index!" << std::endl;
		return this->cards[0];
	}

	return this->cards[index];
}
