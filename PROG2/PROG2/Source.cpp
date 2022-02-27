#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {

public:

	void setName(string name) { this->name = name; }
	string getName() { return name; }
	void printName() { cout << name << endl; }

private:

	string name;
};

void sortArray(Student** studentPtr) {


	for (int i = 0; i < 25; i++) {

		for (int j = i + 1; j < 25; j++) {

			Student* temp;

			if (studentPtr[i]->getName() > studentPtr[j]->getName()) {

				temp = studentPtr[i];
				studentPtr[i] = studentPtr[j];
				studentPtr[j] = temp;

			}

		}


	}

}

void writeToFile(Student** studentPtr) {

	ofstream file;
	file.open("Output.txt");

	file << "Unsorted list of student names:" << endl << endl;
	for (int i = 0; i < 25; i++) { file << studentPtr[i]->getName() << endl;}
	file << endl << endl;

	sortArray(studentPtr);
	
	file << "Sorted list of student names:" << endl << endl;
	for (int i = 0; i < 25; i++) { file << studentPtr[i]->getName() << endl; }

}


int main() {

	Student* studentPtr[25];

	ifstream input;
	input.open("Input.txt");

	for (int i = 0; i < 25; i++) {

		studentPtr[i] = new Student;

		string name;
		input >> name;

		studentPtr[i]->setName(name);

	}

	writeToFile(studentPtr);

	cout << "Unsorted list of student names: " << endl << endl;
	for (int i = 0; i < 25; i++) { studentPtr[i]->printName(); }
	cout << endl << endl;

	sortArray(studentPtr);

	cout << "Alphebetically sorted list of student names: " << endl << endl;
	for (int i = 0; i < 25; i++) { studentPtr[i]->printName(); }


	return 0;


}



