#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class Menu {
private:
	std::vector<std::string> menuElements;
	int selectedElement = 0;
	bool Move(char);
	void PrintMenu();
public:
	//Constructors
	Menu(std::vector<std::string> getMenu) { menuElements = getMenu; }

	//Utility
	std::string Choose();
	int ElementID() const { return selectedElement; }
};

#endif