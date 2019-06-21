#include "Term.h"

#ifdef _WIN32
constexpr char clear[] = "cls";

#else
constexpr char clear[] = "clear";
#endif

//Constructors

int Term::count = 0;

Term::Term()
{
	totalCredit = 0.0f;
	totalWeight = 0.0f;
	count++;
	term_id = count;
}

//Utility

void Term::AddCourse(const Course& toAdd)
{
	courses.push_back(toAdd);
	if (toAdd.Grade() != "In Progress")
	{
		totalCredit += toAdd.Credit();
		totalWeight += toAdd.Weight();
	}	
}

void Term::RemoveCourse(const int& pos)
{
	if (courses[pos].Grade() != "In Progress")
	{
		totalCredit -= courses[pos].Credit();
		totalWeight -= courses[pos].Weight();
	}
	courses.erase(courses.begin() + pos);
}

float Term::GPA() const
{
	if (courses.size() > 0) return totalWeight / totalCredit;
	else return 0;
}

float Term::TotalCredit() const
{
	return totalCredit;
}

float Term::TotalWeight() const
{
	return totalWeight;
}

//Fill Helper Functions

bool isProper(const std::string& lecCode, const float& credit, const std::string& grade)
{
	return credit >= 0.0f && (grade == "VF" || grade == "FF" || grade == "DD" || grade == "DC" ||
		grade == "CC" || grade == "CB" || grade == "BB" || grade == "BA" || grade == "AA" || grade == "U");
}

void ConvertToUpper(std::string& toConvert)
{
	for (int i = 0; i < (int)toConvert.length(); i++)
		toConvert[i] = toupper(toConvert[i]);
}

//Main Functions

void Term::Fill()
{
	std::string courseName;
	float credit;
	while (true)
	{
		system(clear);
		Print();
		std::cout << "Type Lecture Code, Credit and Letter Grade (Type 'x' to Exit, Type 'u' to Skip Letter Grade): ";
		std::cin >> courseName;
		if (courseName == "x" || courseName == "X") break;
		std::cin >> credit;
		std::string grade;
		std::cin >> grade;
		ConvertToUpper(courseName);
		ConvertToUpper(grade);
		if (isProper(courseName, credit, grade))
		{
			if (grade == "U") AddCourse(Course(courseName, credit));
			else AddCourse(Course(courseName, credit, grade));
			std::cout << "Course Successfully Added." << std::endl;
		}
		else
		{
			std::cout << "Course Could not Added." << std::endl;
		}
	}
}

void Term::Edit()
{
	//No Courses to Edit
	if (courses.size() == 0)
	{
		std::cout << "No Courses to Edit" << std::endl;
		system("pause");
		return;
	}
	int choice;
	do {
		system(clear);
		Print();
		std::cout << "Choose a Course to Edit (-1 to Exit): ";
		std::cin >> choice;
		if (choice == -1) break;
		//Index out of range
		while (choice < 1 || choice > (int)courses.size())
		{
			system(clear);
			Print();
			std::cout << "Please give a proper number: ";
			std::cin >> choice;
		}
		system(clear);
		std::cout << "Course" << std::setw(15) << "Credit" << std::setw(15) << "Letter Grade" << std::endl;
		std::cout << courses[choice - 1].LecCode() << std::setw(15) << courses[choice - 1].Credit() << std::setw(15) << courses[choice - 1].Grade() << std::endl;
		int element;
		std::cout << "Edit ( 0: Remove Course, 1: Lecture Code, 2: Credit, 3: Grade, -1: Exit): ";
		std::cin >> element;
		if (element == 0)
		{
			RemoveCourse(choice - 1);
		}
		else if (element == 1)
		{
			std::cout << "Type New Lecture Code: ";
			std::string lecCode;
			std::cin >> lecCode;
			ConvertToUpper(lecCode);
			Course toAdd(lecCode, courses[choice - 1].Credit(), courses[choice - 1].Grade());
			AddCourse(toAdd);
			RemoveCourse(choice - 1);
		}
		else if (element == 2)
		{
			std::cout << "Type New Credit: ";
			float credit;
			std::cin >> credit;
			Course toAdd(courses[choice - 1].LecCode(), credit, courses[choice - 1].Grade());
			AddCourse(toAdd);
			RemoveCourse(choice - 1);
		}
		else if (element == 3)
		{
			std::cout << "Type New Grade: ";
			std::string grade;
			std::cin >> grade;
			ConvertToUpper(grade); 
			Course toAdd(courses[choice - 1].LecCode(), courses[choice - 1].Credit(), grade);
			AddCourse(toAdd);
			RemoveCourse(choice - 1);
		}
		else break;
	} while (choice != -1);
}

void Term::Print()
{
	std::cout << "   \t" << std::setw(15) << "Courses" << std::setw(15) << "Credits" << std::setw(15) << "Letter Grade" << std::endl;
	for (int i = 0; i < (int)courses.size(); i++)
	{
		std::cout << i + 1 << " - \t";
		courses[i].Print();
	}
	std::cout << "Total Credit: " << totalCredit << "\t\tGPA: " << GPA() << std::endl;
}

void Term::WriteFile(const std::string& fileName)
{
	std::ofstream termFile("./TermData/" + fileName);
	termFile << "   \t" << std::setw(15) << "Courses" << std::setw(15) << "Credits" << std::setw(15) << "Letter Grade" << std::endl;
	for (int i = 0; i < (int)courses.size(); i++)
	{
		termFile << i + 1 << " - \t" << std::setw(15) << courses[i].LecCode() << std::setw(15)
			<< courses[i].Credit()  << std::setw(15) << courses[i].Grade() << std::endl;
	}
	termFile << "Total Credit: " << totalCredit << "\t\tGPA: " << GPA() << std::endl;
	termFile.close();
}

void Term::WriteFile()
{
	std::ofstream termFile("./TermData/term_" + std::to_string(term_id) + ".txt");
	termFile << "   \t" << std::setw(15) << "Courses" << std::setw(15) << "Credits" << std::setw(15) << "Letter Grade" << std::endl;
	for (int i = 0; i < (int)courses.size(); i++)
	{
		termFile << i + 1 << " - \t" << std::setw(15) << courses[i].LecCode() << std::setw(15)
			<< courses[i].Credit() << std::setw(15) << courses[i].Grade() << std::endl;
	}
	termFile << "Total Credit: " << totalCredit << "\t\tGPA: " << GPA() << std::endl;
	termFile.close();
}

bool Term::ReadFile()
{
	int c = 0;
	std::ifstream termFile("./TermData/term_" + std::to_string(term_id) + ".txt");
	if (termFile.is_open())
	{
		std::string buff;
		//Top of the Table
		std::getline(termFile, buff);
		while (!termFile.eof())
		{
			//To skip Indexing part of the Table
			termFile >> buff;
			//Last Line
			if (buff == "Total") break;
			//To skip Indexing part of the Table
			termFile >> buff;
			//Course Data
			std::string lec;
			float credit;
			std::string grade;
			termFile >> lec;
			termFile >> credit;
			termFile >> grade;
			Course toAdd(lec, credit, grade);
			AddCourse(toAdd);
			c++;
		}
	}
	termFile.close();
	if (c == 0) return false;
	else return true;

}


