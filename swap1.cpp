#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cout<<"Enter a ="<<endl;
    cin>>a;
    cout<<"Enter b ="<<endl;
    cin>>b;
    c=a;
    a=b;
    b=c;
    cout<<"a = "<<a<<" b = "<<b<<endl;
    return(0);
}