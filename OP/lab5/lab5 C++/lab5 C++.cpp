#include "Functions.h"

int main()
{	
	Tree tree;
	string filename = getFileName();

	printFile(filename);
	readFile(filename, tree);

	tree.show();
}