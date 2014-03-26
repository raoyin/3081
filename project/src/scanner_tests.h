#include <cxxtest/TestSuite.h>

#include "readInput.h"
#include "scanner.h"

using namespace std ;

class ScannerTestSuite : public CxxTest::TestSuite 
{
public:
    /* A Scanner object is created in the test_setup_code method.
       This is a test, beginning with "test_", so that it is executed
       by the testing framework.  The scanner is used in some tests of
       the method "scan".
     */
    Scanner *s ;
    void test_setup_code ( ) {
        s = new Scanner() ;
    }


    // Tests for components and functions used by "scan"
    // --------------------------------------------------

    /* You will need to write several tests to adequately test the
       functions that are called from "scan".  Once you are confident
       that the components used by "scan" work properly, then you can
       run tests on the "scan" method itself.
    */

    // Here you should place tests for these other functions.
    // The following part is created by Raoyin Chen
    // keyWords
    void test_terminal_letKwd ( ) {
        Token *token;
        
        token = (*s).scan("let");
        TS_ASSERT_EQUALS ((*token).terminal, letKwd) ;
    }
    
    void test_terminal_inKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("in");
        TS_ASSERT_EQUALS ((*token).terminal, inKwd) ;
    }
    
    void test_terminal_endKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("end");
        TS_ASSERT_EQUALS ((*token).terminal, endKwd) ;
    }
    
    void test_terminal_ifKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("if");
        TS_ASSERT_EQUALS ((*token).terminal, ifKwd) ;
    }
    
    void test_terminal_thenKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("then");
        TS_ASSERT_EQUALS ((*token).terminal, thenKwd) ;
    }
    
    void test_terminal_elseKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("else");
        TS_ASSERT_EQUALS ((*token).terminal, elseKwd) ;
    }
    
    void test_terminal_printKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("print");
        TS_ASSERT_EQUALS ((*token).terminal, printKwd) ;
    }
    
    void test_terminal_readKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("read");
        TS_ASSERT_EQUALS ((*token).terminal, readKwd) ;
    }
    
    void test_terminal_writeKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("write");
        TS_ASSERT_EQUALS ((*token).terminal, writeKwd) ;
    }
    
    void test_terminal_integerKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("Integer");
        TS_ASSERT_EQUALS ((*token).terminal, integerKwd) ;
    }
    
    void test_terminal_floatKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("Float");
        TS_ASSERT_EQUALS ((*token).terminal, floatKwd) ;
    }
    
    void test_terminal_booleanKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("Boolean");
        TS_ASSERT_EQUALS ((*token).terminal, booleanKwd) ;
    }
    
    void test_terminal_stringKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("String");
        TS_ASSERT_EQUALS ((*token).terminal, stringKwd) ;
    }
    
    void test_terminal_trueKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("true");
        TS_ASSERT_EQUALS ((*token).terminal, trueKwd) ;
    }
    
    void test_terminal_falseKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("false");
        TS_ASSERT_EQUALS ((*token).terminal, falseKwd) ;
    }
    
    void test_terminal_headKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("head");
        TS_ASSERT_EQUALS ((*token).terminal, headKwd) ;
    }
    
    void test_terminal_tailKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("tail");
        TS_ASSERT_EQUALS ((*token).terminal, tailKwd) ;
    }
    
    void test_terminal_nullKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("null");
        TS_ASSERT_EQUALS ((*token).terminal, nullKwd) ;
    }
    
    void test_terminal_mapKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("map");
        TS_ASSERT_EQUALS ((*token).terminal, mapKwd) ;
    }
    
    void test_terminal_filterKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("filter");
        TS_ASSERT_EQUALS ((*token).terminal, filterKwd) ;
    }
    
    void test_terminal_foldKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("fold");
        TS_ASSERT_EQUALS ((*token).terminal, foldKwd) ;
    }
    
    void test_terminal_zipKwd ( ) {
        Token *token;
        
        
        token = (*s).scan("zip");
        TS_ASSERT_EQUALS ((*token).terminal, zipKwd) ;
    }
    
    // Constants
    void test_terminal_intConst ( ) {
        Token *token;
        
        
        token = (*s).scan("5");
        TS_ASSERT_EQUALS ((*token).terminal, intConst) ;
    }
    
    void test_terminal_floatConst ( ) {
        Token *token;
        
        
        token = (*s).scan("5.1");
        TS_ASSERT_EQUALS ((*token).terminal, floatConst) ;
    }
    
    void test_terminal_stringConst ( ) {
        Token *token;
        
        
        token = (*s).scan("\"ssd\"");
        TS_ASSERT_EQUALS ((*token).terminal, stringConst) ;
    }
   


    // The followig part is created by Sichao Shi
    // Names
    void test_terminal_variableName ( ) {
        Token *token;
        
        
        token = (*s).scan("happy");
        TS_ASSERT_EQUALS ((*token).terminal, variableName) ;
    }
    // Punctuation
    void test_terminal_leftParen ( ) {
        Token *token;
        
        
        token = (*s).scan("(");
        TS_ASSERT_EQUALS ((*token).terminal, leftParen) ;
    }

    void test_terminal_rightParen ( ) {
        Token *token;
        
        
        token = (*s).scan(")");
        TS_ASSERT_EQUALS ((*token).terminal, rightParen) ;
    }

    void test_terminal_leftSquare ( ) {
        Token *token;
        
        
        token = (*s).scan("[");
        TS_ASSERT_EQUALS ((*token).terminal, leftSquare) ;
    }

    void test_terminal_rightSquare ( ) {
        Token *token;
        
        
        token = (*s).scan("]");
        TS_ASSERT_EQUALS ((*token).terminal, rightSquare) ;
    }

    void test_terminal_leftAngle ( ) {
        Token *token;
        
        
        token = (*s).scan("<");
        TS_ASSERT_EQUALS ((*token).terminal, leftAngle) ;
    }

    void test_terminal_rightAngle ( ) {
        Token *token;
        
        
        token = (*s).scan(">");
        TS_ASSERT_EQUALS ((*token).terminal, rightAngle) ;
    }

    void test_terminal_colon ( ) {
        Token *token;
        
        
        token = (*s).scan(":");
        TS_ASSERT_EQUALS ((*token).terminal, colon) ;
    }

    void test_terminal_colonColon ( ) {
        Token *token;
        
        
        token = (*s).scan("::");
        TS_ASSERT_EQUALS ((*token).terminal, colonColon) ;
    }

    void test_terminal_comma ( ) {
        Token *token;
        
        
        token = (*s).scan(",");
        TS_ASSERT_EQUALS ((*token).terminal, comma) ;
    }

    void test_terminal_semiColon ( ) {
        Token *token;
        
        
        token = (*s).scan(";");
        TS_ASSERT_EQUALS ((*token).terminal, semiColon) ;
    }

    void test_terminal_equalsSign ( ) {
        Token *token;
        
        
        token = (*s).scan("=");
        TS_ASSERT_EQUALS ((*token).terminal, equalsSign) ;
    }

    void test_terminal_plusSign ( ) {
        Token *token;
        
        
        token = (*s).scan("+");
        TS_ASSERT_EQUALS ((*token).terminal, plusSign) ;
    }

    void test_terminal_star ( ) {
        Token *token;
        
        
        token = (*s).scan("*");
        TS_ASSERT_EQUALS ((*token).terminal, star) ;
    }

    void test_terminal_dash ( ) {
        Token *token;
        
        
        token = (*s).scan("-");
        TS_ASSERT_EQUALS ((*token).terminal, dash) ;
    }

    void test_terminal_forwardSlash ( ) {
        Token *token;
        
        
        token = (*s).scan("/");
        TS_ASSERT_EQUALS ((*token).terminal, forwardSlash) ;
    }

    void test_terminal_percent ( ) {
        Token *token;
        
        
        token = (*s).scan("%");
        TS_ASSERT_EQUALS ((*token).terminal, percent) ;
    }

    void test_terminal_backSlash ( ) {
        Token *token;
        
        
        token = (*s).scan("\\");
        TS_ASSERT_EQUALS ((*token).terminal, backSlash) ;
    }

    void test_terminal_arrow ( ) {
        Token *token;
        
        
        token = (*s).scan("->");
        TS_ASSERT_EQUALS ((*token).terminal, arrow) ;
    }

    void test_terminal_equalsEquals ( ) {
        Token *token;
        
        
        token = (*s).scan("==");
        TS_ASSERT_EQUALS ((*token).terminal, equalsEquals) ;
    }

    void test_terminal_lessThanEquals ( ) {
        Token *token;
        
        
        token = (*s).scan("<=");
        TS_ASSERT_EQUALS ((*token).terminal, lessThanEquals) ;
    }

    void test_terminal_greaterThanEquals ( ) {
        Token *token;
        token = (*s).scan(">=");
        TS_ASSERT_EQUALS ((*token).terminal, greaterThanEquals) ;
    }

    void test_terminal_notEquals ( ) {
        Token *token;
        
        
        token = (*s).scan("!=");
        TS_ASSERT_EQUALS ((*token).terminal, notEquals) ;
    }

    void test_terminal_plusPlus ( ) {
        Token *token;
        
        
        token = (*s).scan("++");
        TS_ASSERT_EQUALS ((*token).terminal, plusPlus) ;
    }

    void test_terminal_dotDot ( ) {
        Token *token;
        
        
        token = (*s).scan("..");
        TS_ASSERT_EQUALS ((*token).terminal, dotDot) ;
    }

    void test_terminal_tupleOp ( ) {
        Token *token;
        
        
        token = (*s).scan("#1(xy)");
        TS_ASSERT_EQUALS ((*token).terminal, tupleOp) ;
    }

    void test_terminal_lexicalError ( ) {
        Token *token;
        
        token = (*s).scan("$");
        TS_ASSERT_EQUALS ((*token).terminal, lexicalError) ;
    }

    /* Below is one of my tests for these components.  It uses a
       helper function function called "tokenMaker_tester", which you
       have not been given.  You are expected to design your own
       components for "scan" and your own mechanisms for easily
       testing them. The example test can be simplified AND improved
	   upon with respect to good testing principles.

        void xtest_TokenMaker_leftCurly ( ) {
            tokenMaker_tester ("{ ", "^\\{", leftCurly, "{" ) ;
        }

        Note that this test is here named "xtest_Token..." The leading
        "x" is so that cxxTest doesn't scan the line above and think
        it is an actual test that isn't commented out.  cxxTest is
        very simple and doesn't even process block comments.
    */
	





} ;





