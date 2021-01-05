//time complexity of the algorithm is C(Constant).  
#include<iostream>
using namespace std;

int main(){
	int a,temp,b;
   	cout<<"Enter a => ";
	cin>>a;
	cout<<"Enter b =>";
	cin>>b;
	temp = a;
   	a = b;
   	b = temp;
	cout<<"a ==> "<<a<<"\nb ==> "<<b<<endl;
	return 0;
}
