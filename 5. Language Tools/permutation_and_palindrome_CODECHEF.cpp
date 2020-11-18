//https://www.codechef.com/problems/PERMPAL


#include<bits/stdc++.h>
using namespace std;

char getChar(int i){
	return char(i + 97);
}

void printPalindrome(string s){
	map<char, vector<int>> indexesMap;
	for(int i = 0; i < s.length(); i++) indexesMap[s[i]].push_back(i);
	
	int odd_freq_count = 0;
	for(int i = 0; i < 26; i++){
		if((indexesMap[getChar(i)].size()) % 2 != 0) odd_freq_count++;
	}
	
	if(odd_freq_count >= 2){
		cout<<"-1";
		return;
	}
	
	int ans[s.length()];
	int start = 0;
	int end = s.length()-1;
	
	for(int i = 0; i < 26; i++){
		char currentChar = getChar(i);
		for(int j = 0; j < indexesMap[currentChar].size(); j+=2){
			
			if(indexesMap[currentChar].size()-j == 1){
				ans[s.length()/2] = indexesMap[currentChar][j];
				continue;
			}
			ans[start] = indexesMap[currentChar][j];
			ans[end] = indexesMap[currentChar][j+1];
			start++;
			end--;
		}
	}
	
	for(int i = 0; i < s.length(); i++){
		cout<<ans[i]+1<<" ";
	}
	return ;
}

//void printPalindrome(string s){
//	
//	unordered_map<char, vector<int>> mp;
//	
//	//indexing mapping
//	for(int i = 0; i < s.length(); i++) mp[s[i]].push_back(i);
//	
//	//checking if odd_freq >= 2
//	int odd_freq = 0;
//	for(auto it = mp.begin(); it!=mp.end(); it++){
//		if(it->second.size()%2 != 0) odd_freq++;
//	}
//	
//	if(odd_freq >= 2) {
//		cout<<"-1";
//		return ;
//	}
//	
//	//creating the permutation
//	int start = 0;
//	int end = s.length()-1;
//	for(auto it = mp.begin(); it!=mp.end(); it++){
//		vector<int> arr = it->second;
//		char curr = it->first;
//		if(arr.size()%2==0){
//			for(int i = 0; i < arr.size()/2; i++){
//				s[start] = curr;
//				s[end] = curr;
//				start++;
//				end--;
//			}
//		}else{
//			for(int i = 0; i < arr.size()/2; i++){
//				s[start] = curr;
//				s[end] = curr;
//				start++;
//				end--;
//			}
//			s[s.length()/2] = curr;
//		}	
//	}
//	cout<<s<<endl;
//}

int main(){
	int t;
	cin>>t;
	
	while(t--){
		string s;
		cin>>s;
		printPalindrome(s);
		cout<<endl;
	}
	return 0;
}
