#include "menu.h"

/// <summary>
/// Output a menu to the stream
/// </summary>
/// <param name="outStream">stream to send the output to</param>
void printMenu(ostream& outStream) {
	outStream << "********************************************************************************" << endl;
	outStream << "*                          Chada Tech - Corner Grocer                          *" << endl;
	outStream << "********************************************************************************" << endl;
	outStream << "-                                 Daily Report                                 -" << endl;
	outStream << "--------------------------------------------------------------------------------" << endl;
	outStream << endl;
	outStream << "1: Show Item Sales Frequency" << endl;
	outStream << "2: Lookup Item Frequency" << endl;
	outStream << "3: Show Item Histogram" << endl;
	outStream << "4: Exit" << endl;
	outStream << endl;
	outStream << "Enter your selection as a number 1, 2, 3, or 4." << endl;
}


/// <summary>
/// Execute the option associated with the menu options
/// </summary>
/// <param name="option">1, 2, or 3</param>
/// <param name="inStream">input stream to get additional input from</param>
/// <param name="outStream">output stream to send prompts to</param>
void handleOption(char option, istream& inStream, ostream& outStream) {
	switch (option) {
	case '1':
		outStream << "Option 1 selected. " << endl;
		CallProcedure("FrequencyOfItems");
		break;
	case '2':
		outStream << "Option 2 selected." << endl;
		break;
	case '3':
		outStream << "Option 3 selected." << endl;
		break;
	case '4': // quit
		outStream << "Exiting application" << endl;
		break;
	default: // unknown option
		outStream << "Unknown option: Expected 1, 2, 3, or 4." << endl;
		break;
	}
	outStream << endl;
}
