#ifndef DECK_HPP
#define DECK_HPP

#include "card_list.hpp"

class deck {
private:
	card_list cards;
public:
	deck();
	card draw_card();
	bool is_empty() const;
};

#endif
