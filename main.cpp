#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];

	try {
		std::strcpy(procname, pName.c_str());

		Py_Initialize();
		PyObject* my_module = PyImport_ImportModule("PythonCode");
		PyErr_Print();
		PyObject* my_function = PyObject_GetAttrString(my_module, procname);
		PyObject* my_result = PyObject_CallObject(my_function, NULL);
	}
	catch (exception ex) {
		delete[] procname;
		Py_Finalize();
		throw ex;
	}

	Py_Finalize();
	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	char* paramval = new char[param.length() + 1];
	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;

	try {
		std::strcpy(procname, proc.c_str());
		std::strcpy(paramval, param.c_str());

		// Initialize the Python Interpreter
		Py_Initialize();
		// Build the name object
		pName = PyUnicode_FromString((char*)"PythonCode");
		// Load the module object
		pModule = PyImport_Import(pName);
		// pDict is a borrowed reference 
		pDict = PyModule_GetDict(pModule);
		// pFunc is also a borrowed reference 
		pFunc = PyDict_GetItemString(pDict, procname);
		if (PyCallable_Check(pFunc))
		{
			pValue = Py_BuildValue("(z)", paramval);
			PyErr_Print();
			presult = PyObject_CallObject(pFunc, pValue);
			PyErr_Print();
			//printf("Result is %d\n", _PyLong_AsInt(presult));
			Py_DECREF(pValue);
		}
		else
		{
			PyErr_Print();
		}
		Py_DECREF(pModule);
		Py_DECREF(pName);
	}
	catch (exception ex) {
		delete[] procname;
		delete[] paramval;

		// Clean up
		Py_Finalize();

		throw ex;
	}

	// clean 
	delete[] procname;
	delete[] paramval;
	Py_Finalize();

	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;

	try {
		std::strcpy(procname, proc.c_str());
		// Initialize the Python Interpreter
		Py_Initialize();
		// Build the name object
		pName = PyUnicode_FromString((char*)"PythonCode");
		// Load the module object
		pModule = PyImport_Import(pName);
		// pDict is a borrowed reference 
		pDict = PyModule_GetDict(pModule);
		// pFunc is also a borrowed reference 
		pFunc = PyDict_GetItemString(pDict, procname);
		if (PyCallable_Check(pFunc))
		{
			pValue = Py_BuildValue("(i)", param);
			PyErr_Print();
			presult = PyObject_CallObject(pFunc, pValue);
			PyErr_Print();
			// Clean up
			//printf("Result is %d\n", _PyLong_AsInt(presult));
			Py_DECREF(pValue);
		}
		else
		{
			PyErr_Print();
		}
		// Clean up
		Py_DECREF(pModule);
		Py_DECREF(pName);
	}
	catch (exception ex) {
		delete[] procname;

		// Finish the Python Interpreter
		Py_Finalize();

		throw ex;
	}

	// clean 
	delete[] procname;
	Py_Finalize();

	return _PyLong_AsInt(presult);
}

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


/// <summary>
/// Program entry point. Prints a menu, takes menu choice, handles menu option until exit.
/// </summary>
/// <returns>0 for success, errocode otherwise</returns>
int main()
{
	string input;
	char option = '0';

	cin.exceptions(std::ios_base::failbit | std::ios_base::badbit);		// set exception handling for stream
	cout.exceptions(std::ios_base::failbit | std::ios_base::badbit);	// set exception handling for stream

	try {
		do {
			printMenu(cout);
			getline(cin, input);  // get user option

			if (input.size() > 0) { // make sure input has something
				option = input.at(0);	// get first character, ignore rest
				handleOption(option, cin, cout);
			}
			else {
				cout << "Invalid entry: Expected 1, 2, 3, or 4." << endl;
			}
		} while (option != '4'); // continue until 4 is pressed
	}
	catch (exception ex) { // something went wrong, could by python, could be stream, or something else
		cout << ex.what();
		return -1;
	}

	return 0;
}