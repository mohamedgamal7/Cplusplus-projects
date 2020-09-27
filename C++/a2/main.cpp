//============================================================================
// Name        : a2.cpp
// Author      : mohamed_gamal
// Version     :
// Copyright   : Your copyright notice
// Description : A2
//============================================================================

#include <iostream>
using namespace std;
#include "InorderLinkedList.h"
#include <string>
#include <fstream>
#include <string.h>
#include <sstream>

bool readinputfile(string filename,InorderLinkedList &list) ;
bool readcommandfile( string filename,string text,InorderLinkedList &list) ;
int wordcount(InorderLinkedList &list);
int charcount(string filename);
void listtraversal(InorderLinkedList &list);
int countword(InorderLinkedList &list,string word);
int distword(InorderLinkedList &list);
char to_lowercase(char c);


int main(int argc , char**argv) {

	if(argc==3){
		InorderLinkedList list;
		ListElemType item;
		readinputfile(argv[1],list);
		list.counteachword();
		readcommandfile(argv[2],argv[1],list);


	}
	else {
		cout<<"Incorrect number of arguments"<<endl;
	}
return 0 ;
}


bool readinputfile(string filename,InorderLinkedList &list ) {


	    ifstream filein;
	    filein.open(filename);
	    if(!(filein.is_open()))
	    {
	        cout << "File not found"<<endl;
	        return false ;
	    }

	    else {



char separators[] = ".,";


string fullline= "" ;
string word = "";
int linenum=1 ;

while (getline(filein, fullline)){

	 for (unsigned int i = 0; separators[i]!='\0'; ++i)
	   {
		 for (char &c: fullline) {

			 if(c==separators[i]){
			 		c = ' ';
			 }}



	   }
	 for (char &c: fullline) {
	 		c = to_lowercase(c);
	 	}


	  stringstream ss( fullline );
	      while ( ss >> word ) {
	    	  if (!list.insert(word,linenum)) {

	    	 	    	             break;
	      }

	      }

	      linenum++ ;



	    }
return true ;
} }

bool readcommandfile(string filename ,string text ,InorderLinkedList &list)
{
	ifstream filein;
		    filein.open(filename);

		    if(!filein.is_open())
		    {
		        cout << "File not found"<<endl;
		        return false ;
		    }

		    else{
		    	string fulline ;
		    	string word="" ;
		    	string words[50] ;

		    	while (filein.good() && getline(filein, fulline)){
		    		string words[10] ;
		    		words[1]="";
		    		 int i=0 ;
		    		  stringstream ss( fulline );
		    			      while ( ss >> word ) {
		    		  words[i]=word ;
		    		  i++ ;
		    		    }




if(words[0].compare("wordCount")==0){


	if(words[1]=="")
			{cout<<wordcount(list)<<" "<<"words"<<endl ;;}
			else{cout<<"Incorrect number of arguments"<<endl;}
		words[1]="";

}
else if(words[0].compare("distWords")==0){

	if(words[1]=="")
		{cout<<distword(list)<<" "<<"distinct words"<<endl ;}
		else{cout<<"Incorrect number of arguments"<<endl;}
	words[1]="";

	}




else if(words[0].compare("charCount")==0){
	if(words[1]=="")
	{cout<<charcount(text)<<" "<<"characters"<<endl ;}
	else{cout<<"Incorrect number of arguments"<<endl;}


}
else if(words[0].compare("frequentWord")==0){
	if(words[1]=="")
	{cout<<"Most frequent word is: "<<list.frequentwords()<<endl ;}
	else{cout<<"Incorrect number of arguments"<<endl;}
words[1]="";

}
else if(words[0].compare("countWord")==0){
	if(words[1]!="" && words[2].empty()){
cout<<words[1]<<" is repeated "<<countword(list,words[1])<<" times"<<endl ;}
	else{cout<<"Incorrect number of arguments"<<endl;}
words[1]="";

}
else if(words[0].compare("starting")==0){

if(words[1].empty()||i>2){ cout<<"Incorrect number of arguments"<<endl; words[1]="";
continue ;}
else if (list.starting(words[1]).compare("")==0){cout<<"Word not found"<<endl; words[1]="";
continue ;}
else{
	 cout<<list.starting(words[1])<<endl ;
	 words[1]="";

}
}
else if(words[0].compare("containing")==0){
	if(words[1].empty()||i>2){ cout<<"Incorrect number of arguments"<<endl; continue;}
	else if (list.containing(words[1]).compare("")==0){cout<<"Word not found"<<endl;}
	else{
 cout<<list.containing(words[1])<<endl ;}
}
else if(words[0].compare("search")==0){
	 for (char &c:words[1]) {
			 		c = to_lowercase(c);
			 	}
if(words[1].empty()||i>2){ cout<<"Incorrect number of arguments"<<endl; continue;}
else if (list.containing(words[1]).compare("")==0){cout<<"Word not found";}
cout<<list.search(words[1])<<endl ;
}

else{
	cout<<"Undefined command"<<endl;
}





} return true ;
		    }

}


int wordcount(InorderLinkedList &list){
    string str ;

    int count =0 ;
    if(list.first(str)){
	bool status = list.first(str);
	    while (status != false) {
	        count++ ;
	        status = list.next(str);
	    }
    return count ;}
    else {
    	cout<<"File is empty"<<endl;
return false ;
    }

}


int charcount(string filename){

	string fulline= "" ;
	ifstream filein;
    filein.open(filename);
    int charcount=0 ;
    int textfilelines=0 ;
    while (getline(filein, fulline)){
    	textfilelines++ ;

    	if(textfilelines==1){ charcount += fulline.length() ;}
    	else{
    	charcount += fulline.length()+1;}
    }
    if(textfilelines!=0 &&fulline.length()==0){ charcount ++ ;}
return charcount;

}

void listtraversal(InorderLinkedList &list){
	  string str ;

	    if(list.first(str)){
		bool status = list.first(str);
		    while (status != false) {
		       cout<<str<<endl ;
		        status = list.next(str);
		    }
	   }
	    else {
	    	cout<<"File is empty"<<endl;

	    }
}



int countword(InorderLinkedList &list,string word){
   string str ;
    int count =0 ;
    if(list.first(str)){
	bool status = list.first(str);
	 for (char &c: word) {
		 		c = to_lowercase(c);
		 	}
	    while (status != false) {

	     if(str.compare(word)==0)
	    	{count++ ;}
	        status = list.next(str);

	    }
    return count ;}
    else {
    	cout<<"File is empty"<<endl;
return false ;
    }

}


int distword(InorderLinkedList &list){

int allwords=wordcount(list);
int distwords=allwords-list.repeated();

return distwords ;

}

char to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;

	return c;
}


