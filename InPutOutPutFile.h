#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
using namespace std;

void main()
{
	//the ifstream class stands for input file stream
	//input file stream is used to OPEN/READ the file
	ifstream inFile;

	//use the member function open() and type in the file name
	inFile.open("file.txt");

	//you must check for errors 
	if (inFile.fail())
	{
		cout << "Error. File corrupted." << endl;
		//this will exit the application
		exit(1);
	}

	//the file "file.txt" contains 6 words, one word per line
	//create a string array that will contain 6 words 
	string str[6];
	for (int i = 0; i < 6; i++)
	{
		//use the >> to take each word and place it inside the string array
		inFile >> str[i];
	}
	
	//display the contents 
	for (int i = 0; i < 6; i++)
	{
		cout << "str[" << i << "] = " << str[i] << endl;
	}

	//don't forget to close the file
	inFile.close();
	cout << "==============================================" << endl;

	ifstream file1;
	file1.open("numbers.txt");

	if (file1.fail())
	{
		cout << "Error in opening file." << endl;
	}

	//How to display the contents of a file another way
	int count = 0;
	int item;

	//use a loop to read until the end of file (EOF)
	while (!file1.eof())
	{
		//this will take the string in the current line within the 'inFile' and place it in the variable 'item'
		file1 >> item;
		//display what was read
		cout << "Item = " << item << endl;
		//update the counter to see how many items were in the file
		count++;
	}

	cout << "There are " << count << " number of items in this file." << endl;
	file1.close();
	cout << "==============================================" << endl;

	//how to write to a file
	//must use ofstream, which stands for outfile stream

	ofstream outFile;
	outFile.open("sample.txt"); //"sample.txt" doesn't exist, but it will be created

	//to write to a file:
	outFile << "Hello World!" << endl;
	outFile << "This is the second line" << endl;
	outFile << "Steven Susanto." << endl;

	//don't forget to type .close();
	outFile.close();
	
};