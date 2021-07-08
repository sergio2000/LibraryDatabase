// CS311 Project Client using a generic hash table
// Loading the data file has to happen here because
// generic htable should not know about the file
// format.
//
// Change everywhere it says **
// Must write / change @@ functions in htable.
// ** Must improve the user interface!
#include <limits>
#include "htable.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream> // to convert ISBN from string to long int
using namespace std;

//======================================================
// HW#: Final Project
// Name: SERGIO ACOSTA
// File Type: implementation file projclient1.cpp
// PURPOSE: be able to input, delete, save data to/from a
//          a data file through hashing.
//========================================================

int main()
{
  htable T;  // generic hash table

  
  // declare all of the data to be retrieved by file
  int inList;
  string isbn;
  long int key;//isbn number     
  string title;
  string author;
  string genre;
  double rating;
  //both isSeries and isAvailable start off as strings and then transformed into bools
  string series;
  string available;
  bool isSeries;
  bool isAvailable;

  el_t E;     // blank element

  // File info declared outside switch
  // Only the client should know about file names
  string fname;
  cout << "What is the input file? (.txt)";
  cin >> fname;

  ifstream fin (fname.c_str(), ios::in);
  //  T.fillTable(fin);
  ofstream fout ("newout.txt", ios::out);

  int ans = 0;
  while (ans != 7)
    {
      // *** change menu items to be descriptive
      cout << "MENU------------------ :"<<endl;
      cout << "1. Enter a file of books to Database" << endl;
      cout << "2. Display all Books and Location(section)" << endl;
      cout << "3. Search for Book" << endl;
      cout << "4. Add a new Book" << endl;
      cout << "5. Delete a Book" << endl;
      cout << "6. Save all books to a file" << endl;
      cout << "7. Exit" << endl;
      cout << "==>";
      cin >> ans;

      switch (ans)
	{
	  
	case 1:
          // LOADING
	  while(fin >> inList)//grab all vertex names from file
		{
		  getline(fin, isbn, ',');
		  stringstream convert(isbn);
		  convert >> key;
		  getline(fin, title, ',');
		  getline(fin, author, ',');
		  getline(fin, genre, ',');
		  fin >> rating;
		  getline(fin, series, ',');
		  getline(fin, available, ',');
		  
		  if(series == "true"){
		    isSeries = true;
		  }else {
		    isSeries = false;
		  }
		  
		  if(available == "true"){
		    isAvailable = true;
		  }else {
		    isAvailable = false;
		  }
		  
		  T.add(el_t(key, title, author, genre, rating, isSeries, isAvailable));
	    } 
	  cout << "loaded data..." << endl; 
	  break;
	  
	case 2:
          // DISPLAYING
	  T.displayTable(); 
          break;
	  
	case 3: 
          // SEARCHING
	  cout << "Enter key to look for: ";
	  cin >> key; 
	  E = T.find(key);
	  if (E == el_t()) /// was blank
	    { cout << "Book does not match any in our database" << endl;}
          else {cout << "Book was found!" << E << endl;}
	  break;
	  
	case 4:
          // ADDING
	  //	  cout << "Enter the Book's ISBN Number(last 9 Digits): "; cin >> key;
	  cout << "Book title: "; getline(cin, title);
	  cin.ignore();
	  cout << "Enter author: "; getline(cin, author);
	  cin.ignore();
	  cout << "Enter genre: "; getline(cin, genre);
	  cin.ignore(1000,'\n');
	  cout << "Enter the Book's ISBN Number(last 9 Digits): "; cin >> key;
	  cin.ignore();
	  cout << "Is this book a series?: "; cin >> series;
	  
	  cin.ignore();
	  cout << "Is this book available?: "; cin >> available;
	  cin.ignore();
          cout << "Enter rating: "; cin >> rating;

	  if(series == "true"){
	    isSeries = true;
	  }else {
	    isSeries = false;
	  }

	  if(available == "true"){
	    isAvailable = true;
	  }else {
	    isAvailable = false;
	  }

 	  cout << "In Slot: " << T.add(el_t(key, title, author, genre, rating, isSeries, isAvailable));
          cout << "  added." << endl;
	  break;
	  
	case 5:
          // DELETING 
          cout << "Enter the last 9 digits of ISBN#: "; cin >> key;
	  E = T.find(key);
          if (E == el_t()) /// was blank
            { cout << "Book does not match any in our database" << endl;}
          else {
          cout << "In Slot: " << T.deleteIt(el_t(key, "", "", "", 0, false, false)); //@@ NEW
          cout << "  deleted." << endl;
	  }
          // ** what happens if the item was not found?
	  break;
	  
	case 6:
          // SAVING TO FILE
	  T.saveTable(fout); // @@ NEW
	  cout << "Sent data to newout.txt" << endl; 
          cout << "Be sure to rename it before using it as input" << endl;
	  break;
	  
        default:
	  cout << "No action" << endl;
	  break;
	}
    }// end of loop

  fin.close();
  fout.close();
}

