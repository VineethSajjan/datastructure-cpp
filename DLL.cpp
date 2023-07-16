#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *next;
  Node *prev;
  
  Node(int d){
	  data=d;
      next=NULL;
      prev = NULL;
  }
  void display()
  {
      cout<<data<<endl;
  }
  
};
class DLL
{  
    public:
    	int length=0;
    Node *hptr=NULL;
    Node *tptr=NULL;
    void add(int d)
    {
        Node*nptr = new Node(d);
        if(hptr == NULL)
        {
            hptr = tptr = nptr;
        }
        else
        {
            tptr ->next = nptr;
            nptr->prev = tptr;
            tptr = nptr;
        }
        length++;
        
    }
    void forward_display()
    {
       Node *temp=hptr;
       while(temp!=NULL)
        { 
            temp->display();
            temp = temp->next;
    }
    }
      void backward_display()
      {
          Node*temp = tptr;
          while(temp!=NULL)
          {
              temp->display();
              temp = temp->prev;
          }
      }
      void del(int val)
      {   
         
          if(hptr->data == val)
          {    
              Node*temp = hptr;
              hptr->next->prev = NULL;
              hptr = temp->next;
              length--;
          }
          else if(tptr->data == val)
          {
              Node*temp = tptr; 
              tptr = temp->prev;
              tptr->prev->next = NULL;
              length--;
          }
          else
          {
              Node*temp = hptr;
             while(temp!=NULL)
             {
                 if(temp->next!=NULL  && temp->next->data == val)
                 {
                     temp->next = temp->next->next;
                     temp->next->prev = temp; 
                     return ;
                     length--;
                 }
                 temp = temp->next;
             }
             cout<<"Element  Not Found"<<endl;
             
          }
      }
          void insert_node(int p,int v){
          	Node *temp=hptr;
          	Node *nptr=new Node(v);
          	if(p == 0){
          		temp->prev=nptr;
          		nptr->next=temp;
          		hptr=nptr;
          		length++;
			}
			else if(p>length-1){
				cout<<"insert out of bound"<<endl;
				return;
			}
			else{
				int count=0;
				while(count<p-1){
					temp=temp->next;
					count++;
				}
				Node *t=temp->next;
				temp->next=nptr;
				nptr->prev=temp;
				nptr->next=t;
				t->prev=nptr;
				length++;
			}
			
		  }
          
};
int main(){
    DLL dll;
    int n,i;
    cout<<"enter size of list"<<endl;
    cin>>n;
    cout<<"enter elements"<<endl;
    for(i=0;i<n;i++){
    	int d;
    	cin>>d;
    	dll.add(d);
	}
    cout<<"Enter node to be delete"<<endl;
    int v,p,d;
    cin>>v;
    dll.del(v);
    cout<<"After Deletion"<<endl;
    dll.forward_display();
    cout<<"enter position and element to be added"<<endl;
    cin>>p>>d;
    dll.insert_node(p,d);
    cout<<"after insertion"<<endl;
    dll.forward_display();
    
    return 0;
}
