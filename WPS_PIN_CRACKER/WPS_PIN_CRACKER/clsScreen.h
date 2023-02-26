#pragma once


#include<iostream>
using namespace std;


class clsScreen {

	protected:

	static void _clearScreen(void);

	static	void _pauseScreen(void);

	static	void _makeSound(void);

	static	void _drawScreenHeader(string, string);

};



void clsScreen::_clearScreen() {
	system("cls");
}

void clsScreen::_pauseScreen() {
	system("pause>0");
}

void _makeSound() {
	cout << "\a";
}

void clsScreen::_drawScreenHeader(string title, string description = "") {


	cout << "\n\n\t\t\t\t\t____________________________________________________";
	cout << "\n\n\t\t\t\t\t" << title;

	if (description != "") {
		cout << "\n\n\t\t\t\t\t" << description;
	}

	cout << "\n\n\t\t\t\t\t____________________________________________________";



}
