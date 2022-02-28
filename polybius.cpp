/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Ojochilemi Okoka, Antwanne Maddox
 * okokaojo, mantwanne
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * A short program encrypt and decrypt phrases using the polybius square
 */


#include "polybius.h"
#include <string>
using namespace std;

//Function to format key properly
string mixKey(string key){
    string charBank = ALNUM;
    string finalBank;
    
    finalBank = key + charBank;
    finalBank = removeDuplicate(finalBank);
    
    return finalBank;
}

//Function to make a correct grid
void fillGrid(char grid[SIZE][SIZE], string content) {
    int i = 0;
    int j;
    int k;
    
        for (j = 0; j < SIZE; ++j) {
            for (k = 0; k < SIZE; ++k) {
                
                grid[j][k] = content[i];
                ++i;
            }
        }
    return;
}

//Function to find the letter/number in the proper grid
string findInGrid(char c, char grid[SIZE][SIZE]) {
    int i;
    int j;
    string iNum;
    string jNum;
    string location;
    
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (grid[i][j] == c) {
                iNum = to_string(i);
                jNum = to_string(j);
                location = iNum;
                location = location.append(jNum);
            }
        }
    }
    return location;
}

//Function to perform Polybius Square encryption or decryption
string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt) {
    int i;
    
    string a_key;
    string tempString;
    string finalResult = "";
    
    a_key = mixKey(key);
    fillGrid(grid, a_key);
    
    if (encrypt) {
        
        for (i = 0; i < original.size(); ++i) {
            if (isalpha(original[i]) || isdigit(original[i])) {
                tempString = findInGrid(original[i], grid);
            } else {
                tempString = original[i];
            }
            finalResult = finalResult.append(tempString);
        }
    } else {
        for (i = 0; i < original.size(); i++) {
            if ((original[i] != ' ') && (original[i + 1] != ' ')) {
                finalResult +=
                grid[charToInt(original[i])][charToInt(original[i+1])];
                i++;
                }
             else {
                finalResult += ' ';
            }
        }
    }
    return finalResult;
}


