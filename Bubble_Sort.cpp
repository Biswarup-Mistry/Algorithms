#include<iostream>
#include<stdlib.h>
using namespace std;

class bubbleSort{
	private:
		int n,*a,comp=0,swap=0;
	public:
		bubbleSort(int size);
		void BubbleSort();
		void Array();
		void display();
		int count_swap(int data);
		int count_comparision(int data);

};

bubbleSort :: bubbleSort(int size){
	n= size;
	a= new int[n];
}

void bubbleSort :: Array(){
	int i;
	cout<<"Enter the elements of the Array ==>>"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
}

int bubbleSort :: count_comparision(int data){
	int count=data;
	count++;
	return(count);
}

int bubbleSort :: count_swap(int data){
	int swap=data;
	swap++;
	return(swap);
}

void bubbleSort :: BubbleSort(){
	int i,j,temp;
	for (i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap=count_swap(swap);
			}
			comp=count_comparision(comp);
		}
	}
}

void bubbleSort :: display(){
	int i;
	for(i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	cout<<"Total No. of Comparision ==>> "<<comp<<endl<<"Total No. of Swap ==>> "<<swap<<endl;
}


int main(){
	system("clear");
	int size;
	cout<<"***Welcome to the BUbble Sorting Algorithm ***"<<endl;
	cout<<"Enter the Size of the Array ==>>"<<endl;
	cin>>size;
	bubbleSort b(size);
	b.Array();
	cout<<"Befor Sorting with Bubble Sort ==>>"<<endl;
	b.display();
	b.BubbleSort();
	cout<<"After Sorting with Bubble Sort ==>>"<<endl;
	b.display();
	return 0;
}