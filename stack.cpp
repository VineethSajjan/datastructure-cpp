#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node(int d){
		next=NULL;
		data=d;
	}
};
class stack{
	public:
		Node *hptr;
		int maxlength,clength;
		stack(int n){
			hptr=NULL;
			maxlength=n;
			clength=0;
		}
		void push(int d){
			if(clength == maxlength){
				cout<<"stack is full"<<endl;
			}
			else if(hptr == NULL){
				Node *temp=new Node(d);
				hptr=temp;
				clength++;
			}
			else{
				Node *nptr=new Node(d);
				nptr->next=hptr;
				hptr=nptr;
				clength++;
			}
		}
		void pop(){
			if(clength == 0){
				cout<<"stack overflow"<<endl;
			}
			else{
				int t=hptr->data;
				hptr=hptr->next;
				clength--;
				cout<<t<<endl;
			}
		}
			void display(){
			Node *temp=hptr;
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
};
int main(){
	stack s(4);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.display();
	cout<<"popped elements are:"<<endl;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	return 0;
}
