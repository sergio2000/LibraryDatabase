// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// I use IFNDEF in case this file gets included more than once
// ---------------------------------------------------------

#ifndef A
#define A

#include <iostream>
#include <string>

using namespace std;

class el_t
{
 private:  // these will change depending
            // on the client needs
  long int key;      // ISBN (Last 9 Digits)  
  string title;      // book title
  string author;     // book author
  string genre;      // book genre
  double rating;     // book rating
  bool isSeries;     // is it a series?
  bool isAvailable;  // is it available?
  
 public:

  el_t();  // to create a blank el_t object
  el_t(long int, string, string, string, double, bool, bool); 
// to create an initialized el_t object - useful for the client

 // The following functions are available to
 // the htable class to be able to
 // use different el_t without modifying the code

  int getkey(); // only the key part can be accessed by the user of this class.
  void setkey(long int); // only the key part can be accessed by the user of this class.


  // In linked list search,
  //    == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?  
  bool operator==(el_t);  // overload == for search
  bool operator!=(el_t);  // overload != for search

  // This overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const el_t&);


};

#endif
  


