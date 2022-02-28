/**************************************************************/
/*                                                            */
/*  The Code below this point should NOT need to be modified  */
/*  for this program.   If you feel you must modify the code  */
/*  below this point, you are probably trying to solve a      */
/*  more difficult problem that you are being asked to solve  */
/*                                                            */
/**************************************************************/

#include <cstdio>
#include <cstring>
#include <cctype>
#include "calculator.h"

using namespace std;

void printCommands()
{
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("or any infix mathematical expression using operators of (), *, /, +, -\n");
}


    /**************************************************************/
    /*                                                            */
    /*  The Code above this point should NOT need to be modified  */
    /*  for this program.   If you feel you must modify the code  */
    /*  below this point, you are probably trying to solve a      */
    /*  more difficult problem that you are being asked to solve  */
    /*                                                            */
    /**************************************************************/

int eval(int x, int op, int y);
void popAndEval(MyStack& digit, MyStack& op);
void processExpression (Token inputToken, TokenReader *tr);

int main(int argc, char *argv[])
{
    /***************************************************************/


    Token inputToken;
    TokenReader tr;

    printf ("Starting Expression Evaluation Program\n\n");
    printf ("Enter Expression:\n");


    inputToken = tr.getNextToken ();

    while (inputToken.equalsType(QUIT) == false)
    {
      /* check first Token on Line of input */
      if(inputToken.equalsType(HELP))
      {
       printCommands();
       tr.clearToEoln();
      }
      else if(inputToken.equalsType(ERROR))
      {
       printf ("Invalid Input - For a list of valid commands, type ?\n");
       tr.clearToEoln();
      }
      else if(inputToken.equalsType(EOLN))
      {
       printf ("Blank Line - Do Nothing\n");
       /* blank line - do nothing */
      }
      else
      {

       processExpression(inputToken, &tr);
			 
      }

      printf ("Enter Expression:\n");
      inputToken = tr.getNextToken ();
    }

  printf ("Quitting Program\n");
  return 0;
}

void processExpression (Token inputToken, TokenReader *tr)
{
 /**********************************************/
 /* Declare both stack pointers here      */
 MyStack digitStack;
 MyStack opStack;

 /* Loop until the expression reaches its End */
 while (!inputToken.equalsType(EOLN))
   {
    /* The expression contain a VALUE */
    if (inputToken.equalsType(VALUE))
      {

       digitStack.push(inputToken.getValue());
			 
      }

    /* The expression contains an OPERATOR */
    else if (inputToken.equalsType(OPERATOR))
    {

       if (inputToken.getOperator() == '(') {
				 opStack.push(inputToken.getOperator());
			 }
			 else if (inputToken.getOperator() == '+' || inputToken.getOperator() == '-') {
				 while (!opStack.isEmpty() && (opStack.top() == '+'
				 														|| opStack.top() == '-'
																		|| opStack.top() == '*'
																		|| opStack.top() == '/'
																		|| opStack.top() == '%')) {
					  popAndEval(digitStack, opStack);
				  }
					opStack.push(inputToken.getOperator());
			  }
			 else if (inputToken.getOperator() == '*' 
			 			 || inputToken.getOperator() == '/' 
						 || inputToken.getOperator() == '%') {
					while (!opStack.isEmpty() && (opStack.top() == '*'
				 														|| opStack.top() == '/'
																		|| opStack.top() == '%')) {
						popAndEval(digitStack, opStack);
					}
					opStack.push(inputToken.getOperator());
			  }
			else if (inputToken.getOperator() == ')') {
				while (!opStack.isEmpty() && opStack.top() != '(') {
					popAndEval(digitStack, opStack);
				}
				if (opStack.isEmpty()) {
					printf("missing '('\n");
				}
				else {
					opStack.pop();
				}
			}
	  }
    /* get next token from input */
    inputToken = tr->getNextToken ();
   }

 /* The expression has reached its end */

 // add code to perform this operation here
 while (!opStack.isEmpty()) {
	 popAndEval(digitStack, opStack);
 }
 if (digitStack.isEmpty()) {
	 printf("Invalid expression.\n");
 }
 else {
	//  printf("Expression result: %d\n", digitStack.top());
	int result = digitStack.top();
	 digitStack.pop();
	 if (!digitStack.isEmpty()) {
		 printf("invalid expression.\n");
	 }
	 else {
		 printf("Expression result: %d\n", result);
	 }
 }
}

void popAndEval(MyStack& digitStack, MyStack& opStack) {
	int oper = opStack.top();
	opStack.pop();
	int v2 = digitStack.top();
	digitStack.pop();
	int v = digitStack.top();
	digitStack.pop();
	int v3 = eval(v, oper, v2);
	digitStack.push(v3);
}

int eval(int x, int op, int y) {
	if (op == '+') {
		return x + y;
	}
	else if (op == '-') {
		return x - y;
	}
	else if (op == '*') {
		return x * y;
	}
	else if (op == '/') {
		return x / y;
	}
	else {
		return x % y;
	}
}