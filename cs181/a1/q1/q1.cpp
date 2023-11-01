// Karl Ramberg
// 2-14-19
// CS181 - Assignment 1 - Q1
// prints the first ten lines of a file

#include<iostream>
#include<fstream>

using namespace std;

// opens a file the user requests
// parameter - filename - string for holding a filename to open
// parameter - file - the input stream to open a file with
void getInputFile(string &filename, ifstream &file);

int main()
{
	string filename;
	ifstream inputFile;
	getInputFile(filename, inputFile);
	cout << "Reading the first 10 lines of " << filename << "..." << endl;

	int count = 0;
	string line;
	while(count < 10 && getline(inputFile, line))
	{
		cout << line << endl;
		count++;
	}

	if(count < 10)
	{
		cout << "FULL FILE PRINTED" << endl;
	}

	inputFile.close();
	return 0;
}

public void getInputFile(string &filename, ifstream &file)
{
	cout << "Enter a filename: ";
	cin >> filename;

	file.open(filename);

	while(file.fail())
	{
		cout << "Cannot read that file" << endl;
		cout << "Enter a filename: ";
		cin >> filename;
		file.open(filename);
	}
}

