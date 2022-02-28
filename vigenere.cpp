/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Ojochilemi Okoka, Antwane Maddox
 * okokaojo, mantwane
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * A cool function that encrypts and decrypts strings using keywords
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

using namespace std;

//Function to perform Vigenere cipher
string vigenereCipher(string original, string keyword, bool encrypt) {
    string newKey;
    string tempEncryption = original;
    string finalEncryption = tempEncryption;
    string finalDecryption = tempEncryption;

    int i;
    int j = 0;
    int move = 0;
    int moveBack = 0;
    const int ASCII_A = 65;
    
    if (encrypt) {
        newKey = removeNonAlphas(keyword);
        newKey = toUpperCase(newKey);
        
        for (i = 0; i < original.size(); ++i) {
            if (j >= newKey.size()) {
                j = 0;
            }
            if (isalpha(original[i])) {
                
            move = newKey[j] - ASCII_A;
            finalEncryption[i] = shiftAlphaCharacter((tempEncryption[i]), move);
                ++j;
            }
        }
        return finalEncryption;
    } else {
        newKey = removeNonAlphas(keyword);
        newKey = toUpperCase(newKey);
        
        for (i = 0; i < original.size(); ++i) {
            if (j >= newKey.size()) {
                j = 0;
            }
            if (isalpha(original[i])) {
                
            moveBack = -(newKey[j] - ASCII_A);
            finalDecryption[i] =
                shiftAlphaCharacter((tempEncryption[i]),moveBack);
                ++j;
            }
        }
    }
        return finalDecryption;
}
