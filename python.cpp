#include "python.h"

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