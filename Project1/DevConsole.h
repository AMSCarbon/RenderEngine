#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include "ConsoleFunctions.h"

class DevConsole
{
private:
	std::vector<ConsoleFunction*> commands;

	std::string readLine() {
		std::string	input; 
		 std::getline(std::cin, input);	
		 return input; 
	}

	std::vector<std::string> parseLine(std::string line) {
		std::istringstream iss(line);
		std::vector<std::string> results(std::istream_iterator<std::string>{iss},
			std::istream_iterator<std::string>());
		return results;
	}
	
	void findCommand() {
		
	}

public: 
	void awaitInput() {
		std::cout << "carbon >";
		auto userIn = parseLine(readLine());
		for (std::string word : userIn) {
			std::cout << word << "+"; 
		}
		std::cout <<std::endl;
	}
};

