#include<bits/stdc++.h>
using namespace std;

int kadane(int *arr, int n){
	int max_ending_here = 0;
	int max_so_far = 0;
	
	for(int i = 0; i < n; i++){
		max_ending_here+=arr[i];
		
		if(max_ending_here > max_so_far) max_so_far = max_ending_here;
		if(max_ending_here < 0) max_ending_here = 0;
	}
	return max_so_far;
}

int main(){
	int arr[] = {1,2,3,4,-5,-4,1,2,10,33,-27};
	int n = sizeof(arr)/sizeof(int);
	cout<<kadane(arr, n);
	return 0;
}
