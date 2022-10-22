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
    smaller = head; 
    return llpivot (head->next, smaller->next, larger, pivot);
  }

  if (head->val > pivot) //larger linked list
  {
    larger = head;
    return llpivot (head->next, smaller, larger->next, pivot);
  }
}
