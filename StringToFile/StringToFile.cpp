// StringToFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;



class someStream {
private:
	string filePath;
	int command;

public:
	bool run;
	string text;


	//constructor
	someStream()
	{
		//instantiates all variables
		filePath = "";
		command = 0;
		text = "";
		run = true;
	}

	//destructor
	~someStream()
	{
		//release all memory here
	}


	void typeWriter()
	{
		cout << "Here is a fresh slate!" << endl;
		cout << "To stop writing, after submitting a new line, type '/finish' and click enter. Also type /clear to clear saved text." << endl << endl;

		string subText;
		bool fin = true;

		while (fin)
		{
			getline(cin, subText);

			//if != finish write to subtext
			if (subText == "/finish")
			{
				cout << "END WRITING" << endl << endl;
				fin = false;
				break;
			}
			else if (subText == "/clear")
			{
				cout << "TEXT CLEARED" << endl << endl;
				text = "";
			}
			else
			{
				if (text == "")
				{
					text = subText + "\n";
				}
				else
				{
					//cout << subText << endl;
					text = text + subText + "\n";
				}
			}
		}
	}


	void readString()
	{
		//cout << "Where would like to save your file? (Enter a valid file path)" << endl;
		//getline(cin, filePath);
		filePath = "FILES/";
		cout << "What file would you like to load?" << endl;
		string fileName;
		cin >> fileName;
		//concatenates *DEFAULT filepath with the fileName Input
		string fullPath = filePath + fileName;


		//clears text before loading
		text = "";

		//creates new read object
		ifstream readObj;
		//opens file in input mode
		readObj.open(fullPath, ios::in);
		//reads in data
		while (!readObj.eof())
		{
			string subText;
			getline(readObj, subText);
			text += subText + "\n";
		}
		//close read object
		readObj.close();


		//PRINT INPUT
		cout << "File Loaded" << endl << endl;
		//HERE TO WRITE LINE FOR LINE
		//CURRENTLY JUST EXPORTING TEXT TO SCREEN.
		cout << text << endl << endl;
	}


	void writeString()
	{
		//GETS ALL INPUT FROM USER ABOUT WHERE AND HOW TO SAVE FILE
		//cout << "Where would like to save your file? (Enter a valid file path)" << endl;
		//getline(cin, filePath);
		filePath = "FILES/";
		cout << "What would like to save your file as?" << endl;
		string fileName;
		cin >> fileName;
		//concatenates *DEFAULT filepath with the fileName Input
		string fullPath = filePath + fileName;



		//creates new write object
		ofstream writeObj;
		//opens file in output mode
		writeObj.open(fullPath, ios::out);
		//write text to file
		writeObj << text;
		//close write object
		writeObj.close();

		cout << "File saved at " << fullPath << endl << endl;
	}


	void takeCommand()
	{
		//enter command
		cout << "What would you like to do?" << endl;

		//commands
		cout << "0) exit" << endl;
		cout << "1) type" << endl;
		cout << "2) save" << endl;
		cout << "3) load" << endl;


		//take the input
		cin >> command;


		//SWITCH BASED OFF OF INPUT
		switch (command)
		{
			//exit
		case 0:
			cout << endl;
			exitProgram();
			break;
			//type
		case 1:
			cout << endl;
			typeWriter();
			break;
			//save
		case 2:
			cout << endl;
			writeString();
			break;
			//load
		case 3:
			cout << endl;
			readString();
			break;
		default:
			cout << endl;
			cout << "That is not a valid command" << endl;
			break;
		}

	}
	
	//this function should terminate the program | ISSUE = be sure that all memory from stack and heap have been released.
	void exitProgram() 
	{
		run = false;
		exit(0);
	} 


};












//MAIN FUNCTION
int main()
{
	someStream s;

	while (s.run)
	{
		s.takeCommand();
	}
	
	cout << "Thanks for using someStream" << endl;
}




