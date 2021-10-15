import re
import string


def printsomething():
    print("Hello from python!")


def PrintMe(v):
    print("You sent me: " + v)
    return 100;


def SquareValue(v):
    return v * v


def countWordFrequency(file):
    itemFreq = {}

    for item in file:
        if item[:-1] in itemFreq: # last character is a newline, strip it out
            itemFreq[item[:-1]] += 1
        else: 
            itemFreq[item[:-1]] = 1

    return itemFreq


def getFrequencyDictionary():
    file = open('InputFile.txt')
    frequencies = countWordFrequency(file)
    file.close()
    return frequencies;


def FrequencyOfItems():
    frequencies = getFrequencyDictionary();

    words = sorted(frequencies.keys())
    format_string = '{keyword:15} {freq:5}'
    print(format_string.format(keyword='Item', freq='Frequency'))
    for word in words:
        print(format_string.format(keyword=word, freq=frequencies[word]))

def LookupItemFrequency(item):
    frequencies = getFrequencyDictionary();
    return frequencies.get(item, -1)