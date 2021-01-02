#include<iostream>
#include<stdlib.h>
using namespace std;

class quick{
	private:
		int *a,n;
	public:
		quick(int size);
		void array();
		void quickSort(int low,int high);
		int partition(int low,int high);
		void display();
};

quick :: quick(int size){
	n=size;
	a= new int[n];
}

void quick :: array(){
	int i;
	cout<<"Enter now ==>>"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
}

void quick :: quickSort(int low,int high){
	int p;
	if(low<high){
		p=partition(low,high);	//getting the position of a sorted element which is exactly present to it's right place
		quickSort(low,p-1);		//for the left unsorted array	
		quickSort(p+1,high);	//for the right one
	}
}

int quick :: partition(int low,int high){
	int i,j,p;
	i=low;
	j=high;
	p=a[i];
	while(i<j){		//for one low element, we have see it's right position as well as other elements right position
		while(p>=a[i]){		//if p is greater than or equals to the a[i]
			i=i+1;
		}
		while(p<a[j]){		//if p is less than or equals to the a[i]
			j=j-1;
		}
		if(i<j){				//if (i<j)=>there exist two elements which has to be swapped for their own right positions
			int temp=a[i];		//i.e., ((a[i]->a[j])&&(a[j]->a[i]))
			a[i]=a[j];
			a[j]=temp;
		}
	}
	int temp=a[low];	//after swapping of the other elements to thier own respective positions, we have to swap the p 
	a[low]=a[j];		//to it's own right position i.e., (j=((p>(low-(p-1)) && (p<(high-p-1))))=>j is the right position
	a[j]=temp;			//for p.
	return(j);			//returning the right position of p i.e., j
}

void quick :: display(){
	int i;
	for(i=0;i<n;i++){
		cout<<"a["<<i<<"] => "<<a[i]<<endl;
	}
}

int main(){
	system("clear");
	int size,opt;
	cout<<"\t***Welcome To the Quick Sort***"<<endl;
	cout<<"Enter the Size of the Array ==>>"<<endl;
	cin>>size;
	quick q(size);
	do{
		cout<<"\tMENU"<<endl;
		cout<<"0. Eixt"<<endl;
		cout<<"1. Enter the Elements into the Array"<<endl;
		cout<<"2. Apply Quick Sort"<<endl;
		cout<<"3. Display"<<endl;
		cin>>opt;
		switch(opt){
			case 0:
			break;
			case 1:
			q.array();
			break;
			case 2:
			q.quickSort(0,size-1);
			cout<<"Done..."<<endl;
			break;
			case 3:
			q.display();
			break;
			default:
			cout<<"Wrong Choise... Choose Again..."<<endl;
			break;
		}
	}while(opt!=0);
	cout<<"Exiting..."<<endl;
	return 0;
}