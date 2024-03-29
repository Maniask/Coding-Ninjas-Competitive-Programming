

//https://codeforces.com/problemset/problem/1037/C

#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;
	string s, t;
	cin>>s>>t;
	
	int cost = 0;
	
	for(int i = 0; i < n; ){
		if(s[i] != t[i]){
			//Either swap or flip and increment the cost
			if( (i+1 < n) && s[i+1] != s[i] && s[i+1] != t[i+1]){
				// Swapping
				i+=2;
			}else{
				// Flipping
				i++;
			}
			cost++;
		}else i++;
	}
	cout<<cost<<endl;
	return 0;
}
