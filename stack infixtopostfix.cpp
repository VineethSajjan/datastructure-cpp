#include<iostream>
#include<string>
#include<stack>
using namespace std;
class ITFConversion{
	public:
		int prec(char c){
			if(c == '+' || c == '-'){
				return 1;
			}
			else if(c == '/' || c == '*'){
				return 2;
			}
			else{
				return 0;
			}
		}
		bool isoperator(char ch){
			if(ch == '-' || ch == '+' || ch == '/' || ch == '*'){
				return true;
			}
			else{
				return false;
			}
		}
		string infixtopostfix(string s){
			string res;
			stack<char> st;
			for(int i=0;i<s.length();i++){
				if(!isoperator(s[i])){
				res=res+s[i];
				continue;
			}
			if(st.empty()){
				st.push(s[i]);
			}
			else{
				while(!st.empty() && prec(st.top())>=prec(s[i])){
					res+=st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			}
			while(!st.empty()){
				res+=st.top();
				st.pop();
			}
			return res;
		}
};
int main(){
	ITFConversion itf;
	string exp;
	cout<<"enter the expression"<<endl;
	cin>>exp;
	cout<<"postfix form"<<itf.infixtopostfix(exp)<<endl;
	return 0;
}
