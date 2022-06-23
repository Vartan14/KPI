#include "Tree.h"

Node::~Node()
{
	delete left;
	delete right;
}

Tree::~Tree()
{
	delete root;
}

Node* Tree::insertRecursion(Node* temp, string value, int key, string branch)
{
	if (temp == NULL)
	{
		return new Node(value, key);
	}
	if (branch == "left")
	{
		temp->left = insertRecursion(temp->left, value, key, branch);
	}
	else if (branch == "right")
	{
		temp->right = insertRecursion(temp->right, value, key, branch);
	}
	return temp;
}

void Tree::insert(string value, int key, string branch)
{
	if (root == NULL)
	{
		root = insertRecursion(root, value, key, branch);
	}
	else
	{
		insertRecursion(root, value, key, branch);
	}
}

void Tree::showRecursion(const string& prefix, const Node* temp, bool isRight)
{
	if (temp != NULL)
	{
		cout << prefix;
		cout << (isRight ? "|--" : "\\--");
		cout << temp->data << "(" << temp->key << ")" << endl;
		showRecursion(prefix + (isRight ? "|       " : "        "), temp->right, true);
		showRecursion(prefix + (isRight ? "|       " : "        "), temp->left, false);
	}
}

void Tree::show()
{
	cout << "\nTree:\n";
	showRecursion("", root, false);
	cout << "\n\n";
}