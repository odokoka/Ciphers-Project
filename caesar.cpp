/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Ojochilemi Okoka, Antwane Maddox
 * okokaojo, mantwane
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * Function to shift Alphabet characters the amount specified
 */

#include "caesar.h"
#include <iostream>

//Function to perform character shift
char shiftAlphaCharacter(char c, int n) {
    char temp;
    int tempNum = n;
    const int ASCII_RANGE = 26;
    const int ASCII_LOWERCASE_MAX = 122;
    const int ASCII_LOWERCASE_MIN = 97;
    const int ASCII_UPPERCASE_MAX = 90;
    const int ASCII_UPPERCASE_MIN = 65;
    
    
    while((tempNum >= ASCII_RANGE) || (tempNum <= -ASCII_RANGE)) {
        if (tempNum > 0) {
        tempNum = tempNum % ASCII_RANGE;
        }
        if (tempNum < 0) {
            tempNum = abs(tempNum);
            tempNum = tempNum % ASCII_RANGE;
            tempNum = -tempNum;
        }
    }
    
    
    
    // Letter bounds for forward A-Z and a-z which correspondingly will work
    // for backwards as well
    if (((c >= ASCII_LOWERCASE_MIN) &&
         (c <= ASCII_LOWERCASE_MAX) &&
         (c + tempNum) > ASCII_LOWERCASE_MAX)) {
        tempNum = tempNum - ASCII_RANGE;
    } else if (((c >= ASCII_UPPERCASE_MIN) &&
                (c <= ASCII_UPPERCASE_MAX) &&
                (c + tempNum) > ASCII_UPPERCASE_MAX)) {
        tempNum = tempNum - ASCII_RANGE;
    } else if (((c >= ASCII_LOWERCASE_MIN) &&
                (c <= ASCII_LOWERCASE_MAX) &&
                (c + tempNum) < ASCII_LOWERCASE_MIN)) {
        tempNum = tempNum + ASCII_RANGE;
    } else if (((c >= ASCII_UPPERCASE_MIN) &&
                (c <= ASCII_UPPERCASE_MAX) &&
                (c + tempNum) < ASCII_UPPERCASE_MIN)) {
        tempNum = tempNum + ASCII_RANGE;
    }
    
    temp = c + tempNum;
    return temp;
}
//Function to perform Caesar Cipher
string caesarCipher(string original, int key, bool encrypt) {
    string temp;
    
    if (encrypt == true) {
        for (int i = 0; i < original.length(); i++) {
            if(isalpha(original[i])) {
                temp += shiftAlphaCharacter(original[i], key);
            } else {
                temp += original[i];
            }
        }
    } else {
        for (int i = 0; i < original.length(); i++) {
            if(isalpha(original[i])) {
                temp += shiftAlphaCharacter(original[i], 0 - key);
            } else {
                temp += original[i];
            }
        }
    }
    return temp;
}

     
