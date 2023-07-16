#include<iostream>
#define max 50
using namespace std;
class stack{
	int data;
	public:
	int arr[max];
	int top=-1;
		void push(int d){
			if(top == max-1){
				cout<<"stack is full:"<<endl;
			}
			else{
				top++;
				arr[top]=d;
			}
		}
		void pop(){
			if(top == -1){
				cout<<"stack is overflow:"<<endl;
			}
			else{
				cout<<arr[top]<<endl;
				top--;
			}
		}
		void display(){
			for(int i=top;i>=0;i--){
				cout<<arr[i]<<endl;
			}
		}
};
int main(){
	stack s;
	s.push(10);
		s.push(29);
			s.push(45);
				s.push(50);
				s.display();
				cout<<"popped elements are:"<<endl;
				s.pop();
				s.pop();
				s.pop();
				cout<<"after popping:"<<endl;
				s.display();
}
