
/*
Quick Sort Code

Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7
*/

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int si, int ei){
	// choosing a random pivot
	int pivot = arr[si];
	
	// counting elements which are less than pivot
	int count = 0;
	for(int i = si+1; i<=ei; i++){
		if(pivot >= arr[i]) count++;
	}
	
	int pi = si+count;
	
	// placing pivot at the right place
	int temp = arr[si];
	arr[si] = arr[pi];
	arr[pi] = temp;
	
	//comparing left and right side of pivot element
	int i = si, j = ei;
	while(i <= pi && j >= ei){
		while(arr[i] <= pivot) i++;
		while(arr[j] > pivot) j--;
		if(i < pi && j > pi){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	return pi;
}

void quick_sort(int arr[], int si, int ei){
	if(si>=ei) return;
	int pi = partition(arr, si, ei);
	quick_sort(arr, si, pi-1);
	quick_sort(arr, pi+1, ei);
}

int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	
	for(int i = 0; i < n; i++) cin>>arr[i];
	
	quick_sort(arr, 0, n-1);
	for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
	return 0;
}
