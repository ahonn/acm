// Integer Inquiry

// Description
// One of the first users of BIT's new supercomputer was Chip Diller. He extended his exploration of powers of 3 to go from 0 to 333 and he explored taking various sums of those numbers.
// ``This supercomputer is great,'' remarked Chip. ``I only wish Timothy were here to see these results.'' (Chip moved to a new apartment, once one became available on the third floor of the Lemon Sky apartments on Third Street.)

// Input
// The input will consist of at most 100 lines of text, each of which contains a single VeryLongInteger. Each VeryLongInteger will be 100 or fewer characters in length, and will only contain digits (no VeryLongInteger will be negative).
// The final input line will contain a single zero on a line by itself.

// Output
// Your program should output the sum of the VeryLongIntegers given in the input.
// This problem contains multiple test cases!
// The first line of a multiple input is an integer N, then a blank line followed by N input blocks. Each input block is in the format indicated in the problem description. There is a blank line between input blocks.
// The output format consists of N output blocks. There is a blank line between output blocks.

// Sample Input
// 1 

// 123456789012345678901234567890
// 123456789012345678901234567890
// 123456789012345678901234567890
// 0


// Sample Output
// 370370367037037036703703703670

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;

int main(){
	// freopen("../input.txt", "rt", stdin);
	int t, i, len1, len2, len, result, carry;
	char temp, str[105], sum[105];
	scanf("%d", &t);
	while(t--) {
		memset(sum, 0, sizeof(sum));
		sum[0] = '0';
		while(scanf("%s", str) && str[0] != '0') {
			len1 = strlen(sum);
			len2 = strlen(str);
			
			// reversal
			for(i = 0; i < len2/2; ++i) {
				temp = str[len2-i-1];
				str[len2-i-1] = str[i];
				str[i] = temp;
			}

			// align
			if(len1 > len2) {
				len = len1;
				for(i = len2; i < len; ++i) {
					str[i] = '0';
				}
			} else {
				len = len2;
				for(i = len1; i < len; ++i) {
					sum[i] = '0';
				}
			}

			// add
			carry = 0;
			for(i = 0;i < len; ++i) {
				result = str[i]-'0' + sum[i]-'0' + carry;
				carry = result / 10;
				sum[i] = result % 10 + '0';
			}
			if(carry != 0) {
				sum[i] = carry + '0';
			}
		}
		for(i = strlen(sum)-1;i >= 0; --i ) {
			printf("%c", sum[i]);
		}
		printf("\n");
		if(t) {
			printf("\n");
		}
	}
    return 0;
}