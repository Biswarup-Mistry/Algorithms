#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

class radix{
	private :
		int n,*a,*b,*d;
		int m=10;
	public:
		radix(int size);
		void array();
		void radixSort();
		void countingSort(int l);
		int getmax();
		void display();
};

radix :: radix(int size){
	n=size;
	a=new int[n];
	d=new int[n];
}

void radix :: array(){
	int i,max;
	cout<<"Enter Now ==>>"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		d[i]=0;
	}
	b=new int[m];
}

int radix :: getmax(){
	int max,i;
	max=a[0];
	for(i=1;i<n;i++){
		if(max<a[i])
			max=a[i];
	}
	return max;
}

void radix :: radixSort(){
	int max;
	int l=1;
	max=getmax();
	int	h=max/l;
	while(h>0){
		countingSort(l);
		l=l*10;
		h=max/l;
	}
	cout<<"Done (Radix Sort)..."<<endl;
}

void radix :: countingSort(int l){
	int i,k=0;
	for(i=0;i<m;i++){
		b[i]=0;
	}
	for(i=0;i<n;i++){
		k=(a[i]/l)%10;
		b[k]=b[k]+1;
	}
	for(i=1;i<m;i++){
		b[i]=b[i-1]+b[i];
	}
	for(i=n-1;i>=0;i--){
		k=(a[i]/l)%10;
		d[b[k]-1]=a[i];
		b[k]--;
	}
	for(i=0;i<n;i++){
		a[i]=d[i];
	}
}

void radix :: display(){
	int i;
	cout<<"========a[]========="<<endl;
	for(i=0;i<n;i++){
		cout<<"a["<<i<<"] ==> "<<a[i]<<endl;
	}
	cout<<"===================="<<endl;
}

int main(){
	system("clear");
	int opt,size;
	cout<<"***Welcome to the Radix Sort***"<<endl;
	cout<<"Enter the size of the Array ==>>"<<endl;
	cin>>size;
	radix r(size);
	do{
		cout<<"\tMENU"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"1. Enter the Elements"<<endl;
		cout<<"2. Apply Radix Sort"<<endl;
		cout<<"3. Display"<<endl;
		cin>>opt;
		switch(opt){
			case 0:
			break;
			case 1:
			r.array();
			break;
			case 2:
			r.radixSort();
			break;
			case 3:
			r.display();
			break;
			default:
			cout<<"Wrong Choise... Choose Again..."<<endl;
			break;
		}
	}while(opt!=0);
	return 0;
}