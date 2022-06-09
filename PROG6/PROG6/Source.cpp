#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ofstream file;
	file.open("Output.txt");

	int distMAT[6][6] = 

	{	{0,2,5,99,99,99},
		{99,0,7,1,99,8},
		{99,99,0,4,99,99},
		{99,99,99,0,3,99},
		{99,99,2,99,0,3},
		{99,5,99,2,4,0}	
	};

	int pathMAT[6][6] =

	{	{99,0,0,99,99,99},
		{99,99,1,1,99,1},
		{99,99,99,2,99,99},
	    {99,99,99,99,3,99},
		{99,99,4,99,99,4},
		{99,5,99,5,5,99}
	};

	for (int k = 0; k <= 5; k++) {

		for (int i = 0; i <= 5; i++) {

			for (int j = 0; j <= 5; j++) {

				if (distMAT[i][j] > distMAT[i][k] + distMAT[k][j]) {

					distMAT[i][j] = distMAT[i][k] + distMAT[k][j];

					if (distMAT[i][j] == 0 || distMAT[i][j] == 99) {

						pathMAT[i][j] = 99;
					}
					else {

						pathMAT[i][j] = i;

					}

				}

			}

		}

		cout << endl << endl;
		cout << "Distance Matrix for k = " << k << endl << endl;
		file << endl << endl;
		file << "Distance Matrix for k = " << k << endl << endl;

		cout << "    0   1   2   3   4   5" << endl;
		cout << "  ________________________" << endl;
		file << "    0   1   2   3   4   5" << endl;
		file << "  ________________________" << endl;

		for (int i = 0; i <= 5; i++) {

			cout << i << "|  ";
			file << i << "|  ";

			for (int j = 0; j <= 5; j++) {

				cout << distMAT[i][j] << "   ";
				file << distMAT[i][j] << "   ";

				if (j == 5) {

					cout << endl;
					file << endl;

				}

			}

		}

		cout << endl << endl;
		cout << "Path Matrix for k = " << k << endl << endl;
		file << endl << endl;
		file << "Path Matrix for k = " << k << endl << endl;

		cout << "    0   1   2   3   4   5" << endl;
		cout << "  ________________________" << endl;
		file << "    0   1   2   3   4   5" << endl;
		file << "  ________________________" << endl;

		for (int i = 0; i <= 5; i++) {

			cout << i << "|  ";
			file << i << "|  ";

			for (int j = 0; j <= 5; j++) {

				if (pathMAT[i][j] == 99 || pathMAT[i][j] == 0) {

					cout << "-" << "   ";
					file << "-" << "   ";

				}
				else {

					cout << i << "   ";
					file << i << "   ";

				}

				if (j == 5) {

					cout << endl;
					file << endl;

				}

			}

		}

		cout << endl;
		cout << "----------------------------------" << endl;
		file << endl;
		file << "----------------------------------" << endl;

	}

	cout << endl;
	cout << "Shortest Distance Matrix:" << endl << endl;
	file << endl;
	file << "Shortest Distance Matrix:" << endl << endl;

	cout << "    0   1   2   3   4   5" << endl;
	cout << "  ________________________" << endl;
	file << "    0   1   2   3   4   5" << endl;
	file << "  ________________________" << endl;

	for (int i = 0; i <= 5; i++) {

		cout << i << "|  ";
		file << i << "|  ";

		for (int j = 0; j <= 5; j++) {

			cout << distMAT[i][j] << "   ";
			file << distMAT[i][j] << "   ";

			if (j == 5) {

				cout << endl;
				file << endl;

			}

		}

	}


	
	return 0;
}