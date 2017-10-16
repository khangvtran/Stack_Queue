/*
 * Postfix.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: KVTran
 */

/**
 * Questions:
 * Nature of string stream
 * stringstream vs istringstream
 * Detecting the end of line in a string stream
 * Detecting if the stringstream is a number
 */


# include "Queue.h"
# include "Stack.h"
# include <sstream>

bool firstHasHigherPrec(string & operator1, string & operator2);
// this function takes in two string values and return true if the first one has higher precedence.
// Return false otherwise

int main()

{
	string first = "+";
	string second = "/";
	if (firstHasHigherPrec(first, second)) cout << "true" << endl;
	else cout << "false" << endl;

	// Read in the user input in format 1 + 2 * 3
	cout << "Please enter an equation or 'q' to quit: ";
	string equation;
	getline(cin, equation);

	// declare stringstream, string, stack, queue
	stringstream ss(equation);
	string component;
	Stack<string> S;
	Queue<string> Q;

	// process the input equation
	while (ss >> component)
	{
		if (component != "+" && component != "-" && component != "*" && component != "/")
		{
			cout << "Number: " << component << endl;
			Q.enqueue(component);
		}
		else
		{
			cout << "operand: " << component << endl;
			if (!S.empty())
			{
				string stackTop = S.peek();
				if (firstHasHigherPrec(stackTop, component))
				{
					Q.enqueue(stackTop);
					S.pop();
					S.push(component);
				}
				else S.push(component);
			}
			else S.push(component);
		}
	}
	while (!S.empty())
	{
		Q.enqueue(S.peek());
		S.pop();
	}

	Q.print();
	return 0;
}

bool firstHasHigherPrec(string & operator1, string & operator2)
{
	if ((operator1 == "+" || operator1 == "-") && (operator2 == "*" || operator2 == "/"))
	{
		return false;
	}
	return true;
}



