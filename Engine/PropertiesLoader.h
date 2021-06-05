#pragma once
#include <iostream>
#include <string>
#include <fstream>

class PropertiesLoader {
public:
	void loadProperties();
	int getSpeed() const;
private:
	int width;
	int height;
	int tiles;
	int speed;
	const std::string path = "properties.txt";
};