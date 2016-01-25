// Soundex

// Description
// Soundex coding groups together words that appear to sound alike based on their spelling. For example, "can" and "khawn", "con" and "gone" would be equivalent under Soundex coding. 

// Soundex coding involves translating each word into a series of digits in which each digit represents a letter:
// 1 represents B, F, P, or V
// 2 represents C, G, J, K, Q, S, X, or Z
// 3 represents D or T
// 4 represents L
// 5 represents M or N
// 6 represents R

// The letters A, E, I, O, U, H, W, and Y are not represented in Soundex coding, and repeated letters with the same code digit are represented by a single instance of that digit. Words with the same Soundex coding are considered equivalent.

// Input
// Each line of input contains a single word, all upper case, less than 20 letters long.

// Output
// For each line of input, produce a line of output giving the Soundex code.

// Sample Input
// KHAWN
// PFISTER
// BOBBY

// Sample Output
// 25
// 1236
// 11

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	// freopen("input.txt", "rt", stdin);
	int i, len;
	char a[27] = "01230120022455012623010202";
	char text[30], now, last;
	while(cin.getline(text, 30)) {
		len = strlen(text);
		last = '0';
		for(i = 0;i < len; ++i) {
			now = a[text[i] - 'A'];
			if(now != '0' && now != last) {
				printf("%c", now);
			}
			last = now;
		}
		printf("\n");
	}
    return 0;
}