#ifndef PROJECT_THREE_MENU_H
#define PROJECT_THREE_MENU_H

#include <iostream>			// cin cout input output streams
#include <fstream>			// file stream
#include <iomanip>			// stream manipulators for alignment, width, etc
#include "python.h"

using namespace std;

/// <summary>
/// Display the menu to the output stream.
/// </summary>
/// <param name="outStream">The stream to send the menu to.</param>
void printMenu(ostream& outStream);

/// <summary>
/// Handle the menu choice from the user and dispatch to an appropriate function.
/// </summary>
/// <param name="option">A numeric character. I.E 1,2,3,4</param>
/// <param name="inStream">The input stream to get the selected option from.</param>
/// <param name="outStream">The output stream to send prompts to.</param>
void handleOption(char option, istream& inStream, ostream& outStream);

/// <summary>
/// Helper function to get the next input line from the input stream.
/// </summary>
/// <param name="inStream">The stream to read from.</param>
/// <returns>Returns the contents of the next line from the stream, empty string if input could not be read.</returns>
string getWord(istream& inStream);

/// <summary>
/// Output the item and frequency to the output stream
/// </summary>
/// <param name="item">The word to output</param>
/// <param name="frequency">The frequency to output</param>
/// <param name="outStream">The stream to send the data to</param>
void displayItemFrequency(string item, int frequency, ostream& outStream);

/// <summary>
/// Read in a file and output the data as a histogram.
/// </summary>
/// <param name="fileName">The name of the file.</param>
/// <param name="outStream">The output stream to send the histogram to.</param>
void displayFileHistogram(string fileName, ostream& outStream);

#endif
