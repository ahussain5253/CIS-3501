#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main() {

	ifstream input;
	input.open("Input.txt");

	map<string, double> Students; // String = Name; int = GPA

	struct Student
	{
		string name;
		double gpa;

	};

	for (int i = 0; !input.eof(); i++) {

		string name; double gpa;

		input >> name >> gpa;

		Students.insert({ name, gpa });

	}

	ofstream file;
	file.open("Output.txt");


	for (auto itr = Students.begin(); itr != Students.end(); ++itr) {

		cout << itr->first << '\t' << itr->second << '\n';
		file << itr->first << '\t' << itr->second << '\n';

	}
	

	return 0;

}