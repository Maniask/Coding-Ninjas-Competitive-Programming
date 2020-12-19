
/*
String Search

Given two strings S and T, write a function to find if T is present as a substring inside S or not. 
If yes, return the starting index otherwise return -1.

Input format :
Line 1 : String S
Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3

Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1

*/

#include<bits/stdc++.h>
using namespace std;

int findString(char S[], char T[]) {
    // Write your code here
    int n = strlen(S);
    int m = strlen(T);
    
    int j;
    for(int i = 0; i <= (n-m); i++){
        j = 0;
        while(j < m && S[i+j] == T[j]) j++;
        
        if(j == m) return i;
    }
    return -1;
}

int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}

