#pragma once

class node
{
public:
	node* next;
	node* prev;
	int data;

	// Function to get a new node
	static node* getnode(int data)
	{
		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		newNode->prev = newNode->next = NULL;
		return newNode;
	}
};


class Stack
{
private:
	node* head;
	int length;

public:
	Stack();
	void insert(int data);
	void display();
	void demoPrev();
	void removeStack();
};

class Queue {
	node* front;
	node* rear;
	int Size;

public:
	Queue()
	{
		front = rear = NULL;
		Size = 0;
	}

	void insertFront(int data);
	void insertRear(int data);
	void deleteFront();
	void deleteRear();
	int getFront();
	int getRear();
	int size();
	bool isEmpty();
	void erase();
	void display();
};