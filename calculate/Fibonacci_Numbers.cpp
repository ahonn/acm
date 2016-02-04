// Fibonacci Numbers

// Description
// A Fibonacci sequence is calculated by adding the previous two members of the sequence, with the first two members being both 1.
// f(1) = 1, f(2) = 1, f(n > 2) = f(n - 1) + f(n - 2)
// Your task is to take a number as input, and print that Fibonacci number.

// Sample Input
// 100

// Sample Output
// 354224848179261915075

// Note:
// No generated Fibonacci number in excess of 1000 digits will be in the test data, i.e. f(20) = 6765 has 4 digits.

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[5005][1005];

int main(){
	// freopen("../input.txt", "rt", stdin);
	int i, j, n, carry;
	memset(f, 0, sizeof(f));
	f[1][0] = f[2][0] = 1;
	for(i = 3; i < 5005; ++i) {
		carry = 0;
		for(j = 0; j < 1001; ++j) {
			f[i][j] = f[i-2][j] + f[i-1][j] + carry;
			carry = f[i][j] / 10;
			f[i][j] %= 10;
		}
	}
	while(scanf("%d", &n) != EOF) {
		for(j = 1001; j >= 0; --j) {
			if(f[n][j] != 0) {
				break;
			}
		}
		for(; j >= 0; --j) {
			printf("%d", f[n][j]);
		}
		printf("\n");
	}
    return 0;
}
