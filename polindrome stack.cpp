#include<iostream>
#include<stack>
using namespace std;
class polindrome{
	public:
	bool ispolindrome(string s){
		stack<char> st;
		string res;
		for(int i=0;i<s.length();i++){
			st.push(s[i]);
		}
		while(!st.empty()){
			res+=st.top();
			st.pop();
		}
		if(res == s){
			return true;
		}
		else{
			return false;
		}
	}
};
int main(){
	polindrome st;
	string exp;
	cout<<"enter the expression"<<endl;
	cin>>exp;
	if(st.ispolindrome(exp)){
		cout<<"sting is polindrome"<<endl;
	}
	else{
		cout<<"string is not polindrome:"<<endl;
	}
	return 0;
}
