// Karl Ramberg
// 2-17-19
// CS181 - Assignment 1 - Q3
// Tool for encrypting and decrypting files

#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

void getInputFile(string &filename, ifstream &file);

void encrypt(string inputFilename, ifstream &input, ofstream &output);

void decrypt(string inputFilename, ifstream &input, ofstream &output);

int main()
{
    ifstream original;
    string originalFilename;
    getInputFile(originalFilename, original);

    int choice;
    cout << "(1) Encrypt or (2) Decrypt? ";
    cin >> choice;

    if (choice == 1) {
	ofstream encrypted("encrypted.txt");
	encrypt(originalFilename, original, encrypted);
        encrypted.close();
    } else {
	ofstream decrypted("decrypted.txt");
	decrypt(originalFilename, original, decrypted);
	decrypted.close();
    } 

    original.close();
    return 0;
}

void getInputFile(string &filename, ifstream &file)
{
    cout << "Choose a file: ";
    cin >> filename;
    
    file.open(filename);

    while(file.fail())
    {
	cout << "Cannot read that file" << endl;
	cout << "Choose a file: ";
	cin >> filename;
	file.open(filename);
    }
}

void encrypt(string inputFilename,ifstream &input, ofstream &output)
{
    cout << "Encrypting " << inputFilename << "..." << endl;

    input.seekg(ios::beg);

    unsigned seed = static_cast<unsigned int>(time(nullptr));
    output.write(reinterpret_cast<char *>(&seed), sizeof seed);
    
    char c;
    input.get(c);
    while(!input.eof())
    {
	c += seed;
	output.write(reinterpret_cast<char *>(&c), sizeof c);
	input.get(c);
    }	
}

void decrypt(string inputFilename, ifstream &input, ofstream &output)
{
    cout << "Decrypting " << inputFilename << "..." << endl;

    input.seekg(ios::beg);

    unsigned seed;
    input.read(reinterpret_cast<char *>(&seed), sizeof seed);

    char c;
    input.get(c);
    while(!input.eof())
    {
	c -= seed;
	output.write(reinterpret_cast<char *>(&c), sizeof c);
	input.get(c);
    }   
}
