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
  void display()
  {
      cout<<data<<endl;
  }
  
};
class queue{
	public:
	Node *front=NULL,*rear=NULL;
	void enqueue(int d){
		if(front == NULL){
			Node *nptr =new Node(d);
			front=rear=nptr;
		}
		else{
			Node *nptr =new Node(d);
			rear->next=nptr;
			rear=nptr;
		}
	}
	int dequeue(){
		if(front == NULL){
			cout<<"queue is empty"<<endl;
		}
		else{
			Node *temp=front;
			front=front->next;
			return temp->data;
			delete temp;
		}
	}
	void display(){
		Node *temp=front;
		while(temp!=NULL){
			temp->display();
			temp=temp->next;
		}
	}
};
int main(){
	queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.display();
	cout<<"deleted :"<<endl;
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.display();
	return 0;
	
}
