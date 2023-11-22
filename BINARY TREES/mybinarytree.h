#include "binarytree.h"
#include <stdexcept>
#include <iostream>

using namespace std;

class MyBinaryTree : public BinaryTree {
	node* root;
	int size;
	
	public:
	MyBinaryTree() {
		root = nullptr;
		size = 0;
	}

	node* addRoot(int e){
		if (!root) {
			node* n = (node*) calloc(1, sizeof(node));
			n->elem = e;
			size++;
			root = n;
			return n;
		}
		throw logic_error("Already has root");
	}

	node* addLeft(node* p, int e) {
		if (!p->left) {
			node* n = (node*) calloc(1, sizeof(node));
			n->elem = e;
			n->parent = p;
			size++;
			p->left = n;
			return n;
		}
		throw logic_error("Already has root");
	}

	node* addRight(node* p, int e ) {
		if (!p->right) {
			node* n = (node*) calloc(1, sizeof(node));
			n->elem = e;
			n->parent = p;
			p->right = n;
			size++;
			return n;
		}
		throw logic_error("Already has root");
	}

	int findHeight(node* p) {
		if(!root) {
			return -1;
		} else {
			return 1 + max(findHeight(p->left), findHeight(p->right));
		}
	}

	int findDepth(node* p) {
		if(!root) {
			return -1;
		} else {
			return 1 + findDepth(p->parent);
		}
	}

	int remove(node* p) {
		int data = p->elem;
		if(p->left && p->right) {
			cout << "Error, cant remove if naay 2 ka anak";
			return 0;
		}
		node* temp = p->parent;
		if(temp->left == p || temp->right == p) {
			free(p);
			temp->left = nullptr;
			temp->right = nullptr;
		}
		size--;
		return data;
	}


	void print(){
		cout << "Size: " << size << endl;
		print(root);
	}

	void print(node* n) {
		if (n) {
			cout << n->elem << endl;
			if (n->left) {
				cout << "L: ";
				print(n->left);
			}
			if (n->right) {
				cout << "R: ";
				print(n->right);
			}
		}
	}
};