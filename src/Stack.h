/*
 * Stack.h
 *
 *  Created on: Oct 14, 2017
 *      Author: Khang Vinh Tran, Tri Doan
 *      CIS 22C, Lab 3
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;

template <class stackdata>
class Stack
{
private:
   struct Node
   {
       stackdata data;
       Node* link;
       Node(stackdata ndata)
       {
    	   data = ndata;
    	   link = NULL;
        }
    };
   Node* top;
   int size;


    public:
        /**constructors and destructors*/

        Stack();

        //initializes an empty stack
        //postcondition: an empty stack

        Stack(const Stack &S);
        //initializes this stack to have same elements as S
        //postcondition: a copy of stack


        ~Stack();
        //frees memory allocated to the stack
        //postcondition: memory for stack has been freed

        /**manipulation procedures*/

        void pop();
        //removes an element from the top of the stack
        //precondition: size != 0
        //postcondition: an element has been removed from the top of the stack

        void push(stackdata data);
        //adds an element to the top of the stack
        //postcondition: an element added to the top of the stack

        /**accessors*/


       bool operator==(const Stack &S);
       //returns whether this stack is equal to another stack S

       stackdata peek() const;
       //returns the element at the top of the stack
       //precondition: size != 0

       int getSize() const;
       //returns the size of the stack

       bool empty() const;
       //returns whether the stack is empty


       /**additional operations*/

       void print() const;
       //prints the elements in the stack each element separate by a blank space to stdout
};

/*************************************************************************/
/**Constructors and Destructors*/
template <class stackdata>
Stack<stackdata>::Stack()
{
	top = NULL;
	size = 0;
}


template <class stackdata>
Stack<stackdata>::Stack(const Stack& S)
{
	size = S.size;
	if (S.top == NULL)
	{
		top = NULL;
	}
	else
	{
		top = new Node(S.top->data);
		Node* temp = S.top;
		Node* stemp = top;
		while(temp->link != NULL)
		{
			temp = temp->link;
			stemp->link = new Node(temp->data);
			stemp = stemp->link;
		}
	}
}

template <class stackdata>
Stack<stackdata>::~Stack()
{
	Node* b = top;
	Node* a = NULL;
	while(b != NULL)
	{
		a = b->link;
		delete b;
		b = a;
	}
}



/*************************************************************************/
/**Manipulators*/

/*
template <class stackdata>
void Stack<stackdata>::push(stackdata data)
{
	Node* N = new Node(data);
	if (size == 0) top = N;
	else
	{
		N->link = top;
		top = N;
	}
	size++;   // enforce postcondition
}
*/

template <class stackdata>
void Stack<stackdata>::push(stackdata data)
{
	Node* N = new Node(data);
	N->link = top;
	top = N;
	size++;   // enforce postcondition
}

/*
template <class stackdata>
void Stack<stackdata>::pop()
{
	assert(!empty());     // enforce the precondition
	if (size == 1)
	{
		delete top;
		top = NULL;
	}
	else
	{
		Node* temp = top;
		top = top->link;
		delete temp;
	}
	size--;               // enforce post condition
}
*/
template <class stackdata>
void Stack<stackdata>::pop()
{
	assert(!empty());     // enforce the precondition
	Node* temp = top;
	top = top->link;
	delete temp;
	size--;               // enforce post condition
}




/*************************************************************************/
/**Accessors**/

template<class stackdata>
int Stack<stackdata>::getSize() const
{
	return size;
}

template<class stackdata>
bool Stack<stackdata>::empty() const
{
	return size == 0;
}

template <class stackdata>
stackdata Stack<stackdata>::peek() const
{
	assert(!empty());     // enforce precondition
	return top->data;
}


template <class stackdata>
bool Stack<stackdata>::operator==(const Stack & stack)
{
	if (size != stack.size) return false;
	else
	{
		Node* temp1 = top;
		Node* temp2 = stack.top;
		while(temp1 != NULL)
		{
			if (temp1->data != temp2->data) return false;
			temp1 = temp1->link;
			temp2 = temp2->link;
		}
		return true;
	}
}




/*************************************************************************/
/**additional operations*/
template <class stackdata>
void Stack<stackdata>::print() const
{
	Node* temp = top;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}


#endif /* STACK_H_ */



