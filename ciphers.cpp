/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Ojochilemi Okoka, Antwane Maddox
 * okokaojo, mantwane
 *
 * EECS 183: Project 3
 * Winter 2022
 * Functions to completely run the cipher program, giving users choice of
 * using Vigenere, Caesar, and Polybius function
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;
//Need to add error messages for user inputs
//Function to perform Caesar Cipher w/ user prompts
void doCaesar(bool encryptionType) {
    string userMessage;
    int userKey;

    cout << endl << "Enter a message: ";
    getline(cin, userMessage);
    
    cout << endl << "What is your key: ";
    cin >> userKey;
    
    if (encryptionType) {
        cout << endl << "The encrypted message is: " <<
        caesarCipher(userMessage, userKey, encryptionType) << endl;
    } else {
        cout << endl << "The decrypted message is: " <<
        caesarCipher(userMessage, userKey, encryptionType) << endl;
    }
}
//Need to add error messages for user inputs
//Function to do Vigenere Cipher w/ user prompts
void doVigenere(bool encryptionType) {
    string userMessage;
    string userKey;
    bool validKey = false;
    int i;
    
    cout << endl << "Enter a message: ";
    getline(cin, userMessage);
    
    cout << endl << "What is your key: ";
    getline(cin, userKey);
    for (i = 0; i < userKey.size(); ++i) {
        if (isalpha(userKey[i])) {
            validKey = true;
        } else {
            validKey = false;
        }
    }
    if (!validKey) {
        cout << endl << "Invalid key!" << endl;
        return;
    } else {
    if (encryptionType) {
        cout << endl << "The encrypted message is: " <<
        vigenereCipher(userMessage, userKey, encryptionType) << endl;
    } else {
        cout << endl << "The decrypted message is: " <<
        vigenereCipher(userMessage, userKey, encryptionType) << endl;
        }
    }
}
//Need to add error messages for user inputs
//Function to do Polybius Cipher w/ user prompts
void doPolybius(bool encryptionType) {
    string userMessage;
    string userKey;
    char grid[SIZE][SIZE];
    int i;
    
    
    cout << endl << "Enter a message: ";
    getline(cin, userMessage);
    //Loop for message validity
    for (i = 0; i < userMessage.size(); ++i) {
        if (((!isdigit(userMessage[i])) && (!isalpha(userMessage[i])) && (!isspace(userMessage[i])))) {
            cout << "Invalid message!" << endl;
            return;
        }
    }
    cout << endl << "What is your key: ";
    getline(cin, userKey);
    //Loop for key validity
    for (i = 0; i < userKey.size(); ++i) {
        if (((!isdigit(userKey[i])) &&
             (!isalpha(userKey[i])) &&
             (!isspace(userKey[i])))){
            cout << "Invalid key!" << endl;
            return;
        }
    }
    //Functions for key and message formatting
    userKey = toUpperCase(userKey);
    userMessage = toUpperCase(userMessage);
    
    userKey = removeDuplicate(userKey);
    
    if (encryptionType) {
        cout << endl << "The encrypted message is: " <<
        polybiusSquare(grid, userKey, userMessage, encryptionType) << endl;
    } else {
        cout << endl << "The decrypted message is: " <<
        polybiusSquare(grid, userKey, userMessage, encryptionType) << endl;
    }
}

void ciphers() {
    //user cipher prompt
    string cipherType;
    string encryptionType;
    bool encrypt;
    
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    getline(cin, cipherType);
    cipherType = toUpperCase(cipherType);
    
    if ((cipherType != "CAESAR") &&
        (cipherType != "C") &&
        (cipherType != "VIGENERE") &&
        (cipherType != "V") &&
        (cipherType != "POLYBIUS") &&
        (cipherType != "P")) {
        cout << "Invalid cipher!" << endl;
        return;
    }
    
    cout << endl << "Encrypt or decrypt: ";
    getline(cin, encryptionType);
    encryptionType = toUpperCase(encryptionType);
    
    if ((encryptionType == "ENCRYPT") || (encryptionType == "E")) {
        encrypt = true;
    } else if (encryptionType == "DECRYPT" || encryptionType == "D") {
        encrypt = false;
    } else {
        cout << "Invalid mode!" << endl;
        return;
    }
    
    if ((cipherType == "CAESAR") || (cipherType == "C")) {
        doCaesar(encrypt);
    } else if ((cipherType == "VIGENERE") || (cipherType == "V")) {
        doVigenere(encrypt);
    } else if ((cipherType == "POLYBIUS") || (cipherType == "P")) {
        doPolybius(encrypt);
    }
    
    return;
}
