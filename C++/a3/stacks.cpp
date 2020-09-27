/*
 * list.cpp
 *
 *  Created on: Mar 25, 2020
 *      Author: student
 */

#include "stacks.h"

stacks::stacks()
{
    head = NULL;
}




bool stacks::push(StackElementType& e)
{
    Link addedNode = new Node;
    if (addedNode == NULL) {
        return false;
    }
    else {
        addedNode->element = e;
        addedNode->next = head;
        head = addedNode;
        return true;
    }
}


bool stacks::isEmpty()
{
    return bool(head == NULL);
}


bool stacks::pop(StackElementType& e)
{
	 if (head == NULL) {
	        return false;
	    }
	 else{
		 e=head->element;
		 Link deletedNode=head ;
		 head=head->next;
		 delete deletedNode;

	 }
    return true;
}


bool stacks::top(StackElementType& e)
{
	Link top =head;
	if(top!=NULL)
	{
	e=top->element ;
	}
	else{
		return false ;
	}
    return true;
}

void stacks::Display()
{
Link p=head;
while(p!=NULL)
{
cout<<p->element;
p=p->next;
} }


int stacks::size()
{
int count=0;
Link p=head;
while(p!=NULL)
{
count++ ;
p=p->next ;
}
return count ;
}

string stacks::tostring(){

string result="" ;
Link p=head;
while(p!=NULL)
{
result=result+to_string(p->element);
p=p->next ;
}

return result;
}

