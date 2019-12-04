// FILE: QueueCLL.cpp
// Name: Bailey Cheung
// IMPLEMENTS: QueueCLL 
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
//Summary: Copy Constructor - initilizes invoking using src
//Pre-Conditions: (none)
//Post-Conditions: The QueueCLL has been initialized to the src queue
//Parameter(s): src - address of object to be copied from
//Returns: (none)
QueueCLL::QueueCLL(const QueueCLL& src) : numItems(src.numItems)
{
   Node* temp = src.rear_ptr; //temp pointer to source queue
   Node* new_rear_ptr = new Node; //new node for new queue rear_ptr
   rear_ptr = new_rear_ptr; 
   for(size_type i = 0; i < numItems; i++)
   {
      //copies queue from source to invoking object queue
      new_rear_ptr->data = temp->data;
      new_rear_ptr->link = new Node;  
      new_rear_ptr = new_rear_ptr->link;   
      temp = temp->link; 
   }
}

//...................................................................
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

//...................................................................
//Name: QueueCLL& operator=(const QueueCLL& rhs)
//Summary: overloaded assignment operator 
//Pre-Conditions: (none)
//Post-Conditions:(none)
//Parameter(s): rhs - address of object to be copied from 
//Returns: address of newly copied object from rhs object 
QueueCLL& QueueCLL::operator=(const QueueCLL& rhs)
{
   if(this != &rhs)
   {
      Node *temp = rhs.rear_ptr; //temp gets rhs rear_ptr
      Node *new_rear_ptr = new Node; //new pointer to new circuluar linked list 
      rear_ptr = new_rear_ptr; //invoking object rear_ptr gets new_rear_ptr
      for(size_type i = 0; i < rhs.numItems; i++) //iterates through rhs queue
      {
         //copies data from rhs to invoking object queue
         new_rear_ptr->data = temp->data;
         new_rear_ptr->link = new Node; 
         new_rear_ptr = new_rear_ptr->link;   
         temp = temp->link; 
      }
      this->numItems = rhs.numItems; 
   }
   return *this; //returns invoking object 
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
      rear_ptr = new Node; //create new node for rear_ptr 
      rear_ptr->data = entry; //fill in data of rear_ptr
      rear_ptr->link = rear_ptr; //point rear to itself 
      numItems++; //increment numItems
   }
   else if(numItems == 1) //if queue has only one item 
   {
      Node* newNode = new Node; //creates new node for new item added 
      newNode->data = entry; //fill in data of new node
      rear_ptr->link = newNode; //point rear_ptr to the new node
      newNode->link = rear_ptr; //point the new node to the rear_ptr
      rear_ptr = newNode; //put new node at the end of the queue 
      numItems++; //increment numItems
   }
   else //if queue has more than one item 
   {
      Node *temp = rear_ptr->link; //points to the front of the queue
      Node *newNode = new Node; //creates new node for new item added 
      newNode->data = entry; //fill in data of new node
      newNode->link = temp; //point link to front of the queue 
      rear_ptr->link = newNode; //put entry after rear_ptr
      rear_ptr = newNode; //rear_ptr is to the new entry 
      numItems++; //increment numItems
   }
}

//...................................................................
//Name: value_type QueueCLL::front( ) const
//Summary: constant member function - returns the front of the data
//    held by the first queue item 
//Pre-Conditions: size() > 0
//Post-Conditions: The return value is the data of the front item of
//    the queue, but the queue is unchanged.
//Parameter(s): (none)
//Returns: data value of front item 
QueueCLL::value_type QueueCLL::front( ) const
{
   assert(size() > 0); //fulfill precondition 
   if(size() == 1)
   {
      return rear_ptr->data;
   } 
   else 
   {
      Node* front = rear_ptr->link; 
      return front->data; 
   }
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
   assert(size() > 0); //fulfill precondition 
   if(size() == 1) //only one item in the queue 
   {
      rear_ptr->link = rear_ptr; //set rear_ptr to itself 
      rear_ptr = 0; //set rear_ptr to null value 
   }
   else //more than one item in the queue 
   {
      Node *newFrontTemp = rear_ptr->link->link; //pointer to the new front 
      rear_ptr->link = newFrontTemp; //point rear of queue to the new front
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
//Summary: constant member function - determines if the queue is empty 
//Pre-Conditions: (none)
//Post-Conditions: The return value is true if the queue is empty,
//    otherwise false.
//Parameter(s): (none)
//Returns: true if list is empty, else false
bool QueueCLL::empty() const
{
   if(size() == 0) //if size of queue is 0 
      return true; 
   else //if size of queue is not 0 
      return false; 
}

//...................................................................
//Name: value_type peek(size_type n) const
//Summary: constant member function - peeks at data at n-th item 
//Pre-Conditions: size() > 0.
//Post-Conditions:The return value is the data of the n-th item
//    (front item is 1st item) of the queue, with
//    circular wraparound.
//Parameter(s): the queue item (n) the user wishes to view 
//Returns: data value at the specified queue item 
QueueCLL::value_type QueueCLL::peek(size_type n) const
{
   assert(size() > 0); //fulfill precondition 
   Node* peekTemp = rear_ptr->link; //assign temp pointer to front of queue
   while(n > 0) //while n-th item has not been reached 
   {
      peekTemp = peekTemp->link; //move onto the next item 
      n--; //decrement n
   }
   return peekTemp->data; //data at n-th item 
}
