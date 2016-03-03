// Head-to-Head Match

// Description
// Our school is planning to hold a new exciting computer programming contest. During each round of the contest, the competitors will be paired, and compete head-to-head. The loser will be eliminated, and the winner will advance to next round. It proceeds until there is only one competitor left, who is the champion. In a certain round, if the number of the remaining competitors is not even, one of them will be chosed randomly to advance to next round automatically, and then the others will be paired and fight as usual. The contest committee want to know how many rounds is needed to produce to champion, then they could prepare enough problems for the contest.

// Input
// The input consists of several test cases. Each case consists of a single line containing a integer N - the number of the competitors in total. 1 <= N <= 2,147,483,647. An input with 0(zero) signals the end of the input, which should not be processed.

// Output
// For each test case, output the number of rounds needed in the contest, on a single line.

// Sample Input
// 8
// 16
// 15
// 0

// Sample Output
// 3
// 4
// 4

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    // freopen("../input.txt", "rt", stdin);
    int n, times;  
    while(scanf("%d", &n) && n) {  
        times=0;  
        while(n > 1) {  
            times++;  
            if(n%2 != 0) {
                n = n/2 + 1;
            }
            else {
                n /= 2;  
            }
        }  
        printf("%d\n", times);  
    } 
    return 0;  
}