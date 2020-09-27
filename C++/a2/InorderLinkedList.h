/*
 * list.h
 *
 *  Created on: Mar 25, 2020
 *      Author: student
 */

#ifndef INORDERLINKEDLIST_H_
#define INORDERLINKEDLIST_H_

#include <iostream>
using namespace std;
#include <string>
#include <sstream>


typedef string ListElemType;

class InorderLinkedList {
public:
    InorderLinkedList();
    bool insert(const ListElemType& item,const	int linenum );
    bool first(ListElemType& item);
    bool next(ListElemType& item);
    bool previous(ListElemType& item);
    int repeated();
    bool counteachword();
    string frequentwords();
    string containing(string sub);
    string starting(string sub);
    string search(string sub);


private:
    struct Node; // Forward declaration of structure
    typedef Node* Link;
    struct Node {
        ListElemType element;
        Link next;
        Link prev;
        int linenum ;
        int wordcount ;

    };
    Link head;
    Link tail;
    Link current;
};

#endif /* INORDERLINKEDLIST_H_ */
