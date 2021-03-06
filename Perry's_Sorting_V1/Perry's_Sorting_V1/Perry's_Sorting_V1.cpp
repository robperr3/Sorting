#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "DLL.h"

using namespace std;



int main()
{

	int choice;
	do {//menu allowing to chose which sorting method you would like to see

		cout << "\nWelcome to the Sorting Application. Please choose a valid option\n" << endl;
		cout << "1. Sort using Insertion Sort" << endl;
		cout << "2. Sort using Selection Sort" << endl;
		cout << "3. Quit" << endl;

		cin >> choice;

		DL_List<int> List1;//Linked List
		List1.Insert(7);//Inserting 20 nodes into the linked list
		List1.Insert(4);
		List1.Insert(5);
		List1.Insert(2);
		List1.Insert(9);
		List1.Insert(6);
		List1.Insert(21);
		List1.Insert(3);
		List1.Insert(1);
		List1.Insert(13);
		List1.Insert(8);
		List1.Insert(16);
		List1.Insert(25);
		List1.Insert(11);
		List1.Insert(14);
		List1.Insert(10);
		List1.Insert(19);
		List1.Insert(23);
		List1.Insert(17);
		List1.Insert(27);

		if (choice == 1) {// if 1 is chosen

			

			cout << "\nHere's our linked list in its origanl form, unsorted." << endl;
			List1.DisplayDLL();//display linked list as it currently is
			cout << "\nAnd here's the linked list sorted using insertion sort." << endl;
			//List1.InsertSort_DLL(List1);//calling insert sorting function on linked list
			List1.InsertSort_2();
			List1.DisplayDLL();//display new linked list
			
		}

		if (choice == 2)// if 2 is chosen
		{
			cout << "Here's our linked list in its original form, unsorted." << endl;
			List1.DisplayDLL();//display linked list as it currently is
			cout << "Now here's the linked list sorted using selection sort." << endl;
			List1.SelectSort(List1.top);//calling selection sorting function on linked list
			List1.DisplayDLL();//display new linked list
		}	


	} while (choice != 3);// do all this as long as user doesnt choose 3
	
	system("pause");
	return 0;
}
