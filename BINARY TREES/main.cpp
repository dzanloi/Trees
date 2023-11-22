#include <iostream>
#include <stdexcept>
#include "mybinarytree.h"

using namespace std;

int main(int argc, char** argv) {
	BinaryTree* tree = new MyBinaryTree();
	node* fifty = tree->addRoot(50);
	try {
		tree->addRoot(40);
	} catch (exception& e) {
		cout << e.what();
	} 
	node* thirty = tree->addLeft(fifty, 30);
	tree->addLeft(thirty, 20);
    node* five = tree->addRight(thirty, 5);
	
	tree->print();
	return 0;
}