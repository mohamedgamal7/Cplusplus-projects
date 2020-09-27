
//============================================================================
// Name        : a1.cpp
// Author      : Mohamed_Gamal_Roushdy
// Version     : 1
// Copyright   : none
// Description :first_assignment
//============================================================================
#include <string.h>
#include <iostream>
#include<cmath>
#include<ctype.h>
#include<cstdlib>
#include <sstream>
using namespace std;

void PrintCmd(const  int inputs_number,char*inputs_vector[]);
void ReverseCmd(const  int inputs_number,char*inputs_vector[]);
void UpperCmd(const  int inputs_number,char*inputs_vector[]);
void shuffleWordCmd(const  int inputs_number,char*inputs_vector[]);
void shuffleStatementCmd(const  int inputs_number,char*inputs_vector[]);
void DeleteCmd(const  int inputs_number,char*inputs_vector[]);
void MiddleCmd(const  int inputs_number,char*inputs_vector[]);
void AddCmd(const  int inputs_number,char*inputs_vector[]);
void RandomCmd(const  int inputs_number,char*inputs_vector[]);
bool isinteger(char pointertostr);
bool isindex(char* indexpos);
int getindex(char* indexpos);

int main(int argc ,char* argv[]) {

if (strcmp(argv[1],"print")==0)
{
	PrintCmd(argc,argv);
}
else if (strcmp(argv[1],"reverse")==0)
{
	ReverseCmd(argc,argv);
}
else if (strcmp(argv[1],"upper")==0)
{
	UpperCmd(argc,argv);
}
else if (strcmp(argv[1],"shuffle")==0)
{
	shuffleWordCmd(argc,argv);
}
else if (strcmp(argv[1],"shuffleStatement")==0)
{
	shuffleStatementCmd(argc,argv);
}

else if (strcmp(argv[1],"delete")==0)
{
	DeleteCmd(argc,argv);
}

else if (strcmp(argv[1],"middle")==0)
{
	MiddleCmd(argc,argv);
}
else if (strcmp(argv[1],"add")==0)
{
	AddCmd(argc,argv);
}
else if (strcmp(argv[1],"random")==0)
{
	RandomCmd(argc,argv);
}
else
{
	cout<<"Undefined Command";
}


	return 0;
}

void PrintCmd(const  int inputs_number,char*inputs_vector[]){

	if (inputs_number>2){
		for(int i=2;i<inputs_number;i++){
			cout<<inputs_vector[i]<<" ";
		}
	}
	else {
		cout<<"Incorrect Number of Arguments"<<endl;
	}
}


void ReverseCmd(const  int inputs_number,char*inputs_vector[]){
	if (inputs_number>2){
		char* reverse_inputs[inputs_number];
			for(int i=2;i<inputs_number;i++){
				reverse_inputs[i]=inputs_vector[inputs_number-i+1];
		                                 	}
			for(int i=2;i<inputs_number;i++){
				cout<<reverse_inputs[i]<<" ";
			                                 }
			            }
	else {
			cout<<"Incorrect Number of Arguments"<<endl;
         }
}


void UpperCmd(const  int inputs_number,char*inputs_vector[]){
	if (inputs_number>2){

		for(int i=2;i<inputs_number;i++){
			for(int j=0;inputs_vector[i][j]!='\0';j++)
			{

						if (inputs_vector[i][j]>= 'a' && inputs_vector[i][j] <= 'z')   // making sure the character is small letter
							inputs_vector[i][j] = inputs_vector[i][j]- 32;
			}
		}

		for(int i=2;i<inputs_number;i++){
						cout<<inputs_vector[i]<<" ";
					                                 }
		}



	else {
				cout<<"Incorrect Number of Arguments"<<endl;
	         }
}

void shuffleWordCmd(const  int inputs_number,char*inputs_vector[]){
	if (inputs_number==3){
			for(int i=2;i<inputs_number;i++){
				char temp=0;
				int l =0 ;
				for(int j=0;inputs_vector[i][j]!='\0';j++)
								{


					l=l+1 ;
								}
				if(l%2==0){
				for(int j=0;inputs_vector[i][j]!='\0';j+=2)
				{


					                    temp=inputs_vector[i][j];
										inputs_vector[i][j]=inputs_vector[i][j+1];
										inputs_vector[i][j+1]=temp;

				}cout<<inputs_vector[i]<<" ";
				}
				else {
char keep = inputs_vector[i][l-1];
int k=0 ;
for(;inputs_vector[i][k]!='\0';k+=2)
				{

					temp=inputs_vector[i][k];
					inputs_vector[i][k]=inputs_vector[i][k+1];
					inputs_vector[i][k+1]=temp;
				}
				cout<<inputs_vector[i]<<keep<<" ";
			}


			}


	}
		else {
					cout<<"Incorrect Number of Arguments";
		         }
	}
void shuffleStatementCmd(const  int inputs_number,char*inputs_vector[]){

	if (inputs_number>2){
		char* temp ;

	for(int i=2;i<(inputs_number-1);i+=2){
		temp=inputs_vector[i];
		inputs_vector[i]=inputs_vector[i+1];
		inputs_vector[i+1]=temp;
	}
	for(int i=2;i<inputs_number;i+=1){
		cout<<inputs_vector[i]<<" ";
	}

	}
	else{
		cout<<"Incorrect Number of Arguments";
	}
}



void DeleteCmd(const  int inputs_number,char*inputs_vector[]){

	if(inputs_number>3){

				   if(isindex(inputs_vector[2])==0){
					   cout<<"Incorrect Data Type";
					   		    }

				   else if(getindex(inputs_vector[2])==0){
					   cout<<"Incorrect Data Type";
				   }
				   else if(getindex(inputs_vector[2])>(inputs_number-3)){

					   cout<<"Incorrect Number of Arguments";

				   }
					else{
						inputs_vector[getindex(inputs_vector[2])+2][0]='\0';
						 for(int i=3;i<(inputs_number);i++){
							 if(*inputs_vector[i]==0) continue;
												   cout<<inputs_vector[i]<<" ";
											   }
				         }


	}

	else{

			cout<<"Incorrect Number of Arguments";
		}
}

void MiddleCmd(const  int inputs_number,char*inputs_vector[]){

	if(inputs_number>2){


			if((inputs_number-2)%2!=0){
				int num=ceil(inputs_number/2);
				cout<<inputs_vector[num+1];
                                      }
			else{
				cout<<inputs_vector[(inputs_number/2)]<<" "<<inputs_vector[(inputs_number/2)+1];
			}
	}

	else{
			cout<<"Incorrect Number of Arguments";
		}
}
void AddCmd(const  int inputs_number,char*inputs_vector[]){


	if(inputs_number>2){

		signed int sum=0,flag=0 ;
		for(int i=2;i<(inputs_number);i+=1){
			for(int j=0;inputs_vector[i][j]!='\0';j+=1){
				if(isinteger(inputs_vector[i][j])==false){
					cout<<"Incorrect Data Type";
				flag=1;	break ;
				}

			}
	if (flag==0){		sum=sum+ atoi(inputs_vector[i]) ;}
	if (flag==1){break ;}
		}

		if (flag==0){
			cout<<sum;
		}

	}
	else{
		cout<<"Incorrect Number of Arguments";
	}

}
void RandomCmd(const  int inputs_number,char*inputs_vector[]){
if (inputs_number==6){

	      int flag=0 ;
			for(int i=2;i<(inputs_number);i+=1){
				for(int j=0;inputs_vector[i][j]!='\0';j+=1){
					if( ( isinteger(inputs_vector[i][j])==0 ) || ( atoi(inputs_vector[2])==0)){
						cout<<"Incorrect Data Type";
					flag=1;	break ;
					}
				}
		if (flag==1){break ;}	}

			if (flag==0){

				int max=atoi(inputs_vector[4]);
				int min =atoi(inputs_vector[3]);
				srand(atoi(inputs_vector[5]));

				if (max>=min){
				for(int i=0;i<atoi(inputs_vector[2]);i+=1){

					int random_number = min + rand() % (max+1 - min);
					    cout <<random_number<<" ";
				}

				}
				else{

								cout<<"Incorrect Number of Arguments";}
			}





}

else{cout<<"Incorrect Number of Arguments";}

}


bool isinteger(char pointertostr){

	char check = pointertostr ;
	int minuscounter=0 ;

	switch(check)
	{
	case'-': if (++minuscounter>1)
		return false ;
	break ;
	default :
		if (check<'0'||check>'9'){
			return false ;
		}
	}
	return true ;
}


bool isindex(char* indexpos){

	 char flag=0 ;
	 for(int i=0 ;indexpos[i]!='\0';i++){
		 if(isdigit(indexpos[i])==0)
	 {
			 flag=1; return false ;
	 }
	 }
	if (flag==0){
		return true ;
	}
	 }

int getindex(char* indexpos)
{ stringstream str(indexpos);
int returnnumber=0;
   str >>returnnumber;
return returnnumber ;
	}
