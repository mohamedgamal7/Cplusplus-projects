/*
 * list.cpp
 *
 *  Created on: Mar 25, 2020
 *      Author: student
 */

#include "InorderLinkedList.h"

InorderLinkedList::InorderLinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}
bool InorderLinkedList::insert(const ListElemType& item ,const	int linenum)
{

    Link addedNode = new Node;
    Link pred;
    if (addedNode == NULL) {
        return false; // allocation failed
    }
    else {
        addedNode->element = item;
        addedNode->linenum = linenum;


        if (head == NULL  ) {
            head = addedNode;
            return true;
        }

        else if(item.compare(head->element)<0){

        	            addedNode->next = head;
        	            addedNode->next->prev=addedNode ;
        	            head = addedNode;
     return true ;   }

        else {
        	pred = head;
        	            while (pred->next != NULL && pred->next->element <=item) {
        	                pred = pred->next;
        	            }
        	            addedNode->next = pred->next;
        	            if(pred->next!=NULL)
        	            	 addedNode->next->prev = addedNode;
        	            pred->next = addedNode;
        	            addedNode->prev =pred ;


        	            return true;


        }


        }
    }


bool InorderLinkedList::first(ListElemType& item)
{
    if (head == NULL) {
        // check if the list is empty
        return false;
    }
    else {
        current = head;
        item = current->element;
        return true;
    }
}




bool InorderLinkedList::next(ListElemType& item)
{
    if (current == NULL || current->next == NULL) {
        // check if first has been called at least once
        // check if end of the list is reached
        return false;
    }
    else {
        current = current->next;
        item = current->element;
        return true;
    }
}



bool InorderLinkedList::previous(ListElemType& item)
{
    if (current == NULL || current->prev == NULL) {
        return false;
    }
    else {
        current = current->prev;
        item = current->element;
        return true;
    }
}
int InorderLinkedList::repeated(){


 int rep =0 ;

 current=head ;

if (current == NULL) {
        // check if the list is empty
        return false;
    }

else{
	Link after ;
	after= current->next ;
while(current!=NULL &&after!=NULL){



	if((current->element).compare(after->element)==0){
		rep++ ;
	}


current=current->next ;
if(current==NULL){break ;}

after=current->next ;
if(after==NULL){break ;}



}

return rep ;} }


bool InorderLinkedList ::counteachword(){




	if(head==NULL){
		 return false;
	}
	else{
	int wordcount=0 ;
	 Link comparing ; //the node we r comparing all list with
	comparing=head ;
	current=head ;
	while(comparing!=NULL){
		while(current!=NULL){


		if((current->element).compare(comparing->element)==0){
			wordcount++ ;
		}
		current=current->next ;
		if(current==NULL){break ;}
		}
		comparing->wordcount=wordcount ;
		wordcount=0 ;
		current=head ;
		comparing=comparing->next ;
	}
	return true ;}

}


string InorderLinkedList :: frequentwords (){



string freqwords;
int maxwordcount=0;


		freqwords="" ;
	  current=head ;
		for(;current!=NULL;(current=current->next)){

			if((current->element).compare("a")==0 ||(current->element).compare("an")==0||(current->element).compare("the")==0||(current->element).compare("in")==0||(current->element).compare("on")==0||(current->element).compare("of")==0||(current->element).compare("and")==0||(current->element).compare("is")==0||(current->element).compare("are")==0){
				continue ;
			}
			else if ((current->next)!=NULL && (current->element).compare(current->next->element)==0 ){
				continue ;
			}
			else{
				if((current->wordcount)>maxwordcount){
					maxwordcount=current->wordcount ;
					freqwords=current->element ;
				}
				else if (current->wordcount<maxwordcount){continue ;}

				else{freqwords=freqwords+" "+current->element ;}
			}

		}
return freqwords ;

}



string InorderLinkedList :: containing(string sub){

	string wordscontaining="" ;
      current=head ;
	for(;current!=NULL;(current=current->next)){

		if ((current->next)!=NULL && (current->element).compare(current->next->element)==0 ){
						continue ;
					}
		else{

		if ((current->element).find(sub) != string::npos) {
			if(wordscontaining.compare("")!=0){
			wordscontaining=wordscontaining+"	"+current->element +": "+to_string(current->wordcount);
			}
			else{
				wordscontaining=wordscontaining+current->element +": "+to_string(current->wordcount);
				}
			}


	}   }

return wordscontaining ;

}

string InorderLinkedList :: starting(string sub){

	string wordsstarting="" ;
      current=head ;
	for(;current!=NULL;(current=current->next)){

		if ((current->next)!=NULL && (current->element).compare(current->next->element)==0 ){
						continue ;
					}
		else{

		if ((current->element).rfind(sub, 0) == 0) {
			if(wordsstarting.compare("")!=0){
				wordsstarting=wordsstarting+"	"+current->element +": "+to_string(current->wordcount);
			}
			else{
				wordsstarting=wordsstarting+current->element +": "+to_string(current->wordcount);
				}
			}


	}   }
return wordsstarting ;

}


string InorderLinkedList :: search(string sub){

	string search="" ;
     current=head;
     Link compare=head;

     for(;current!=NULL;(current=current->next)){

     		if ((current->next)!=NULL && (current->element).compare(current->next->element)==0 ){
     						continue ;
     					}
     		else{

     		if ((current->element).find(sub) != string::npos) {
     			if(search.compare("")!=0){
     				search=search+"\n"+current->element +":"+"	"+"lines";
     				while(compare!=NULL){



     						 if((current->element).compare(compare->element)==0 &&(compare->linenum)!=(compare->next->linenum)){
     						     							search=search+" "+to_string(compare->linenum);
     						     						}
     						else if((current->element).compare(compare->element)==0 &&(compare->linenum)==(compare->next->linenum)&&(compare->element).compare(compare->next->element)!=0 ){
     						     				     						     				     							search=search+" "+to_string(compare->linenum);
     						     				     						     				     						}

     						compare=compare->next ;
     				}

     			compare=head ;}
     			else{
     				search=search+current->element +":"+"	"+"lines";
     				while(compare!=NULL){

     				     						if((current->element).compare(compare->element)==0 &&(compare->linenum)!=(compare->next->linenum)){
     				     							search=search+" "+to_string(compare->linenum);
     				     						}

     				     						else if((current->element).compare(compare->element)==0 &&(compare->linenum)==(compare->next->linenum)&&(compare->element).compare(compare->next->element)!=0 ){
     				     						     				     							search=search+" "+to_string(compare->linenum);
     				     						     				     						}


     				     						compare=compare->next ;
     				     				}

     				compare=head ;

     				}
     			}


     	}


} return search ;}


