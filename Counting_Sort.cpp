#include<iostream>
#include<stdlib.h>
using namespace std;

class counting{
	private:
		int n,*a,*b,*d;	
		int m=10;
	public:
		int max,p=1,l=0;
		counting(int size);
		void array();
		void countingSort();
		void display1();
};

counting :: counting(int size){
	n=size;
	a= new int[n];
	d= new int[n];
}

void counting :: array(){
	int i;
	cout<<"Enter now... ==>>"<<endl;
	for(i=0;i<n;i++){	//getting the numbers into the array a
		cin>>a[i];
		d[i]=0;
	}
	b=new int[m];	//m is a constant
	for(i=0;i<m;i++){
		b[i]=0;
	}
}

void counting :: countingSort(){
	int i;
	for(i=0;i<n;i++){	//count the repeated numbers
		b[a[i]]=b[a[i]]+1;
	}
	for(i=1;i<m;i++){	//for how much space is there after inserting an element into the array d
		b[i]=b[i]+b[i-1];
	}
	for(i=n-1;i>=0;i--){	//creating the output array with sorted elements
		int k=a[i];
		d[b[k]-1]=k;
		b[k]=b[k]-1;
	}
	for(i=0;i<n;i++){
		a[i]=d[i];
	}
	cout<<"Done (Counting Sort)"<<endl;
}

void counting :: display1(){
	int i;
	cout<<"a ==>>"<<endl;
	for(i=0;i<n;i++){
		cout<<"a["<<i<<"] ==>> "<<a[i]<<endl;
	}
}

int main(){
	system("clear");
	int size,opt;
	cout<<"***Welcome to the Counting Sort***\nEnter the array size"<<endl;
	cin>>size;
	counting c(size);
	do{
		cout<<"\tMenu\t"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"1. Enter the Elements"<<endl;
		cout<<"2. Apply Counting Sort on the array"<<endl;
		cout<<"3. display1"<<endl;
		//cout<<"4. display2"<<endl;
		cin>>opt;
		switch(opt){
			case 0:
			break;
			case 1:
			c.array();
			break;
			case 2:
			c.countingSort();
			break;
			case 3:
			c.display1();
			break;
			default:
			cout<<"Wrong Choise... Choose Again..."<<endl;
			break;
		}

	}while(opt!=0);
	return 0;
}