#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

// Enumarated Type specifying all of the Tokens
enum TokenType{
  ERROR, OPERATOR, VALUE, EOLN, QUIT, HELP, EOFILE
};

class Token
{
  private:
    TokenType type;
    char      op;       // using '$' as undefined/error
    int       val;      // using -999 as undefined/error

  public:
		Token();
		Token (TokenType t);
		void setToType(TokenType t);
		void setToOperator(char c);
		void setToValue(int v);
		bool equalsType(TokenType t);
		bool equalsOperator(char c);
		char getOperator ();
		int getValue();
};

class TokenReader
{
  private:
     char inputline[300];  // this assumes that all input lines are 300 characters or less in length
     bool needline;
     int pos;


  public:
		TokenReader();
		void clearToEoln();
		Token getNextToken();
};

// digits stack class
class MyStack {
	private:
		int* myStack;
		int capacity;
		int size; // size and not index (last item index is size - 1)

	public:
		MyStack();
		~MyStack();
		void push(int x);
		int top();
		void pop();
		bool isEmpty();
		void clear();
};
