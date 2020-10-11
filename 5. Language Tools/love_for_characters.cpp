
/*
Love for Characters

Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters 
and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.

Input:
First line contains an integer denoting length of the string.
Next line contains the string.

Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’

Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.

Sample Input:
6
aabsas

Sample output:
3 2 0
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a = 0; // count for a
    int sx = 0; // count for s
    int p = 0; // count for p
    
    for(int i =  0; i < s.length(); i++){
        if(s[i] == 'a') a++;
        else if(s[i] == 's') sx++;
        else if(s[i] == 'p') p++;
        else continue;
    }
    cout<<a<<" "<<sx<<" "<<p;
	return 0;
}

