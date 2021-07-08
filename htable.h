// CS311 Yoshii - Hash Table header DO NOT CHANGE!!! 
// ------------------------------------------------

#include "slist.h"
#include <fstream>
const int TSIZE = 29;  // 29 slots ; a prime number 


class htable
{
 private:
 // each node of slist is el_t 
 slist B[TSIZE];
                           // as defined in elem.h
 int hash(long int);  // private hash function

 public:
 htable();//constructor
 ~htable();//destructor

  int add(el_t);  // adds an element to the table and returns slot#
  el_t find(long int); // finds an element based on key and returns it
  void displayTable(); // displays the table with slot#s
  el_t deleteIt(el_t);//delete an item and return it 
  void saveTable(ostream&); //function to write elements to table
};
