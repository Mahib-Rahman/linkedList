#include <iostream>
#include <vector>
using namespace std;

#include "linkedList.h"

template<typename T>
linkedList<T>::linkedList()
{
    //the default constructor sets the head, tail and temp pointers to NULL
    head = NULL;
    tail = NULL;
    temp = NULL;
}

template<typename T>
linkedList<T>::linkedList(vector<T> arr)
{
    //takes in a vector argument and makes a list wthe the values of the vector
    head = NULL;
    tail = NULL;
    temp = NULL;
    
    for(int i = 0; i < arr.size(); i++)
    {
        addback(arr[i]);
    }
}

template <typename T>
T linkedList<T>::index_val(int index)
{
    //this function returns the data in the node that was requwsted by the index
    //brak the list into two halves for better time complexity
    if(index <= (size_of_list/2))
    {
        temp = head;

        while(index > 0)
        {
            if(temp -> next == NULL)
                break;
            temp = temp -> next;
            index--;
        }

        return temp -> data;
    }
    else
    {
        temp = tail;
        index = size_of_list - index - 1;
        while(index > 0)
        {
            if(temp -> prev == NULL)
                break;
            temp = temp -> prev;
            index--;
        }

        return temp -> data;
    }
}

template<typename T>
void linkedList<T>::reverse()
{
    //reverses the nodes
    //adjusts the pointers accordingly
    temp = head;
    struct node* swap;
    while(temp != NULL)
    {
        swap = temp -> next;
        temp -> next = temp -> prev;
        temp -> prev = swap;
        temp = temp -> prev;
    }
    //also adjusts the head and tail pointer
    swap = head;
    head = tail;
    tail = swap;
}

template<typename T>
void linkedList<T>::printList()
{
    //print the valuse of the linked list from head to tail
    temp = head;
    cout << "list from head to tail : ";
    while (temp != NULL)
    {
        cout << temp ->data << ", ";
        if(temp -> next == NULL)
            break;
        temp = temp ->next;
    }
    cout << endl;

    //print the valuse of the linked list from tail to head
    cout << "list form tail to head : ";
    while (temp != NULL)
    {
        cout << temp ->data << ", ";
        if(temp -> prev == NULL)
            break;
        temp = temp ->prev;
    }
    cout << endl;
}

template<typename T>
void linkedList<T>::addback(T value)
{
    //creates a new node and links it to the end of the list
    //adjusts the pointers accordingly
    struct node* n = new node;
    size_of_list++;
    n -> data = value;
    n -> next = NULL;

    //if head is null this will create the fisrt node
    if(head == NULL)
    {
        head = n;
        tail = n;
        n -> prev = NULL;
    }
    else
    {
        tail -> next = n;
        //prev for doubly linked list
        n -> prev = tail;
    }
    tail = n;
}

template<typename T>
void linkedList<T>::addfront(T value)
{
    //adds a node to the front of the list
    struct node* n = new node;
    n -> next = head;
    head -> prev = n;
    //sets the head pointer to this node
    //and adjusts the next and previous pointers
    head = n;
    size_of_list++;
    n -> data = value;
    n -> prev = NULL;
    return;
}

template<typename T>
void linkedList<T>::add_at_pos(T value, int index)
{
    if(index > size_of_list)
    {
        cout << "ERROR index inaccessable" << endl;
        return;
    }
    if(index == 0)
    {
        //if index = 0 just call the addfront function
        addfront(value);
        return;
    }
    if(index == size_of_list)
    {
        //if index = size of list just call the addback function
        addback(value);
        return;
    }

    struct node* n = new node;
    size_of_list++;
    temp = head;

    while(index > 0)
    {
        if(temp -> next == NULL)
            break;
        temp = temp -> next;
        index--;
    }

    n -> data = value;

    n -> prev = temp -> prev;
    n -> next = temp;

    temp -> prev = n;
    n -> prev -> next = n;
    
}

template<typename T>
void linkedList<T>::del_at_pos(int index)
{
    if(index >= size_of_list)
    {
        cout << "ERROR index inaccessable" << endl;
        return;
    }
    if(index == 0)
    {
        //if index = 0 just call the delfront function
        delfront();
        return;
    }
    if(index == size_of_list-1)
    {
        //if index = size of list just call the delback function
        delback();
        return;
    }
    temp = head;

    while(index > 0)
    {
        if(temp -> next == NULL)
            break;
        temp = temp -> next;
        index--;
    }
    //adter this loop temp points to the node that we wnt to delete
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    delete temp;
    temp = NULL;
    size_of_list--;
}
template<typename T>
void linkedList<T>::del_by_val(T value)
{
    //deletes the first node with the passed value
    //if a node containing the passed value isn't found return error;
    if(head -> data == value)
    {
        delfront();
        return;
    }
    if(tail -> data == value)
    {
        delback();
        return;
    }

    temp = head;
    while(temp -> data != value)
    {
        if(temp -> next == NULL)
        {
            cout << "ERROR Value Not Found" << endl;
            return;
        }
        temp = temp -> next;
    }
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    delete temp;
    temp = NULL;
    size_of_list--;
}

template<typename T>
void linkedList<T>::delfront()
{
    temp = head;
    temp = temp -> next;
    delete temp -> prev;
    head = temp;
    temp -> prev = NULL;
    size_of_list--;
}
template<typename T>
void linkedList<T>::delback()
{
    //reassignes the tail pointer to the previous one
    tail = tail -> prev;
    //deletes the last element in the list
    delete tail -> next;
    //sets the next pointer to NULL
    tail -> next = NULL;
    size_of_list--;
}