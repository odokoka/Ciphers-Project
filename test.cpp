/*
 *  Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 *  Ojochilemi Okoka, Antwane Maddox
 *  okokaojo, mantwane
 *
 *  EECS 183: Project 3
 *  Winter 2022
 *  Created by Ojochilemi Okoka on 2/16/22.
 */
#include <iostream>
#include "caesar.h"
#include "polybius.h"
#include "utility.h"
#include "vigenere.h"
using namespace std;

//All functions for tests

//Caesar Test Functions
void testShiftAlphaCharacter();
void testCaesarCipher();
void testCharToInt();

//Polybius Test Functions
void testMixKey();
void testFillGrid();
void testFindInGrid();
void testPolybiusSquare();

//Utility Test Functions
void testToUpperCase();
void testRemoveNonAlphas();
void testCharToInt();
void testRemoveDuplicate();
void testPrintGrid();

//Vigenere Test Functions
void testVigenereCipher();

//Function to Start tests
void startTests() {
    cout << "\nExecuting your test cases\n" << endl;
    
     testShiftAlphaCharacter();
     testCaesarCipher();
     testCharToInt();
     testMixKey();
     testFillGrid();
     testFindInGrid();
     testPolybiusSquare();
     testToUpperCase();
     testRemoveNonAlphas();
     testCharToInt();
     testRemoveDuplicate();
     testPrintGrid();
     testVigenereCipher();
}

//Test Function Definitions
void testToUpperCase() {
    cout << "Now testing function, toUpperCase()" << endl;
    
    cout << "'Eecs 183': Expected: EECS 183, actual: " <<
    toUpperCase("Eecs 183") << endl;
    cout << "'Udoka': Expected: UDOKA, actual: " <<
    toUpperCase("Udoka") << endl;
    cout << endl;
    
}

void testRemoveNonAlphas() {
    cout << "Now testing function, removeNonAlphas()" << endl;
    
    cout << "'Eecs 183': Expected: Eecs, actual: " <<
    removeNonAlphas("Eecs 183") << endl;
    cout << "Now testing function, removeNonAlphas()" << endl;
    cout << "'Grabba 183': Expected: Grabba, actual: " <<
    removeNonAlphas("Grabba 183") << endl;
    cout << endl;
}

void testRemoveDuplicate() {
    cout << "Now testing function, removeDuplicate()" << endl;
    
    cout << "'AB': Expected: AB, actual: " <<
    removeDuplicate("AB") << endl;
    cout << "'GGFFHH': Expected: GFH, actual: " <<
    removeDuplicate("GGFFHH") << endl;
    cout << "'LMNN1': Expected: LMN1, actual: " <<
    removeDuplicate("LMNN1") << endl;
}
void testCharToInt() {
    cout << "Now testing function, charToInt()" << endl;
    
    cout << "'5': Expected: 5, actual: " <<
    charToInt('5') << endl;
    cout << "'6': Expected: 6, actual: " <<
    charToInt('6') << endl;
}
void testShiftAlphaCharacter() {
    cout << "Now testing function, shiftAlphaCharacter()" << endl;
    
    cout << "'g, -15': Expected: r, actual: " <<
    shiftAlphaCharacter('g', -15) << endl;
    cout << "'Z, -30': Expected: V, actual: " <<
    shiftAlphaCharacter('Z', -30) << endl;
    cout << "'B, 27': Expected: C, actual: " <<
    shiftAlphaCharacter('B', 27) << endl;
    cout << "'M, 16': Expected: C, actual: " <<
    shiftAlphaCharacter('M', 16) << endl;
    cout << "'X, 25': Expected: W, actual: " <<
    shiftAlphaCharacter('X', 25) << endl;
    cout << "'Z, 30': Expected: D, actual: " <<
    shiftAlphaCharacter('Z', 30) << endl;
    cout << "'Y, 2': Expected: A, actual: " <<
    shiftAlphaCharacter('Y', 2) << endl;
    cout << "'R, 26': Expected: R, actual: " <<
    shiftAlphaCharacter('R', 26) << endl;
}
void testCaesarCipher() {
    cout << "Now testing function, caesarCipher()" << endl;
    
    cout << "'Meet me at the Diag at 11 p.m., 42, true' Expected: " <<
    "Cuuj cu qj jxu Tyqw qj 11 f.c., actual: " << endl;
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << "'Cuuj cu qj jxu Tyqw qj 11 f.c., 42, false' Expected: Meet me at "
    << "the Diag at 11 p.m., actual: " << endl;
    cout << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;
    cout << "'I Love Coding!, 17, true' Expected: " <<
    "Z Cfmv Tfuzex!, actual: " << endl;
    cout << caesarCipher("I Love Coding!", 17, true) << endl;
    cout << "'Z Cfmv Tfuzex!, 17, false' Expected: " <<
    "I Love Coding!, actual: " << endl;
    cout << caesarCipher("Z Cfmv Tfuzex!", 17, false) << endl;
    cout << "'I need sleep..., 29, true' Expected: " <<
    "L qhhg vohhs..., actual: " << endl;
    cout << caesarCipher("I need sleep...", 29, true) << endl;
    cout << "'L qhhg vohhs..., 29, false' Expected: " <<
    "I need sleep..., actual: " << endl;
    cout << caesarCipher("L qhhg vohhs...", 29, false) << endl;
}
void testVigenereCipher() {
    cout << "Now testing function, viginereCipher()" << endl;
    
    cout << "'I 3love CS, gas, true' Expected: O 3lgbe UY, actual: "
    << vigenereCipher("I 3love CS", "gas", true) << endl;
    cout << "Now testing function, viginereCipher()" << endl;
    cout << "'O 3lgbe UY, gas, true' Expected: I 3love CS,actual: "
    << vigenereCipher("O 3lgbe UY", "gas", false) << endl;
}
void testMixKey() {
    cout << "Now testing function, mixKey()" << endl;
    
    cout << "'ILOVE3CS'" <<
    "Expected: I LOVE 3CSABCDEFGHIJKLMNOPQRSTUV..., actual: " << endl;
    cout << mixKey("ILOVE3CS") << endl;
    cout << "'GRUNT'" <<
    "Expected: GRUNTABCDEFHIJKLMOPQSV..., actual: " << endl;
    cout << mixKey("GRUNT") << endl;
}

void testFillGrid() {
    char grid[SIZE][SIZE];
    
    cout << "Now testing function fillGrid()" << endl;
    
    cout << "'grid, ALNUM' Expected: filled grid with ALNUM chars, actual: "
    << endl;
    fillGrid(grid, ALNUM);
    printGrid(grid);
}

void testFindInGrid() {
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    
    cout << "Now testing function findInGrid()" << endl;
    
    cout << "'G, grid' Expected: 10, actual: " << findInGrid('G', grid) << endl;
    cout << "'A, grid' Expected: 0, actual: " << findInGrid('A', grid) << endl;
}

void testPolybiusSquare() {
    char grid[SIZE][SIZE];
    cout << "Now testing function polybiusSquare()" << endl;
    
    cout << "'grid, 183, EECS 183 IS THE BEST, true'" <<
    "Expected: 11110533 000102 1533 341411 04113334, actual " << endl;
    cout << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << endl;
    
    cout << "'grid, 183, 11110533 000102 1533 341411 04113334, false'" <<
    "Expected: EECS 183 IS THE BEST, actual " << endl;
    cout <<
    polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false)
    << endl;
}
void testPrintGrid() {
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    printGrid(grid);
}
