//File QueueCLL.h
// CLASS PROVIDED: QueueCLL (queue)
//
// TYPEDEFS for the QueueCLL class:
//   typedef _____ value_type
//     QueueCLL::value_type is the data type of the items in
//     the QueueCLL. It may be any of the C++ built-in types
//     (int, char, etc.), or a class with a default constructor,
//     a copy constructor, and an assignment operator.
//
//   typedef _____ size_type
//     QueueCLL::size_type is the data type of choice for any
//     quantifier/identifier object whose value is by nature
//     and intent always non-negative (unsigned).
//
// VALUE SEMANTICS for the QueueCLL class:
//   Assignments and the copy constructor may be used with QueueCLL
//   objects.

#ifndef QUEUE_CLL_H
#define QUEUE_CLL_H

#include <cstdlib>  // provides size_t

class QueueCLL
{
   struct Node
   {
      typedef int value_type;
      value_type data;
      Node *link;
   };

public:
   //TYPEDEF
   typedef Node::value_type value_type;
   typedef size_t size_type;

   // CONSTRUCTORS and DESTRUCTOR
   QueueCLL();
   QueueCLL(const QueueCLL& src);
   ~QueueCLL();

   // MODIFICATION functions
   void push(const value_type& entry);
   value_type front() const;
   void pop();
   QueueCLL& operator=(const QueueCLL& rhs);

   // CONSTANT functions
   size_type size() const;
   bool empty() const;
   value_type peek(size_type n) const;

private:
   Node *rear_ptr;
   size_type numItems;
};

#endif
