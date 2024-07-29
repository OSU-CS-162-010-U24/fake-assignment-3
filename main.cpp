#include <iostream>

#include "display_color.hpp"

int main() {
	/* 
	 * The starter code comes with fancy print functions in
	 * display_color.hpp and implemented in display_color.cpp that print
	 * the given text in a certain color over a white background. The text
	 * color depends on the function called. This is useful for printing
	 * uno cards to the terminal. You can use these functions like so:
	 */
	print_red("This text is red!");
	std::cout << std::endl;
	print_yellow("This text is yellow!");
	std::cout << std::endl;
	print_green("This text is green!");
	std::cout << std::endl;
	print_blue("This text is blue!");
	std::cout << std::endl;
	print_rainbow("This text is rainbow!");
	std::cout << std::endl;
}
