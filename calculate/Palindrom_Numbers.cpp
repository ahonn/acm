// Palindrom Numbers

// Description
// Statement of the Problem
// We say that a number is a palindrom if it is the sane when read from left to right or from right to left. For example, the number 75457 is a palindrom.
// Of course, the property depends on the basis in which is number is represented. The number 17 is not a palindrom in base 10, but its representation in base 2 (10001) is a palindrom.
// The objective of this problem is to verify if a set of given numbers are palindroms in any basis from 2 to 16.

// Input Format
// Several integer numbers comprise the input. Each number 0 < n < 50000 is given in decimal basis in a separate line. The input ends with a zero.

// Output Format
// Your program must print the message Number i is palindrom in basis where I is the given number, followed by the basis where the representation of the number is a palindrom. If the number is not a palindrom in any basis between 2 and 16, your program must print the message Number i is not palindrom.

// Sample Input
// 17
// 19
// 0

Sample Output

Number 17 is palindrom in basis 2 4 16
Number 19 is not a palindrom

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	// freopen("../input.txt", "rt", stdin);
	int a[20], s[17];
	int n, m, i, j, k;
	while(scanf("%d", &n) && n != 0) {
		memset(s, 0, sizeof(s));
		for(i = 2; i <= 16; ++i) {
			m = n;
			j = 0;
			memset(a, '\0', sizeof(a));
			while(m) {
				a[j++] = m % i;
				m /= i;
			}

			m = 1;
			for(k = 0;k < j/2; ++k) {
				if(a[k] != a[j-k-1]) {
					m = 0;
				}
			}
			if(m == 0) {
				continue;
			}

			s[i] = 1;
			if(s[0] == 0) {
				s[0] = 1;
			}
		}

		if(s[0]) {
			printf("Number %d is palindrom in basis", n);
			for(i = 2; i < 17; ++i) {
				if(s[i]) {
					printf(" %d", i);
				}
			}
		} 
		else {
			printf("Number %d is not a palindrom", n);
		}
		printf("\n");
	}
    return 0;
}