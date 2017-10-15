/*
 * Queue.h
 *
 *  Created on: Oct 13, 2017
 *      Author: Khang Vinh Tran
 *      CIS 22C, Lab3
 */

#ifndef QUEUE_H_
#define QUEUE_H_

# include <iostream>
# include <cstddef>
# include <assert.h>
using namespace std;

template <class queuedata>
class Queue
{
private:
    struct Node
    {
        queuedata data;
        Node* link;
        Node(queuedata ndata)
        {
        	data = ndata;
		link = NULL;
        }
    };
    Node* front;
    Node* back;
    int size;
    public:
        /**constructors and destructors*/

        Queue();
        //initializes an empty queue
        //postcondition: an empty queue

        Queue(const Queue &queue);
        //initializes queue to have same elements as another queue
        //postcondition: a copy of queue

        ~Queue();
        //frees memory allocated to the queue
        //postcondition: memory for queue has been freed

        /**manipulation procedures*/

        void dequeue();
        //removes an element from the front of the queue
        //precondition:size!=0
        //postcondition: an element has been removed from the front of the queue

        void enqueue(queuedata data);
        //adds an element to the end of the queue
        //postcondition: an element added to the end of the queue

        /**accessors*/

        bool operator==(const Queue &queue);
        //returns whether this queue is equal to another queue

        queuedata getFront() const;
        //returns the element at the front of the queue
        //precondition: size != 0

        int getSize() const;
        //returns the size of the queue

        bool empty() const;
        //returns whether the queue is empty

        /**additional queue operations*/
        void print() const;
        //prints the elements in the queue separated by a blank space to stdout
};




/*************************************************************************/
/**Constructors and Destructors*/

template<class queuedata>
Queue<queuedata>::Queue()
{
	front = back = NULL;
	size = 0;
}

template <class queuedata>
Queue<queuedata>::Queue(const Queue &queue)
{
       size = queue.size;
       if(queue.front == NULL)
       {
           back = front = NULL;
       }

       else
        {
            front = new Node(queue.front->data); // Create the node that start is pointing to
            Node* temp = queue.front;
            Node* qtemp = front; //create temporary iterator

            while(temp->link != NULL)
            {
                temp = temp->link;
                qtemp->link = new Node(temp->data);
                qtemp = qtemp->link;
            }
            back = qtemp;
        }
}


template <class queuedata>
Queue<queuedata>::~Queue()
{
	Node* b = front;
	Node* a = NULL;       //a stands for "after" (i.e. after b)
	while(b != NULL)
	{
		a = b->link;     //move a to node after b
		delete b;        //remove b (you know it is not NULL from if)
		b = a;           //b "catches up" with a (both point to same place in list)
	}
}

/*************************************************************************/
/**Manipulators*/
template <class queuedata>
void Queue<queuedata>::enqueue(queuedata data)
{
	Node* N = new Node(data);
	if (size == 0) front = back = N;     // case 1: the list is currently empty
	else                                 // case 2: the list already had least one node
	{
		back->link = N;
		back = N;
	}
	size++;
}

template <class queuedata>
void Queue<queuedata>::dequeue()
{
	assert(!empty());           // enforce precondition
	if (size == 1)
	{
		delete front;
		front = back = NULL;
	}
	else
	{
		Node*temp = front;
		front = front->link;
		delete temp;
	}
	size--;                    // enforce postcondition
}

/*************************************************************************/
/**Accessors**/

template <class queuedata>
queuedata Queue<queuedata>::getFront() const
{
	assert(!empty());
	return front->data;
}

template <class queuedata>
int Queue<queuedata>::getSize() const
{
	return size;
}

template <class queuedata>
bool Queue<queuedata>::empty() const
{
	return size == 0;
}


template <class queuedata>
void Queue<queuedata>::print() const
{
	Node* temp = front;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}


template <class queuedata>
bool Queue<queuedata>::operator==(const Queue& queue)
{
	if (size != queue.size) return false;
	Node* temp1 = front;
	Node* temp2 = queue.front;
	while(temp1 != NULL)
	{
		if (temp1->data != temp2->data) return false;
		temp1 = temp1->link;
		temp2 = temp2->link;
	}
	return true; // after checking every node, if not return false yet, then return true
}
#endif /* QUEUE_H_ */
