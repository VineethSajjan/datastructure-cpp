#include<bits/stdc++.h>
using namespace std;
class Queue{
	public:
		stack<int> s1,s2;
		void enqueue(int d){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(d);
			while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}
		}
		int dequeue(){
			while(s1.empty()){
				cout<<"queue is empty"<<endl;
				exit(0);
			}
			int x=s1.top();
			s1.pop();
			return x;
		}
};
int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout<<q.dequeue()<<" ";
	cout<<q.dequeue()<<" ";
	cout<<q.dequeue()<<" ";
	return 0;
}
