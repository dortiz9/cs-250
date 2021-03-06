#include <iostream>
#include <string>
#include <list>
using namespace std;

class Student
{
public:
	Student(const string& name, int grade) : m_name(name), m_grade(grade) { }
	void Display();

	bool operator>(const Student& other);
	bool operator<(const Student& other);
	bool operator>=(const Student& other);
	bool operator<=(const Student& other);
	bool operator==(const Student& other);

private:
	string m_name;
	int m_grade;
};


int main()
{
	// Create a list of Student objects called students
	list<Student> students;

	// Push multiple students into the list.
	students.push_back(Student("Vid", 100));
	students.push_back(Student("Josh", 60));
	students.push_back(Student("Claire", 90));
	students.push_back(Student("Bob", 10));
	students.push_back(Student("Jim", 75));
	// students.push_back( Student( "Vid",         100 ) );

	// Call the sort() function
	students.sort();
	// Call the reverse() function to make it descending.
	students.reverse();
	// Display all the students
	
	for (list<Student>::iterator it = students.begin(); it != students.end(); it++)
	{
		it->Display();
	}

	return 0;
}

void Student::Display()
{
	cout << m_grade << "\t" << m_name << endl;
}


bool Student::operator>(const Student& other)
{
	return this->m_grade > other.m_grade;
}

bool Student::operator<(const Student& other)
{
	return this->m_grade < other.m_grade;
}

bool Student::operator>=(const Student& other)
{
	return this->m_grade >= other.m_grade;
}

bool Student::operator<=(const Student& other)
{
	return this->m_grade <= other.m_grade;
}

bool Student::operator==(const Student& other)
{
	return this->m_grade == other.m_grade;
}