#include<iostream>
#include<stdlib.h>
using namespace std;

class mergesort{
	private :
		int *a,*c,n;
	public :
		mergesort(int size);
		void array();
		void mergeSort(int low,int high);
		void merge(int low,int mid,int high);
		void display();

};

mergesort :: mergesort(int size){
	n=size;
	a=new int[n];
	c=new int[n];
}

void mergesort :: array(){
	int i;
	cout<<"Enter Now ==>>"<<endl;
	for(i=0;i<n;i++){		//entering the elements into the array 'a'
		cin>>a[i];
	}
	for(i=0;i<n;i++){				//intitialization of array 'c'
		c[i]=0;
	}
}

void mergesort :: mergeSort(int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergeSort(low,mid);		//for left side of the array
		mergeSort(mid+1,high);		//for right side of the array
		merge(low,mid,high);		//for sorting the two arrayes
	}
}

void mergesort :: merge(int low,int mid,int high){
	int i,j,k,p;
	i=low;
	j=mid+1;
	k=0;
	while((i<=mid)&&(j<=high)){		//copy the elements in sorted ordered
		if(a[i]<a[j]){
			c[k]=a[i];
			i=i+1;
			k=k+1;
		}
		else{
			c[k]=a[j];
			j=j+1;
			k=k+1;
		}
	}
	if((i<=mid)&&(j>high)){		//to copy the reast of the elements from i=low to mid
		while(i<=mid){
			c[k]=a[i];
			i=i+1;
			k=k+1;
		}
	}
	else if((i>mid)&&(j<=high)){	//to copy the reast of the elements from j=mid+1 to high
		while(j<=high){
			c[k]=a[j];
			j=j+1;
			k=k+1;
		}
	}
	for(p=0;p<k;p++){
		a[low+p]=c[p];	//for copy the elements from one array to another
	}
}

void mergesort :: display(){
	int i;
	for(i=0;i<n;i++){
		cout<<"a["<<i<<"] ==>> "<<a[i]<<endl;	//displaying the elements of the array 'a'
	}
}

int main(){
	system("clear");
	int size,opt;
	cout<<"\t***Welcome to the Merge Sort***\nEnter the Size of the array ==>>"<<endl;
	cin>>size;
	mergesort m(size);
	do{
		cout<<"\tMENU"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"1. Enter the Elements of the Array"<<endl;
		cout<<"2. Apply Merge Sort"<<endl;
		cout<<"3. Display"<<endl;
		cin>>opt;
		switch(opt){
			case 0:
			break;
			case 1:
			m.array();
			break;
			case 2:
			m.mergeSort(0,size-1);	//in algorithm(theories) we start form i=1 to n, but not here.
			cout<<"\tDone..."<<endl;
			break;
			case 3:
			m.display();
			break;
			default:
			cout<<"Wrong Choise... Choose Again..."<<endl;
			break;
		}
	}while(opt!=0);
	cout<<"Exiting..."<<endl;
	return 0;
}