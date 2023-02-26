#pragma once


#include<iostream>
#include"clsScreen.h"
#include"clsGeneratePinScreen.h"
using namespace std;



class clsLaunchScreen: clsScreen {


	private:



	public:

		static void showLaunchScreen(void);

};



void clsLaunchScreen::showLaunchScreen() {

	_drawScreenHeader("\n\t\t\t\t\t\t\tWPS PIN Cracker");

	
	cout << "\n\n\t\t\t\t\tWPS is a feature in WPA/WPA2 that allows devices";
	cout << "\n\t\t\t\t\tTo connect to the network using a 8 digit PIN";
	cout << "\n\t\t\t\t\twithout needing the actual password";
	cout << "\n\t\t\t\t\tAuthentication is done using 8 digits PIN";
	cout << "\n\t\t\t\t\tIf we get the 8 PIN key we can use";
	cout << "\n\t\t\t\t\treverse engineering to compute the actual password";
	cout << "\n\t\t\t\t\tWPS only works if PBC is not used.";

	cout << "\n\n\t\t\t\t\t____________________________________________________";

	cout << "\n\n\t\t\t\t\tPress Any Key To Continue ...";

	_pauseScreen();

	clsGeneratePinScreen::showGeneratePinScreen();

}
