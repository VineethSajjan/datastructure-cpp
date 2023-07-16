#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int first,int mid,int last){
	int temp[50],i,j,k;
	i=first;
	j=mid+1;
	k=0;
	while(i<=mid && i<=last){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=last){
		temp[k++]=arr[j++];
	}
	for(i=first,k=0;i<=last;i++,k++){
		arr[i]=temp[k];
	}
}
void mergesort(int arr[],int first,int last){
	int mid;
	if(first<last){
		mid=(first+last)/2;
		mergesort(arr,first,mid);
		mergesort(arr,mid+1,last);
		merge(arr,first,mid,last);
	}
	  
}
int linearsearch(int arr[],int n,int d){
	for(int i=0;i<n;i++){
		if(arr[i]==d){
			return i+1;
		}
	}
	return -1;
}
int main(){
	int n,d;
	cout<<"enter the size of array:"<<endl;
	cin>>n;
	int arr[n],i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"sorted elements"<<endl;
	mergesort(arr,0,n);
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"enter the element:"<<endl;
	cin>>d;
	int x=linearsearch(arr,n,d);
	if(x!=-1){
		cout<<"element found at"<<x<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
}
