#include "menu.h"

void printMenu(ostream& outStream) {
	// output banner
	outStream << RESET;
	outStream << YELLOW << setfill('*') << setw(80) << "" << endl;
	outStream << "*" << GREEN << setfill(' ') << setw(26) << "" << "Chada Tech - Corner Grocer" << setw(26) << "" << YELLOW << "*" << endl;
	outStream << YELLOW << setfill('*') << setw(80) << "" << endl;
	outStream << YELLOW << "-" << GREEN << setfill(' ') << setw(33) << "" << "Daily Report" << setw(33) << "" << YELLOW << "-" << endl;
	outStream << YELLOW << setfill('-') << setw(80) << "" << endl;
	outStream << setfill(' ') << setw(1) << endl;
	// output menu choices
	outStream << BLUE;
	outStream << "1: Show Item Sales Frequency" << endl;
	outStream << "2: Lookup Item Frequency" << endl;
	outStream << "3: Show Item Histogram" << endl;
	outStream << "4: Exit" << endl;
	outStream << endl;
	// output prompt
	outStream << BOLDBLUE;
	outStream << "Enter your selection as a number 1, 2, 3, or 4." << endl;
	outStream << BOLDWHITE;
}

void handleOption(char option, istream& inStream, ostream& outStream) {
	outStream << endl;
	outStream << RESET;

	switch (option) {
	case '1': // Show Item Sales Frequency
		CallProcedure("FrequencyOfItems"); // Call Python procedure to get item list and number sold.
		break;
	case '2': // Lookup Item Frequency
		outStream << BOLDBLUE;
		outStream << "Please enter item to lookup:" << endl;
		outStream << BOLDWHITE;
		{
			string input = getWord(inStream); // call helper to get input 
			// call Python function to find item and return frequency, if not found frequency will be -1
			int frequency = callIntFunc("LookupItemFrequency", input);  
			displayItemFrequency(input, frequency, outStream); // display result
		}
		break;
	case '3': // Show Item Histogram
		CallProcedure("ExportFrequencyData"); // Call Python to save frequencies to a file
		displayFileHistogram("Frequency.dat", outStream); // Read File to display Histogram
		break;
	case '4': // quit
		outStream << YELLOW;
		outStream << "Exiting application" << endl;
		break;
	default: // unknown option
		outStream << BOLDRED;
		outStream << "Unknown option: Expected 1, 2, 3, or 4." << endl;
		break;
	}
	outStream << endl;
}

string getWord(istream& inStream) {
	string input;
	getline(inStream, input);  // read whole line even if it has spaces, inludes newline character

	if (input.length() > 0) {
		auto noNewLine = std::remove(input.begin(), input.end(), '\n'); // remove newline character
		input.erase(noNewLine, input.end());							// compact string
		return input;
	}
	else {
		return "";				// unexpected input so return empty string
	}
}

void displayItemFrequency(string item, int frequency, ostream& outStream) {
	outStream << endl;

	if (frequency == -1) {		// item not found
		outStream << "Item not found: " << item << endl;
		return;
	}

	outStream << "The number of " << item << " sold today is " << frequency << "." << endl;
}

void displayFileHistogram(string fileName, ostream& outStream) {
	ifstream inputFile;
	string item;
	int frequency;
	const char pattern = '*'; // histogram character

	outStream << RESET;
	outStream << BOLDWHITE;

	inputFile.open(fileName);
	if (!inputFile.is_open()) {
		outStream << BOLDRED;
		cout << "Could not open file " << fileName << "." << endl;
		return;
	}

	while (!inputFile.fail() && !inputFile.eof()) { 
		inputFile >> item;
		inputFile >> frequency;

		// need to check again otherwise last item prints twice
		if (!inputFile.fail() && !inputFile.eof()) { // I think because the newline isn't consumed by the >> above so it loops one more time
			string histogram = string(frequency, pattern);
			outStream << right << setw(15) << item << " " << setw(64) << left << histogram << endl;
		}
	}
}