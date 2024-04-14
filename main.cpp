#include <iostream>
#include "classes.h"
#include <cstdlib>
#include <chrono>
#include <ctime>

using namespace std;

int main()
{
    // Start Stack Program
   clock_t start, end;
	Stack MyStack;
	start = clock();
	for (int i = 0; i < 1000; i++)
	{
		MyStack.insert(rand() % 1000);
	}
	end = clock();

	MyStack.display();
	cout << "Time it took: " << end - start << endl;

    clock_t start1, end1;
	start1 = clock();
	for (int i = 0; i < 1000; i++)
	{
		MyStack.removeStack();
	}
	end1 = clock();
	MyStack.display();
    cout << "Time it took: " << end1 - start1 << endl;
    // End Stack Program

	// Start Queue Program
     Queue myQue;
	
	clock_t start2, end2;
	start2 = clock();
	for (int i = 0; i < 1000; i++)
	{
		myQue.insertFront(rand() % 1000);
	}
	end2 = clock();
	myQue.display();
	cout << "Time it took: " << end2 - start2 << endl;

	clock_t start3, end3;
	start3 = clock();
	for (int i = 0; i < 1000; i++)
	{
		myQue.deleteRear();
	}
	end3 = clock();
	myQue.display();
	cout << "Time it took: " << end3 - start3 << endl;

	return 0;

}