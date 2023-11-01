// Karl Ramberg
// 2-16-19
// CS181 - Assignment 1 - Q2
// Tells a joke give a joke and punchline

#include<iostream>
#include<fstream>

using namespace std;

void getInputFile(ifstream &file);
 
void printFile(ifstream &file);

void printLastLine(ifstream &file);

int main()
{
    ifstream jokeFile;
    cout << "Choose a joke - ";
    getInputFile(jokeFile);

    ifstream punchlineFile;
    cout << "Choose the punchline - ";
    getInputFile(punchlineFile);
    
    printFile(jokeFile);
    printLastLine(punchlineFile);

    jokeFile.close();
    punchlineFile.close();
    return 0;
}

void getInputFile(ifstream &file)
{
    string filename;
    cout << "enter a filename: ";
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

void printFile(ifstream &file)
{
    string line;
    while(getline(file, line))
    {
	cout << line << endl;
    }
}

void printLastLine(ifstream &file)
{
    string line;
    int oldLineStart = 0; 
    int newLineStart = 0;
    while(!file.eof())
    {
	oldLineStart = newLineStart; 
	newLineStart = file.tellg();
	getline(file, line);
    }
    file.clear();

    file.seekg(static_cast<long>(oldLineStart));
    getline(file, line);
    cout << endl << line << endl;
}
