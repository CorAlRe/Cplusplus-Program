# Cplusplus-Program
## Competency

Utilize various programming languages to develop secure, efficient code

## Scenario

You are doing a fantastic job at Chada Tech in your new role as a junior developer, and you exceeded expectations in your last assignment for Airgead Banking. Since your team is impressed with your work, they have given you another, more complex assignment. Some of the code for this project has already been completed by a senior developer on your team. Because this work will require you to use both C++ and Python, the senior developer has given you the code to begin linking between C++ and Python. Your task is to build an item-tracking program for the Corner Grocer, which should incorporate all of their requested functionality.

The Corner Grocer needs a program that analyzes the text records they generate throughout the day. These records list items purchased in chronological order from the time the store opens to the time it closes. They are interested in rearranging their produce section and need to know how often items are purchased so they can create the most effective layout for their customers. The program that the Corner Grocer is asking you to create should address the following three requirements for a given text-based input file that contains a list of purchased items for a single day:

* Produce a list of all items purchased in a given day along with the number of times each item was purchased.
* Produce a number representing how many times a specific item was purchased in a given day.
* Produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased.

## Requirements
1. Use C++ to develop a menu display that asks users what they would like to do. Include options for each of the three requirements outlined in the scenario and number them 1, 2, and 3. You should also include an option 4 to exit the program. All of your code needs to effectively validate user input.

1. Create code to determine the number of times each individual item appears. Here you will be addressing the first requirement from the scenario to produce a list of all items purchased in a given day along with the number of times each item was purchased. Note that each grocery item is represented by a word in the input file. Reference the following to help guide how you can break down the coding work.
    * Write C++ code for when a user selects option 1 from the menu. Select and apply a C++ function to call the appropriate Python function, which will display the number of times each item (or word) appears.
    * Write Python code to calculate the frequency of every word that appears from the input file. It is recommended that you build off the code you have already been given for this work.
    * Use Python to display the final result of items and their corresponding numeric value on the screen.

1. Create code to determine the frequency of a specific item. Here you will be addressing the second requirement from the scenario to produce a number representing how many times a specific item was purchased in a given day. Remember an item is represented by a word and its frequency is the number of times that word appears in the input file. Reference the following to help guide how you can break down the coding work.
    1. Use C++ to validate user input for option 2 in the menu. Prompt a user to input the item, or word, they wish to look for. Write a C++ function to take the user’s input and pass it to Python.
    1. Write Python code to return the frequency of a specific word. It will be useful to build off the code you just wrote to address the first requirement. You can use the logic you wrote but modify it to return just one value; this should be a fairly simple change (about one line). Next, instead of displaying the result on the screen from Python, return a numeric value for the frequency of the specific word to C++.
    1. Write a C++ function to display the value returned from Python. Remember, this should be displayed on the screen in C++. We recommend reviewing the C++ functions that have already been provided to you for this work.

1. Create code to graphically display a data file as a text-based histogram. Here you will be addressing the third requirement from the scenario: to produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased. Reference the following to help guide how you can break down the coding work:
    1. Use C++ to validate user input for option 3 in the menu. Then have C++ prompt Python to execute its relevant function.
    1. Write a Python function that reads an input file (CS210_Project_Three_Input_File, which is linked in the Supporting Materials section) and then creates a file, which contains the words and their frequencies. The file that you create should be named frequency.dat, which needs to be specified in your C++ code and in your Python code. Note that you may wish to refer to work you completed in a previous assignment where you practiced reading and writing to a file. Some of your code from that work may be useful to reuse or manipulate here. The frequency.dat file should include every item (represented by a word) paired with the number of times that item appears in the input file. For example, the file might read as follows:
        Potatoes 4
        Pumpkins 5
        Onions 3
    1. Write C++ code to read the frequency.dat file and display a histogram. Loop through the newly created file and read the name and frequency on each row. Then print the name, followed by asterisks or another special character to represent the numeric amount. The number of asterisks should equal the frequency read from the file. For example, if the file includes 4 potatoes, 5 pumpkins, and 3 onions then your text-based histogram may appear as represented below. However, you can alter the appearance or color of the histogram in any way you choose.
        Potatoes ****
        Pumpkins *****
        Onions ***

1. Apply industry standard best practices such as in-line comments and appropriate naming conventions to enhance readability and maintainability. Remember that you must demonstrate industry standard best practices in all your code to ensure clarity, consistency, and efficiency. This includes the following:
    1. Using input validation and error handling to anticipate, detect, and respond to run-time and user errors (for example, make sure you have option 4 on your menu so users can exit the program)
    1. Inserting in-line comments to denote your changes and briefly describe the functionality of the code
    1. Using appropriate variable, parameter, and other naming conventions throughout your code