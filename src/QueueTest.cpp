/*

 * QueueTest.cpp
 *
 *  Created on: Oct 13, 2017
 *      Author: Khang Vinh Tran, Tri Doan
 *      CIS 22C, Lab3




# include "Queue.h"


int main()
{
	cout << "This is QueueTest.cpp" << endl;
	cout << endl << "- Test default constructor by create an empty queue." << endl;
	Queue<int> Q1;
	cout << "Default constructor works" << endl;
	cout << "- Test empty() on the empty list. Should print out: 'Yes. The list is empty'" << endl;
	if (Q1.empty()) cout << "Yes. The list is empty" << endl;
	else cout << "No. The list is not empty" << endl;
	cout << "Test getSize(). Should get 0" << endl;
	cout << Q1.getSize() << endl;
	cout << "- Test print. Should get empty line" << endl;
	Q1.print();
	cout << "- Now, enque 1 2 3 4. Should print out: 'No. The list is not empty'" << endl;
	for (int i = 1; i <= 4; i++) Q1.enqueue(i);
	if (Q1.empty()) cout << "Yes. The list is empty" << endl;
	else cout << "No. The list is not empty" << endl;
	cout << "- Test getSize() again. Should get 4" << endl;
	cout << Q1.getSize() << endl;
	cout << "- Test print. Should get 1 2 3 4" << endl;
	Q1.print();
	cout <<"- Now, test dequeue 1 node. Then getSize(). Should get 3" << endl;
	Q1.dequeue();
	cout << Q1.getSize() << endl;
	cout << "- Test print. Should get 2 3 4" << endl;
	Q1.print();
	cout << "- Now, create 2 empty queues and test ==. Should print 'Equal'" << endl;
	Queue<int> Q2;
	Queue<int> Q3;
	if (Q2 == Q3) cout << "Equal" << endl;
	cout << "-Now, enqueue 2 3 4 to one of them and test ==. Should print 'Not equal'" << endl;
	for (int i = 2; i <= 4; i++) Q2.enqueue(i);
	if (!(Q2 == Q3)) cout << "Not Equal" << endl;
	cout << "- Now test == between the 2 queues with 2 3 4. Should print 'Equal'" << endl;
	if (Q1 == Q2) cout << "Equal" << endl;
	cout << "- Now, test copy constructor. Create Q4 as acopy of Q1. then print Q4. Should get 2 3 4 " << endl;
	Queue<int> Q4(Q1);
	Q4.print();
	return 0;
}



 This is QueueTest.cpp

- Test default constructor by create an empty queue.
Default constructor works
- Test empty() on the empty list. Should print out: 'Yes. The list is empty'
Yes. The list is empty
Test getSize(). Should get 0
0
- Test print. Should get empty line

- Now, enque 1 2 3 4. Should print out: 'No. The list is not empty'
No. The list is not empty
- Test getSize() again. Should get 4
4
- Test print. Should get 1 2 3 4
1 2 3 4
- Now, test dequeue 1 node. Then getSize(). Should get 3
3
- Test print. Should get 2 3 4
2 3 4
- Now, create 2 empty queues and test ==. Should print 'Equal'
Equal
-Now, enqueue 2 3 4 to one of them and test ==. Should print 'Not equal'
Not Equal
- Now test == between the 2 queues with 2 3 4. Should print 'Equal'
Equal
- Now, test copy constructor. Create Q4 as acopy of Q1. then print Q4. Should get 2 3 4
2 3 4



*/
