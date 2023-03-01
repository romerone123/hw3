#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  if (head == NULL)
  {
    smaller = NULL;  //gets rid of rest of elements 
    larger = NULL;
    return;
  }
  
  if (head->val <= pivot) //smaller linked list
  {
		Node* temp = head;
		head = head->next;
    smaller = temp; 
    llpivot (head, smaller->next, larger, pivot);
  }

  else //larger linked list
  {
		Node* temp = head;
		head = head->next;
    larger = temp;
    llpivot (head, smaller, larger->next, pivot);
  }
}
