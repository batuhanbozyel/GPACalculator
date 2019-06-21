#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>

class Course {
private:
	std::string lecCode;
	float credit;
	std::string grade;
public:
	//Constructors
	Course();
	Course(std::string, float);
	Course(std::string, float, std::string);
	//Operator Overloads
	Course& operator=(const Course&);
	//Utility
	void Print();
	float Weight() const;
	std::string LecCode() const;
	float Credit() const;
	std::string Grade() const;
	void SetLecCode(std::string);
	void SetCredit(float);
	void SetGrade(std::string);
};

#endif