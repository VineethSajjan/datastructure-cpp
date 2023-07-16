#include<iostream>
using namespace std;
class node{
	int data;
	public:
	node*next, *prev;
	node(int d){
		data=d;
		next=NULL;
		prev=NULL;	
	}
	void display(){
		cout<<data<<endl;
	}
};
class DLL{
	public:
	node *hptr=NULL;
	node *tptr=NULL;
	void add(int d){
		node *temp=hptr;
		node *nptr=new node(d);
		if(hptr == NULL){
			hptr=tptr=nptr;
		}
		else{
			tptr->next=nptr;
			nptr->prev=tptr;
			tptr=nptr;
		}
	}
	void forward_display(){
		node *temp=hptr;
		while(temp!=NULL){
			temp->display();
			temp=temp->next;
		}
	}
};
int main(){
	DLL l;
	l.add(10);
	l.add(20);
	l.add(30);
	l.add(40);
	l.add(50);
	l.add(60);
	l.forward_display();
}
