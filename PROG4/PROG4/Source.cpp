#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

struct Node {

	int data;
	Node* left;
	Node* right;

};

Node* newNode(int data) {

	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	return newNode;

}

Node* insertData(Node* rootNode, int data) {

	if (rootNode == NULL) { rootNode = newNode(data); }

	else if (data <= rootNode->data) { rootNode->left = insertData(rootNode->left, data); }

	else { rootNode->right = insertData(rootNode->right, data); }

	return rootNode;
}

void Preorder(Node* rootNode) {

	if (rootNode == NULL) { return; }

	cout << " " << rootNode->data;
	

	Preorder(rootNode->left);
	Preorder(rootNode->right);

}

void Inorder(Node *rootNode) {

	if (rootNode == NULL) { return; }

	Inorder(rootNode->left);
	
	cout << " " << rootNode->data;

	Inorder(rootNode->right);
}

void Postorder(Node* rootNode) {

	if (rootNode == NULL) { return; }

	Postorder(rootNode->left);
	Postorder(rootNode->right);

	cout << " " << rootNode->data;

}


int main() {

	Node* rootNode = NULL; // Empty Tree

	rootNode = insertData(rootNode, 14);
	rootNode = insertData(rootNode, 4);
	rootNode = insertData(rootNode, 15);
	rootNode = insertData(rootNode, 3);
	rootNode = insertData(rootNode, 9);
	rootNode = insertData(rootNode, 14);
	rootNode = insertData(rootNode, 18);
	rootNode = insertData(rootNode, 7);
	rootNode = insertData(rootNode, 9);
	rootNode = insertData(rootNode, 16);
	rootNode = insertData(rootNode, 20);
	rootNode = insertData(rootNode, 5);
	rootNode = insertData(rootNode, 7);
	rootNode = insertData(rootNode, 4);
	rootNode = insertData(rootNode, 5);




	cout << "Preorder Transversal: "; Preorder(rootNode); cout << endl << endl;
	cout << "Inorder Transversal: "; Inorder(rootNode); cout << endl << endl;
	cout << "Postorder Transversal: "; Postorder(rootNode); cout << endl << endl;

	ofstream file;
	file.open("Output.txt");


	return 0;
}