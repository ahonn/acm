// Description
// Recently you must have experienced that when too many people use the BBS simultaneously, the net becomes very, very slow.
// To put an end to this problem, the Sysop has developed a contingency scheme for times of peak load to cut off net access for some buildings of the university in a systematic, totally fair manner. Our university buildings were enumerated randomly from 1 to n. XWB is number 1, CaoGuangBiao (CGB) Building is number 2, and so on in a purely random order.
// Then a number m would be picked at random, and BBS access would first be cut off in building 1 (clearly the fairest starting point) and then in every mth building after that, wrapping around to 1 after n, and ignoring buildings already cut off. For example, if n=17 and m=5, net access would be cut off to the buildings in the order [1,6,11,16,5,12,2,9,17,10,4,15,14,3,8,13,7]. The problem is that it is clearly fairest to cut off CGB Building last (after all, this is where the best programmers come from), so for a given n, the random number m needs to be carefully chosen so that building 2 is the last building selected.
// Your job is to write a program that will read in a number of buildings n and then determine the smallest integer m that will ensure that our CGB Building can surf the net while the rest of the university is cut off.

// Input Specification
// The input file will contain one or more lines, each line containing one integer n with 3 <= n < 150, representing the number of buildings in the university.
// Input is terminated by a value of zero (0) for n.

// Output Specification
// For each line of the input, print one line containing the integer m fulfilling the requirement specified above.

// Sample Input
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 0

// Sample Output
// 2
// 5
// 2
// 4
// 3
// 11
// 2
// 3
// 8
// 16

#include <cstdio>
#include <cstring>
using namespace std;

int build[155];

int main() {
  //freopen("../input.txt", "rt", stdin);
  int n, i, j, ans;
  while(scanf("%d", &n) != EOF && n) {
    for(i = 2; i <= 9999; i++) {
        ans = 0;
        for(j = 2;j < n;j++) {
          ans = (ans + i) % j;
        }
        if(ans == 0) {
          printf("%d\n", i);
          break;
        }
    }
  }
  return 0;
}
