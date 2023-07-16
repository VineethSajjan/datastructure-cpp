#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *left;
		Node *right;
		Node(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
		void display(){
			cout<<data<<endl;
		}
};
class BinarySearchTree{
	public:
	Node *rptr=NULL;
	Node *addnode(Node *r,int d)
	{
		if(r == NULL){
			Node *nptr=new Node(d);
			return nptr;
		}
		else if(r->data>d){
			r->left=addnode(r->left,d);
			return r;
		}
		else{
			r->right=addnode(r->right,d);
			return r;
		}
	}
	void inorder(Node *r){
		if(r == NULL){
			return;
		}
		else{
			inorder(r->left);
			r->display();
			inorder(r->right);
		}
	}
	Node *getmin(Node *r){
	    if(r->left == NULL) return r;
	    getmin(r->left);
	}
	Node *delete_node(Node *r,int d){
		if(r == NULL){
			return NULL;
		}
		if(r->data>d){
			r->left=delete_node(r->left,d);
		}
		else if(r->data<d){
			r->right=delete_node(r->right,d);
		}
		else{
			if(r->left == NULL && r->right == NULL){
				r = NULL;
			}
			else if(r->left == NULL){
				Node *temp=r;
				r = r->right;
				delete temp;
			}
			else if(r->right == NULL){
				Node *temp=r;
				r = r->left;
				delete temp;
			}
			else{
				Node *temp=getmin(r->right);
				r->data=temp->data;
				r->right=delete_node(r->right,temp->data);
			}
		}
		return r;
	}
	int height(Node *r){
		if(r == NULL){
			return 0;
		}
		else{
			return 1+max(height(r->left),height(r->right));
		}
	}
	bool isbalanced(Node *r){
		int lh,rh;
		if(r == NULL){
			return true;
		}
		else{
			lh=height(r->left);
			rh=height(r->right);
			if(abs(lh-rh)>1){
				return false;
			}
			else{
				return isbalanced(r->left)&&isbalanced(r->right);
			}
		}
	}
};
int main(){
	BinarySearchTree BST;
	Node *rptr=BST.addnode(NULL,50);
	rptr=BST.addnode(rptr,20);
	rptr=BST.addnode(rptr,30);
	rptr=BST.addnode(rptr,40);
	rptr=BST.addnode(rptr,70);
	rptr=BST.addnode(rptr,60);
	rptr=BST.addnode(rptr,80);
	rptr=BST.addnode(rptr,25);
	cout<<"Display:"<<endl;
	BST.inorder(rptr);
	BST.delete_node(rptr,20);
	cout<<"after deletion:"<<endl;
	BST.inorder(rptr);
	if(BST.isbalanced(rptr)){
		cout<<"tree is balanced:"<<endl;
	}
	else{
		cout<<"tree is not balanced:"<<endl;
	}
	
}
