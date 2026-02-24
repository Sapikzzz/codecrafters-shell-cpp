#include <cstddef>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <filesystem>

bool is_executable(const std::filesystem::path& p){
	std::filesystem::perms prms = std::filesystem::status(p).permissions();

	// Check if the prms bitmask is the same as exec permissions bitmask
	return ((prms & std::filesystem::perms::owner_exec) != std::filesystem::perms::none ||
		(prms & std::filesystem::perms::group_exec) != std::filesystem::perms::none ||
		(prms & std::filesystem::perms::others_exec) != std::filesystem::perms::none);
}

std::string check_all_paths(std::vector<std::string> paths_to_check, std::string target_command){
	for (size_t i = 0; i < paths_to_check.size(); i++) {
		std::filesystem::path directory_path = paths_to_check[i];
		if(std::filesystem::exists(directory_path) && std::filesystem::is_directory(directory_path)){
			for(const auto& entry : std::filesystem::directory_iterator(directory_path)){
				if(entry.path().filename() == target_command){
					if(is_executable(entry.path())){
						std::string path = entry.path();
						std::string result = target_command + " is " + path + "\n";
						return result;
					}
				}
			}
		}
	}
}

int main() {
  // Flush after every std::cout / std:cerr
	std::cout << std::unitbuf;
	std::cerr << std::unitbuf;

	const char* PATH_VAR = "PATH";
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
				std::cout << target_command << " is a shell builtin\n";
			}
			else if(target_command == "exit"){
				std::cout << target_command << " is a shell builtin\n";
			}
			else if(target_command == "type"){
				std::cout << target_command << " is a shell builtin\n";
			}
			else{
				const std::string PATH_ENV_VAL = getenv(PATH_VAR);
				if(PATH_ENV_VAL != ""){
					std::stringstream ss(PATH_ENV_VAL);
					std::string segment;
					std::vector<std::string> paths_to_check;
					while(std::getline(ss, segment, ':')){
						paths_to_check.push_back(segment);
					}
					std::cout << check_all_paths(paths_to_check, target_command);
				}
				else{
					std::cout << target_command << ": not found\n";
				}
			}
		}
		else{
			std::cout << user_input << ": command not found\n";
		}
   }
}
