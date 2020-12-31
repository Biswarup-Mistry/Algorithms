#include<iostream>
#include<stdlib.h>
using namespace std;

class counting{
	private:
		int s,n,*a,*b,*c,*d;	
	public:
		int max,p=1,l=0,m=1;
		counting(int size);
		void array();
		void countingSort();
		void display1();
		void display2();
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
	}
	max=a[0];

	for(i=1;i<n;i++){	//getting the maximum number from the array a
		if(a[i]>max)
			max=a[i];
	}

	while(max!=0){	//the size of the maximum number
		max=max/10;
		l=l+1;
	}

	while(l!=0){	//getting the size of the array according to the size of the maximum number
		m=m*10;
		l=l-1;
	}


	b=new int[m];	//m 'cause for maximum number on the array
	c=new int[m];	//m 'cause for maximum number on the array


	for(i=0;i<m;i++){
		b[i]=0;
		c[i]=0;
	}
	s=n+1;	//there will be an extra block for decimal number
	for(i=0;i<s;i++){
		d[i]=0;
	}

}

void counting :: countingSort(){
	int i;
	for(i=0;i<n;i++){	//count the repeated numbers
		b[a[i]]=b[a[i]]+1;
	}
	for(i=1;i<m;i++){	//for how much space is there after inserting an element into the array d
		c[i]=b[i]+c[i-1];
	}
	for(i=n;i>=0;i--){	//i=n to 0 for accuracy
		int k=a[i];
		d[c[k]]=k;
		c[k]=c[k]-1;
	}
	cout<<"Done (Counting Sort)"<<endl;
}

void counting :: display2(){
	int i;
	cout<<"b ==>>"<<endl;
	for(i=0;i<m;i++){
		cout<<"b["<<i<<"] ==>> "<<b[i]<<endl;
	}
	cout<<"c ==>>"<<endl;
	for(i=0;i<m;i++){
		cout<<"c["<<i<<"] ==>> "<<c[i]<<endl;
	}

}


void counting :: display1(){
	int i;
	cout<<"a ==>>"<<endl;
	for(i=0;i<n;i++){
		cout<<"a["<<i<<"] ==>> "<<a[i]<<endl;
	}
	cout<<"d ==>>"<<endl;
	for(i=0;i<s;i++){
		cout<<"d["<<i<<"] ==>> "<<d[i]<<endl;
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
		cout<<"4. display2"<<endl;
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
			case 4:
			c.display2();
			break;
			default:
			cout<<"Wrong Choise... Choose Again..."<<endl;
			break;
		}

	}while(opt!=0);
	return 0;
}