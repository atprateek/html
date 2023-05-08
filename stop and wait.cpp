#include<iostream>
#include <unistd.h>
#include<time.h>
#include<cstdlib>
using namespace std;
int main()
{
	string data;int k=0,f;
	srand(time(NULL));
	cout<<"Enter the data"<<endl; 
	cin>>data;
	for(int i=0;i<data.length();i++)
	{f=0;
	 cout<<"Frame no "<<i+1<<" is sent Waiting for Acknowledgement"<<endl;
	 cout<<endl;
	 while(f!=1)
	   {
    		k=rand() % 3+1;      	
		  	sleep(4);
		  	switch(k){
		  		case 1:
		  			cout<<"\n Delayded TIMEOUT!!!!!!!!!!!!!!"<<endl;
		  			cout<<"SENDING frame "<<i+1<<" again"<<endl;
		  			cout<<"Please Wait "<<endl;
		  			break;
		    	case 2:
					cout<<"\n Acknowledgement for Frame no "<<i+1<<" is Received"<<endl;
					cout<<endl;
					f=1;
					cout<<endl;
					break;
				case 3:
					cout<<"\n Acknowledgement for Frame no "<<i+1<<" is not received"<<endl;
					cout<<"Please Wait "<<endl;
					break;
					cout<<endl;
				}}}
		cout<<"All frames sent succesfully"<<endl;
		return 0;
	}
