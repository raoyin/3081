#include "scanner.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "scanner.h"
#include "regex.h"
using namespace std;


Token::Token(){
	
}

Token::Token(const char* s, terminal_t t, Token* n){
	terminal = t;
	lexeme = s;
	next = n;
}
int Scanner::consumeWhiteSpaceAndComments (regex_t *whiteSpace, regex_t *blockComment, regex_t *lineComment, const char *text) {
        int numMatchedChars = 0 ;
        int totalNumMatchedChars = 0 ;
        int stillConsumingWhiteSpace ;

        do {
            stillConsumingWhiteSpace = 0 ;  // exit loop if not reset by a match

            // Try to match white space
            numMatchedChars = matchRegex (whiteSpace, text) ;
            totalNumMatchedChars += numMatchedChars ;
            if (numMatchedChars > 0) {
                text = text + numMatchedChars ;
                stillConsumingWhiteSpace = 1 ;
            }

            // Try to match block comments
            numMatchedChars = matchRegex (blockComment, text) ;
            totalNumMatchedChars += numMatchedChars ;
            if (numMatchedChars > 0) {
                text = text + numMatchedChars ;
                stillConsumingWhiteSpace = 1 ;
            }

            // Try to match single-line comments
            numMatchedChars = matchRegex (lineComment, text) ;
            totalNumMatchedChars += numMatchedChars ;
            if (numMatchedChars > 0) {
                text = text + numMatchedChars ;
                stillConsumingWhiteSpace = 1 ;
            }
        }
        while ( stillConsumingWhiteSpace ) ;    

        return totalNumMatchedChars ;
    }


Token* Scanner::scan (const char * text) {
	// Output Token
	Token *startToken, *currentToken;
	currentToken = new Token();
	startToken = currentToken;
    // Create the compiled regular expressions.
    regex_t *whiteSpace ;
    whiteSpace = makeRegex ("^[\n\t\r ]+") ;

    regex_t *blockComment ;
    blockComment = makeRegex ("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");

    regex_t *lineComment ;
    lineComment = makeRegex ("^//[^\n]*\n");
    
    // This part is modified by Raoyin Chen
    // Keywords
    regex_t *re_letKwd ;
    re_letKwd = makeRegex ("^let");
    
    regex_t *re_inKwd ;
    re_inKwd = makeRegex ("^in");

    regex_t *re_endKwd ;
    re_endKwd = makeRegex ("^end");

    regex_t *re_ifKwd ;
    re_ifKwd = makeRegex ("^if");

    regex_t *re_thenKwd ;
    re_thenKwd = makeRegex ("^then");

    regex_t *re_elseKwd ;
    re_elseKwd = makeRegex ("^else");

    regex_t *re_printKwd ;
    re_printKwd = makeRegex ("^print");

    regex_t *re_readKwd ;
    re_readKwd = makeRegex ("^read");

    regex_t *re_writeKwd ;
    re_writeKwd = makeRegex ("^write");

    regex_t *re_integerKwd ;
    re_integerKwd = makeRegex ("^Integer");

    regex_t *re_floatKwd ;
    re_floatKwd = makeRegex ("^Float");

    regex_t *re_booleanKwd ;
    re_booleanKwd = makeRegex ("^Boolean");

    regex_t *re_stringKwd ;
    re_stringKwd = makeRegex ("^String");

    regex_t *re_trueKwd ;
    re_trueKwd = makeRegex ("^true");

    regex_t *re_falseKwd ;
    re_falseKwd = makeRegex ("^false");

    regex_t *re_headKwd ;
    re_headKwd = makeRegex ("^head");

    regex_t *re_tailKwd ;
    re_tailKwd = makeRegex ("^tail");

    regex_t *re_nullKwd ;
    re_nullKwd = makeRegex ("^null");

    regex_t *re_mapKwd ;
    re_mapKwd = makeRegex ("^map");
    
    regex_t *re_filterKwd ;
    re_filterKwd = makeRegex ("^filter");
    
    regex_t *re_foldKwd ;
    re_foldKwd = makeRegex ("^fold");
    
    regex_t *re_zipKwd ;
    re_zipKwd = makeRegex ("^zip");
    
    //Constants
    regex_t *re_intConst ;
    re_intConst = makeRegex ("^[0-9]+") ;

    regex_t *re_floatConst ;
    re_floatConst = makeRegex ("^[0-9]+\\.[0-9]+");

    regex_t *re_stringConst ;
    re_stringConst = makeRegex ("^\"(\\.|[^\"])*\"");
    
    
    // The following part is created by Sichao Shi
    // Names
    regex_t *re_variableName ;
    re_variableName = makeRegex ("^([a-zA-Z_]+)[0-9]*");

    // Punctuation
    regex_t *re_leftParen ;
    re_leftParen = makeRegex ("^\\(");

    regex_t *re_rightParen ;
    re_rightParen = makeRegex ("^\\)");

    regex_t *re_leftSquare ;
    re_leftSquare = makeRegex ("^\\[");

    regex_t *re_rightSquare ;
    re_rightSquare = makeRegex ("^\\]");

    regex_t *re_leftAngle ;
    re_leftAngle = makeRegex ("^<");

    regex_t *re_rightAngle ;
    re_rightAngle = makeRegex ("^>");

    regex_t *re_colon ;
    re_colon = makeRegex ("^:");

    regex_t *re_colonColon ;
    re_colonColon = makeRegex ("^::");

    regex_t *re_comma ;
    re_comma = makeRegex ("^,");

    regex_t *re_semiColon ;
    re_semiColon = makeRegex ("^;");

    regex_t *re_equalsSign ;
    re_equalsSign = makeRegex ("^=");

    regex_t *re_plusSign ;
    re_plusSign = makeRegex ("^\\+");

    regex_t *re_star ;
    re_star = makeRegex ("^\\*");

    regex_t *re_dash ;
    re_dash = makeRegex ("^-");

    regex_t *re_forwardSlash ;
    re_forwardSlash = makeRegex ("^/");

    regex_t *re_percent ;
    re_percent = makeRegex ("^%");

    regex_t *re_backSlash ;
    re_backSlash = makeRegex ("^\\\\");

    regex_t *re_arrow ;
    re_arrow = makeRegex ("^->");

    regex_t *re_equalsEquals ;
    re_equalsEquals = makeRegex ("^==");

    regex_t *re_lessThanEquals ;
    re_lessThanEquals = makeRegex ("^<=");

    regex_t *re_greaterThanEquals ;
    re_greaterThanEquals = makeRegex ("^>=");

    regex_t *re_notEquals ;
    re_notEquals = makeRegex ("^!=");

    regex_t *re_plusPlus ;
    re_plusPlus = makeRegex ("^\\+\\+");

    regex_t *re_dotDot ;
    re_dotDot = makeRegex ("^\\.\\.");

    regex_t *re_tupleOp ;
    re_tupleOp = makeRegex ("^#[1-9][0-9]*");

    regex_t *re_endOfFile ;
    re_endOfFile = makeRegex ("^\\Z");


    /* This enumerated type is used to keep track of what kind of
       construct was matched. 
     */
 
	terminal_t matchType;

    int numMatchedChars = 0 ;
    
    /* text is a character pointer that points to the current
       beginning of the array of characters in the input.  Adding an
       integer value to it advances the pointer that many elements in
       the array.  Thus, text is increased so that it points to the
       current location in the input. 
     */
    numMatchedChars = consumeWhiteSpaceAndComments (whiteSpace, blockComment, lineComment, text);
    text = text + numMatchedChars ;

    int maxNumMatchedChars = 0 ;

    while ( text[0] != '\0' ) {
		numMatchedChars = consumeWhiteSpaceAndComments (whiteSpace, blockComment, lineComment, text) ;
        maxNumMatchedChars = 0 ; matchType = lexicalError ;

        /* maxNumMatchedChars is used to ensure that the regular
           expression that matched the longest string is the one that
           we use.  

           The regexs for word and integerConst cannot match the
           same text, but if we extend this program to search for
           specific keywords, then the keyword regex and the
           word-regex may, in some cases, match the same input text.

           If two regexs match the same number of characters
           then the tie has to be broken.  To break the tie, priority
           is given to the first one that was tried.  Thus the
           comparison
              (numMatchedChars > maxNumMatchedChars) 
           is strictly greater than.  Not greater than or  equal to.
        */
	//The following part is created by Raoyin Chen
    // Try to match variable name
    numMatchedChars = matchRegex (re_variableName, text) ;
    if (numMatchedChars > maxNumMatchedChars) {
        maxNumMatchedChars = numMatchedChars ;
        matchType = variableName ;
    }


    // Try to match an integer constant
    numMatchedChars = matchRegex (re_intConst, text) ;
    if (numMatchedChars > maxNumMatchedChars) {
        maxNumMatchedChars = numMatchedChars ;
        matchType = intConst ;
    }

	//Try to match an float constant
	numMatchedChars = matchRegex (re_floatConst, text) ;
	if (numMatchedChars > maxNumMatchedChars) {
		maxNumMatchedChars = numMatchedChars ;
        matchType = floatConst ;
    }
    
    //Try to match a string constant
	numMatchedChars = matchRegex (re_stringConst, text) ;
	if (numMatchedChars >= 2 && maxNumMatchedChars >= 0 ) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = stringConst ;
	}
	
	//Try to match 'let'
	numMatchedChars = matchRegex (re_letKwd, text) ;
	
	if (numMatchedChars == 3 && maxNumMatchedChars == 3 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = letKwd ;
	}
	
	//Try to match 'in'
	numMatchedChars = matchRegex (re_inKwd, text) ;
	
	if (numMatchedChars == 2 && maxNumMatchedChars == 2 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = inKwd ;
	}
	//Try to match 'end'
	numMatchedChars = matchRegex (re_endKwd, text) ;
	
	if (numMatchedChars == 3 && maxNumMatchedChars == 3 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = endKwd ;
	}
	
	//Try to match 'if'
	numMatchedChars = matchRegex (re_ifKwd, text) ;
	
	if (numMatchedChars == 2 && maxNumMatchedChars == 2 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = ifKwd ;
	}
	
	//Try to match 'then'
	numMatchedChars = matchRegex (re_thenKwd, text) ;
	
	if (numMatchedChars == 4 && maxNumMatchedChars == 4 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = thenKwd ;
	}
	
	//Try to match 'else'
	numMatchedChars = matchRegex (re_elseKwd, text) ;
	
	if (numMatchedChars == 4 && maxNumMatchedChars == 4 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = elseKwd ;
	}
	
	//Try to match 'print'
	numMatchedChars = matchRegex (re_printKwd, text) ;
	
	if (numMatchedChars == 5 && maxNumMatchedChars == 5 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = printKwd ;
	}
	
	//Try to match 'read'
	numMatchedChars = matchRegex (re_readKwd, text) ;
	
	if (numMatchedChars == 4 && maxNumMatchedChars == 4 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = readKwd ;
	}

	//Try to match 'write'
	numMatchedChars = matchRegex (re_writeKwd, text) ;
	
	if (numMatchedChars == 5 && maxNumMatchedChars == 5 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = writeKwd ;
	}
	
	//Try to match 'int'
	numMatchedChars = matchRegex (re_integerKwd, text) ;
	
	if (numMatchedChars == 7 && maxNumMatchedChars == 7 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = integerKwd ;
	}
	
	//Try to match 'float'
	numMatchedChars = matchRegex (re_floatKwd, text) ;
	
	if (numMatchedChars == 5 && maxNumMatchedChars == 5 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = floatKwd ;
	}
	
	//Try to match 'boolean'
	numMatchedChars = matchRegex (re_booleanKwd, text) ;
	
	if (numMatchedChars == 7 && maxNumMatchedChars == 7 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = booleanKwd ;
	}
	
	//Try to match 'string'
	numMatchedChars = matchRegex (re_stringKwd, text) ;
	
	if (numMatchedChars == 6 && maxNumMatchedChars == 6 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = stringKwd ;
	}
	
	//Try to match 'true'
	numMatchedChars = matchRegex (re_trueKwd, text) ;
	
	if (numMatchedChars == 4 && maxNumMatchedChars == 4 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = trueKwd ;
	}
	
	//Try to match 'false'
	numMatchedChars = matchRegex (re_falseKwd, text) ;
	
	if (numMatchedChars == 5 && maxNumMatchedChars == 5 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = falseKwd ;
	}
	
	//Try to match 'head'
	numMatchedChars = matchRegex (re_headKwd, text) ;
	
	if (numMatchedChars == 4 && maxNumMatchedChars == 4 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = headKwd ;
	}
	
	//Try to match 'tail'
	numMatchedChars = matchRegex (re_tailKwd, text) ;
	
	if (numMatchedChars == 4 && maxNumMatchedChars == 4 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = tailKwd ;
	}



	//Try to match 'null'
	numMatchedChars = matchRegex (re_nullKwd, text) ;
	
	if (numMatchedChars == 4 && maxNumMatchedChars == 4 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = nullKwd ;
	}
	
	//Try to match 'map'
	numMatchedChars = matchRegex (re_mapKwd, text) ;
	
	if (numMatchedChars == 3 && maxNumMatchedChars == 3 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = mapKwd ;
	}
	
	//Try to match 'filter'
	numMatchedChars = matchRegex (re_filterKwd, text) ;
	
	if (numMatchedChars == 6 && maxNumMatchedChars == 6 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = filterKwd ;
	}
	
	//Try to match 'fold'
	numMatchedChars = matchRegex (re_foldKwd, text) ;
	
	if (numMatchedChars == 4 && maxNumMatchedChars == 4 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = foldKwd ;
	}
	
	//Try to match 'zip'
	numMatchedChars = matchRegex (re_zipKwd, text) ;
	
	if (numMatchedChars == 3 && maxNumMatchedChars == 3 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = zipKwd ;
	}


	// The following part is created by Sichao
	// Try to match 'leftParen'
	numMatchedChars = matchRegex (re_leftParen, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = leftParen ;
	}
	
	// Try to match 'rightParen'
	numMatchedChars = matchRegex (re_rightParen, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = rightParen ;
	}
	
	// Try to match 'leftSquare'
	numMatchedChars = matchRegex (re_leftSquare, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = leftSquare ;
	}
	
	// Try to match 'rightSquare'
	numMatchedChars = matchRegex (re_rightSquare, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = rightSquare ;
	}
	
	// Try to match 'leftAngle'
	numMatchedChars = matchRegex (re_leftAngle, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = leftAngle ;
	}

	
	// Try to match 'rightAngle'
	numMatchedChars = matchRegex (re_rightAngle, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = rightAngle ;
	}
	// Try to match 'colon'
	numMatchedChars = matchRegex (re_colon, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = colon ;
	}
	
	// Try to match 'colonColon'
	numMatchedChars = matchRegex (re_colonColon, text) ;
	
	if (numMatchedChars == 2) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = colonColon ;
	}
	
	// Try to match 'comma'
	numMatchedChars = matchRegex (re_comma, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = comma ;
	}
	
	// Try to match 'semiColon'
	numMatchedChars = matchRegex (re_semiColon, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = semiColon ;
	}
	
	// Try to match 'equalsSign'
	numMatchedChars = matchRegex (re_equalsSign, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = equalsSign ;
	    
	}
	// Try to match 'plusSign'
	numMatchedChars = matchRegex (re_plusSign, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = plusSign ;
	}
	
	// Try to match 'star'
	numMatchedChars = matchRegex (re_star, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = star ;
	}
	
	// Try to match 'dash'
	numMatchedChars = matchRegex (re_dash, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = dash ;
	}
	
	// Try to match 'forwardSlash'
	numMatchedChars = matchRegex (re_forwardSlash, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = forwardSlash ;
	}
	
	// Try to match 'percent'
	numMatchedChars = matchRegex (re_percent, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = percent ;
	}
	
	// Try to match 'backSlash'
	numMatchedChars = matchRegex (re_backSlash, text) ;
	
	if (numMatchedChars == 1) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = backSlash ;
	}
	
	// Try to match 'arrow'
	numMatchedChars = matchRegex (re_arrow, text) ;
	
	if (numMatchedChars == 2) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = arrow ;
	}
	
	// Try to match 'equalsEquals'
	numMatchedChars = matchRegex (re_equalsEquals, text) ;
	
	if (numMatchedChars == 2) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = equalsEquals ;
	}
	
	// Try to match 'lessThanEquals'
	numMatchedChars = matchRegex (re_lessThanEquals, text) ;
	
	
	if (numMatchedChars == 2) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = lessThanEquals ;
	}
	
	// Try to match 'greaterThanEquals'
	numMatchedChars = matchRegex (re_greaterThanEquals, text) ;
	
	if (numMatchedChars == 2) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = greaterThanEquals ;
	}
	
	// Try to match 'notEquals'
	numMatchedChars = matchRegex (re_notEquals, text) ;
	
	if (numMatchedChars == 2) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = notEquals ;
	}
	
	// Try to match 'plusPlus'
	numMatchedChars = matchRegex (re_plusPlus, text) ;
	
	if (numMatchedChars == 2) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = plusPlus ;
	}
	
	// Try to match 'dotDot'
	numMatchedChars = matchRegex (re_dotDot, text) ;
	
	if (numMatchedChars == 2) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = dotDot ;
	}
	
	// Try to match 'tupleOp'
	numMatchedChars = matchRegex (re_tupleOp, text) ;
	if (numMatchedChars >= 2 && maxNumMatchedChars >= 0) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = tupleOp ;
	}
	
	// Try to match 'endOfFile'
	numMatchedChars = matchRegex (re_endOfFile, text) ;
	
	if (numMatchedChars == 3 && maxNumMatchedChars == 3 && matchType == variableName) {
		maxNumMatchedChars = numMatchedChars ;
	    matchType = endOfFile ;
	}
	if (matchType == lexicalError) {
            // If we didn't match anything, then just skip the first character.
            (*currentToken).terminal=lexicalError;
            (*currentToken).lexeme = text[0];
            (*currentToken).next = new Token();
            currentToken = (*currentToken).next;
            text = text + 1;
        }
        else {
			
            // Consume the characters that were matched.
            (*currentToken).terminal = matchType;
            char sub[maxNumMatchedChars+1];
            memcpy( sub, text, maxNumMatchedChars );
            sub[maxNumMatchedChars]='\0';
            (*currentToken).lexeme = sub;
			(*currentToken).next = new Token();
            currentToken = (*currentToken).next;
            text = text + maxNumMatchedChars ;
        }
        
        // Consume white space and comments before trying again for
        // another word or integer.
        numMatchedChars = consumeWhiteSpaceAndComments (whiteSpace, blockComment, lineComment, text) ;
        text = text + numMatchedChars ;

    }
    if((*currentToken).terminal != lexicalError) {
		(*currentToken).terminal = endOfFile;
		(*currentToken).next = NULL;
	}
	
    return startToken;
}
