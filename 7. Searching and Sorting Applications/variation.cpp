
//https://www.codechef.com/ZCOPRAC/problems/ZCO15002

#include<bits/stdc++.h>
using namespace std;

long variationPairs(int *arr, int n, int k){
	
	sort(arr, arr+n);
	
	int i = 0, j = 1;
	long count = 0;
	
	while(j < n){
		if((arr[j]-arr[i]) >= k){
			count += (n-j);
			i++;
		}else j++;
	}
	return count;
}


int main(){
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i = 0; i < n; i++) cin>>arr[i];
	
	long ans = variationPairs(arr, n, k);
	cout<<ans<<endl;
	return 0;
}
