#ifndef CARD_LIST_HPP
#define CARD_LIST_HPP

#include "card.hpp"

class card_list {
private:
	int n_cards = 0;
	card* cards = nullptr;
public:
	card_list();
	card_list(int n_cards);
	~card_list();
	card_list(const card_list& other);
	card_list& operator=(const card_list& other);

	void append_card(const card& to_append);
	card remove_from_end();
	card remove(int index);
	int size() const;
	card& at(int index);
	const card& at(int index) const;
};

#endif
