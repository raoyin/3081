#ifndef SCANNER_H
#define SCANNER_H
#include <regex.h>
#include "regex.h"
#include <string>
#include <cstring>
class Token ;
class Scanner;
using namespace std;

/* This enumerated type is used to keep track of what kind of
   construct was matched. 
*/
// nothing change
enum tokenEnumType { 

    // Keywords
    letKwd, inKwd, endKwd, ifKwd, thenKwd, elseKwd, //0-5
    printKwd, readKwd, writeKwd, //6-8
    integerKwd, floatKwd, booleanKwd, stringKwd, //9-12 
    trueKwd, falseKwd, //13-14

    headKwd, tailKwd, nullKwd, //15-17
    mapKwd, filterKwd, foldKwd, //18-20
    zipKwd, //21

    // Constants
    intConst, floatConst, stringConst, //22-24 

    // Names
    variableName , //25

    // Punctuation
    leftParen, rightParen, //26-27 
    leftSquare, rightSquare, leftAngle, rightAngle, //28-31
    colon, colonColon, comma, semiColon, //32-35
    equalsSign, //36

    plusSign, star, dash, forwardSlash, percent, //37-41 
    backSlash, arrow, //42-43
    equalsEquals, //44
    lessThanEquals, greaterThanEquals, notEquals, //45-47 
    plusPlus, dotDot, //48-49
    tupleOp, //50

    endOfFile ,
    lexicalError
} ;
typedef enum tokenEnumType terminal_t ;


// Below you need to write your class definitions for Token and Scanner.
class Token {
public:
    Token();
    Token(const char* s, terminal_t t, Token* n);
	terminal_t terminal;
	string lexeme;
	Token* next;
};
class Scanner {
public:
	Token *scan (const char *);
	int consumeWhiteSpaceAndComments (regex_t *whiteSpace, regex_t *blockComment, regex_t *lineComment, const char *text);
};

#endif /* SCANNER_H */
