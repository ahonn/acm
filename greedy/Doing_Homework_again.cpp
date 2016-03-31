// Description
// Ignatius has just come back school from the 30th ACM/ICPC. Now he has a lot of homework to do. Every teacher gives him a deadline of handing in the homework. If Ignatius hands in the homework after the deadline, the teacher will reduce his score of the final test. And now we assume that doing everyone homework always takes one day. So Ignatius wants you to help him to arrange the order of doing homework to minimize the reduced score.
//
// Input
// The input contains several test cases. The first line of the input is a single integer T that is the number of test cases. T test cases follow.
// Each test case start with a positive integer N(1<=N<=1000) which indicate the number of homework.. Then 2 lines follow. The first line contains N integers that indicate the deadlines of the subjects, and the next line contains N integers that indicate the reduced scores.
//
// Output
// For each test case, you should output the smallest total reduced score, one line per test case.
//
// Sample Input
// 3
// 3
// 3 3 3
// 10 5 1
// 3
// 1 3 1
// 6 2 3
// 7
// 1 4 6 4 2 4 3
// 3 2 1 7 6 5 4
//
// Sample Output
// 0
// 3
// 5

#include <cstdio>
#include <algorithm>
using namespace std;

int pass[1005];

struct Homework {
  int day;
  int sorce;
}hw[1005];

int cmp(Homework a, Homework b) {
  if (a.sorce != b.sorce) {
    return a.sorce > b.sorce;
  }
  else {
    return a.day < b.day;
  }
}

int main() {
  // freopen("../input.txt", "rt", stdin);
  int t, n, i, j, reduce;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    memset(pass, 0, sizeof(pass));
    for(i = 0; i < n; i++) {
      scanf("%d", &hw[i].day);
    }
    for(i = 0; i < n; i++) {
      scanf("%d", &hw[i].sorce);
    }
    sort(hw, hw+n, cmp);
    reduce = 0;
    for(i = 0; i < n; i++) {
      for(j = hw[i].day; j >= 0; j--) {
        if( ! pass[j] && j) {
          pass[j] = 1;
          break;
        }
        if(j == 0) {
          reduce += hw[i].sorce;
          break;
        }
      }
    }
    printf("%d\n", reduce);
  }
  return 0;
}
