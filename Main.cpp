#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include "Term.h"
#include "Menu.h"

#ifdef _WIN32
constexpr char clear[] = "cls";

#else
constexpr char clear[] = "clear";
#endif


int main()
{
	bool isFilled[8];
	Term term[8];
	for (int i = 0; i < 8; i++) isFilled[i] = term[i].ReadFile();
	Menu main_menu({ "Fill Term" , "Edit Term" , "Print Term" , "Print Overall GPA", "Exit" });
	Menu term_menu({ "Term 1" , "Term 2" , "Term 3" , "Term 4" , "Term 5" , "Term 6" , "Term 7" , "Term 8" , "Back" });
	std::string main_choice;
	std::string term_choice;
	do {
		main_choice = main_menu.Choose();
		if (main_choice == "Fill Term")
		{
			do {
				term_choice = term_menu.Choose();
				system(clear);
				if (term_choice == "Back") break;
				int i = term_menu.ElementID();
				term[i].Fill();
			} while (true);
		}
		else if (main_choice == "Edit Term")
		{
			do {
				term_choice = term_menu.Choose();
				system(clear);
				if (term_choice == "Back") break;
				int i = term_menu.ElementID();
				term[i].Edit();
			} while (true);
		}
		else if (main_choice == "Print Term")
		{
			do {
				term_choice = term_menu.Choose();
				system(clear);
				if (term_choice == "Back") break;
				int i = term_menu.ElementID();
				term[i].Print();
				system("pause");
			} while (true);
		}
		else if (main_choice == "Print Overall GPA")
		{
			system(clear);
			float totalC = 0.0f, totalW = 0.0f;
			for(int i = 0; i < 8; i++)
				if (isFilled[i])
				{
					totalC += term[i].TotalCredit();
					totalW += term[i].TotalWeight();
				}
			std::cout << "Overall GPA: " << totalW / totalC << std::endl;
			system("pause");
		}

	} while (main_choice != "Exit");

	for (int i = 0; i < 8; i++) term[i].WriteFile();
	
	return 0;
}