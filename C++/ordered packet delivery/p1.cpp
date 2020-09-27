//============================================================================
// Name        : P1.cpp
// Author      : mohamed_gamal
// Date create :10/5/2020
// Copyright   : Your copyright notice
// Description : final project
//============================================================================

#include <iostream>
using namespace std;
#include <math.h>
#include <string>


//Global variables
int maxQueue ;
int initseq ;

typedef int QueueElementType;
class CPQueue {
public:
    CPQueue();
    bool enqueue(const QueueElementType& item);
    bool dequeue(QueueElementType& item);
    bool front(QueueElementType& item);
    bool isEmpty();
    bool isfull();
    bool isWaiting(QueueElementType& item);
private:
    int fronti; // indicates front
    int reari; // indicates rear
    int nextPosition(int pointer);
    int prevPosition(int pointer);
    QueueElementType* queuearray;
    int shiftposi ;

};


CPQueue::CPQueue()
{
	fronti = 0;
    reari = 0;
    queuearray=new int[maxQueue];
    shiftposi=0;


}



bool CPQueue::enqueue(const QueueElementType& item)
{
	 int wrapposi=-1 ;
     int inserti=0;


	 if (nextPosition(reari) == fronti) {
	        return false; // Queue is Full
	    									}
	 else{

		 if (isEmpty()) {


		    	reari = nextPosition(reari);
		        queuearray[reari] = item; 		}
		 else{

			 for(int i=nextPosition(fronti);;i=nextPosition(i)){

                if(queuearray[i]<initseq){ wrapposi=i; break ;}
                    if(nextPosition(i)==nextPosition(reari)){break ;}


			 						                                               }
			if(item>=initseq){
               if(wrapposi!=-1){
				if(prevPosition(wrapposi)!=fronti&&queuearray[prevPosition(wrapposi)]<item){
				    		 reari= nextPosition(reari);
				    		 queuearray[reari]=queuearray[wrapposi] ;
				    		 queuearray[wrapposi]=item ;
				                 return true ;                   }
				else if (prevPosition(wrapposi)==fronti){
					reari= nextPosition(reari);
					  inserti=reari ;
					 for(int i=wrapposi;;i=nextPosition(i)){
										    		 if(i== nextPosition(reari)){ break ;}
										              queuearray[inserti]=  queuearray[prevPosition(inserti)] ;
										              inserti= prevPosition(inserti);	 	 	   }
					                                  queuearray[wrapposi]=item;
				                                                                                                  }
				else{
					 for(int i=nextPosition(fronti);;i=nextPosition(i)){

					    		 if(i==nextPosition(wrapposi)){ break ;}

					    		 if(queuearray[i]<item){continue;}

					    		 else if(queuearray[i]>item){shiftposi=i; break ;}
					                                                                    }
					 reari = nextPosition(reari);
					   inserti=reari ;
					    		 for(int i=shiftposi;;i=nextPosition(i)){
					    		 if(i== nextPosition(reari)){ break ;}
					              queuearray[inserti]=  queuearray[prevPosition(inserti)] ;
					              inserti= prevPosition(inserti);	 	 	   }
					    	 queuearray[shiftposi]=item ;

				                                                                          }


                                                                                             }
               else {

            	 if(item>queuearray[reari])  {reari= nextPosition(reari); queuearray[reari]=item ;}
            	 else{
            		 for(int i=nextPosition(fronti);;i=nextPosition(i)){

            							    		 if(i==nextPosition(wrapposi)){ break ;}

            							    		 if(queuearray[i]<item){continue;}

            							    		 else if(queuearray[i]>item){shiftposi=i; break ;}
            							                                                                    }
            							 reari = nextPosition(reari);
            							   inserti=reari ;
            							    		 for(int i=shiftposi;;i=nextPosition(i)){
            							    		 if(i== nextPosition(reari)){ break ;}
            							              queuearray[inserti]=  queuearray[prevPosition(inserti)] ;
            							              inserti= prevPosition(inserti);	 	 	   }
            							    	 queuearray[shiftposi]=item ;
            	 }
               }
               return true ;																    }

			else{
				if(wrapposi!=-1){
				 for(int i=wrapposi;;i=nextPosition(i)){

									    		 if(i==nextPosition(reari)){ break ;}

									    		 if(queuearray[i]<item){continue;}

									    		 else if(queuearray[i]>item){shiftposi=i; break ;}
									                                                                    }
				 if(queuearray[reari]<item){
				    		 reari= nextPosition(reari);
				    		 queuearray[reari]=item ;   }
				 else{
					 reari = nextPosition(reari);
					     	       inserti=reari ;
					     		 for(int i=shiftposi;;i=nextPosition(i)){
					     		 if(i== nextPosition(reari)){ break ;}
					               queuearray[inserti]=  queuearray[prevPosition(inserti)] ;
					               inserti= prevPosition(inserti);	 	 	   }
					     	 queuearray[shiftposi]=item ;
				                                                                                      }

																															}
				else {
					reari= nextPosition(reari); queuearray[reari]=item ;
				}
				         					return true ;											                    }
						              																	                   }



		 return true ;

		 	 	 	 	 	 	 	 	 	 	 	 	 }











	 	 	 	 	 	 	 	 	 	 	 	 	 	 	}



bool CPQueue::dequeue(QueueElementType& item)
{   item=-1;
    if (reari == fronti) {
        return false; // Queue is Empty
    }
    else {
    	fronti = nextPosition(fronti);
        item = queuearray[fronti];
        return true;
    }
}


bool CPQueue::front(QueueElementType& item)
{
    if (fronti == reari) {
        return false; // Queue is Empty
    }
    else {

    	fronti=nextPosition(fronti);
        item = queuearray[fronti];
        fronti=prevPosition(fronti);
        return true;
    }
}


bool CPQueue::isEmpty()
{
    return bool(reari == fronti);
}


int CPQueue::nextPosition(int pointer)
{
    return ((pointer + 1) % maxQueue);
}


int CPQueue::prevPosition(int pointer)
{
    return ((pointer+maxQueue-1) % maxQueue);
}


bool CPQueue::isfull()
{
	 if (nextPosition(reari) == fronti) {
		        return true; // Queue is Full
		    									}
	 else {return false ;}
}

bool CPQueue::isWaiting(QueueElementType& item)
{
	if ((fronti == reari)){
		// if queue is empty
	return false ;
	}
	else{
  int i =nextPosition(fronti) ;
  bool found=0 ;
  while (i!=nextPosition(reari)){
	  if(queuearray[i]==item){
		  found=1 ;break ;
	  }
	  i=nextPosition(i);
  }
  if(found){return true ;}
  else{return false ;}
}
}




int main(int argc ,char*argv[]) {

bool sflagerror=0;
bool wflagerror=0;
bool iflagerror=0;
bool pflagerror=0;
bool wrongoperation=0;
int seqnumbits=-1 ;
int winsize=-1 ;
    initseq=-1 ;
int maxseqnu=-1;

if (argc>4){
// seqnum check
	for(int i=0 ;argv[1][i]!='\0';i++)
	if(!isdigit((argv[1][i]))){
		sflagerror=1; wrongoperation=1;
		cout<<"Invalid seqNumBits";
	break ;}
	if(!sflagerror&&stoi(argv[1])<=0) {sflagerror=1; wrongoperation=1; cout<<"Invalid seqNumBits";}

	if(!sflagerror){ seqnumbits=stoi(argv[1]); 	maxseqnu=pow(2,seqnumbits);}
//winsize check
	for(int i=0 ;argv[2][i]!='\0';i++)
		if(!isdigit((argv[2][i])))
		{	if(sflagerror){cout<<" ";}
		 wflagerror=1; wrongoperation=1;
			cout<<"Invalid winSize";
			break ;}
	if((!wflagerror&&stoi(argv[2])<=0)||(!wflagerror&&(seqnumbits>0)&&stoi(argv[2])>(pow(2,seqnumbits)-1))) { wflagerror=1; wrongoperation=1;if(sflagerror){cout<<" ";} cout<<"Invalid winSize";}
	if(!wflagerror){winsize=stoi(argv[2]);maxQueue=winsize;}
//intseq check
	for(int i=0 ;argv[3][i]!='\0';i++)
		if(!isdigit((argv[3][i]))){
			if(sflagerror||wflagerror){cout<<" ";}
			iflagerror=1; wrongoperation=1;
			cout<<"Invalid initSeq";
		break ;}
	if((!iflagerror&&stoi(argv[3])<0) ||(!iflagerror&&!sflagerror&&stoi(argv[3])>=maxseqnu)) { iflagerror=1;if(sflagerror||wflagerror){cout<<" ";} cout<<"Invalid initSeq";}
	if(!iflagerror){initseq=stoi(argv[3]);}
//pids check
for(int i=4;i<argc;i++){
	for(int j=0 ;argv[i][j]!='\0';j++)
							{
		if(!isdigit((argv[i][j]))){
			if(sflagerror||wflagerror||iflagerror){cout<<" ";}
				pflagerror=1; wrongoperation=1;
				cout<<"Invalid packet ID";
			break ;}
										}

					if(pflagerror){break ;}
		if(!pflagerror){
			if(maxseqnu!=-1){
			if(atoi(argv[i])>=maxseqnu){pflagerror=1; wrongoperation=1;
			if(pflagerror&!sflagerror&!wflagerror&!iflagerror){ cout<<"Invalid packet ID";break ;}
			if(pflagerror||sflagerror||wflagerror||iflagerror){cout<<" "; cout<<"Invalid packet ID";break ;}

											}
		                                      }
												}
													}

if(!wrongoperation){

	CPQueue waiting;
    int item=0;
    int x=-1;

	int sizesTX=argc-4;
	int TX[sizesTX];
    int RX[sizesTX];

    string dropped="" ;
    int E=initseq ;
    int rxindex=0;
    int maxwinlim=0;




    bool maxwinlimrestart=0;



// getting all tx values
    for(int i=4;i<argc;i++ ) {TX[i-4]=atoi(argv[i]) ; }


//setting maxwindows limit initially
 if(E+winsize-1>maxseqnu-1){maxwinlim=E-maxseqnu+(winsize-1); maxwinlimrestart=1;} //restart of max limit t0 zero happened
 else{maxwinlim=E+(winsize-1); maxwinlimrestart=0;} //no restart

 // loop on tx to classify elements
 for(int i=0;i<sizesTX;i++ ){

	if( waiting.isWaiting((TX[i]))){dropped=dropped+" "+to_string(TX[i]);continue; }

while(1){
	 //getting item out of the waiting list if it was the expected item
	 if(waiting.front(x)){ //if there is an element in the queue
		 if(E==x){
		waiting.dequeue(x);
		 RX[rxindex]=x;
		 E++; 	rxindex++ ;
		 if(E>maxseqnu-1){ E=0; }
		 if(E+winsize-1>maxseqnu-1){maxwinlim=E-maxseqnu+(winsize-1); maxwinlimrestart=1;} //restart of max limit t0 zero happened
		 else{maxwinlim=E+(winsize-1); maxwinlimrestart=0;} //no restart
		 	 //to search only in the newseq part for repeated elements
		 // we dont continue here as we will skip an element if we do so

		 	 	 	 	 	 	 	 	 	 	 	 	 }

	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 }
  x=-1;	 waiting.front(x);
	  if(x!=E){break ;}																	}
//the last condition is used to break this loop when the element at front is not expected

	 if(maxwinlimrestart){  // in this range the maxwin limit has been restarted to zero and E>maxwinlim
		 if((TX[i]>=E&&TX[i]<=maxseqnu)||(TX[i]>=0&&TX[i]<=maxwinlim)){  //in this range i can recieve/wait or drop (due to repeatition)
			 if(TX[i]==E){
				 RX[rxindex]=TX[i];
				 E++; 	rxindex++ ;
				 if(E>maxseqnu-1){ E=0;  } //wrapping has happened 	//dont no yet what to do with wrapping flag
				 if(E+winsize-1>maxseqnu-1){maxwinlim=E-maxseqnu+(winsize-1); maxwinlimrestart=1;} //restart of max limit t0 zero happened
				 else{maxwinlim=E+(winsize-1); maxwinlimrestart=0;} //no restart

			 	 //to search only in the newseq part for repeated elements
				 continue; 	 	 	 	 	 }




			 if(TX[i]!=E){
			 if(waiting.front(x)){if(TX[i]==x){dropped=dropped+" "+to_string(TX[i]);continue;}}
             if(waiting.isfull()){dropped=dropped+" "+to_string(TX[i]);continue;}
			 waiting.enqueue(TX[i]); continue;}
			 //putting item in the waiting list as it was not the expected item yet it falls in the windows limit
			 //and is not recieved yet in the current sequence

		 	 	 	 	 	 	 	 	 	    		}

		 else{ //in this range I drop due to  window limits  condition break
			 dropped=dropped+" "+to_string(TX[i]); 	 continue;
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	}
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 }
	 else{// this is the acceptable winlim when receiving  E<maxwinlim
		 if(TX[i]>=E&&TX[i]<=maxwinlim){ //in this range i can recieve/wait or drop (due to repeatition)
			 if(TX[i]==E){
						 RX[rxindex]=TX[i];
						 E++; 	rxindex++ ;
						 if(E>maxseqnu-1){ E=0; } //wrapping has happened 	//dont no yet what to do with wrapping flag
						 if(E+winsize-1>maxseqnu-1){maxwinlim=E-maxseqnu+(winsize-1); maxwinlimrestart=1;} //restart of max limit t0 zero happened
						 else{maxwinlim=E+(winsize-1); maxwinlimrestart=0;} //no restart
					 	 //to search only in the newseq part for repeated elements
						 continue; 	 	 	 	 	 }




					 if(TX[i]!=E){
					 if(waiting.front(x)){if(TX[i]==x){dropped=dropped+" "+to_string(TX[i]);continue;}}
					   if(waiting.isfull()){dropped=dropped+" "+to_string(TX[i]);continue;}
					 waiting.enqueue(TX[i]); continue;

					 }
					 //putting item in the waiting list as it was not the expected item yet it falls in the windows limit
					 //and is not recieved yet in the current sequence
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	}
		 else{ //in this range I dropped the element  due to  window limits condition breach
					 dropped=dropped+" "+to_string(TX[i]); 	 continue;
				 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	}

	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 }

 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 }

 while(waiting.front(x)){
	 if(E==x){
		 waiting.dequeue(x);
		 		 RX[rxindex]=x;
		 		 E++; 	rxindex++ ;
		 		 if(E>maxseqnu-1){ E=0; }
		 		 if(E+winsize-1>maxseqnu-1){maxwinlim=E-maxseqnu+(winsize-1); maxwinlimrestart=1;} //restart of max limit t0 zero happened
		 		 else{maxwinlim=E+(winsize-1); maxwinlimrestart=0;} //no restart

	 }

	 else break;
 }

 



 cout<<"R"<<" ";
 for(int i=0 ;i<rxindex;i++){
	 cout<<RX[i]<<" ";
 }

 cout<<"E"<<" ";
  cout<<E<<" ";

 cout<<"W"<<" ";
 while (waiting.dequeue(item)) {
	             cout << item <<" ";
	         }

 cout<<"D";
 cout<<dropped;

																				}
																							 }
else {
	cout<<"Invalid number of arguments ";
	// seqnum check
	if(argc>=2){
		for(int i=0 ;argv[1][i]!='\0';i++)
		if(!isdigit((argv[1][i]))){
			sflagerror=1; wrongoperation=1;
			cout<<"Invalid seqNumBits";
		break ;}
		if(!sflagerror&&stoi(argv[1])<=0) {sflagerror=1; wrongoperation=1; cout<<"Invalid seqNumBits";}

		if(!sflagerror){ seqnumbits=stoi(argv[1]); 	maxseqnu=pow(2,seqnumbits);}
	}
	//winsize check
	if(argc>=3){
		for(int i=0 ;argv[2][i]!='\0';i++)
			if(!isdigit((argv[2][i])))
			{	if(sflagerror){cout<<" ";}
			 wflagerror=1; wrongoperation=1;
				cout<<"Invalid winSize";
				break ;}
		if((!wflagerror&&stoi(argv[2])<=0)||(!wflagerror&&(seqnumbits>0)&&stoi(argv[2])>(pow(2,seqnumbits)-1))) { wflagerror=1; wrongoperation=1;if(sflagerror){cout<<" ";} cout<<"Invalid winSize";}
		if(!wflagerror){winsize=stoi(argv[2]);maxQueue=winsize;}
	}
	//intseq check
	if(argc>=4){
		for(int i=0 ;argv[3][i]!='\0';i++)
			if(!isdigit((argv[3][i]))){
				if(sflagerror||wflagerror){cout<<" ";}
				iflagerror=1; wrongoperation=1;
				cout<<"Invalid initSeq";
			break ;}
		if((!iflagerror&&stoi(argv[3])<0) ||(!iflagerror&&!sflagerror&&stoi(argv[3])>=maxseqnu)) { iflagerror=1;if(sflagerror||wflagerror){cout<<" ";} cout<<"Invalid initSeq";}
		if(!iflagerror){initseq=stoi(argv[3]);}
			}
}


	return 0;
}

