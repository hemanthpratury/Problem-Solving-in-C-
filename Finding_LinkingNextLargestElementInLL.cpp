Given an unsorted lined list of integers, implement an O(n) algorithm to create a link from each element to the next largest element in the list. Assume the elements in the list have two pointers, next to implement the linked list and next_largest to point to the largest element. Note that if an element value  is followed by two values element + 3 and then element + 5, the next largest pointer should point to the second  element.
Solution:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Author: Sai Siva Hemanth Pratury
Class ID: 010817833
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

struct Node

{

    int data;

    Node* next, *start;

};

//Performing the reverse operation on the list
Node* reverse(Node *crown)

{

    Node *previous = NULL, *present = crown, *next;

		while (present != NULL)

		{

			next = present->next;

			present->next = previous;

			previous = present;

			present = next;

		}

    return previous;

}

//Populating the list     
Node* Fill_List(Node *crown)

{
    crown = reverse(crown);

    Node *max = crown;

    Node *temp = crown->next;

		while (temp != NULL)

		{

			temp->start = max;

			if (max->data < temp->data){

				max = temp;
			}

			temp = temp->next;

		}

    return reverse(crown);

}

//Printing the next pointer and next highest pointer
void printNext_Pointers(Node *node)

{

    printf("Node\tNext Pointer\tNext_largest Pointer\n");

    while (node!=NULL)

    {
        cout << node->data << "\t\t";
     
        if (node->next){

            cout << node->next->data << "\t\t";
		}

        else 
		{
			cout << "NULL" << "\t\t";
		}

        if (node->start){

            cout << node->start->data;
		}
        else{
				cout << "NULL";
			
		}
        cout << endl;

        node = node->next;

    }

}

//Creating new nodes depending on the inputs
Node *newNode(int data)

{

    Node *new_node = new Node;

    new_node->data = data;

    new_node->next = NULL;

    return new_node;

}



int main()

{
//creating a list of numbers 7,1,2,15,10,14
    Node *crown = newNode(7);

 crown->next = newNode(1);

crown->next->next = newNode(2);

crown->next->next->next = newNode(15);
	
crown->next->next->next->next = newNode(10);
	
crown->next->next->next->next->next = newNode(14);

    
//Populating the list     
    crown = Fill_List(crown);

    
//Printing the next pointer and next highest pointers 
    printNext_Pointers(crown);

  
    return 0;

}
