//Avarage time complexity of Bucket Sort is O(n), but in this code, it turns into T(n)>O(n)

#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

struct node{
	int key;			//no. of a node
	double data;		//the data of a node
	node *left;			//left link
	node *right;		//right link
};

class bucket{
	private:
		int n,k=10,j=0;
		double *a;
	public:
		node *head1=NULL;
		node *last1=NULL;
		node *roy=NULL;												//for safty purposes
		bucket(int size);
		void array();												//for insert the elements into the array a and create the Bucket
		bool isEmpty(node *&head);									//for check if the head is NULL or not
		node*& getnode1(node *&head1,node *&last1,int data);		//for create the first Bucket
		node*& insert1(node *&head1,node *&last1,int data);			//for create the other Buckets
		node*& getnode(node *&head,node *&last,double data);		//for create the first node of a Bucket
		node*& insert(node *&head,node *&last,double data);			//for create the other nodes of a Bucket
		void bucketSort(node *&head,node *&last);					//sort the array a with the help of Buckets
		void insertionSort(node *&head);							//sort the nodes of a perticular Bucket
		node*& searchLast(node *&head,node *&last);					//gives the last of a linked list of a Bucket
		void concatinate(node *&head1);								//concatinate the nodes of the Buckets into the array
		void display(node *&head);									//just display the array and the Buckets
};

bucket :: bucket(int size){
	int i;
	n=size;
	a=new double[n];
	for(i=0;i<k;i++){
		head1=insert1(head1,last1,i);
	}
	roy=head1;
}

void bucket :: array(){
	int i;
	cout<<"Enter Now ==>>"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
}

bool bucket :: isEmpty(node *&head){
	if(head==NULL)
		return true;
	else
		return false;
}

node*& bucket :: getnode(node *&head,node *&last,double data){
	node *temp=new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	head=temp;
	last=temp;
	return head;
}

node*& bucket :: getnode1(node *&head1,node *&last1,int data){
	//cout<<"Inside getnode1 "<<data<<endl;
	node *temp=new node;
	temp->key=data;
	temp->right=NULL;
	temp->left=NULL;
	head1=temp;
	last1=temp;
	return head1;
	//cout<<"exit from getnode1"<<data<<endl;
}

node*& bucket :: insert1(node *&head1,node *&last1,int data){
	//cout<<"Inside Insert1 "<<data<<endl;
	if(isEmpty(head1)){
		head1=getnode1(head1,last1,data);
	}
	else{
		node *temp=new node;
		temp->key=data;
		temp->data=0.00;
		temp->right=NULL;
		temp->left=NULL;
		last1->right=temp;
		last1=temp;
	}
	//cout<<"exit from Insert1 "<<data<<endl;
	return head1;
}

node*& bucket :: insert(node *&head,node *&last,double data){
	if(isEmpty(head)){
		head=getnode(head,last,data);
	}
	else{
		node *temp=new node;
		temp->data=data;
		temp->key=0;
		temp->left=NULL;
		temp->right=head;
		head->left=temp;
		head=temp;	
	}
	return head;
}

node*& bucket :: searchLast(node *&head,node *&last){
	node *ptr=head;
	node *t=head->right;
	while(t!=NULL){
		ptr=t;
		t=t->right;
	}
	last=ptr;
	return last;
}

void bucket :: bucketSort(node *&head,node *&last){
	int s=0,i,g,p;
	double d;	
	node *h=head;
	node *l=last;
	node *t=new node;
	node *temp=head1;
	s=temp->key;
	for(i=0;i<n;i++){		//the time complexity of this for loop turn into O(n^2), but it should be O(n), I couldn't do that
		d=a[i];
		g=(d*n);
		//cout<<"g => "<<g<<endl;
		//cout<<"s1 = "<<s<<endl;
		while(s<g){
			temp=temp->right;
			s=temp->key;
			//cout<<"s = "<<s<<endl;
		}
		if((temp->left)==NULL){
			t=insert(h,l,d);
			temp->left=t;
		}
		else if((temp->left)!=NULL){
			node *p=new node;
			p=NULL;
			l=searchLast(temp->left,p);
			t=insert(temp->left,l,d);
			temp->left=t;
		}
		s=0;
		d=0;
		g=0;
		t=NULL;
		temp=head1;
		h=NULL;
		l=NULL;
	}
	node *ptr=head1;
	while(ptr!=NULL){
		if((ptr->left)!=NULL){
			//cout<<"Inside loop"<<endl;
			insertionSort(ptr->left);
		}
		ptr=ptr->right;
	}
	select;ptr;
	concatinate(head1);
	cout<<"[.]Successfully sorted with Bucket Sort[.]"<<endl;
}


void bucket :: insertionSort(node *&head){
	int i;
	double val,d;
	node *ptr=head;
	while(ptr!=NULL){
		//cout<<"Inside InsertionSort"<<endl;
		node *t=ptr;
		node *t1=ptr->left; 
		val=t->data;
		while(t1!=NULL){
			d=t1->data;
			//cout<<"val = > "<<val<<endl;
			//cout<<"d = > "<<d<<endl;
			while((d>val) && (t1!=NULL)){
				t->data=d;
				t=t1;
				t1=t->left;
				if(t1!=NULL)
					d=t1->data;
				else
					d=0;
			}
			t->data=val;
		}
		t=NULL;
		select;t;
		t1=NULL;
		select;t1;
		ptr=ptr->right;
	}
	select;ptr;
}

void bucket :: concatinate(node *&head1){
	int s,u=0,i=0;
	node *temp=head1;
	while(temp!=NULL){
		cout<<"c"<<i<<endl;
		node *ptr=temp->left;
		while(ptr!=NULL){
			a[u]=ptr->data;
			u++;
			ptr=ptr->right;
		}
		ptr=NULL;
		select;ptr;
		temp=temp->right;
		i++;
	}
	temp=NULL;
	select;temp;
}

void bucket :: display(node *&head){
	int i;
	double d,val;
	cout<<"\t<<===== Array =====>>"<<endl;
	for (i=0;i<n;i++){
		cout<<"a["<<i<<"] => "<<a[i]<<endl;
	}
	cout<<"\t<<===== Bucket =====>>"<<endl;
	node *ptr=head1;
	while(ptr!=NULL){
		d=ptr->data;
		cout<<"b["<<ptr->key<<"] ==>> ";
		if((ptr->left)!=NULL){
				node *t=ptr->left;
				while(t!=NULL){
					val=t->data;
					cout<<"["<<val<<"]-->";
					t=t->right;
				}
				if(t==NULL)
					cout<<"[/]"<<endl;
			}
		else
			cout<<"[/]"<<endl;
		ptr=ptr->right;
	}
}

int main(){
	system("clear");
	node *head=NULL;
	node *last=NULL;
	int opt,size;
	cout<<"***Welcome to the Bucket Sort***"<<endl;
	cout<<"Enter the size of the Array ==>>"<<endl;
	cin>>size;
	bucket b(size);
	do{
		cout<<"\tMENU"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"1. Enter the Elements"<<endl;
		cout<<"2. Apply bucketSort"<<endl;
		cout<<"3. Display"<<endl;
		cin>>opt;
		switch(opt){
			case 0:
			break;
			case 1:
			b.array();
			break;
			case 2:
			b.bucketSort(head,last);
			break;
			case 3:
			b.display(head);
			break;
			default:
			cout<<"Wrong Choise... Choose Again..."<<endl;
			break;
		}
	}while(opt!=0);
	return 0;
}