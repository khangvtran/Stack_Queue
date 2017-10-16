/*
 * StackTest.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: KVTran
 */



# include "Stack.h"

/*
int main()
{

	cout << "This is StackTest.cpp" << endl;
	cout << endl << "- Test default constructor by create an empty stack." << endl;
	Stack<int> S1;
	cout << "Default constructor works" << endl;
	cout << "- Test empty() on the empty stack. Should print out: 'Yes. The stack is empty'" << endl;
	if (S1.empty()) cout << "Yes. The stack is empty" << endl;
	else cout << "No. The stack is not empty" << endl;
	cout << "- Test getSize(). Should get 0" << endl;
	cout << S1.getSize() << endl;
	cout << "- Test print. Should get empty line" << endl;
	S1.print();

	cout << "- Now, push 1 2 3 4, then empty(). Should print out: 'No. The stack is not empty'" << endl;
	for (int i = 1; i <= 4; i++) S1.push(i);
	if (S1.empty()) cout << "Yes. The stack is empty" << endl;
	else cout << "No. The stack is not empty" << endl;
	cout << "- Test getSize() again. Should get 4" << endl;
	cout << S1.getSize() << endl;
	cout << "- Test print. Should get 4 3 2 1" << endl;
	S1.print();

	cout <<"- Now, test pop 1 node. Then getSize(). Should get 3" << endl;
	S1.pop();
	cout << S1.getSize() << endl;
	cout << "- Test print. Should get 3 2 1" << endl;
	S1.print();

	cout << "- Now, create 2 empty Stacks and test ==. Should print 'Equal'" << endl;
	Stack<int> S2;
	Stack<int> S3;
	if (S2 == S3) cout << "Equal" << endl;
	cout << "-Now, push 1 2 3 to one of them and test ==. Should print 'Not equal'" << endl;
	for (int i = 1; i <= 3; i++) S2.push(i);
	if (!(S2 == S3)) cout << "Not Equal" << endl;
	cout << "- Now test == between the 2 Stacks with 3 2 1. Should print 'Equal'" << endl;
	if (S1 == S2) cout << "Equal" << endl;

	cout << "- Now, test copy constructor. Create S4 as acopy of S1. then print S4. Should get 3 2 1 " << endl;
	Stack<int> S4(S1);
	S4.print();
	return 0;
}
*/
