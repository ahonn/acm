// All in All

// Description
// You have devised a new encryption technique which encodes a message by inserting between its characters randomly generated strings in a clever way. Because of pending patent issues we will not discuss in detail how the strings are generated and inserted into the original message. To validate your method, however, it is necessary to write a program that checks if the message is really encoded in the final string.
// Given two strings s and t, you have to decide whether s is a subsequence of t, i.e. if you can remove characters from t such that the concatenation of the remaining characters is s.

// Input
// The input contains several testcases. Each is specified by two strings s, t of alphanumeric ASCII characters separated by whitespace. Input is terminated by EOF.

// Output
// For each test case output, print "Yes" if s is a subsequence of t or "No" if not.

// Sample Input
// sequence subsequence
// person compression
// VERDI vivaVittorioEmanueleReDiItalia
// caseDoesMatter CaseDoesMatter

// Sample Output
// Yes
// No
// Yes
// No

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[1000005];
char b[1000005];

int main(){
	// freopen("input.txt", "rt", stdin);
	long i, j;
	int len1, len2;
	while(scanf("%s %s", a, b) != EOF) {
		len1 = strlen(a);
		len2 = strlen(b);
		i = j = 0;
		while(1) {
			if(i == len1) {
				printf("Yes\n");
				break;
			}
			else if(i < len1 && j == len2) {
				printf("No\n");
				break;
			}
			if(a[i] == b[j]) {
				i++;
			}
			j++;
		}
	}
    return 0;
}
