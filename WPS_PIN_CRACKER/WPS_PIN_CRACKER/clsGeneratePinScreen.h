#pragma once


#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsScreen.h"
using namespace std;



class clsGeneratePinScreen: clsScreen {


	private:

		enum enSaveAnswer { Yes = 1 ,  No = -1 };
		
		static int _readNumberOfPins(void);

		static bool _isValidNumberOfPins(int);

		static int _getRandomNumber(int, int);

		static vector<string> vGenerateRandomPins(int);

		static string _generatePin(void);

		static enSaveAnswer _readSaveAnswer(void);

		static void _saveResultsToFile(vector<string>);

		static string _readFileName(void);

		static void _printPins(vector<string>);

	public:


		static void showGeneratePinScreen(void);

};


void clsGeneratePinScreen::showGeneratePinScreen() {

	_clearScreen();

	_drawScreenHeader("\n\t\t\t\t\t\t\tGenerate WPS PIN Screen");

	int numberOfPins = _readNumberOfPins();

	vector<string> vPins = vGenerateRandomPins(numberOfPins);

	_printPins(vPins);

	enSaveAnswer answer = _readSaveAnswer();

	if (answer == enSaveAnswer::Yes) {

		_saveResultsToFile(vPins);

	}


	cout << "\n\n\n\t\t\t\t\tPree Any Key To Continue ...";
	
	_pauseScreen();

}


int clsGeneratePinScreen::_readNumberOfPins() {

	int number = 0;

	do {
		cout << "\n\n\t\t\t\t\tEnter Number of Pins to generate: ";
		cin >> number;

	} while (!_isValidNumberOfPins(number));

	return number;
}

bool clsGeneratePinScreen::_isValidNumberOfPins(int number) {
	return (number > 0);
}

int clsGeneratePinScreen::_getRandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}

vector<string> clsGeneratePinScreen::vGenerateRandomPins(int numberOfPins) {

	vector<string> vPins;
	
	string pin = "";

	for (int i = 1; i <= numberOfPins; i++) {

		pin = _generatePin();

		vPins.push_back(pin);

	}

	return vPins;
}

string clsGeneratePinScreen::_generatePin() {

	string pin = "";

	for (short i = 1; i <= 8 ; i++) {
		
		pin += to_string(_getRandomNumber(0, 9));

	}

	return pin;
}

clsGeneratePinScreen::enSaveAnswer clsGeneratePinScreen::_readSaveAnswer() {

	char answer = 'N';

	cout << "\n\n\t\t\t\t\tDo You Want To Save Results To File [ Y | N ] ? ";
	cin >> answer;

	answer = toupper(answer);

	return (answer == 'Y') ? clsGeneratePinScreen::enSaveAnswer::Yes : clsGeneratePinScreen::enSaveAnswer::No;
}

string clsGeneratePinScreen::_readFileName() {

	string filename = "";

	cout << "\n\n\t\t\t\t\tEnter Filename: ";
	cin >> filename;

	return filename;

}

void clsGeneratePinScreen::_saveResultsToFile(vector<string> vPins) {

	string filename = _readFileName();

	fstream myFile;

	myFile.open(filename, ios::app | ios::out);

	if (myFile.is_open()) {

		for (string& pin : vPins) {

			myFile << pin << endl;

		}

		myFile.close();
	}

	cout << "\n\n\t\t\t\t\tPins Saved To " << filename;

}

void clsGeneratePinScreen::_printPins(vector<string> vPins) {

	int counter = 0;

	for (string& pin : vPins) {

		cout << "\n\t\t\t\t\t[" << ++counter << "]  " << pin;

	}

}