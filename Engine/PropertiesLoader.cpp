#include "PropertiesLoader.h"
void PropertiesLoader::loadProperties()
{
	std::ifstream in(path);
	std::string properties_text;
	char c;
	while (in >> c) {
		if (c == '[') {
				std::string property_label;
			while (c != ']') {
				in >> c;
				property_label.push_back(c);
			}
			if (property_label.compare("speed]") == 0) {
				std::string speedValue;
				while (c < '0' || c > '9') {
					in >> c;
				}
				do {
					speedValue.push_back(c);
					in >> c;
				} while (c >= '0' && c <= '9');
				speed = std::stoi(speedValue);
			}
		}
	}
}

int PropertiesLoader::getSpeed() const
{
	return speed;
}
