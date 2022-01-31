

#include "Header.h";

int main() {

	
	vector<Student> Students;

	populateVectorStudents(Students);

	int a = 1;

	while (a == 1) {

		int num;

		cout << "What would you like to do?" << endl << endl;
		cout << "1: Sorted master list with average GPA" << endl;
		cout << "2: Freshman list with average GPA" << endl;
		cout << "3: Sophomore list with average GPA" << endl;
		cout << "4: Junior list with average GPA" << endl;
		cout << "5: Senior list with average GPA" << endl;
		cout << "6: Write all lists to a file" << endl << endl;
		cout << "Please enter the option number" << endl << endl;

		cin >> num;
		cout << endl;

		if (num == 1) {

			sortVectorByName(Students);

			printAllStudents(Students);


		}

		else if (num == 2) {

			sortVectorByName(Students);
			printVectorByClass(Students, 'f');

		}

		else if (num == 3) {

			sortVectorByName(Students);
			printVectorByClass(Students, 's');

		}

		else if (num == 4) {

			sortVectorByName(Students);
			printVectorByClass(Students, 'j');

		}

		else if (num == 5) {

			sortVectorByName(Students);
			printVectorByClass(Students, 'S');

		}

		else if (num == 6) {

			sortVectorByName(Students);
			writeToFile(Students);

			cout << "Success!" << endl;
		}

		cout << endl;
		cout << "Again? (0 for no or 1 for yes)" << endl << endl;
		cin >> a;
		cout << endl;

	}
	

	return 0;
}


