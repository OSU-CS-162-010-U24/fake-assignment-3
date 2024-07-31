#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "card_list.hpp"

class player {
private:
	card_list hand;
public:
	void append_card(const card& to_append);
	card remove_card(int index);
	void print_hand() const;
	int prompt_for_playable_card(const card& top_of_discard_pile) const;
	int get_index_of_first_playable_card(const card& top_of_discard_pile) const;
	bool has_playable_cards(const card& top_of_discard_pile) const;
	bool is_out_of_cards() const;
};

#endif
