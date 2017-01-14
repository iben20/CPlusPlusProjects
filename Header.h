#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//create a class that takes in a word and manipulates it
class Word
{
private:
	vector<string> s;

	//this will store the user's name, only used for aesthetics of the program
	string name;

	//iterator will be used to navigate through the vector 
	vector<string>::iterator siter;

	//string pointer will be used to point to the string
	string* strptr;

	//this will display the function name
	string func_name;

	//this will store the current word
	string current_word;

	int vector_length, str_length, choice;

public:	
	//no argument constructor
	Word()
	{
		strptr = NULL;
		siter = s.begin();
		vector_length = 0;
		str_length = 0;
		current_word = "";
		choice = 0;
		name = "";
	}

	//"Main Menu"
	void Help();

	//function to reverse the word
	void Reverse();

	//function to count the number of vowels 
	void CountVowels();

	//count how many letter in the word
	void HowManyLetters();

	//choice will determine which function to run
	void Choice();

	//add word
	void AddWord();

	//shows the word list
	void WordList();

	//enters the user's name
	void User(string s);

	//removes the specified character from string 's'
	string remove(string s, string &word);

	//a function to start the program
	void Start();

	//reteurns the user's name
	string User();

	//Set the current word
	void SetCurrentWord();
};

//function that generates a banner for customer
void banner_word();

#endif // !HEADER_H