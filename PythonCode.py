import re
import string

# Helper function
# Reads a word from a file, adds word to a dictionary
# If the word is already in the dictionary increments the count
# returns a dictionary
def countWordFrequency(file):
    itemFreq = {}

    for item in file:
        if item[:-1] in itemFreq:       # last character is a newline, strip it out
            itemFreq[item[:-1]] += 1
        else: 
            itemFreq[item[:-1]] = 1

    return itemFreq

# Helper function
# Open input file
# Count the item frequencies
# return the dictionary result
def getFrequencyDictionary():
    with open('InputFile.txt') as file:     # read from file
        frequencies = countWordFrequency(file)

    return frequencies;


# Helper function
# Given dictionary as input
# Dictionary should contain a string as key and integer as value
# Save dictionary to file
def saveFrequencyDictionary(frequencies):
    with open('Frequency.dat', 'w') as file:    # overwrite file
        for item, frequency in frequencies.items():
            file.write(item)
            file.write(' ')
            file.write('{}'.format(frequency))  # convert int to string
            file.write('\n');

# helper function
# Sort dictionary by key, does not mutate input
# Return sorted dictionary
def sortDictionary(dictionary):
    returnDict = {}

    for key in sorted(dictionary):
        returnDict[key] = dictionary[key]

    return returnDict;

# Called from C++
# Calls helpers to open file, count frequencies
# Gets results as dictionary, key string, value integer
# Sorts dictionary by key
# Outputs dictionary to ouput stream
def FrequencyOfItems():
    frequencies = getFrequencyDictionary()

    words = sortDictionary(frequencies)
    format_string = '{keyword:15} {freq:5}'
    print(format_string.format(keyword='Item', freq='Frequency'))

    for word in words:
        print(format_string.format(keyword=word, freq=frequencies[word]))

# Called from C++
# Calls helpers to open file, count frequencies
# Gets results as dictionary, key string, value integer
# Returns frequency as integer, if item not found return -1
def LookupItemFrequency(item):
    frequencies = getFrequencyDictionary()
    return frequencies.get(item, -1) 

# Called from C++
# Calls helpers to open file, count frequencies
# Gets results as dictionary, key string, value integer
# Sorts dictionary by key
# Outputs dictionary to file
def ExportFrequencyData():
    frequencies = getFrequencyDictionary()
    frequencies = sortDictionary(frequencies)
    saveFrequencyDictionary(frequencies)