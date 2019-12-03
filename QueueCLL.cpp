// FILE: QueueCLL.cpp
// IMPLEMENTS: QueueCLL (see QueueCLL.h for documentation.)
//
// INVARIANT for the QueueCLL class:
//   1. The number of items in the QueueCLL is stored in the member
//      variable numItems.
//   2. The items themselves are stored in a circular linked list
//      of Nodes.
//      2.1 The member variable rear_ptr points to the rear of the
//          QueueCLL (tail node of the circular linked list).
//          heap[0] through heap[used - 1].
//      2.2 The rear_ptr is set to the null address if the circular
//          linked list (thus queue) is empty.

#include <iostream>
#include <cassert>  // provides assert
#include <cstdlib>  // provides size_t
using namespace std;

#include "QueueCLL.h"   

//...................................................................
//Name: QueueCLL()
//Summary: Default constructor - intializes invoking object and 
//    relevent parameters 
//Pre-Conditions: (none)
//Post-Conditions:The QueueCLL has been initialized to an empty queue
//Parameter(s): (none)   
//Returns: (none)
QueueCLL::QueueCLL() : rear_ptr(0), numItems(0) {}

//...................................................................
//Name: QueueCLL(const QueueCLL& src)
//Summary: copy constructor 
//Pre-Conditions: (none)
//Post-Conditions: The QueueCLL has been initialized to the src queue
//Parameter(s): 
//Returns: (none)
QueueCLL::QueueCLL(const QueueCLL& src) : numItems(src.numItems)
{
   rear_ptr = src.rear_ptr; 
}

//working 
//Name: ~QueueCLL()
//Summary: destructor 
//Pre-Conditions: (none)
//Post-Conditions:(none)
//Parameter(s): (none)
//Returns: (none)
QueueCLL::~QueueCLL()
{
   delete rear_ptr; 
}

//working 
//Name: QueueCLL& operator=(const QueueCLL& rhs)
//Summary: overloaded assignment operator 
//Pre-Conditions: (none)
//Post-Conditions:(none)
//Parameter(s): 
//Returns: 
QueueCLL& QueueCLL::operator=(const QueueCLL& rhs)
{
   if(this != &rhs)
   {
      Node *new_rear_ptr = new ; 

   }
   return *this;
}

//...................................................................
//Name: void push(const value_type& entry)
//Summary: Modification member function that pushes a new entry onto 
//    the end of the queue 
//Pre-Conditions: (none)
//Post-Conditions: A new copy of item with the specified data has been
//    added to the rear of the queue.
//Parameter(s): entry - the data to be added into the queue 
//Returns: (none)
void QueueCLL::push(const value_type& entry)
{
   if(empty()) //if queue is empty 
   {
      rear_ptr->data = entry; //give data entry
      rear_ptr->link = rear_ptr; //point rear to itself 
   }
   else //if queue is not empty, add to the rear 
   {
      Node *temp = 0; //prevent dangling pointer 

      temp->data = entry; //add entry to temp 
      temp->link = rear_ptr->link; //link front of the queue to temp

      rear_ptr->link = temp; //put entry at end of queue
      rear_ptr = temp; //new rear is new entry 
   }
   numItems++; //increment numItems
}

//...................................................................
//Name: value_type QueueCLL::front( ) const
//Summary: constant member function - returns the front of the data
//    held by the first queue item 
//Pre-Conditions: size() > 0
//Post-Conditions: The return value is the data of the front item of
//    the queue, but the queue is unchanged.
//Parameter(s): (none)
//Returns: (none)
QueueCLL::value_type QueueCLL::front( ) const
{
   assert(size() > 0); 
   Node *front = rear_ptr->link; //temp pointer to front of queue 
   return front->data; 
}

//...................................................................
//Name: void pop( )
//Summary: Pops off the first item in the queue 
//Pre-Conditions: size() > 0.
//Post-Conditions:The front item has been removed from the queue.
//Parameter(s): (none)
//Returns: (none)
void QueueCLL::pop( )
{
   assert(size() > 0); //meet precondition 
   if(size() == 1) //only one item in the queue 
   {
      rear_ptr->link = 0; //no dangling pointer
      rear_ptr = 0; //set rear_ptr to null value 
   }
   else 
   {
      Node *newFrontTemp = rear_ptr->link->link; //pointer to the new
                                                 //front of the queue
      rear_ptr->link = newFrontTemp; //point rear of queue to the new
                                     //front 
   }
   numItems--; //decrement numItems 
}

//...................................................................
//Name: size_type size() const
//Summary: constant member function - returns the size of the queue 
//Pre-Conditions: (none)
//Post-Conditions: The return value is the total number of items in the
//    queue.
//Parameter(s): (none)
//Returns: number of items in the queue
QueueCLL::size_type QueueCLL::size() const
{
   return numItems; 
}

//...................................................................
//Name: bool empty() const
//Summary: constant member function - determines if the heap is empty 
//Pre-Conditions: (none)
//Post-Conditions: The return value is true if the queue is empty,
//    otherwise false.
//Parameter(s): (none)
//Returns: true if list is empty, else false
bool QueueCLL::empty() const
{
   if(rear_ptr == 0)
      return true; 
   return false; 
}

//...................................................................
//Name: value_type peek(size_type n) const
//Summary: constant member function - 
//Pre-Conditions: size() > 0.
//Post-Conditions:The return value is the data of the n-th item
//    (front item is 1st item) of the queue, with
//    circular wraparound.
//Parameter(s): (none) 
//Returns: 
QueueCLL::value_type QueueCLL::peek(size_type n) const
{
   assert(size() > 0); 
   int i = n; 
   Node* peekTemp = rear_ptr->link; 
   while(i > 0)
   {
      peekTemp = peekTemp->link; 
      i--;  
   }
   return peekTemp->data; 
}

