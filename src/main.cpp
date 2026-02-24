#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
	std::cout << std::unitbuf;
	std::cerr << std::unitbuf;

	std::string user_input = "";
  	while(1){
		std::cout << "$ ";
		std::getline(std::cin, user_input);

		switch(user_input.substr(0, user_input.find(" "))){
			case "exit":
				return 0;
			case "echo":
				std::cout << user_input.substr(5) << "\n";
			default:
				std::cout << user_input << ": command not found\n";
		}
	}
}
