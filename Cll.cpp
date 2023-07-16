#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int d){
			data=d;
			next=NULL;
		}
		void display(){
			cout<<data<<endl;
		}
};
class circular_list{
	public:
		Node *hptr=NULL;
		void cappend(int d){
			Node *nptr=new Node(d);
			if(hptr == NULL){
				hptr=nptr;
				nptr->next=hptr;
			}
			else{
				Node *temp=hptr;
				while(temp->next!=hptr){
					temp=temp->next;
				}
				temp->next=nptr;
				nptr->next=hptr;
				
			}
		}
		void display(){
			Node *temp=hptr;
			while(temp->next!=hptr){
				temp->display();
				temp=temp->next;
				
			}
			temp->display();
		}
		void delete_node(int val){
			Node *temp=hptr;
			if(hptr->data==val){
				
			}
		}
};
int main(){
	circular_list cl;
	int i,n,d;
	cout<<"enter the number of elements:"<<endl;
	cin>>n;
	cout<<"enter elements:"<<endl;
	for(i=0;i<n;i++){
		cin>>d;
		cl.cappend(d);
	}
	cout<<"elements of list are:"<<endl;
	cl.display();
}
