#include "node.h"
class BinaryTree {
    public:
    virtual node* addRoot(int) = 0;
	virtual node* addLeft(node*, int) = 0;
	virtual node* addRight(node*, int) = 0;
	virtual int findDepth(node* p) = 0;
	virtual int findHeight(node* p) = 0;
	virtual int remove(node* p) = 0;
	virtual void print() = 0;
};