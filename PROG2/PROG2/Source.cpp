#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

vector<string*> populatePointersVector() {

	vector<string*> pointerNames;

	ifstream input;
	input.open("Input.txt");

	while (!input.eof()) {

		string name;

		input >> name;

		pointerNames.push_back(&name);

	}

	return pointerNames;

}

void sortNames(vector<string*> &Names) {

	for (int i = 0; i < Names.size(); i++) {

		for (int j = i + 1; j < Names.size(); j++) {

			string* temp;

			if (Names.at(i) > Names.at(j)) {

				temp = Names.at(i);
				Names.at(i) = Names.at(j);
				Names.at(j) = temp;

			}

		}


	}

}

int main() {


	vector<string*> pointerNames;

	ifstream input;
	input.open("Input.txt");

	while (!input.eof()) {

		string name;

		input >> name;

		pointerNames.push_back(&name);

	}

	cout << *pointerNames.at(0);


	
	
	return 0;
}