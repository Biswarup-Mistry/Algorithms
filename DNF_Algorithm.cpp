/*
The swap function runs on O(1) time,
the sort function runs on O(n) time,
so, the total time requires for running the DNF algorithm is O(n) .
(This is a linear time sorting algorithm, created because of pure boredom)
;-p
*/


#include <iostream>
using namespace std;

class DNF{
    private :
    int *arr;
    public :
    int n;
    DNF(int size);
    void array();
    void swap(int num1,int num2);
    void sort();
    void display();
};

DNF :: DNF(int size){
    n=size;
    arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
}

void DNF :: array(){
    int i;
    cout<<"Enter the elements of the array now ==>>"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
}

void DNF :: swap(int num1,int num2){
    int k;
    k=arr[num1];
    arr[num1]=arr[num2];
    arr[num2]=k;
}

void DNF :: sort(){
    int i,l,m,h;
    h=n-1;
    l=m=0;
    while(m!=h){
        if(arr[m]==1)
            m++;
        else if(arr[m]==0){
            swap(m,l);
            l++;
            m++;
        }
        else 
        
        if(arr[m]==2){
            swap(m,h);
            h--;
        }
    }

}

void DNF :: display(){
    int i;
    for(i=0;i<n;i++){
        cout<<"a["<<i<<"] ==>> "<<arr[i]<<endl;
    }
}

int main(){
    system("cls");
    cout<<"\tWelcome to the DNF Sort"<<endl;
    cout<<"Enter the size of the Array"<<endl;
    int size,opt;
    cin>>size;
    DNF d(size);
    do{
        cout<<"\tMENU"<<endl;
        cout<<"0 := Quit Programe"<<endl;
        cout<<"1 := Enter the elements into the array"<<endl;
        cout<<"2 := Run the DNF Sort Algorithm"<<endl;
        cout<<"3 := Display the array"<<endl;
        //cout<<"0 := Quit Programe"<<endl;
        cin>>opt;
        switch(opt){
            case 0:
            break;
            case 1:
            d.array();
            break;
            case 2:
            d.sort();
            break;
            case 3:
            d.display();
            break;
            default:
            cout<<"Wrong Choice... Choose again..."<<endl;
            break;
        }
    }while(opt!=0);
    cout<<"Quiting the program..."<<endl;
    return (0);
}