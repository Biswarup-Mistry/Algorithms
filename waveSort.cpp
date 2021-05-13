#include<iostream>
using namespace std;

class waveSort{
    private:
    int n,*a;
    public :
    waveSort(int size);
    void swap(int num1,int num2);
    void sort();
    void array();
    void display();
};

waveSort :: waveSort(int size){
    n=size;
    a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=0;
    }
}

void waveSort :: swap(int num1,int num2){
    int k,b,c;
    k=num1;
    b=num2;
    c=a[k];
    a[k]=a[b];
    a[b]=c;
}

void waveSort :: array(){
    cout<<"Enter the Elements now ==>>"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

void waveSort :: sort(){
    int i;
    for(i=1;i<n-1;i+=2){
        if(a[i]>a[i-1]){
            swap(i,i-1);
        }
        if(a[i]>a[i+1]){
            swap(i,i+1);
        }
    }
}

void waveSort :: display(){
    cout<<"The Element(s) in the Array are ==>>"<<endl;
    for (int i=0;i<n;i++){
        cout<<"arr["<<i<<"] => "<<a[i]<<endl;
    }
}

int main(){
    int n,opt;
    cout<<"Enter the size of the Array : "<<endl;
    cin>>n;
    waveSort w(n);
    do{
		cout<<"\tMenu\t"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"1. Enter the Elements"<<endl;
		cout<<"2. Apply Wave Sort on the array"<<endl;
		cout<<"3. display"<<endl;
		//cout<<"4. display2"<<endl;
		cin>>opt;
		switch(opt){
			case 0:
			break;
			case 1:
			w.array();
			break;
			case 2:
			w.sort();
			break;
			case 3:
			w.display();
			break;
			default:
			cout<<"Wrong Choise... Choose Again..."<<endl;
			break;
		}

	}while(opt!=0);
    return (0);
}