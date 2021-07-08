// CS311 Project Client using a generic tree class.
// Loading the data file has to happen in the client because
// the generic tree should not know about the file name.

// Change based on ** and @@
// **  Must improve the user interface!!!

// You may delete all the tracing couts from binstree.cpp!

#include "binstree.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// ** Add purpose of your program here

int main()
{
  BST T;  // generic tree
  
  // All declarations happen outside switch
  string fname;

  int key;       // ** change to fit your key
  string name;   // ** change and add more
  el_t E;        // blank element

  // File declarations happen outside switch
  cout << "What is the input file? (.txt)";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in);
  ofstream fout ("newout.txt", ios::out);


  int ans = 0;
  while (ans != 7)
    { // ** Change the menu items to be descriptive
      cout << "MENU------------------ :"<<endl;
      cout << "1. Load data from a file" << endl;
      cout << "2. Display the tree" << endl;
      cout << "3. Search using a key" << endl;
      cout << "4. Add a new entry" << endl;
      cout << "5. Delete an entry" << endl;
      cout << "6. Save data to a file" << endl;
      cout << "7. Exit" << endl;
      cout << "==>";
      cin >> ans;

      switch (ans)
	{

	case 1:  // ** change element parts
          // LOADING
	  while (fin >> key)
	    { fin >> name;
	      T.InsertVertex(el_t(key, name));
	    } 
	  cout << "loaded data..." << endl; 
	  break;

	case 2:
          // DISPLAYING SORTED
	  T.Display(); 
          break;

	case 3: // ** change key
          // SEARCHING
	  cout << "Enter key to look for: ";
	  cin >> key; 
	  E = T.Search(el_t(key,"")); //@@ updated search
	  if (E == el_t()) /// was blank
	    cout << "Not found" << endl;
          else cout << "Found " << E << endl;
	  break;

	case 4: // ** change element parts
          // ADDING  
          cout << "Enter a key: "; cin >> key;
	  cout << "Enter a name: "; cin >> name;
	  T.InsertVertex(el_t(key, name));
          cout << "  added." << endl;
	  break;
       
	case 5: // ** change key
          // DELETING
          cout << "Enter a key: "; cin >> key;
          T.DeleteVertex(el_t(key,"")); 
          cout << "  deleted." << endl;
        // ** what happens if the vertex was not found?
	  break;
        
	case 6:
	  // SAVING TO A FILE
	  T.saveTree(fout); //@@ new function
	  cout << "Sent data to newout.txt" << endl; 
          cout << "Be sure to rename the file before using as input" << endl;
	  break;

        default:
	  cout << "No action" << endl;
	  break;
	}
    }// end of loop
  fin.close();
  fout.close();
}

