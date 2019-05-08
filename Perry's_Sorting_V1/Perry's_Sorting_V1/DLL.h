#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <type_traits>

using namespace std;

template <typename generic_type>  //creating a template of generic data type
class Node// my class for nodes
{
public:
	Node* next;  // pointer for next node
	Node* prev; // pointer for previous node
	generic_type data; // variable for class

	Node()
	{
		data = NULL; //nullifying the variable data;
		next = nullptr;//nullifying the pointer
		prev = nullptr;
	}

	Node(generic_type init_D)
	{// passing the class constructor w/ all its data members
		data = init_D; //initializing data members
		next = nullptr;//nullifying the pointer
		prev = nullptr;
	}

	Node(generic_type init_D, Node* init_N, Node* init_PV)
	{
		data = init_D;
		next = init_N; //initializing next pointer
		prev = init_PV;//initializing previous pointer
	}

	


};

template <typename generic_type>
class DL_List // creating the doubly-linked list class
{

public:
	DL_List<generic_type>*L1;// linked list pointer;
	Node<generic_type>* top;// creating the head & tail pointer
	Node<generic_type>* bottom;

	DL_List()// creating the linked list default constructor (w/ empty head & tail )
	{
		top = 0;
		bottom = 0;
	}

	DL_List(DL_List* init_T, DL_List* init_B)// linked list constructor w/ data passed in
	{
		top = init_T; // initializing next pointer
		bottom = init_B;// initializing previous pointer
	}

	void Insert(generic_type init_D)// creates node object using node data passed in & puts it on top of list
	{
		Node<generic_type>*N1 = new Node<generic_type>(init_D);//automatically creating new node & pointer 

		if (bottom == nullptr)// if linked list is empty
		{
			top = N1;//point head pointer to new node
			bottom = N1;//since its the only node, its also the tail 
			N1->next = 0;//its next & previous pointers are null since its by itself
			N1->prev = 0;
		}
		else// if linked list does in fact contain a node
		{
			N1->prev = top;// adds new node to list and link it and head pointer to each other
			top->next = N1;
			top = N1;// point head pointer to new node
		}
	}

	Node<generic_type>* Find(generic_type init_D)// takes in data to compare to nodes in the list
	{
		if (top == NULL)// if list is empty print message saying so
		{
			cout << "This list is empty!" << endl;
		}

		if (top->data = init_D)// if data of head node matches data being passing in 
		{
			cout << "Here's your Node " << top->data << endl;// tell user this
			return top;	//and return head node
		}
		// for as long as the next node is NOT null
		while (top->next != NULL) {
			if (top->next->data = init_D)//if data for the next node matches data being passed 
			{
				return top->next;
			}//return pointer of that node

			else // otherwise if data doesn't match datt of any nodes, then node isn't here
			{
				cout << "Sorry, it's not here!!!" << endl;
			}
		}

	}



	void Delete(Node<generic_type>*delN)// delelte function removes node in list with pointer passed in
	{
		if (bottom == NULL)// if list is empty, tell user this
		{
			cout << "\nThis list is empty!." << endl;
		}
		else
		{
			if (delN == top && delN == bottom)// if the node's is the only node in the list
			{
				top = NULL;// turn both head & tail pointers into null, emptying the list
				bottom = NULL;
			}
			else if (delN == top)// if head node is node you want to delete
			{
				top = top->prev;// make pointer of head now point to tail
				top->next = NULL;// old pointer of heads next node is now tail 
			}
			else if (delN == bottom)// if node you want deleted is the tail node
			{
				bottom = bottom->next;// tail is now pushed to head position (next of tail)
				bottom->prev = NULL;
			}
			else
			{// otherwise move next pointer of the node before node you want deleted to the node after target node
				delN->prev->next = delN->next;
				delN->next->prev = delN->prev;// and move pointer of target node from the next node to node before target node
			}
			delete delN;//then delete the target node
		}
	}

	void DisplayDLL()// prints out data of all nodes within linked list
	{
		Node<generic_type>* temp;// make pionter for current node
		temp = bottom;// current pointer now points to tail
		if (temp == nullptr) { cout << "\nThis Linked List is empty!" << endl; }// if tail  is null list is empty
		else
		{// other wise as long as currrent node pointer isnt null
			while (temp != nullptr)
			{//print out the data of the current node
				cout << "\nNode: " << temp->data << endl;
				temp = temp->next;// the current node is now the next node
			}//it will keep moving through the list of nodes until current node is null
		}
	}

	
	void InsertSort_DLL(DL_List<generic_type>& List1)// insert sort function
	{
			Node<generic_type>* current;// Nodes to represent current node & iterate through linked list
			Node<generic_type>* i;
			current =List1.top;
			if (current = NULL)// if current node (top) is null then do nothing
			{
				return;
			}

			for (i = current->next; i != nullptr; i = i->next)// as long as the next node exists, iterate through the list 
			{
		
				Node<generic_type>*j = i;
				while (j != nullptr && j->data < j->prev->data)// while next node exists & it's data is smaller than the node before it
				{
					int temp = j->data;//swap the data of both nodes
					j->data = j->prev->data;
					j->prev->data= temp;
					j--;
				}
				j = j->next;//the next node is now the node after it
			}
		
	}
	void New_display()
	{
		Node<generic_type>* temp;// make pionter for current node
		temp = top;// current pointer now points to head
		if (temp == nullptr) { cout << "\nThis Linked List is empty!" << endl; }// if temp  is null list is empty
		else
		{// other wise as long as currrent node pointer isnt null
			while (temp != nullptr)
			{//print out the data of the current node
				cout << "\nNode: " << temp->data << endl;
				temp = temp->prev;// the current node is now the next node
			}//it will keep moving through the list of nodes until current node is null
		}
	}

	void SelectSort(Node<generic_type>* top)//selection sort function
	{
		Node<generic_type>* t = top;//a node pointing to the list's head node
		Node<generic_type>* j;//Node created for nested iteration
		Node<generic_type>* i;//Node created for iteration
		Node<generic_type>* mini;//Node representing smallest element
		

		for (i = top; i != NULL && i->next != NULL; i = i->next)//as long as i (head) & its next node exist, iterate through list 
		{
			mini =i;//and make smallest element the head

			for (j = i->next; j != NULL; j = j->next)//as long as i's next node exists, iterate through list
			{
				if (j->data < mini->data)// and if the node's (mini) data is bigger than the next node's data
				{
					mini = j;// then make that next node the new mini
				}
			}

			if (mini != i)// and if mini isnt the smallest node 
			{
				int temp;//swap the data of both nodes
				temp = mini->data;
				mini->data = i->data;
				i->data = temp;
			}
		}
		top = t;
	}

	void InsertSort_2()
	{
		if (top != NULL)
		{
			return;
		}
		else
		{
			Node<generic_type>* index = top;


			while (index != NULL)//search how to iterate using while loops
			{

				Node<generic_type>*j = index->next;
				while (j != nullptr && j->data < j->prev->data)
				{
					int temp = j->data;
					j->data = j->prev->data;
					j->prev->data = temp;
					j--;
				}
				index = index->next;
			}
		}
	}
};

