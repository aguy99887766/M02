#include <iostream>
#include <string>
#include <cmath>
#include <vector>


std::vector<int> create_list(std::string binary) {	
	// Takes a string then loops through each character to then add it to the vector then return the vector
	//
	//
	std::vector<int> decimal = {};

	for (auto &ch : binary) {
		decimal.push_back(ch - '0');	
	}

	return decimal;

}

int convert(std::string binary) {
	/*	Takes the string then calls the functions to create a list
	 *	This then goes to through the while loop that uses the formula:
	 *
	 *	u(2^n)
	 *	where u is equal to a 1 or 0 and n is the index of the number
	 *
	 */


	std::vector<int> number_list = create_list(binary);
	int decimal = 0;
	int current_num = 0;

	int n = number_list.size();

	for (int i = 0; i < n; i++) {
		current_num = pow(2, n -1 -i);
		decimal += number_list[i] * current_num;
		
	}
	return decimal;

}

int main() {


	int number = convert("11100");
	std::cout << number << std::endl;

	return 0;

}
