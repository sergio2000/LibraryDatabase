//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: SERGIO ACOSTA
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================
#include "elem.h"
// alias el_t : element type definition
//char el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:          // change to protected to get access in slist.h but not client.
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE:Checks if Front & Rear are NULL and Count is 0, returns true, otherwise false.
  bool isEmpty();
    
  //PURPOSE: displayAll() calls isEmpty() and if true returns [Empty!],
  //         otherwise, loops through list to display elements horizontally.
  void displayAll();

  //PURPOSE:If list isEmpty()start new list,and pass value of NewNum to both
  //        Front and Rear, otherwise just set value of NewNum to Front pointer and
  //        adjust Next pointer to element that was previously front.
  //PARAMETER:pass value in NewNum to be added to Front node; 
  void addFront(el_t);
    
  //PURPOSE:calls isEmpty() and if true create a new list & passes elem,
  //        otherwise just pass new element to Rear and delete prev Rear.
  //        Increment Count for both cases.
  //PARAMETER:pass value in NewNum to be added to Rear node.
  void addRear(el_t);

  //PURPOSE:Checks if list isEmpty(), if so throw Underflow error,
  //        otherwise if list is going to be empty pass Front element to OldNum
  //        and set Front & Rear to Null, for regular cases just pass element to OldNum.
  //        For all cases except the error case, increment Count.
  //PARAMETER:OldNum recieves the value being deleted from the Front.
   void deleteFront(el_t&);
    
  //PURPOSE:Checks if list isEmpty, outputs error if true. Otherwise if removing
  //      will create an empty list, pass Rear node,delete, and set Front and Rear to NULL.
  //      For all other cases pass Rear node, delete, update Rear pointer.
  //PARAMETER:OldNum recieves value deleted from Rear.
  void deleteRear(el_t&);
    

  //PURPOSE: Checks if index is out of range, if so throws an out of range error. If item being deleted is first element, call deleteFront()
  //         otherwise if it is the last element deleteRear() is called. For all regular cases, create 2 pointers to point to sides of element
  //         being deleted, delete middle element, and then connect both side pointers together.
  //PARAMETER: The index of the element is given in I and OldNum recieves the value that was deleted.
    void deleteIth(int, el_t&);  // calls moveTo

  //PURPOSE: Checks if index is out of range, if so throws an out of range error. If the index is equal to 1, addFront is called w/
  //         newNum being passed as parameter. Otherwise if index is equal to Count + 1, call addRear and pass newNum as parameter.
  //         For all regular cases, creates 3 pointers, one for element being added and two for side elements, then connects the side pointers
  //         to the new element pointer.
  //PARAMETER: I passes the index of where the client wants the new element to be placed wNum holds that element to be passed.
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
