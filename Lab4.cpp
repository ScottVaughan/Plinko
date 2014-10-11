
/*
	Scott Vaughan 
	Oct. 2013
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>


using namespace std; 

int main (){   
	string input;
	double slot;

	do{	
	srand(time(NULL));
	cout<<"\"S\" to drop one chip\n";
	cout<<"\"M\" to drop multiple chips\n";
	cout<<"\"Q\"to Quit\n";
	cin>>input;

	if (input=="S"){
		cout<<"select a slot to drop chip ";
		cin>>slot;
		if (slot>=0 && slot<=8){
			cout<<slot<<" ";
			for (int i=0;i<12;i++){
				if(slot==8){
					slot = slot-0.5;
				}
				else if(slot==0){
					slot = slot+0.5;
				}
				else{	
					int random_numbers=rand()%2+0;
					if (random_numbers==1){
					slot=slot +0.5;
					}
					else{	
					slot=slot-0.5;
					}
				}
				cout<< slot<<" ";
			}
			if(slot==0||slot==8)
				cout<<"You won $100"<<endl;
			else if (slot==1||slot==7)
				cout<<"You won $500"<<endl;
			else if (slot==2||slot==6)
				cout<<"You won $1000"<<endl;
			else if (slot==3||slot==5)
				cout<<"You won $0"<<endl;
			else if (slot==4)
				cout<<"You won $10000"<<endl;
		}
	}
	else if (input=="M"){	
		int chips;
		cout<<"number of chips to drop: ";
		cin>>chips;

		if (chips>0){
			double slots;
			cout<<"select a slot to drop chips: ";
			cin>>slots;
			double temp=slots;

			if (slots>=0 && slots<=8){
				int Total=0;
				for(int k=0; k<chips; k++)
				{
					for (int i=0;i<12;i++){
						if(slots==8){
							slots = slots-0.5;
						}
						else if(slots==0){
							slots = slots+0.5;
						}
						else{	
							int random_numbers=rand()%2+0;
							if (random_numbers==1){
								slots=slots +0.5;
							}
							else{	
								slots=slots-0.5;
							}
						}
					}
					if(slots==0||slots==8)
					Total=Total+100;
					else if (slots==1||slots==7)
					Total=Total+500;
					else if (slots==2||slots==6)
					Total=Total+1000;
					else if (slots==3||slots==5)
					Total=Total+0;
					else if (slots==4)
					Total=Total+10000;
					slots = temp;
				}
				int Average=Total/chips;
				cout<<"Total: "<<Total<<"\tAverage: "<<Average<<"\n";
			}	
		}
	}	
	}
	while (input!="Q");
	system ("pause");
	return 0;
}




