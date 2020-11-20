
/*
Print Keypad Combinations Code

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

Note : The order of strings are not important. Just print different strings in new lines.

Input Format :
Integer n
Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include<bits/stdc++.h>
using namespace std;

int keypad(int n, string *output, string *options){
    if(n == 0){
        output[0] = "";
        return 1;
    }
    
    string x[500];
    int count = keypad(n/10, x, options);
    
    string op = options[n%10];
    
    int k = 0;
    for(int i = 0; i < op.length(); i++){
        for(int j = 0; j < count; j++){
            output[k++] = x[j] + op[i];
        }
    }
    return k;
}

void printKeypad(int num){
    if(num == 0) return;
    string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output[100000];
    int count = keypad(num, output, options);
    for(int i = 0; i < count; i++) cout<<output[i]<<endl;
}

int main(){
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}

