import re
import string

def countWordFrequency(file):
    itemFreq = {}

    for item in file:
        if item[:-1] in itemFreq: # last character is a newline, strip it out
            itemFreq[item[:-1]] += 1
        else: 
            itemFreq[item[:-1]] = 1

    return itemFreq

def getFrequencyDictionary():
    with open('InputFile.txt') as file: # read from file
        frequencies = countWordFrequency(file)

    return frequencies;

def saveFrequencyDictionary(frequencies):
    with open('Frequency.dat', 'w') as file: # overwrite file
        for item, frequency in frequencies.items():
            file.write(item)
            file.write(' ')
            file.write('{}'.format(frequency))
            file.write('\n');

def sortDictionary(dictionary):
    returnDict = {}

    for key in sorted(dictionary):
        returnDict[key] = dictionary[key]

    return returnDict;

def FrequencyOfItems():
    frequencies = getFrequencyDictionary()

    words = sortDictionary(frequencies)
    format_string = '{keyword:15} {freq:5}'
    print(format_string.format(keyword='Item', freq='Frequency'))

    for word in words:
        print(format_string.format(keyword=word, freq=frequencies[word]))

def LookupItemFrequency(item):
    frequencies = getFrequencyDictionary()
    return frequencies.get(item, -1) # if not found return -1

def ExportFrequencyData():
    frequencies = getFrequencyDictionary()
    frequencies = sortDictionary(frequencies)
    saveFrequencyDictionary(frequencies)