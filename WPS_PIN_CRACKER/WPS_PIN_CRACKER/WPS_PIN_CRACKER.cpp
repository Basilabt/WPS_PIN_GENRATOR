#include<iostream>
using namespace std;

#include"clsLaunchScreen.h"


int main() {

	// Seeds C++ Random Generator , Called Once At Main.
	srand((unsigned)time(NULL));

	clsLaunchScreen::showLaunchScreen();

	return 0;
}