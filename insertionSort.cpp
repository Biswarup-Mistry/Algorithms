#include<iostream>
#include<stdlib.h>
using namespace std;

class insertion{
	private :
		int n,*a;
	public :
		insertion(int size);
		void array();
		void insertionSort();
		void display();
};

insertion :: insertion(int size){
	n=size;
	a=new int[n];
}

void insertion :: array(){
	int i;
	cout<<"Enter now ==>>"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
}

void insertion :: insertionSort(){
	int val,i,j;
	for(i=0;i<n;i++){
		val=a[i];
		j=i-1;
		while((j>=0) && (val<a[j])){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=val;
	}
}

void insertion :: display(){
	int i;
	for (i=0;i<n;i++){
		cout<<"a["<<i<<"] ==>>"<<a[i]<<endl;
	}
}


int main(){
	system("clear");
	int opt,size;
	cout<<"\t***Welcome to the Insertion Sort***"<<endl;
	cout<<"Enter the size of the Array ==>>"<<endl;
	cin>>size;
	insertion i(size);
	do{
		cout<<"\tMENU"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"1. Enter the Elements"<<endl;
		cout<<"2. Apply insertonSort"<<endl;
		cout<<"3. Display"<<endl;
		cin>>opt;
		switch(opt){
			case 0:
			break;
			case 1:
			i.array();
			break;
			case 2:
			i.insertionSort();
			break;
			case 3:
			i.display();
			break;
			default:
			cout<<"Wrong Choise... Choose Again..."<<endl;
			break;
		}
	}while(opt!=0);
	return 0;
}