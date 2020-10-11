
/*
https://www.geeksforgeeks.org/maximum-product-subarray/

Maximum Product Subarray  

Given an array that contains both positive and negative integers, 
find the product of the maximum product subarray. Expected Time complexity is O(n) and only O(1) extra space can be used.

Examples:
Input: arr[] = {6, -3, -10, 0, 2}
Output:   180  // The subarray is {6, -3, -10}

Input: arr[] = {-1, -3, -10, 0, 60}
Output:   60  // The subarray is {60}

Input: arr[] = {-2, -3, 0, -2, -40}
Output:   80  // The subarray is {-2, -40}
*/

#include<bits/stdc++.h>
using namespace std;

int maximumProductSubarray(int *arr, int n){
	int max_ending_here = 1;
	int min_ending_here = 1;
	int max_so_far = 1;
	int flag = 0;
	
	for(int i = 0; i < n; i++){
		
		if(arr[i] > 0){
			max_ending_here = max_ending_here*arr[i];
			min_ending_here = min(min_ending_here*arr[i], 1);
			flag = 1;
		}else if(arr[i] == 0){
			max_ending_here = 1;
			min_ending_here = 1;
		}else{
			int temp = max_ending_here;
			max_ending_here = max(1, min_ending_here*arr[i]);
			min_ending_here = temp*arr[i];
		}
		
		if(max_so_far < max_ending_here) max_so_far = max_ending_here;
	}
	
	if(flag == 0 && max_so_far == 1) return 0;
	else return max_so_far;
}

int main(){
	int arr[] = {-1, -3, -10, 0, 60};
	int n = sizeof(arr)/sizeof(int);
	cout<<maximumProductSubarray(arr, n)<<endl;
	return 0;
}
