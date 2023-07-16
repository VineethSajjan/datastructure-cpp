#include<bits/stdc++.h>
using namespace std;
void quicksort(int array[10],int first,int last){
	int pivot,temp,i,j;
	if(first<last){
		pivot=first;
		i=first;
		j=last;
		while(i<j){
			while(array[i]<=array[pivot] && i<last){
				i++;
			}
			while(array[j]>array[pivot]){
				j--;
			}
			if(i<j){
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
			temp=array[pivot];
			array[pivot]=array[j];
			array[j]=temp;
			quicksort(array,first,j-1);
			quicksort(array,j+1,last);
		}
	}
	
}
int binarysearch(int arr[],int n,int d){
	int l,r=n-1,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(arr[mid]==d){
			return mid+1;
		}
		else if (arr[mid]<d){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return -1;
}
int main(){
	int size,d;
	cout<<"enter the size of an array:"<<endl;
	cin>>size;
	int array[size];
	cout<<"enter the elements:"<<endl;
	for(int i=0;i<size;i++){
		cin>>array[i];
	}
	quicksort(array,0,size-1);
	cout<<"sorted elements are:"<<endl;
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	cout<<"enter element to search:"<<endl;
	cin>>d;
	int x=binarysearch(array,size,d);
	if(x!=-1){
		cout<<"found element at position:"<<x<<endl;
	}
	else{
		cout<<"element not found:"<<endl;
	}
}
