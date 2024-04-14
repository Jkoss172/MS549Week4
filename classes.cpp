#include <iostream>
#include "classes.h"

using namespace std;

Stack::Stack()
{
	head = NULL;
}

void Stack::display()
{
	node* curr = head;
	while (curr)
	{
		cout << "Node = " << curr->data << endl;
		curr = curr->next;
	}
}

void Stack::insert(int number)
{
	node* newNode = new node();
	newNode->data = number;
	if (head == NULL)
	{
		newNode->prev = NULL;
		newNode->next = head;
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	
}

void Stack::demoPrev()
{
	node* curr = head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	while (curr->prev != NULL)
	{
		cout << "Curr - PREV = " << curr->data << endl; // prints all but last value
		curr = curr->prev;
	}
	cout << "Curr - PREV = " << curr->data << endl; // need this to print out last value
}

void Stack::removeStack()
{
	if (head != NULL)
	{
		node* curr = head;
		cout << head->data << " removed in a stack" << endl;
		head = head->next;
		//head->prev = NULL;
	}
	else
	{
		cout << "empty list - did not remove" << endl;
	}
}

// Function to check whether Queue
// is empty or not
bool Queue::isEmpty() { return (front == NULL); }

// Function to return the number of
// elements in the deque
int Queue::size() { return Size; }

// Function to insert an element
// at the front end
void Queue::insertFront(int data)
{
    node* newNode = node::getnode(data);
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else {
        // If queue is empty
        if (front == NULL)
            rear = front = newNode;

        // Inserts node at the front end
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        // Increments count of elements by 1
        Size++;
    }
}

// Function to insert an element
// at the rear end
void Queue::insertRear(int data)
{
    node* newNode = node::getnode(data);
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else {
        // If deque is empty
        if (rear == NULL)
            front = rear = newNode;

        // Inserts node at the rear end
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        Size++;
    }
}

// Function to delete the element
// from the front end
void Queue::deleteFront()
{
    // If deque is empty then
    // 'Underflow' condition
    if (isEmpty())
        cout << "UnderFlow\n";

    // Deletes the node from the front end and makes
    // the adjustment in the links
    else {
        node* temp = front;
        front = front->next;

        // If only one element was present
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);

        // Decrements count of elements by 1
        Size--;
    }
}

// Function to delete the element
// from the rear end
void Queue::deleteRear()
{

    node* temp = rear;
    cout << rear->data << " removed in a queue" << endl;
    rear = rear->prev;
    

    // If only one element was present
    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;
    free(temp);
  
    

    // Decrements count of elements by 1
    //Size--;
}

      /*  if (rear != NULL)
        {
            node* curr = rear;
            rear = rear->prev;
            cout << rear->data << " removed in a queue" << endl;
            
          //  rear->prev = NULL;
        }
        else
        {
            cout << "empty list - did not remove" << endl;
        }

        // Decrements count of elements by 1
        Size--;
    */
//}

// Function to return the element
// at the front end
int Queue::getFront()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return front->data;
}

// Function to return the element
// at the rear end
int Queue::getRear()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return rear->data;
}

// Function to delete all the elements
// from Queue
void Queue::erase()
{
    rear = NULL;
    while (front != NULL) {
        node* temp = front;
        front = front->next;
        free(temp);
    }
    Size = 0;
}

void Queue::display()
{
    node* curr = front;
    while (curr)
    {
        cout << "Node = " << curr->data << endl;
        curr = curr->next;
    }
}
