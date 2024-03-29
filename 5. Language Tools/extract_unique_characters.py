
'''
Extract Unique characters

Given a string, you need to remove all the duplicates. That means, the output string 
should contain each character only once. The respective order of characters should remain same.

Input format :
String S

Output format :
Output String

Constraints :
0 <= Length of S <= 10^8

Sample Input 1 :
ababacd

Sample Output 1 :
abcd

Sample Input 2 :
abcde

Sample Output 2 :
abcde
'''


def uniqueChars(string):
    m = {}
    ans = ""
    for i in string:
        m[i] = m.get(i, 0) + 1
        if m[i] == 1:
            ans = ans + i
    return ans


string = input()
print(uniqueChars(string))
