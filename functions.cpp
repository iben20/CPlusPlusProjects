#include "Header.h"

void flush()
{
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void banner_word()
{
	cout << "==============================================================\n";
	cout << "=                         WORD PROGRAM                       =\n";
	cout << "==============================================================\n";
}

string Word::remove(string s, string &word)
{
	while (word.find(s) <= word.length())
		{
			word.erase(word.find(s), 1);
		}

	return word;
}

void Word::Help()
	{
		do
		{
			func_name = "Help() Function";
			system("CLS");
			banner_word();
			cout << "The current word is \"" << current_word <<"\".\n\n";  
			cout << "These are the things that I may do:\n";
			cout << "1. Reverse \"" << current_word << "\".\n";
			cout << "2. Count the number of vowels in \"" << current_word << "\".\n";
			cout << "3. Count the number of letters in \"" << current_word << "\".\n";
			cout << "4. Add another word.\n";
			cout << "5. Display word list.\n";
			cout << "6. Set Current Word.\n";
			cout << "99. Exit. " << endl<< endl;
			cout << "Please enter your choice: ";
			cin >> choice;
			Choice();
		} while (choice != 99);
	}

void Word::Reverse()
	{
		func_name = "Reverse Function";
		//return the reversed word
		cout << func_name << " Initialized..." << endl;
		cout << current_word; cout << " in reverse is: "; 
		for (int i = (str_length - 1); i >= 0; i--)
		{
			cout << current_word[i];
		}
		cout << "\n\n";
		system("pause");
	}

void Word::CountVowels()
	{
		func_name = "Counting Vowels Function";
		cout << func_name << " Initialized..." << endl;
		cout << "The number of vowels in " << current_word << " is ";
		int vowel = 0;
		for (int i = 0; i < str_length; i++)
		{
			char j = toupper(current_word[i]);
			if (j == 'A' || j == 'E' || j == 'I' || j == 'O' || j == 'U')
			{
				vowel++;
			}
		}
		cout << vowel << "\n\n";
		system("pause");
	}

void Word::HowManyLetters()
	{
		func_name = "How Many Letters Function";
		cout << func_name <<" Initialized..." << endl;
		cout << "The number of letters in " << current_word << " is " << str_length << "\n\n";
		system("pause");
	}

void Word::Choice()
	{
		if (choice == 1)
		{
			Reverse();
		}

		else if (choice == 2)
		{
			CountVowels();
		}

		else if (choice == 3)
		{
			HowManyLetters();
		}

		else if (choice == 4)
		{
			AddWord();
		}

		else if (choice == 5)
		{
			WordList();
		}

		else if (choice == 6)
		{
			SetCurrentWord();
		}

		else if (choice == 99)
		{
			cout << "Good bye "<< name << endl;
			return;
		}

		else
		{
			cout << "Invalid choice, please try again!\n\n";
			flush();
			Help();
		}

	}

//SET CURRENT WORD HAS ISSUES
void Word::SetCurrentWord()
{
	WordList();
	int a;
	cout << "Which word would you like to manipulate?(Enter a number) " << endl;
	cin >> a;
	flush();
	//see if the choice is a number
	current_word = s.at(a-1);
}

void Word::AddWord()
{
	string input;
	cout << "Please enter a new word to add: ";
	flush();
	getline(cin, input);
	current_word = input;
	s.push_back(input);
}

void Word::WordList()
{
	int i = 1;
	siter = s.begin();
	cout << "This is the list of words that you've inputted sir:" << endl;

	while (siter != s.end())
	{
		cout << i << ". " << *siter << endl;
		i++; siter++;
	}
	system("pause");
}

void Word::Start()
{
	cout << "Greetings, I am the Word program.\nI can manipulate any word you wish." << endl;
	cout << "To whom am I speaking with? ";
	getline(cin, name);
	cout << "\nHello " << User() << ".\nPlease enter a word you'd like to manipulate: " << endl;
	getline(cin, current_word);
	str_length = current_word.length();
	s.push_back(current_word);
	vector_length = s.size();
	Help();
};

string Word::User()
{
	return name;
};