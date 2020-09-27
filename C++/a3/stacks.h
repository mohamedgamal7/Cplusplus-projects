/*
 * list.h
 *
 *  Created on: Mar 25, 2020
 *      Author: student
 */

#ifndef STACKS_H_
#define STACKS_H_

#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <assert.h>


typedef int StackElementType;

class stacks {
public:
	stacks();
	bool push(StackElementType& e);
    bool pop(StackElementType& e);
    bool top(StackElementType& e);
    bool isEmpty();
    void Display() ;
    int  size() ;
    string tostring();
private:
    struct Node; // Forward declaration of structure
    typedef Node* Link;
    struct Node {
    	StackElementType element;
        Link next;



    };
    Link head;

};

#endif /* STACKS_H_ */
