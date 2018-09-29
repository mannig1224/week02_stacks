/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
#include <stdio.h>     // for Alpha and Digits

using namespace std;

int priority (char c)
{
	if(c == '^')
	 return 3;
	 else if(c == '*' || c == '/')
	 return 2;
	 else if(c == '+' || c == '-')
	 return 1;
	 else
	 return -1;
}

/*****************************************************
* CONVERT INFIX TO POSTFIX
* Convert infix equation "5 + 2" into postifx "5 2 +"
*****************************************************/
string convertInfixToPostfix(const string & infix)
{
	custom::stack <char> cTemp;
	string postfix;

	for (int i = 0; i < infix.length(); i++)
	{
		if(infix[i] == ' ')
		{
			continue;
		}
		if(isalpha(infix[i]) || isdigit(infix[i]) || infix[i] == '.')
		{
			postfix += infix[i];
			continue;
		}
		postfix += ' ';

    if (cTemp.empty())
		{
			cTemp.push(infix[i]);
			continue;
		}
		if(infix[i] == '(')
		{
			cTemp.push(infix[i]);
			continue;
		}
		if(infix[i] == ')')
		{
			char lastPop = '0';
			while(lastPop != '(')
			{
				lastPop = cTemp.top();
				postfix += ' ';
				if (lastPop != ')' && lastPop != '(')
				{
					postfix += lastPop;
				}
				postfix += ' ';
				cTemp.pop();
			}
			cTemp.push(infix[i]);
			continue;
		}
		while (priority(infix[i]) <= priority(cTemp.top()))
		{
			char tempChar = cTemp.top();
			postfix += ' ';
			if (tempChar != ')' && tempChar != '(')
			{
				postfix += tempChar;
			}

			postfix += ' ';
			cTemp.pop();
			if(cTemp.empty())
			{
				break;
			}
		}
      cTemp.push(infix[i]);
	}
	   while(!cTemp.empty())
		 {
			 char tempChar = cTemp.top();
			 postfix += ' ';
			 if (tempChar != ')' && tempChar != '(')
			 {
				 postfix += tempChar;

			 }
			 postfix += ' ';
 			 cTemp.pop();
		 }


		 string postfixWithSingleSpaces;
   for(int i = 0; i < postfix.size(); i++)
	 {
		 if(postfix[i] == ' ')
 		{
			if(postfix[i - 1] == ' ')
			{
				continue;
			}
			else
			{
 			postfixWithSingleSpaces += postfix[i];
 			continue;
		  }
 		}
		 postfixWithSingleSpaces += postfix[i];
	 }
	 string noSpaceAtEnd;
	 for (int i = 0; i < postfixWithSingleSpaces.size() -1; i++ )
	 {
		 if (i == 0 && postfixWithSingleSpaces[i] == ' ')
		 {
			 continue;
		 }
		 noSpaceAtEnd += postfixWithSingleSpaces[i];
	 }
   return noSpaceAtEnd;
}


/*****************************************************
* TEST INFIX TO POSTFIX
* Prompt the user for infix text and display the
* equivalent postfix expression
*****************************************************/
void testInfixToPostfix()
{
	string input;
	cout << "Enter an infix equation.  Type \"quit\" when done.\n";

	do
	{
		// handle errors
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
		}

		// prompt for infix
		cout << "infix > ";
		getline(cin, input);

		// generate postfix
		if (input != "quit")
		{
			string postfix = convertInfixToPostfix(input);
			cout << "\tpostfix:  " << postfix << endl << endl;
		}
	} while (input != "quit");
}

/**********************************************
* CONVERT POSTFIX TO ASSEMBLY
* Convert postfix "5 2 +" to assembly:
*     LOAD 5
*     ADD 2
*     STORE VALUE1
**********************************************/
string convertPostfixToAssembly(const string & postfix)
{
	string assembly;

	return assembly;
}

/*****************************************************
* TEST INFIX TO ASSEMBLY
* Prompt the user for infix text and display the
* resulting assembly instructions
*****************************************************/
void testInfixToAssembly()
{
	string input;
	cout << "Enter an infix equation.  Type \"quit\" when done.\n";

	do
	{
		// handle errors
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
		}

		// prompt for infix
		cout << "infix > ";
		getline(cin, input);

		// generate postfix
		if (input != "quit")
		{
			string postfix = convertInfixToPostfix(input);
			cout << convertPostfixToAssembly(postfix);
		}
	} while (input != "quit");

}
