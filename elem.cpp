// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  key = -1;  // initialize each piece of data
  title = "";
  author = "";
  genre = "";
  rating = 0;
  isSeries = false;
  isAvailable = false;

}

// initializing constructor to create an el_t object 
el_t::el_t(long int akey, string bookName, string bookAuthor, string bookGenre, double bookRating, bool series, bool available)
{
  key = akey;
  title = bookName;
  author = bookAuthor;
  genre = bookGenre;
  rating = bookRating;
  isSeries = series;
  isAvailable = available;
}

// ONLY the key part should be available to the user of this class
int el_t::getkey()
{
  return key;
}

// ONLY the key part should be available to the user of this class 
void el_t::setkey(long int akey)
{
  key = akey;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

bool el_t::operator!=(el_t OtherOne)
{
  if (key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  //return output to look same as file input
  os << E.key << "," << E.title << "," << E.author << "," << E.genre << "," << E.rating << " ";
  
  if(E.isSeries == true){
    os  << "true";
  }else {
    os << "false";
  }
  os << ",";
   if(E.isAvailable == true){
    os << "true";
  }else {
    os <<"false";
  }
   os <<",";
 return os;  
}  
