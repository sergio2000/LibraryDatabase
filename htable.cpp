// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: SERGIO ACOSTA
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{
}

htable::~htable()
{}

//PURPOSE: a simple hash function that uses % TSIZE simply
//PARAMETER: a key is passed to be hashed.
int htable::hash(long int key)
{
  int reversedNum = 0;
  int remainder = 0;
  while(key != 0) {
    remainder = key%10;
    reversedNum = reversedNum*10 + remainder;
    key /= 10;
  }
return reversedNum % TSIZE;
}


//PURPOSE: adds the element to the table and returns slot#
//PARAMETER: passes element to be added to table
int htable::add(el_t element)
{
   int slot = hash(element.getkey());  // hash with the key part
   B[slot].addRear(element);
   return slot;//** Note that this means adding the element to a slist in the slot (addRear)
}

//PURPOSE: finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
//PARAMETER: the skey passed represents the key being looked for.
el_t htable::find(long int skey)
{ 
   int slot = hash(skey); // hash with skey
   el_t selement(skey,"","","",0,false,false);  // this is the element to look for in slist
  //** initialize selement with just the skey
 //** call slist's search2 with selement which returns the found element 
  el_t found = B[slot].search2(selement); 
  return found; //** return the found element from here (it could be blank)
}

//PURPOSE: displays the entire table with slot#s too
void htable::displayTable()
{ 
  for (int i = 0; i < TSIZE; i++)
    { cout <<"Section: " << i;
      B[i].displayAll();// call slist's displayAll
    }
}

//PURPOSE: delete an element from the table.
//PARAMETER: element to be deleted is passed.
el_t htable::deleteIt(el_t element)
{
  int slot = hash(element.getkey());//hash key to find position of element
  el_t foundElem;
  int position = B[slot].search(element);//search for position of element
  B[slot].deleteIth(position,foundElem);//delete element at that position
  return foundElem; //return the deleted element
}

//PURPOSE: output all the data to a new file.
//PARAMETER: pass file that is to be written to.
void htable::saveTable(ostream& file)
{
  int count = 1;//initialize count at 1
  for(int z = 0; z < TSIZE; z++){
    el_t selement;// new element
    if(B[z].isEmpty()){//if list is empty
      //do nothing
    }else {
      while(!B[z].isEmpty()){//if list is not empty
	file  << count << " "; 
	B[z].deleteFront(selement);//delete all elements in list till empty
	file << selement;//output element deleted to file
    file << "\n";
    count++;   //increment count
      }
    }
  }//end of for-loop
}
