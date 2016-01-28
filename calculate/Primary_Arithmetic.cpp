// Primary Arithmetic

// Description
// Children are taught to add multi-digit numbers from right-to-left one digit at a time. Many find the "carry" operation - in which a 1 is carried from one digit position to be added to the next - to be a significant challenge. Your job is to count the number of carry operations for each of a set of addition problems so that educators may assess their difficulty.

// Input
// Each line of input contains two unsigned integers less than 10 digits. The last line of input contains 0 0.

// Output
// For each line of input except the last you should compute and print the number of carry operations that would result from adding the two numbers, in the format shown below.

// Sample Input
// 123 456
// 555 555
// 123 594
// 0 0

// Sample Output
// No carry operation.
// 3 carry operations.
// 1 carry operation.

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	// freopen("../input.txt", "rt", stdin);
	long n, m;
	int a, b, c, t;
	while(scanf("%ld %ld", &n, &m)) {
		if(n == 0 && m == 0) {
			break;
		}
		c = t = 0;
		while(1) {
			a = n % 10;
			b = m % 10;
			n /= 10;
			m /= 10;
			if( a+b+c >= 10) {
				t++;
				c = (a+b+c)/10;
			}
			else {
				c = 0;
			}
			if(n == 0 && m == 0) {
				break;
			}
		}
		if(t == 0) {
			printf("No carry operation.\n");
		}
		else if(t == 1) {
			printf("1 carry operation.\n");
		} 
		else {
			printf("%d carry operations.\n", t);
		}
	}
    return 0;
}
