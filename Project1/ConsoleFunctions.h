#pragma once
#include <string>
#include <vector>


class ConsoleFunction
{
	std::string name;
	int expectedArgLen; 
public: 
	virtual int execute(Display display, Model model, Renderer renderer, std::vector<std::string> argV){0;}
	
};

