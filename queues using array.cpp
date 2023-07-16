#include<iostream>
#define max 50
using namespace std;
class queue{
	public:
		int front=-1,rear=-1;
		int arr[max];
		void enqueue(int d){
			if(rear==max-1){
				cout<<"queue overflow"<<endl;
			}
			else{
				if(front == -1){
					front=0;
					rear++;
					arr[rear]=d;
				}
				else{
					rear++;
					arr[rear]=d;
				}
			}
		}
		void dequeue(){
			if(front == -1 || front>rear){
				cout<<"queue underflow"<<endl;
			}
			else{
				arr[front];
				front++;
			}
		}
		void display(){
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<endl;
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
	q.enqueue(60);
	q.display();
	q.dequeue();
	q.dequeue();
	cout<<"after poping:"<<endl;
	q.display();
}
