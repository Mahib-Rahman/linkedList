#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include <vector>
using namespace std;

//use template typename so the dtat in the linked list can be any type
template<typename T>
class linkedList
{
private:
    struct node{
        T data;
        node* next;
        node* prev;
    };

    struct node* head;
    struct node* tail;
    struct node* temp;
    int size_of_list = 0;

public:
    linkedList();
    linkedList(vector<T> arr);
    void addback(T value);
    void addfront(T value);
    void printList();
    int size(){return size_of_list;}
    //the size function returns the number of nodes in the linked list
    void add_at_pos(T value, int index);
    void del_at_pos(int pos);
    void del_by_val(T value);
    void delback();
    void delfront();
    void reverse();
};

#include "linkedList.cpp"

#endif // LINKED_LIST