#include "Course.h"

//Constructors

Course::Course()
{
	lecCode = "Undefined";
	credit = 0.0f;
	grade = "Undefined";
}

Course::Course(std::string lecCode, float credit)
{
	this->lecCode = lecCode;
	this->credit = credit;
	this->grade = "In Progress";
}

Course::Course(std::string lecCode, float credit, std::string grade)
{
	this->lecCode = lecCode;
	this->credit = credit;
	this->grade = grade;
}

//Operator Overloads

Course& Course::operator=(const Course& course)
{
	lecCode = course.lecCode;
	credit = course.credit;
	grade = course.grade;
	return *this;
}

//Utility
void Course::Print()
{
	std::cout << std::setw(15) << lecCode << std::setw(15) << credit << std::setw(15) << grade << std::endl;
}

float Course::Weight() const
{
	if (grade == "AA") return 4.0f * credit;
	else if (grade == "BA") return 3.5f * credit;
	else if (grade == "BB") return 3.0f * credit;
	else if (grade == "CB") return 2.5f * credit;
	else if (grade == "CC") return 2.0f * credit;
	else if (grade == "DC") return 1.5f * credit;
	else if (grade == "DD") return 1.0f * credit;
	else return 0.0f;
}

std::string Course::LecCode() const
{
	return lecCode;
}

float Course::Credit() const
{
	return credit;
}

std::string Course::Grade() const
{
	return grade;
}

void Course::SetLecCode(std::string lecCode)
{
	this->lecCode = lecCode;
}

void Course::SetCredit(float credit)
{
	this->credit = credit;
}

void Course::SetGrade(std::string grade)
{
	this->grade = grade;
}