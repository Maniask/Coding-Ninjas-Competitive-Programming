
/*
Longest Consecutive Sequence

You are given an array of unique integers that contain numbers in random order. 
Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.

Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
0 <= n <= 10^6

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 

Sample Output 1 :
8 
9 
10 
11 
12

Sample Input 2 :
7
3 7 2 1 9 8 41

Sample Output 2 :
7
8
9

Explanation: Sequence should be of consecutive numbers. Here we have 2 
sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] 
because the starting point of [7, 8, 9] comes first in input array.

Sample Input 3 :
7
15 24 23 12 19 11 16

Sample Output 3 :
15 
16
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    unordered_map<int, bool> visited;
    unordered_map<int, int> m;
    
    for(int i = 0; i < n; i++){
        m[arr[i]] = i;
        if(visited.count(arr[i]) == 0) visited[arr[i]] = true;
    }
    
    int ansLength = 1;
    int ansIndex = 0;
    
    for(int i = 0; i < n; i++){
        
        int count = 0;
        int temp = arr[i];
        int currMinStartIndex = i;
        int tempNum = temp;
        
        //forward
        while(visited.count(tempNum) == 1 && visited[tempNum]){
            visited[tempNum] = false;
            count++;
            tempNum++;
        }
        
        //backward
        tempNum = temp-1;
        while(visited.count(tempNum) == 1 && visited[tempNum]){
            visited[tempNum] = false;
            count++;
            currMinStartIndex = m[tempNum];
            tempNum--;
        }
        
        if(count > ansLength){
            ansLength = count;
            ansIndex = currMinStartIndex;
        }
        else if(count == ansLength){
            if(currMinStartIndex < ansIndex) ansIndex = currMinStartIndex;
        }
    }
    
    int num = arr[ansIndex];
    vector<int>ans;
    ans.push_back(num);
    ansLength--;
    
    while(ansLength > 0){
        num++;
        ans.push_back(num);
        ansLength--;
    }
    return ans;
}

int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}
