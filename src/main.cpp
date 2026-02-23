#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
	std::cout << std::unitbuf;
	std::cerr << std::unitbuf;

	std::string user_input = "";
  	while(1){
		std::cout << "$ ";
		std::cin >> user_input;
		if(user_input == "exit"){
			return 0;
		}
		else if(user_input.substr(0, 4) == "echo"){
			cout << user_input.substr(5);
		}
		else{
			std::cout << user_input << ": command not found\n";
		}
   }
}
