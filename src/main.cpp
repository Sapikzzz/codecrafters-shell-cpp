#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::string user_input = "";

  std::cout << "$ ";
  std::cin >> user_input;
  std::cout << user_input << ": command not found";
}
