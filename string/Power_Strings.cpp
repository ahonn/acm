// Power Strings+

// Description
// Given two strings a and b we define a*b to be their concatenation. For example, if a = "abc" and b = "def" then a*b = "abcdef". If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" (the empty string) and a^(n+1) = a*(a^n).

// Input
// Each test case is a line of input representing s, a string of printable characters.

// Output
// For each s you should print the largest n such that s = a^n for some string a. The length of s will be at least 1 and will not exceed 1 million characters. A line containing a period follows the last test case.

// Sample Input
// abcd
// aaaa
// ababab
// .

// Sample Output
// 1
// 4
// 3

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int i, j, len, next[1000005];
char a[1000005];

int main(){
	// freopen("input.txt", "rt", stdin);
	while(scanf("%s", a) != EOF) {
		if(a[0] == '.') {
			break;
		}
		len = strlen(a);
		next[0] = -1;
		for(i = 0, j = -1;i <= len; ) {
			while(j == -1 || (i < len && a[i] == a[j])) {
				next[++i] = ++j;
			}
			j = next[j];
		}
		if(len % (len - next[len]) == 0) {
			printf("%d\n", len / (len - next[len]));
		} 
		else {
			printf("1\n");
		}
	}
    return 0;
}
