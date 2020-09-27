//============================================================================
// Name        : a2.cpp
// Author      : mohamed_gamal
// Version     :
// Copyright   : Your copyright notice
// Description : A2
//============================================================================

#include <iostream>
using namespace std;
#include "stacks.h"
#include <string>
#include <ctype.h>
#include <cstring>
#include <strings.h>

bool inputcheckandseparation(char* argv,string& firstnum,string& secondnum);
bool findoperand(char* argv , char& operand);
void decimalequate(string& firstnum ,string& secondnum);
void pushtostack(stacks& stack1 ,stacks &stack2 ,string& firstnum ,string& secondnum ,int& a ,int& b);
void operation(stacks &stack1 ,stacks& stack2 ,stacks &result,char& operand,int& dotposshift);

int main(int argc , char*argv[]) {

	if (argc==2){
	string firstnum="" ;
	string secondnum="" ;
	char operand='1' ;
	if(inputcheckandseparation(argv[1],firstnum,secondnum))
	{findoperand( argv[1] ,operand);
	decimalequate(firstnum , secondnum ); }
	stacks stack1,stack2,result ;
	int dotpos1=0 ;int dotpos2=0;int dotposshift=0;string finalresult="" ;string dot=".";int zerocheck=1 ;
	pushtostack(stack1 , stack2,firstnum ,secondnum,dotpos1,dotpos2) ;
	operation(stack1 ,stack2 ,result,operand,dotposshift);


	if(dotpos1==0&&dotpos2==0){result.top(zerocheck);while(zerocheck==0 &&(result.size()>1)){result.pop(zerocheck);result.top(zerocheck);}result.Display();}
	else{
		if(dotpos1>=dotpos2){
			finalresult=result.tostring();
			finalresult.insert( dotpos1+dotposshift,dot,0,1);
			int i=0 ;
			 while (finalresult[i] == '0'&&finalresult[i+1] != '.')
			       i++;
			 finalresult.erase(0, i);
			cout<<finalresult;
		}
		else if(dotpos1<dotpos2){
			finalresult=result.tostring();
						finalresult.insert( dotpos2+dotposshift,dot,0,1);
					int i=0 ;
						 while (finalresult[i] == '0'&&finalresult[i+1] != '.')
									       i++;
									 finalresult.erase(0, i);
									cout<<finalresult;
		}
	}

	}
	else{
		cout<<"Invalid input" ;

	}

return 0 ;
}




bool inputcheckandseparation(char* argv,string& firstnum,string& secondnum){



   int countminus=0,countdot=0,countplus=0 ;
   int countdotf=0,countdots=0 ;
		string argvcpp(argv) ;
		 firstnum= "" ;secondnum= "" ;
        int j=0 ;int count =0 ;
		for(int i=0 ;argv[i]!='\0';i++){

		if(isdigit(argv[i])||argv[i]=='+'||argv[i]=='-'||argv[i]=='.'){

			if((argvcpp).find("+") != string::npos && (argvcpp).find("-") != string::npos){
				cout<<"Invalid input" ;
				firstnum= "" ;secondnum= "" ;
				return false  ;				break ;
			}
			else if((argvcpp).find("+.") != string::npos || (argvcpp).find("-.") != string::npos){
						cout<<"Invalid input" ;
						firstnum= "" ;secondnum= "" ;
						return false  ;			break ;
					}

			else if((argvcpp).find(".+") != string::npos || (argvcpp).find(".-") != string::npos){
									cout<<"Invalid input" ;
									firstnum= "" ;secondnum= "" ;
									return false  ;			break ;
								}
			else if(argv[i]=='+'){countplus++ ;}
			else if(argv[i]=='-'){countminus++ ;}
			else if(argv[i]=='.'){countdot++ ;}

		}

		else {
			cout<<"Invalid input" ;
			firstnum= "" ;secondnum= "" ;
			return false  ;		break ;
		}
	count=i;	}

		if(countplus>1||countminus>1||countdot>2){cout<<"Invalid input" ; return false  ;}

		for(int i=0 ;argv[i]!='\0';i++){

			if(argv[i]=='+'||argv[i]=='-'){
				j=i ;
						}
		}
		for(int k=j+1 ;argv[k]!='\0';k++){
			secondnum=secondnum+argv[k];
		}
		for(int z=0 ;z!=j;z++){

	    	firstnum=firstnum+argv[z] ;

		}
		for(char& c : firstnum) {
			if(c=='.'){countdotf++;}

		}
		for(char& c : secondnum) {
			if(c=='.'){countdots++;}

				}
		if(countdotf>1){cout<<"Invalid input" ;  firstnum= "" ;
		 secondnum= "" ;return false  ;}
		else if(countdots>1){cout<<"Invalid input" ;  firstnum= "" ;
		 secondnum= "" ; return false  ;}
		else if(argv[0]=='+'||argv[0]=='-'||argv[0]=='.'){cout<<"Invalid input" ;
					firstnum= "" ;secondnum= "" ;
					return false  ;}
		else if(argv[count]=='+'||argv[count]=='-'||argv[count]=='.'){cout<<"Invalid input" ;
							firstnum= "" ;secondnum= "" ;
							return false  ;}

return true ;
}


bool findoperand(char* argv , char& operand){
	string argvcpp(argv) ;
	if((argvcpp).find("+") != string::npos ){operand='+';}
	else if((argvcpp).find("-") != string::npos ){operand='-';}
	else{cout<<"Invalid input" ; return false ;}

	return true ;
}

void decimalequate(string& firstnum ,string& secondnum){
int d1=0,d2=0 ,c1=0,c2=0 ;
firstnum=(firstnum).c_str();
secondnum=(secondnum).c_str();
	for(int i=0 ;firstnum[i]!='\0';i++) {
				if(firstnum[i]=='.'){
					d1=i; ;
				}
			c1=i ;
			}

	for(int i=0 ;secondnum[i]!='\0';i++) {
		if(secondnum[i]=='.'){
							d2=i; ;
						}
					c2=i ;
					}

	string secondnumcpp(secondnum) ;
	string firstnumcpp(firstnum) ;

	if(d1!=0&&d2==0){
		c1=c1-d1 ;
		secondnumcpp=secondnumcpp+".";
	for(int i=1;i<=c1;i++){
	secondnumcpp=secondnumcpp+"0" ;}}

	else if(d2!=0&&d1==0){
		firstnumcpp=firstnumcpp+".";
			c2=c2-d2 ;
		for(int i=1;i<=c2;i++){
			firstnumcpp=firstnumcpp+"0" ;}}

	else if(d1!=0&&d2!=0){
		c1=c1-d1 ;
		c2=c2-d2 ;
		if(c1>c2){

			for(int i=1;i<=(c1-c2);i++){
				secondnumcpp=secondnumcpp+"0" ;}
		}
		else if(c2>c1){

			for(int i=1;i<=(c2-c1);i++){
				firstnumcpp=firstnumcpp+"0";}
					}
		}

	else if(d1==0&&d2==0){
		firstnumcpp=firstnum;
		secondnumcpp=secondnum;
	}

	firstnum=firstnumcpp ;
	secondnum=secondnumcpp ;
}

void pushtostack(stacks& stack1 ,stacks& stack2,string& firstnum ,string& secondnum,int& dotpos1,int& dotpos2){
	int c1=0 ,c2=0 ;
	 dotpos1=0 ;
     dotpos2=0 ;


	int i=0 ;
	while (firstnum[i] == '0'&&firstnum[i+1] != '.')
				       i++;
	firstnum.erase(0, i);
	 i=0 ;
	while (secondnum[i] == '0'&&secondnum[i+1] != '.')
					       i++;
	secondnum.erase(0, i);
if(firstnum==""){firstnum=firstnum+"0";}
if(secondnum==""){secondnum=secondnum+"0";};

	for(char& c : firstnum) { if(c=='.'){dotpos1=c1;}c1++;}
		for(char& c : secondnum) {if(c=='.'){dotpos2=c2; }c2++;}

		if(dotpos1!=0||dotpos2!=0){c1=c1-1; c2=c2-1;
	firstnum.erase(dotpos1, 1);
	secondnum.erase(dotpos2, 1);}





int secondnumi[(c2)];
int firstnumi[(c1)] ;
for(int i=0 ;i<=c1;i++){
	firstnumi[i]=(int)(firstnum[i])-48;

}
for(int i=0 ;i<=c2;i++){
	secondnumi[i]=(int)(secondnum[i])-48;

}



for(int i=0;i<(c1);i++){


	stack1.push(firstnumi[i]);
}


for(int i=0;i<(c2);i++){


	stack2.push(secondnumi[i]);
}

}

void operation(stacks& stack1 ,stacks &stack2 ,stacks& result,char& operand,int& dotposshift){


bool fflag=0 ;
bool sflag=0 ;
int s1=stack1.size() ;
int s2=stack2.size() ;
if(s1>s2){ fflag=1; }
else if(s2>s1){  sflag=1; }
int op1=0 ;
int op2=0 ;
int op3=0 ;
int carry=0 ;

if(operand=='+'){
  while(stack1.pop(op1)&&stack2.pop(op2)){

  op3=op2+op1+carry ;
  if(op3>=10){carry=1 ;op3=op3-10 ;}
  else{carry=0 ;}
result.push(op3);
if(stack2.isEmpty()||stack1.isEmpty()){break ;}

  }

  if(fflag){
	  while(stack1.pop(op1)&&stack2.isEmpty()){
		  op3=op1+carry ;
		  if(op3>=10){carry=1 ;op3=op3-10 ;}
		   else{carry=0 ;}
		 result.push(op3);
	  }
  }

  else if(sflag){
  	  while(stack2.pop(op2)&&stack1.isEmpty()){
  		  op3=op2+carry ;
  		  if(op3>=10){carry=1 ;op3=op3-10 ;}
  		   else{carry=0 ;}
  		 result.push(op3);
  	  }
    }

  if(carry==1){result.push(carry); dotposshift++; }


}


else if (operand=='-'){

	while(stack1.pop(op1)&&stack2.pop(op2)){

	if(op1>op2){
		 op3=op1-op2-carry;
		 if(op3<0){ op3=op1+10-op2-carry; result.push(op3); carry=1; }
		 else{result.push(op3);
		 carry=0 ;}
	}

	else if(op1==op2&&carry==1){
		op3=op1-op2+10-carry;
		carry=1 ;
		result.push(op3);
	}
	else if(op1==op2&&carry==0){
			op3=op1-op2;
			carry=0 ;
			result.push(op3);
		}

	else{
		 op3=op1+10-op2-carry;
		 result.push(op3);
		carry=1;
	}
	if(stack2.isEmpty()||stack1.isEmpty()){break ;}
	}

	  if(fflag){
		  while(stack1.pop(op1)&&stack2.isEmpty()){
			  op3=op1-carry;
			  if(op3<0){ op3=op1+10-carry; result.push(op3); carry=1; }
			 		 else{result.push(op3);
			 		 carry=0 ;}
		  }
	  }



}


}

