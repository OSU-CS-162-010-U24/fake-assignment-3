#include <iostream>

#include "display_color.hpp"

void print_red(const std::string& text) {
	std::cout << std::flush << "\033[1;47;31m" << std::flush << text <<
		std::flush << "\033[0m" << std::flush;
}

void print_yellow(const std::string& text) {
	std::cout << std::flush << "\033[1;47;33m" << std::flush << text <<
		std::flush << "\033[0m" << std::flush;
}

void print_green(const std::string& text) {
	std::cout << std::flush << "\033[1;47;32m" << std::flush << text <<
		std::flush << "\033[0m" << std::flush;
}

void print_blue(const std::string& text) {
	std::cout << std::flush << "\033[1;47;34m" << std::flush << text <<
		std::flush << "\033[0m" << std::flush;
}

void print_rainbow(const std::string& text) {
	for (int i = 0; i < text.length(); i++) {
		if (i % 4 == 0) {
			std::cout << std::flush << "\033[1;47;31m" <<
				std::flush << text.at(i) << std::flush <<
				"\033[0m" << std::flush;
		} else if (i % 4 == 1) {
			std::cout << std::flush << "\033[1;47;33m" <<
				std::flush << text.at(i) << std::flush <<
				"\033[0m" << std::flush;
		} else if (i % 4 == 2) {
			std::cout << std::flush << "\033[1;47;32m" <<
				std::flush << text.at(i) << std::flush <<
				"\033[0m" << std::flush;
		} else {
			std::cout << std::flush << "\033[1;47;34m" <<
				std::flush << text.at(i) << std::flush <<
				"\033[0m" << std::flush;
		}
	}
}
