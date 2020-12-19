
/*

Palindromic Substrings

Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.

Input Format :
String S
Output Format :
count of palindrome substrings

Constraints :
1 <= Length of S <= 1000

Sample Input :
aba
Sample Output :
4
*/


#include<bits/stdc++.h>
using namespace std;

int countPalindromeSubstrings(char s[]) {
    int count = 0;
    int n = strlen(s);
    
    for(int i = 0; i < n; i++){
        
        //ODD length
        int l = i-1;
        int r = i+1;
        count++;
        while(l>=0 && r< n){
            if(s[l] == s[r]){
                l--;
                r++;
                count++;
            }else{
                break;
            }
        }
        
        // EVEN length
        if(i < n-1 && s[i] == s[i+1]){
            l = i-1;
            r = i+2;
            count++;
            while(l>=0 && r< n){
            if(s[l] == s[r]){
                l--;
                r++;
                count++;
            }else{
                break;
            }
        }
    }
}
    return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}

