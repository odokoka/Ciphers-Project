/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Ojochilemi Okoka
 * okokaojo, mantwane
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * Some function definitions created to increase the efficiency of the ciphers
 */

#include "utility.h"
#include <iostream>
#include <string>

//Function to turn string uppercase
string toUpperCase(string original) {
    int i;
    string tempString = original;
    
    for (i = 0; i < original.size(); ++i) {
        if (isalpha(original[i])) {
            tempString[i] = toupper(original[i]);
        }
        
    }
    return tempString;
}

//Function to remove non-alphabetical characters
string removeNonAlphas(string original) {
    string temp;
    for (int i = 0; i <= original.size(); i++) {
        if (isalpha(original[i])) {
            temp += original[i];
        }
    }
    return temp;
}

string removeDuplicate(string original) {
    
    for (int i = 0; i < original.size(); ++i) {
      for (int j = i + 1; j < original.size(); ++j) {
          if (original[i] == original[j]) {
              original.erase(original.begin()+ j);
              j--;
          }
        }
    }
    
    return original;
}

int charToInt(char original) {
    int numberChar = original - '0';
    
    return numberChar;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
