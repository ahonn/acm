// Parencodings

// Description
// Let S = s1 s2 ... s2n be a well-formed string of parentheses. S can be encoded in two different ways:

// By an integer sequence P = p1 p2 ... pn where pi is the number of left parentheses before the ith right parenthesis in S (P-sequence).
// By an integer sequence W = w1 w2 ... wn where for each right parenthesis, say a in S, we associate an integer which is the number of right parentheses counting from the matched left parenthesis of a up to a. (W-sequence).
// Following is an example of the above encodings:

// S (((()()())))
// P-sequence 4 5 6666
// W-sequence 1 1 1456

// Write a program to convert P-sequence of a well-formed string to the W-sequence of the same string.

// Input
// The first line of the input contains a single integer t (1 <= t <= 10), the number of test cases, followed by the input data for each test case. The first line of each test case is an integer n (1 <= n <= 20), and the second line is the P-sequence of a well-formed string. It contains n positive integers, separated with blanks, representing the P-sequence.

// Output
// The output consists of exactly t lines corresponding to test cases. For each test case, the output line should contain n integers describing the W-sequence of the string corresponding to its given P-sequence.

// Sample Input
// 2
// 6
// 4 5 6 6 6 6
// 9
// 4 6 6 6 6 8 9 9 9

// Sample Output
// 1 1 1 4 5 6
// 1 1 2 4 5 1 1 3 9

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int p[1000];

int main(){
	// freopen("input.txt", "rt", stdin);
	stack<int> stack;
	int i, j, t, n, s, w;
    scanf("%d", &t);
    while(t--) {
    	scanf("%d", &n);
    	memset(p, 0, sizeof(p));
    	for(i = 0; i < n; ++i) {
    		scanf("%d", &s);
    		p[i + s] = 1;
    	}
    	for(j = 0;j < i+s; ++j) {
    		if(p[j] == 0) {
    			stack.push(j);
    		}
    		else {
    			w = (j-stack.top()+1) / 2;
    			if(j == i+s-1) {
    				printf("%d\n", w);
    			}
    			else {
    				printf("%d ", w);
    			}
    			stack.pop();
    		}
    	}
    }
    return 0;
}