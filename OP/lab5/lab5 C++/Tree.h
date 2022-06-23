#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Node
{
	string data;
	int key;
	Node* left;
	Node* right;
	Node(string d, int key) :data(d),key(key), left(NULL), right(NULL) {}
	~Node();
};

class Tree
{
	Node* root;
	Node* insertRecursion(Node*, string, int, string);
	void showRecursion(const string&, const Node*, bool);
public:
	Tree() :root(NULL) {};
	~Tree();
	
	void insert(string, int, string);
	void show();
};