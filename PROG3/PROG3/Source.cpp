#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stack>

using namespace std;

class obj {
public:
	
	int getn() { return this->n; };
	int getx() { return this->x; };
	int gety() { return this->y; };

private:

	int n, x, y;

};

stack<obj> st;

int fibonacci(int n) {

	int x, y;

	if (n <= 1) {

		return n;

	}
	else {


		x = fibonacci(n - 1);
		y = fibonacci(n - 2);

		int sum = x + y;

		return sum;

	}


}

int main() {

	stack<int> stack;

	ofstream file;
	file.open("Output.txt");

	cout << fibonacci(10);
	file << fibonacci(10);

	return 0;
}