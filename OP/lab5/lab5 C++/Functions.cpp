#include "Functions.h"

string getFileName()
{
	string filename;
	cout << "Enter file name: ";
	cin >> filename;
	return filename;
}

void printFile(string filename)
{
	ifstream fin(filename);

	if (!fin.is_open())
	{
		cout << "Error. File is not found.\n";
	}
	else
	{
		cout<<endl << filename << ":\n";
		string line;
		int counter = 0;
		while (!fin.eof())
		{
			getline(fin, line);
			counter++;
			cout << counter << "\t" << line << endl;
		}
		cout << endl;
	}

	fin.close();
}

void readFile(string filename, Tree& tree)
{
	ifstream fin(filename);

	if (!fin.is_open())
	{
		cout << "Error. File is not found.\n";
	}
	else
	{
		string line;
		int counter = 0;
		
		while (!fin.eof())
		{
			getline(fin, line);
			counter++;
			vector<string> types{ "int ","float ","double ","char ","bool " };
			bool condition = false;
			string type = "";

			for (size_t i = 0; i < types.size(); i++)
			{
				if (line.find(types[i]) < line.length())
				{
					condition = true;
					type = types[i];
					break;
				}
			}

			if (condition && line.find(";") < line.length())
			{
				findIdentifier(tree, line, counter, type);
			}
		}
		
	}

	fin.close();
}

void findIdentifier(Tree& tree, string line, int counter, string type)
{
	int startIndex = line.find(type) + type.length();
	int idLength = line.length() - startIndex - 1;

	if (line.find("=") < line.length())
		idLength -= (line.length() - line.find("="));

	string temp = line.substr(startIndex, idLength);

	if (line.find("const ") < line.length())
	{
		tree.insert(temp, counter, "right");
	}
	else
	{
		tree.insert(temp, counter, "left");
	}
}
