#include <iostream>

using namespace std;

int main() {

	int distMAT[6][6] = 

	{	{0,2,5,99,99,99},
		{99,0,7,1,99,8},
		{99,99,0,4,99,99},
		{99,99,99,0,3,99},
		{99,99,2,99,0,3},
		{99,5,99,2,4,0}	
	};

	for (int k = 0; k <= 5; k++) {

		for (int i = 0; i <= 5; i++) {

			for (int j = 0; j <= 5; j++) {

				if (distMAT[i][j] > distMAT[i][k] + distMAT[k][j]) {

					distMAT[i][j] = distMAT[i][k] + distMAT[k][j];

				}

			}

		}

		cout << endl << endl;
		cout << "Distance Matrix for k = " << k << endl << endl;

		cout << "    0   1   2   3   4   5" << endl;
		cout << "  ________________________" << endl;

		for (int i = 0; i <= 5; i++) {

			cout << i << "|  ";

			for (int j = 0; j <= 5; j++) {

				cout << distMAT[i][j] << "   ";

				if (j == 5) {

					cout << endl;

				}

			}

		}

		cout << endl << endl;
		cout << "Path Matrix for k = " << k << endl << endl;

		cout << "    0   1   2   3   4   5" << endl;
		cout << "  ________________________" << endl;

		for (int i = 0; i <= 5; i++) {

			cout << i << "|  ";

			for (int j = 0; j <= 5; j++) {

				if (distMAT[i][j] == 99 || distMAT[i][j] == 0) {

					cout << "-" << "   ";

				}
				else {

					cout << i << "   ";


				}


			

				if (j == 5) {

					cout << endl;

				}

			}

		}

	}
	



	return 0;
}