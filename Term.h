#ifndef TERM_H
#define TERM_H

#include <vector>

#include "Course.h"

class Term{
private:
	std::vector<Course> courses;
	float totalCredit;
	float totalWeight;
	static int count;
	int term_id;
public:
	//Constructors
	Term();
	//Utility
	void AddCourse(const Course&);
	void RemoveCourse(const int&);
	float GPA() const;
	float TotalWeight() const;
	float TotalCredit() const;
	//Main Functions
	void Fill();
	void Edit();
	void Print();
	void WriteFile(const std::string&);
	void WriteFile();
	bool ReadFile();
};

#endif