// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: SERGIO ACOSTA
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them
// do not change this one
slist::slist()
{ //cout << "slist constructor:" << endl;
}

int slist::search(el_t key){
  //positions always start at 1
  int index = 1;

  Node *P = Front;//create pointer P to point to element being searched for.
  //start at the front of list.
  while(P != NULL){
    if(P->Elem == key){
      return index;//if they match return position where element was found.
    }
    index++;//increment index each time element not found in list
    P = P->Next;//go to next element in list
  }
  return 0;//if key is not found at all return 0;
}

// don't forget to throw OutOfRange for bad pos 
void slist::replace(el_t element, int pos){
  if(pos > Count || pos < 1){//error case: out of range
    throw OutOfRange();  
  }else {
    Node *R = Front;//new pointer R used to point to element being replaced
    moveTo(pos, R);//move R pointer to Ith position in linked list
    R->Elem = element;//set R Elem to one passed by client
  }
}
bool slist::operator==(const slist& OtherOne){
  // if not the same length, return false
  if (OtherOne.Count != this->Count){//if size of lists do not match return false.
    return false;
  } else {//If both linked lists are same lengths.
    Node *P = OtherOne.Front;//Pointer P loops through all elements in OtherOne.
    Node *S = this->Front;//Pointer S loops through all elements of this.

    //check each node to see if the elements are the same.
    while (P != NULL && S != NULL){//loop through to the end of both lists.
      if(P->Elem != S->Elem){//if any elements are mismatches return false.
	return false;
      }
      P = P->Next;//have P point to next node.
      S = S->Next;//have S point to next node.
    }
    return true;//If loop completes successfully, return true.
  }
}

el_t slist:: search2(el_t X)
{ el_t M; // blank
  //X has only the ID part set.
  int index = 1;
  Node *P = Front;//create pointer P to point to element being searched for.
  //start at the front of list.
  while(P != NULL){
    if(P->Elem == X){
      return P->Elem;//if they match return el_t object.
    }
    index++;//increment index each time element not found in list
    P = P->Next;//go to next element in list
  }
  return M;//if key is not found return blank object M
}    
  
