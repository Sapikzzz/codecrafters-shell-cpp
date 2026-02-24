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
		if(user_input == "exit"){
			return 0;
		}
		else if(user_input.substr(0, user_input.find(" ")) == "echo"){
			std::cout << user_input.substr(5) << "\n";
		}
		else if(user_input.substr(0, user_input.find(" ")) == "type"){
			std::string target_command = user_input.substr(user_input.find(" ") + 1, user_input.find("\n"));
			if(target_command == "echo" ){
				std::cout << target_command << "is a shell builtin\n";
			}
			else if(target_command == "exit"){
				std::cout << target_command << "is a shell builtin\n";
			}
			else{
				std::cout << target_command << ": not found";
			}
		}
		else{
			std::cout << user_input << ": command not found\n";
		}
   }
}
