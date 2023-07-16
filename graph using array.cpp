#include<iostream>
using namespace std;
int a[10][10];
void add_edge(int u,int v){
	a[u][v]=1;
	a[v][u]=1;
}
void display(int v){
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int v=5;
	add_edge(0,1);
	add_edge(0,4);
	add_edge(1,2);
	add_edge(1,3);
	add_edge(1,4);
	add_edge(2,3);
	add_edge(3,4);
	cout<<"graph is :"<<endl;
	display(v);
}
