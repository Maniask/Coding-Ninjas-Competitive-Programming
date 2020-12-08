#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, n, i;
//	using LEFT SHIFT ( << )
	a = 6;
	b = a<<1;
	cout<<b<<endl;
	
//	using RIGHT SHIFT ( >> )
	a = 6;
	b = a>>1;
	cout<<b<<endl;
	
//	using AND ( & )
	a = 5;
	b = 4;
	c = a&b;
	cout<<c<<endl;
	
//	using OR ( | )
	a = 5;
	b = 4;
	c = a | b;
	cout<<c<<endl;
	
//	using NOT ( ~ )
	a = 5;
	b = ~a;
	cout<<b<<endl;
	
//	using XOR ( ^ )
	a = 5;
	b = 4;
	c = a^b;
	cout<<c<<endl;
	
//	check ith bit is SET or un-SET
	n = 12;
	i = 2;
	if(n&(1<<i)) cout<<"SET";
	else cout<<"un-SET";
	cout<<endl;
	
//	set ith bit
	n = 12;
	i = 0;
	n = n|(1<<i);
	cout<<n<<endl;
	
//	unset ith bit
	n = 12;
	i = 2;
	n = n&~(1<<i);
	cout<<n<<endl;
	
//	flip ith bit
	n = 12;
	i = 2;
	n = n^(1<<i);
	cout<<n<<endl;
	
//	check ODD/EVEN
	n = 11;
	if(n&1) cout<<"ODD";
	else cout<<"EVEN";
	cout<<endl;
	
//	check whether number N is power of 2 or not
	n = 16;
	if(n&(n-1)) cout<<"NO";
	else cout<<"YES";
	cout<<endl;
	
//	find first set bit
	n = 15;
	n = n&(-1*n);
	cout<<n<<endl;
	
//	turn off first set bit
	n = 12;
	a = n&(-1*n);   // finding first set bit
	n = n^a;
	cout<<n<<endl;
	
//	clear all bits from i to LSB
	n = 15;
	i = 1;
	a = 1<<(i+1);
	b = a-1;
	c = ~b;
	n = n&c;
	cout<<n<<endl;
	
//	clear all bits from MSB to i
	n = 15;
	i = 2;
	a = 1<<i;
	b = a-1;
	n = n&b;
	cout<<n<<endl;
	
	return 0;

}
