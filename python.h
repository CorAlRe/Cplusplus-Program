#ifndef PROJECT_THREE_PYTHON_H
#define PROJECT_THREE_PYTHON_H

#include <Python.h>
#include <iostream>
#include <string>

using namespace std;

void CallProcedure(string pName);
int callIntFunc(string proc, string param);
int callIntFunc(string proc, int param);

#endif