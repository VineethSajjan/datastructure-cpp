#include<iostream>
using namespace std;
class node{
	
	public:
		int data;
	node *next;
		node(int d){
			data=d;
			next=0;
		}
		void display(){
			cout<<data<<endl;
		}
};
class linkedlist{
	public:
		node *hptr=NULL;
		int length=0;
		void append(int d){
			node *temp=hptr;
			if(hptr == NULL){
				node *temp =new node(d);
				hptr=temp;
			}
			else{
				while(temp->next!=NULL){
					temp=temp->next;
				}
				node *nptr=new node(d);
				temp->next=nptr;
			}
			length++;
		}
		void forward_display(){
			node *temp=hptr;
			while(temp!=NULL){
				temp->display();
				temp=temp->next;
			}
		}
		void reverse_display(node *temp){
			node *prev=NULL;
			node *n;
			while(temp!=NULL){
				n=temp->next;
				temp->next=prev;
				prev=temp;
				temp=n;
			}
			hptr=prev;	
		}
		void delete_node(int d){
			node *temp=hptr;
			if(hptr->data == d){
				hptr=hptr->next;
				length--;
			}
			else{
				while(temp->next!=NULL && temp->next->data!=d){
					temp=temp->next;
				}
				if(temp->next==NULL){
					cout<<"data not found"<<endl;
				}
				else{
					temp->next=temp->next->next;
					length--;
				}
			}
		}
		void insert_node(int p,int v){
			if(p == 0){
				node *nptr= new node(v);
				nptr->next=hptr;
				hptr=nptr;
				length++;
			}
			else if(p>length-1){
				cout<<"insert out of bound"<<endl;
				return;
			}
			else{
				node *temp=hptr;
				int count=0;
				while(count<p-1){
					temp=temp->next;
					count++;
				}
				node *nptr=temp->next;
				node *temp1=new node(v);
				temp->next=temp1;
				temp1->next=nptr;
				length++;
			}
		}
};
int main(){
	linkedlist l;
	int p,v;
	int n,i,d;
	int h;
	cout<<"Number of elements"<<endl;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>d;
		l.append(d);
	}
	cout<<"forward display"<<endl;
	l.forward_display();
	cout<<"enter element to delete"<<endl;
	cin>>h;
	cout<<"after deletion"<<endl;
	l.delete_node(h);
	l.forward_display();
	cout<<"enter the position and element to display"<<endl;
	cin>>p>>v;
	l.insert_node(p,v);
	cout<<"After insertion:"<<endl;
	l.forward_display();
	cout<<"reverse display"<<endl;
	l.reverse_display(l.hptr);
	l.forward_display();
	
	return 0;
}
