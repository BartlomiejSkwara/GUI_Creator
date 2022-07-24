#pragma once
#include <iostream>
class Generator
{
public :
	Generator();
	~Generator();

	void generateToConsole();
	void generateToFile();
	void saveToFile();
	void loadFromFile();
};

