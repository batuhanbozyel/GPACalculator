#include "Menu.h"
#include <iostream>

#ifdef _WIN32
#include <conio.h>
constexpr char clear[] = "cls";

#else
#include <curses.h>
#define _getch() getch()
constexpr char clear[] = "clear";

#endif

bool Menu::Move(char DIR)
{
	if (DIR == 'w')
	{
		if(selectedElement > 0)
			selectedElement--;
		else
			selectedElement = menuElements.size() - 1;
		return true;
	}
	else if (DIR == 's')
	{
		if (selectedElement < (int)(menuElements.size() - 1))
			selectedElement++;
		else
			selectedElement = 0;
		return true;
	}
	return false;
}

void Menu::PrintMenu()
{
	for (int i = 0; i < (int)menuElements.size(); i++)
	{
		if(selectedElement == i)
			std::cout << ">" << menuElements[i] << std::endl;
		else
			std::cout << "" << menuElements[i] << std::endl;
	}
}

std::string Menu::Choose()
{
	char choice;
	do
	{
		system(clear);
		PrintMenu();
		choice = _getch();
		Move(choice);
	} while (choice == 'w' || choice == 's');
	return menuElements[selectedElement];
}