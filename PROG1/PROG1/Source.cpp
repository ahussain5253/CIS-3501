#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:

	Student(string name, string Class, float GPA);

private:

	string Name;
	string Class;
	float GPA;

};

Student::Student(string name, string Class, float GPA) {

	this->Name = name;
	this->Class = Class;
	this->GPA = GPA;


}



int main() {












	return 0;
}