//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: SERGIO ACOSTA
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ //cout << "... in llist constructor..." << endl; 
  Front = NULL;//initialize Front & Rear to NULL.
  Rear = NULL;
  Count = 0;//initialize List Count at 0.
}

llist::~llist()
{ //cout << ".... in llist destructor..." << endl;
    el_t x;  
  while(!isEmpty()){ 
   deleteFront(x);
   //      cout << "Releasing " << x << "..." << endl; 
    }
  //cout << "====Destructor completed.====" << endl;
}

//PURPOSE:Checks if Front & Rear are NULL and Count is 0, returns true, otherwise false.
bool llist::isEmpty() {  // be sure to check all 3 data members
if(Front == NULL && Rear == NULL && Count == 0){
  return true;//If Linked List is completely empty return true.
 }else {
  return false;//otherwise return false.
 }
}

//PURPOSE: displayAll() calls isEmpty() and if true returns [Empty!],
//         otherwise, loops through list to display elements horizontally.
void llist::displayAll() {
  //  cout << "====Current List is======" <<endl;  
if(isEmpty()){
    cout << "[Empty!]" << endl;
  }else{
    Node *P = new Node;//temp pointer to find all elements in list.
    P = Front;
    cout << " Book Info:"<< endl; 
    cout << "\t   [";
    while(P !=NULL) {//Loop through list repeatedly and print each Element.
      cout << P->Elem;   
      P = P->Next;//Move to next element.
    }
    cout << "]" <<  endl;
}
// cout <<"=========================" << endl;
}

//PURPOSE:calls isEmpty() and if true create a new list & passes elem,
//        otherwise just pass new element to Rear and delete prev Rear.
//        Increment Count for both cases.
//PARAMETER:pass value in NewNum to be added to Rear node.
void llist::addRear(el_t NewNum) {  // comment the 2 cases
  if(isEmpty()){//special case: create new Node, update Rear & Front.
  Node *newNode = new Node;//temp pointer to create new Node element.
  newNode->Next = NULL;
  newNode->Elem = NewNum;
  Front = newNode;
  Rear = newNode;

  }else {//reg. case: update Rear
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
  }
  Count++;//for either case increment Count.
 }

//PURPOSE:If list isEmpty()start new list,and pass value of NewNum to both 
//        Front and Rear, otherwise just set value of NewNum to Front pointer and
//        adjust Next pointer to element that was previously front. 
//PARAMETER:pass value in NewNum to be added to Front node; 
void llist::addFront(el_t NewNum) {  // comment the 2 cases
  Node *Z = new Node;//temp pointer to create new Node element. 
  if(isEmpty()){//special case: create new node, update Front & Rear.
   Z->Elem = NewNum;
   Z->Next = Front;
   Front = Z;
   Rear = Z;
   
  }else{//regular case: update Front w/ NewNum.
    Z->Elem = NewNum;
    Z->Next = Front;
    Front = Z;
 }
  Count++;//either way update Count.
}

//PURPOSE:Checks if list isEmpty(), if so throw Underflow error,
//        otherwise if list is going to be empty pass Front element to OldNum
//        and set Front & Rear to Null, for regular cases just pass element to OldNum.
//        For all cases except the error case, increment Count.
//PARAMETER:OldNum recieves the value being deleted from the Front.
void llist::deleteFront(el_t& OldNum) {  // comment the 3 cases
  Node *Second = new Node;//temp pointer to find second element and assign Front. 
  if(isEmpty()) {//error case: nothing in list.
    throw Underflow();
  }else if (Count == 1){//special case: pass Front value to OldNum, delete, then update Front & Rear.
    OldNum = Front->Elem;
    delete Front;
    Front = NULL;
    Rear = NULL;
    Count--;
  }else {//regular case:pass Front value to OldNum, then delete.
    OldNum = Front->Elem;
    Second = Front->Next;
    delete Front;
    Front = Second;
    Count--;
  }
}

//PURPOSE:Checks if list isEmpty, outputs error if true. Otherwise if removing
//      will create an empty list, pass Rear node,delete, and set Front and Rear to NULL.
//      For all other cases pass Rear node, delete, update Rear pointer.
//PARAMETER:OldNum recieves value deleted from Rear.
void llist::deleteRear(el_t& OldNum){ // comment the 3 cases
  Node *secondLast = new Node;//temp pointer to find element before rear and update to new Rear.
  if(isEmpty()){//error case: nothing in list.
    throw Underflow();

  }else if(Count == 1){//special case: pass Rear value to OldNum, delete, then update Front & Rear. 
    OldNum = Rear->Elem;
    delete Rear;
    Front = NULL;
    Rear = NULL;
    Count--;
 
  }else {
    secondLast = Front;
    while(secondLast->Next != Rear){//find element before rear
      secondLast = secondLast->Next;
    }//regular case:pass Rear value to OldNum, then delete.
    OldNum = Rear->Elem;
    delete Rear;
    Rear = secondLast;
    Rear->Next = NULL;
    Count--;
  }
}
/* harder ones follow */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node
  for (int K = 1; K < J; K++) temp = temp->Next;
}

//PURPOSE: Checks if index is out of range, if so throws an out of range error. If item being deleted is first element, call deleteFront()
//         otherwise if it is the last element deleteRear() is called. For all regular cases, create 2 pointers to point to sides of element 
//         being deleted, delete middle element, and then connect both side pointers together.
//PARAMETER: The index of the element is given in I and OldNum recieves the value that was deleted.
void llist::deleteIth(int I, el_t& OldNum) {  // use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  
int x;
if (I > Count || I < 1) {
  throw OutOfRange(); 

 }else if (I == 1){ //special case: if first element is to be deleted call deleteFront
   deleteFront(OldNum);

 }else if(I == Count){//special case: if last element is to be deleted call deleteRear
   deleteRear(OldNum);

 }else {//regular case:
  //Node *newNode = new Node;
   //OldNum = newNode->Elem;
  Node *beforePtr = new Node;//new pointer to point to node before where element is to be deleted(Ith - 1).
   beforePtr = Front;
   Node *afterPtr = new Node;//new pointer to point to node after where element is to be deleted(Ith + 1).
   afterPtr = Front;

   moveTo(I + 1,afterPtr);//move current pointer to node at Ith + 1 position.
   moveTo(I - 1, beforePtr);//move trail pointer to node at Ith - 1 position.

   //deletes node and adjusts trail and current to link together.
   OldNum = beforePtr->Next->Elem;
   delete beforePtr->Next;
   beforePtr->Next = afterPtr;
   Count--;//decrement count
 }
}

//PURPOSE: Checks if index is out of range, if so throws an out of range error. If the index is equal to 1, addFront is called w/
//         newNum being passed as parameter. Otherwise if index is equal to Count + 1, call addRear and pass newNum as parameter.
//         For all regular cases, creates 3 pointers, one for element being added and two for side elements, then connects the side pointers
//         to the new element pointer.  
//PARAMETER: I passes the index of where the client wants the new element to be placed and newNum holds that element to be passed.
void llist::insertIth(int I, el_t newNum) {  // use moveTo to move local pointers. Be sure to comment to which node you are moving them.
//Node *newNode = new Node;
// newNode->Elem = newNum;
if (I  > Count + 1 || I < 1){//error case: throw OutOfRange exception.
  throw OutOfRange();
  
 }else if(I == 1){//special case: if it is first element being added, call addFront
    addFront(newNum);
 }else if(I == Count + 1){//special case: if element being added is next rear element, call addRear.
    addRear(newNum);
 }else{//Regular case
    Node *newNode  = new Node; //new pointer newNode holds value of element to be added(newNum).
    newNode->Elem = newNum;

    Node *beforePtr = new Node;//points to node before where element is to be added(Ith - 1).
    beforePtr = Front;

    Node *exactPtr = new Node;//points to node where element is to be added(Ith).
    exactPtr = Front;

    moveTo(I, exactPtr);//move current pointer to Ith node.
    moveTo(I-1,beforePtr);// move trail pointer to Ith - 1 node.

    //connect the pointers together.
    newNode->Next = exactPtr;
    beforePtr->Next = newNode;
    Count++;//increment count
 }
}

//PURPOSE:Loops through entire linked list to make a copy.
//PARAMETER:Passes original list by reference to be copied.
llist::llist(const llist& Original) { // use my code
//  this->'s data members need to be initialized here first
  Front = NULL; Rear = NULL; Count = 0;

//  this-> object has to be built up by allocating new cells
//  and copying the values from Original into each cell as we did with 
//  operator= above. To do this,
  Node* P;  // local pointer for Original
  P = Original.Front;
  while (P != NULL)  // a loop which repeats until you reach the end of Original. 
    {
      this->addRear(P->Elem);    //P’s element is added to this->
      P = P->Next;              // Go to the next node in Original  
    }//end of while 
}

//PURPOSE: Defines the = to make a copy of a linked list as a seperate list that doesn't share the same
//         cells as the other.
//PARAMETER: Linked list is passed by reference in OtherOne.
llist& llist::operator=(const llist& OtherOne) {    
    el_t x;
// First make sure this-> and OtherOne are not the same object.
// To do this, compare the pointers to the objects .
    if (&OtherOne != this)  // if not the same
      {
        // this-> object has to be emptied first.
        while(!this->isEmpty())
	  this->deleteRear(x);  
        // this-> object has to be built up by allocating new cells with OtherOne elements
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
	  {
	    this->addRear(P->Elem);    //P’s element is added to this->
	    P = P->Next;              // Go to the next node in OtherOne   
	  }// end of while 
      }// end of if              
    return *this;    // return the result unconditionally. Result is returned by reference.
 } // use my code
