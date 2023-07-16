#include<iostream>
#include<stack>
using namespace std;
class Epf{
	public:
		bool isoperator(char ch){
			if(ch == '+' || ch == '-' || ch == '/' || ch == '*'){
				return true;
				
			}
			else{
				return false;
			}
		}
		int evalpostfix(string s){
			stack<int> st;
			int res,a,b;
			for(int i=0;i<s.length();i++){
			if(!isoperator(s[i])){
				st.push(s[i]-'0');
			}
			else{
				b=st.top();
				st.pop();
				a=st.top();
				st.pop();
				switch(s[i]){
					case '+':
						res=a+b;
						break;
					case '-':
						res=a-b;
						break;
			        case '*':
						res=a*b;
						break;
					case '/':
						res=a/b;
						break;
			}
			st.push(res);
		}
		}
		return st.top();
	}
};
int main(){
	Epf e;
	string exp;
	cout<<"enter the string:"<<endl;
	cin>>exp;
	cout<<e.evalpostfix(exp)<<endl;
}
