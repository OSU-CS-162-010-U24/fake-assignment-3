#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class card {
private:
	std::string color;
	std::string symbol;
public:
	card();
	card(const std::string& color, const std::string& symbol);

	void print() const;
	bool is_playable(const card& top_of_discard_pile) const;
	void declare_color_of_wildcard(const std::string& color);
	std::string get_symbol() const;
};

#endif
