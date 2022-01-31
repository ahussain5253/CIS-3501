#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class Student
{
public:

	Student();
	friend ostream& operator << (ostream& output, Student& student);
	friend ifstream& operator >> (ifstream& input, Student& student);
	string getName() { return this->Name; }
	string getClass() { return this->Class; }
	float getGPA() { return this->GPA; }

private:

	string Name;
	string Class;
	float GPA;

};

Student::Student() {

	this->Name = "noname";
	this->Class = "noclass";
	this->GPA = 0.0;

}

ostream& operator << (ostream& output, Student& student) {

	output << student.Name << "      " << student.Class << "      " << student.GPA;

	return output;
}

ifstream& operator >> (ifstream& input, Student& student) {

	input >> student.Name >> student.Class >> student.GPA;

	return input;

}

void populateVectorStudents(vector<Student>& Students) {

	ifstream input;
	input.open("Input.txt");


	while (!input.eof()) {

		Student student;

		input >> student;

		Students.push_back(student);

	}

	input.close();

}

void sortVectorByName(vector<Student>& Students) {

	// Bubble Sort Algorithm

	for (int i = 0; i < Students.size(); i++) {

		for (int j = i + 1; j < Students.size(); j++) {

			Student temp;

			if (Students.at(i).getName() > Students.at(j).getName()) {

				temp = Students.at(i);
				Students.at(i) = Students.at(j);
				Students.at(j) = temp;


			}

		}

	}

}

void printVectorByClass(vector<Student>& Students, char c) {

	if (c == 'f') {

		float sum = 0;
		int count = 0;

		cout << "Name               Class       GPA" << endl;
		cout << "-----------------------------------------" << endl;
		for (int i = 0; i < Students.size(); i++) {

			if (Students.at(i).getClass() == "Freshman") {

				cout << Students.at(i) << endl;

				sum += Students.at(i).getGPA();

				count++;

			}
		}

		float avg = sum / count;

		cout << endl;
		cout << "Average GPA of Freshman: " << avg << endl << endl;
	}

	else if (c == 's') {

		float sum = 0;
		int count = 0;

		cout << "Name               Class       GPA" << endl;
		cout << "-----------------------------------------" << endl;
		for (int i = 0; i < Students.size(); i++) {

			if (Students.at(i).getClass() == "Sophomore") {

				cout << Students.at(i) << endl;

				sum += Students.at(i).getGPA();

				count++;

			}
		}

		float avg = sum / count;

		cout << endl;
		cout << "Average GPA of Sophomores: " << avg << endl << endl;
	}

	else if (c == 'j') {

		float sum = 0;
		int count = 0;

		cout << "Name               Class       GPA" << endl;
		cout << "-----------------------------------------" << endl;
		for (int i = 0; i < Students.size(); i++) {

			if (Students.at(i).getClass() == "Junior") {

				cout << Students.at(i) << endl;

				sum += Students.at(i).getGPA();

				count++;

			}
		}

		float avg = sum / count;

		cout << endl;
		cout << "Average GPA of Juniors: " << avg << endl << endl;
	}

	else if (c == 'S') {

		float sum = 0;
		int count = 0;

		cout << "Name               Class       GPA" << endl;
		cout << "-----------------------------------------" << endl;
		for (int i = 0; i < Students.size(); i++) {

			if (Students.at(i).getClass() == "Senior") {

				cout << Students.at(i) << endl;

				sum += Students.at(i).getGPA();

				count++;

			}
		}

		float avg = sum / count;

		cout << endl;
		cout << "Average GPA of Seniors: " << avg << endl << endl;
	}

}

void printAllStudents(vector<Student>& Students) {

	cout << "Name               Class       GPA" << endl;
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < Students.size(); i++) {

		cout << Students.at(i) << endl;

	}

	float sum = 0;

	for (int i = 0; i < Students.size(); i++) {

		sum += Students.at(i).getGPA();

	}

	float avg = sum / Students.size();

	cout << endl;
	cout << "Average GPA of all students: " << avg << endl << endl;

}

void writeToFile(vector<Student> Students) {

	ofstream file;
	file.open("Output.txt");

	file << "Sorted Master List with GPAs" << endl << endl;

	for (int i = 0; i < Students.size(); i++) {

		file << Students.at(i) << endl;

	}

	float sum = 0;

	for (int i = 0; i < Students.size(); i++) {

		sum += Students.at(i).getGPA();

	}

	float avg = sum / Students.size();

	file << endl;
	file << "Average GPA of all students: " << avg << endl << endl;

	file << "-----------------------------------------" << endl;
	file << "Sorted Freshman List with GPAs" << endl << endl;

	float sumf = 0;
	int countf = 0;

	file << "Name               Class       GPA" << endl;
	file << "-----------------------------------------" << endl;
	for (int i = 0; i < Students.size(); i++) {

		if (Students.at(i).getClass() == "Freshman") {

			file << Students.at(i) << endl;

			sumf += Students.at(i).getGPA();

			countf++;

		}
	}

	float avgf = sumf / countf;

	file << endl;
	file << "Average GPA of Freshman: " << avgf << endl << endl;

	file << "-----------------------------------------" << endl;
	file << "Sorted Sophomore List with GPAs" << endl << endl;

	float sums = 0;
	int counts = 0;

	file << "Name               Class       GPA" << endl;
	file << "-----------------------------------------" << endl;
	for (int i = 0; i < Students.size(); i++) {

		if (Students.at(i).getClass() == "Sophomore") {

			file << Students.at(i) << endl;

			sums += Students.at(i).getGPA();

			counts++;

		}
	}

	float avgs = sums / counts;

	file << endl;
	file << "Average GPA of Sophomores: " << avgs << endl << endl;

	file << "-----------------------------------------" << endl;
	file << "Sorted Junior List with GPAs" << endl << endl;

	float sumj = 0;
	int countj = 0;

	file << "Name               Class       GPA" << endl;
	file << "-----------------------------------------" << endl;
	for (int i = 0; i < Students.size(); i++) {

		if (Students.at(i).getClass() == "Junior") {

			file << Students.at(i) << endl;

			sumj += Students.at(i).getGPA();

			countj++;

		}
	}

	float avgj = sumj / countj;

	file << endl;
	file << "Average GPA of Juniors: " << avgj << endl << endl;

	file << "-----------------------------------------" << endl;
	file << "Sorted Senior List with GPAs" << endl << endl;

	float sumS = 0;
	int countS = 0;

	file << "Name               Class       GPA" << endl;
	file << "-----------------------------------------" << endl;
	for (int i = 0; i < Students.size(); i++) {

		if (Students.at(i).getClass() == "Senior") {

			file << Students.at(i) << endl;

			sumS += Students.at(i).getGPA();

			countS++;

		}
	}

	float avgS = sumS / countS;

	file << endl;
	file << "Average GPA of Seniors: " << avgS << endl << endl;

}