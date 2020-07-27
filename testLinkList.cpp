#include <iostream>
#include <vector>
using namespace std;

#include "linkedList.h"

int main()
{
    //initializing the list with a vector perameter of 5 elements and printing the list and size
    linkedList<int> myList({5,10,15,20,25});
    myList.printList();
    cout << myList.size() << endl;

    //adding an element to the fornt of the list and at the back
    //then printing the list as well as the nesw size
    myList.addfront(0);
    myList.addback(30);
    myList.printList();
    cout << myList.size() << endl;

    //tests the index_val function
    //this function lets you acess an element in the list given its index
    cout << myList.index_val(0) << endl;
    cout << myList.index_val(1) << endl;
    cout << myList.index_val(5) << endl;

    //adding an element at a position in the list with
    //then printing the list as well as the nesw size 
    myList.add_at_pos(99, 2);
    myList.printList();
    cout << myList.size() << endl;

    //deleting an element at a position in the list
    //then printing the list as well as the nesw size
    myList.del_at_pos(4);
    myList.printList();
    cout << myList.size() << endl;
    
    //deleting the first element in the list with the entered value
    //then printing the list as well as the nesw size
    myList.del_by_val(20);
    myList.printList();
    cout << myList.size() << endl;

    //reversing the list 
    //then printing the list as well as the nesw size
    myList.reverse();
    myList.printList();
    cout << myList.size() << endl;

    //initializing a linked list of type string
    //then printing the list as well as the nesw size 
    linkedList<string> strList;
    strList.addback("Thank");
    strList.addback("You");
    strList.addback("for");
    strList.addback("trying");
    strList.addback("this");
    strList.addback("!!!");
    strList.printList();
    cout << strList.size() << endl;

    return 0;
}